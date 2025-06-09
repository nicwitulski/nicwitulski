#include "Entity.h"
#include <cstdint>

Entity::Entity() {
  m_entityName = "none";
  m_currentAnimationName = "none";
  m_animations.push_back(Animation());
  m_visable = false;
  m_layer = 0;
};

Entity::Entity(std::string entityName, std::vector<Animation> animations,
               bool visable, uint8_t layer) {
  m_entityName = entityName;
  m_animations = animations;
  m_currentAnimationName =
      animations.at(0).getAnimationName(); // Default is first loaded animation,
                                           // change manually
  m_visable = visable;
  m_layer = layer;
};

std::vector<Animation> &Entity::getAnimations() { return m_animations; };

std::string Entity::getEntityName() { return m_entityName; }

void Entity::setEntityName(std::string entityName) {
  m_entityName = entityName;
};

std::string Entity::getCurrentAnimationName() {
  return m_currentAnimationName;
};

bool Entity::setCurrentAnimation(std::string animationName) {
  for (Animation animation : m_animations) {
    if (animation.getAnimationName() == animationName) {
      m_currentAnimationName = animation.getAnimationName();
      return true;
    }
  }
  return false; // If not loaded, stays as current animation
}

void Entity::addAnimation(Animation animation) {
  m_animations.push_back(animation);
}

void Entity::setCurrentAnimation(Animation animation) {
  if (setCurrentAnimation(animation.getAnimationName())) {
    m_currentAnimationName = animation.getAnimationName();
    addAnimation(animation); // Adds animation if not loaded, else prioritizes
                             // current animation name
  }
}

void Entity::displace(uint16_t dx, uint16_t dy) {
  for (Animation &animation : m_animations) {
    animation.eraseDisplace(dx, dy);
  }
}

void Entity::refresh(float deltaTime) {
  int i = 0;
  for (Animation animation : m_animations) {
    if (animation.getAnimationName() == m_currentAnimationName) {
      break;
    }
    i++;
  }
  m_animations.at(i).update(deltaTime);
}