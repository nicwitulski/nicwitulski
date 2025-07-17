#ifndef STARTAPPSTATE_H
#define STARTAPPSTATE_H

#include "../../../GameEngine/include/GameEngine.h"

class StartAppState : public GameState {
private:
  std::shared_ptr<Entity> counterEntity;
  std::shared_ptr<Entity> stickEntity;
  std::shared_ptr<Entity> cameraOutline;

  MEVENT event;
  bool drawing = false;
  int lastMouseX = -1;
  int lastMouseY = -1;

public:
  void onEnter() override;
  void update() override;
  void onExit() override;

  GameState *getNextState() override;
};

#endif