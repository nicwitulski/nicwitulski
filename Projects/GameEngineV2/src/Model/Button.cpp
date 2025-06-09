#include "Button.h"

Button::Button(){

};

Button::Button(int8_t minX, int8_t minY, bool moveableByCamera, Entity entity,
               std::function<void()> function) {
  m_minXPos = minX;
  m_minYPos = minY;
  m_moveableByCamera = moveableByCamera;
  m_entity = entity;
  m_function = std::move(function);
  setMaxPositionsFromEntity();
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
  if (x >= m_minXPos && x <= m_maxXPos && y >= m_minYPos && y <= m_maxYPos) {
    return true;
  }
  return false;
}