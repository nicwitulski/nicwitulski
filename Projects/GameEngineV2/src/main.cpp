#include "Controller/SpriteUtils.h"
#include "Model/Entity.h"
#include "View/Display.h"
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
using Clock = std::chrono::steady_clock;

int main() {
  int userInput = 0;
  constexpr float FRAME_DURATION = 1.0f / FRAME_RATE;
  auto lastTime = Clock::now();

  std::vector<Animation> playerAnimations;
  Animation playerIdleAnimation = loadAnimation("player", "idle", true);
  playerAnimations.push_back(playerIdleAnimation);
  Entity player = Entity("player", playerAnimations, true, 0);

  std::vector<Animation> testAnimations;
  Animation counterAnimation = loadAnimation("test", "count", true);
  testAnimations.push_back(counterAnimation);
  Entity test = Entity("test", testAnimations, true, 1);

  int midX = (SCREEN_WIDTH / 2);
  int midY = (SCREEN_HEIGHT / 2);
  test.displace(midX, midY);

  // GameLoop
  initCurse();
  MEVENT event;
  bool drawing = false;

  while (userInput != '`') {
    // --- INPUT HANDLING ---
    int ch;
    while ((ch = getch()) !=
           ERR) { // non-blocking, get all input events this frame
      userInput = ch;
      if (ch == KEY_MOUSE) {
        if (getmouse(&event) == OK) {
          if (event.bstate & BUTTON1_PRESSED)
            drawing = true;
          if (event.bstate & BUTTON1_RELEASED)
            drawing = false;

          if (drawing && (event.bstate & REPORT_MOUSE_POSITION)) {
            mvaddch(event.y, event.x, 'X');
          }
        }
      } else if (ch == 'w') {
        player.displace(0, -2);
      } else if (ch == 'a') {
        player.displace(-2, 0);
      } else if (ch == 's') {
        player.displace(0, 2);
      } else if (ch == 'd') {
        player.displace(2, 0);
      }
    }

    // --- FRAME UPDATES (LIMITED TO 60FPS) ---
    auto currentTime = Clock::now();
    std::chrono::duration<float> delta = currentTime - lastTime;
    if (delta.count() >= FRAME_DURATION) {
      // Place animation updates and screen refresh here
      std::vector<Entity *> refreshedEntities;
      refreshedEntities.push_back(&test);
      refreshedEntities.push_back(&player);

      refreshAllEntities(refreshedEntities, delta.count());

      refreshCurse();

      lastTime = currentTime;
    }

    // --- Tiny sleep to prevent CPU overuse ---
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  //   // User Input
  //   userInput = getUserInput();

  //   // Game Logic
  //   //
  //   ------------------------------------------------------------------------------------------------------
  //   // Process user input:

  //   if (userInput == 'w') {
  //     player.displace(0, -5);
  //   } else if (userInput == 'a') {
  //     player.displace(-5, 0);
  //   } else if (userInput == 's') {
  //     player.displace(0, 5);
  //   } else if (userInput == 'd') {
  //     player.displace(5, 0);
  //   }

  //   std::vector<Entity *> refreshedEntities;
  //   refreshedEntities.push_back(&test);
  //   refreshedEntities.push_back(&player);

  //   refreshAllEntities(refreshedEntities, deltaTime.count());
  //   //
  //   ------------------------------------------------------------------------------------------------------

  // }

  closeCurseWindow();
  return 0;
}
