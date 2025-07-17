#include "StartAppState.h"

void StartAppState::onEnter() {
  counterEntity = loadEntity("counter", true, 2, true);
  stickEntity = loadEntity("player", true, 1, true);
  cameraOutline = loadEntity("camera", true, 100, false);

  currentCamera = std::make_unique<Camera>(SCREEN_LENGTH, SCREEN_HEIGHT);
  playerEntity = stickEntity;

  //   Initial Displace
  int midX = (SCREEN_LENGTH / 2);
  int midY = (SCREEN_HEIGHT / 2);
  counterEntity->displace(midX, midY);
};

void StartAppState::update() {
  // Mouse Handling
  // --------------
  if (userInput == KEY_MOUSE) {
    if (getmouse(&event) == OK) {

      // Camera Drag
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

      if (drawing && (event.bstate & REPORT_MOUSE_POSITION)) {
        // Calculate how much the mouse moved
        int dx = lastMouseX - event.x;
        int dy = lastMouseY - event.y;

        // Pan the camera accordingly
        currentCamera->displaceViewPort(-dx, -dy);

        // Update the last known position
        lastMouseX = event.x;
        lastMouseY = event.y;
      }
    }
  }

  // Player Movement Test
  if (userInput == 'w') {
    playerEntity->displace(0, -2);
  } else if (userInput == 'a') {
    playerEntity->displace(-2, 0);
  } else if (userInput == 's') {
    playerEntity->displace(0, 2);
  } else if (userInput == 'd') {
    playerEntity->displace(2, 0);
  }
}

void StartAppState::onExit() {}

GameState *StartAppState::getNextState() { return nullptr; }