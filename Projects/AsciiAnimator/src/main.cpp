// #include "GameEngine.h" works, linter doesn't like it though
#include "../../GameEngineV2/src/GameEngine.h" // This will do for now
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <thread>
#include <unistd.h>

// Constant paramters
constexpr uint8_t SCREEN_WIDTH = 80;
constexpr uint8_t SCREEN_HEIGHT = 24;
constexpr uint8_t FRAME_RATE = 60;
constexpr uint8_t UI_LAYER = 100;
using Clock = std::chrono::steady_clock;
bool m_exitFlag = false;

void setExitFlag() { m_exitFlag = true; }

int main() {
  int userInput = 0;
  constexpr float FRAME_DURATION = 1.0f / FRAME_RATE;
  auto lastTime = Clock::now();

  std::vector<Animation> playerAnimations;
  Animation playerIdleAnimation = loadAnimation("player", "idle", true);
  playerAnimations.push_back(playerIdleAnimation);
  auto player = std::make_shared<Entity>("player", playerAnimations, true, 0);
  allEntities.push_back(player);

  std::vector<Animation> testAnimations;
  Animation counterAnimation = loadAnimation("test", "count", true);
  testAnimations.push_back(counterAnimation);
  auto test = std::make_shared<Entity>("test", testAnimations, true, 0);
  allEntities.push_back(test);

  int midX = (SCREEN_WIDTH / 2);
  int midY = (SCREEN_HEIGHT / 2);
  test->displace(midX, midY);

  Camera gameCamera = Camera(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  std::vector<Animation> exitAnimations;
  Animation exitButtonAnimation =
      loadAnimation("exitButton", "exitButton", true);
  exitAnimations.push_back(exitButtonAnimation);
  auto exitEntity =
      std::make_shared<Entity>("exitButton", exitAnimations, true, UI_LAYER);
  Button exitButton = Button(0, 0, false, *exitEntity, setExitFlag);

  // GameLoop
  initCurse();
  MEVENT event;
  bool drawing = false;
  int lastMouseX = -1;
  int lastMouseY = -1;

  while (userInput != '`' && !m_exitFlag) {
    // --- INPUT HANDLING ---
    int ch;
    while ((ch = getch()) !=
           ERR) { // non-blocking, get all input events this frame
      userInput = ch;
      if (ch == KEY_MOUSE) {
        if (getmouse(&event) == OK) {
          if (event.bstate & BUTTON2_PRESSED) {
            drawing = true;
            lastMouseX = event.x;
            lastMouseY = event.y;
          }

          if (event.bstate & BUTTON2_RELEASED) {
            drawing = false;
            lastMouseX = -1;
            lastMouseY = -1;
          }

          if (event.bstate & BUTTON1_PRESSED) {
            if (exitButton.mouseInBounds(event.x, event.y)) {
              exitButton.executeFunction();
            }
          }

          if (drawing && (event.bstate & REPORT_MOUSE_POSITION)) {
            // Calculate how much the mouse moved
            int dx = lastMouseX - event.x;
            int dy = lastMouseY - event.y;

            // Pan the camera accordingly
            gameCamera.displaceViewPort(-dx, -dy);

            // Update the last known position
            lastMouseX = event.x;
            lastMouseY = event.y;
          }
        }
      } else if (ch == 'w') {
        player->displace(0, -2);
      } else if (ch == 'a') {
        player->displace(-2, 0);
      } else if (ch == 's') {
        player->displace(0, 2);
      } else if (ch == 'd') {
        player->displace(2, 0);
      } else if (ch == 'i') {
        gameCamera.displaceViewPort(0, -2);
      } else if (ch == 'k') {
        gameCamera.displaceViewPort(0, 2);
      } else if (ch == 'j') {
        gameCamera.displaceViewPort(-2, 0);
      } else if (ch == 'l') {
        gameCamera.displaceViewPort(2, 0);
      }
    }

    // --- FRAME UPDATES (LIMITED TO 60FPS) ---
    auto currentTime = Clock::now();
    std::chrono::duration<float> delta = currentTime - lastTime;
    if (delta.count() >= FRAME_DURATION) {
      refreshAllEntities(delta.count());
      exitButtonAnimation.update(delta.count());

      refreshCurse();

      lastTime = currentTime;
    }

    // --- Tiny sleep to prevent CPU overuse ---
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  closeCurseWindow();
  return 0;
}
