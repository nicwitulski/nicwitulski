#include "Animation.h"
#include "Button.h"
#include "Camera.h"
#include "Display.h"
#include "Entity.h"
#include "FileLoading.h"
#include "Frame.h"
#include "GameObject.h"
#include "GameState.h"
#include "Parameters.h"
#include "Pixel.h"
#include "Position.h"
#include "Printable.h"
#include "Sprite.h"
#include "UIElement.h"
#include <chrono>

class GameEngine {
private:
  GameState *currentState;

  void exit();

public:
  GameEngine(GameState *initialState) : currentState(initialState) {
    currentState->onEnter();
  }

  void run();
};