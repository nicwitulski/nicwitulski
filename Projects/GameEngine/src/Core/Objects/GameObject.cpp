#include "../../../include/GameObject.h"

GameObject::GameObject() {
  m_visable = false;
  m_layer = 0;
  m_moveableByCamera = true;
  m_currentAnimation = "default";
  m_animations.push_back(Animation());
  m_anchor = Position(0, 0);
  m_moved = false;
  m_spriteBeforeMove = Sprite();
};

GameObject::GameObject(bool visable, int layer, bool moveableByCamera,
                       std::vector<Animation> animations,
                       std::string currentAnimation) {
  m_visable = visable;
  m_layer = layer;
  m_moveableByCamera = moveableByCamera;
  m_animations = animations;
  m_currentAnimation = currentAnimation;
  m_anchor = Position(0, 0);
  m_moved = false;
  m_spriteBeforeMove = Sprite();
};