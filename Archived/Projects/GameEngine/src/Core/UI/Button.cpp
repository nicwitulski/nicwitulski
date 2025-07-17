#include "../../../include/Button.h"

Button::Button() {
  m_visable = false;
  m_layer = 0;
  m_moveableByCamera = true;
  m_currentAnimation = "default";
  m_animations.push_back(Animation());
  m_anchor = Position(0, 0);
  m_moved = false;
  m_spriteBeforeMove = Sprite();
};

Button::Button(std::vector<Animation> animations, bool visable, int layer,
               bool movableByCamera, std::function<void()> function) {
  m_animations = animations;
  m_currentAnimation = m_animations.at(0).getAnimationName();
  m_moved = false;
  m_anchor = Position(0, 0);
  m_visable = visable;
  m_layer = layer;
  m_moveableByCamera = movableByCamera;
  m_function = std::move(function);
  m_spriteBeforeMove = Sprite();
  setPositions();
}

void Button::setFunction(std::function<void()> func) {
  m_function = std::move(func);
};

void Button::executeFunction() {
  if (m_function) {
    m_function();
  } else {
    { return; }
  }
};

bool Button::mouseInBounds(int x, int y) {
  if (x >= m_minPosition.getX() && x <= m_maxPosition.getX() &&
      y >= m_minPosition.getY() && y <= m_maxPosition.getY()) {
    return true;
  }
  return false;
}