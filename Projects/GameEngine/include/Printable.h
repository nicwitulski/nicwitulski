#ifndef PRINTABLE_H
#define PRINTABLE_H

#include "Animation.h"
#include <string>
#include <vector>

class Printable {
protected:
  std::vector<Animation> m_animations;
  std::string m_currentAnimation = "default";
  bool m_moved = false;
  Position m_anchor;
  bool m_visable;
  int m_layer;
  bool m_moveableByCamera;
  Sprite m_spriteBeforeMove;

public:
  Printable();
  void addAnimation(const Animation animation);
  bool setCurrentAnimation(const std::string name);
  std::vector<Animation> &getAnimations();
  std::string getCurrentAnimationName();
  Position getAnchor();
  void displace(int dx, int dy);
  void moveToPosition(Position position);
  bool isVisable();
  int getLayer();
  void setVisability(bool visable);
  void setLayer(int layer);
  bool isMoveableByCamera();
  void setMoveableByCamera(bool moveable);
  bool didMove();
  void setMoved(bool moved);
  Sprite getSpriteBeforeMove();
};

#endif