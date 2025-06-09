#include "UIElement.h"

UIElement::UIElement() {
  m_minXPos = 0;
  m_minYPos = 0;
  m_maxXPos = 0;
  m_maxYPos = 0;
  m_moveableByCamera = false;
  m_entity = Entity();
};

UIElement::UIElement(int8_t minX, int8_t minY, bool moveableByCamera,
                     Entity entity) {
  m_minXPos = minX;
  m_minYPos = minY;
  m_moveableByCamera = moveableByCamera;
  m_entity = entity;
};

void UIElement::setMaxPositionsFromEntity() {
  int16_t currMaxX = 0;
  int16_t currMaxY = 0;
  for (Animation animation : m_entity.getAnimations()) {
    if (animation.getAnimationName() == m_entity.getCurrentAnimationName()) {
      for (Pixel pixel : animation.getCurrentFrameSprite().getPixels()) {
        if (currMaxX < pixel.getX()) {
          currMaxX = pixel.getX();
        }
        if (currMaxY < pixel.getY()) {
          currMaxY = pixel.getY();
        }
      }
    }
  }
  m_maxXPos = currMaxX;
  m_maxYPos = currMaxY;
};