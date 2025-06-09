#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "Entity.h"
#include <cstdint>

class UIElement {
protected:
  int8_t m_minXPos;
  int8_t m_minYPos;
  int8_t m_maxXPos;
  int8_t m_maxYPos;
  bool m_moveableByCamera;
  Entity m_entity;

  void setMaxPositionsFromEntity();

public:
  UIElement();
  UIElement(int8_t minX, int8_t minY, bool moveableByCamera, Entity entity);
};

#endif