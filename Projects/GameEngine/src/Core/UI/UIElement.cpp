#include "../../../include/UIElement.h"

UIElement::UIElement() {
  m_visable = false;
  m_layer = 0;
  m_moveableByCamera = true;
  m_currentAnimation = "default";
  m_animations.push_back(Animation());
  m_anchor = Position(0, 0);
  m_moved = false;
  m_spriteBeforeMove = Sprite();
};

UIElement::UIElement(std::vector<Animation> animations, bool visable, int layer,
                     bool movableByCamera) {
  m_animations = animations;
  m_currentAnimation = m_animations.at(0).getAnimationName();
  m_moved = false;
  m_anchor = Position(0, 0);
  m_visable = visable;
  m_layer = layer;
  m_moveableByCamera = movableByCamera;
  m_spriteBeforeMove = Sprite();
  setPositions();
};

void UIElement::setPositions() {
  m_minPosition = m_anchor;
  int maxX = 0;
  int maxY = 0;

  for (Animation animation : m_animations) {
    if (animation.getAnimationName() == m_currentAnimation) {
      for (Pixel pixel : animation.getCurrentFrameSprite().getPixels()) {
        if (pixel.getPosition().getX() > maxX) {
          maxX = pixel.getPosition().getX();
          if (pixel.getPosition().getY() > maxY) {
            maxY = pixel.getPosition().getY();
          }
        }
      }
    }
  }
};