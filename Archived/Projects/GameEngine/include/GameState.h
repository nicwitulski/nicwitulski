#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
public:
  virtual ~GameState() = default;

  virtual void onEnter() = 0;
  virtual void onExit() = 0;
  virtual void update() = 0;

  virtual GameState *getNextState() { return nullptr; }
};

#endif