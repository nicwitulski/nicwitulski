#include "../../../include/Entity.h"

Entity::Entity() {
  m_entityName = "none";
  m_currentAnimation = "default";
  m_animations.push_back(Animation());
  m_visable = false;
  m_layer = 0;
  m_moveableByCamera = true;
  m_moved = false;
  m_anchor = Position(0, 0);
  Sprite m_spriteBeforeMove = Sprite();
};

Entity::Entity(std::string entityName, std::vector<Animation> animations,
               bool visable, int layer, bool moveableByCamera) {
  m_entityName = entityName;
  m_animations = animations;

  if (!animations.empty()) {
    m_currentAnimation = animations.at(0).getAnimationName();
  } else {
    std::cerr << "Warning: Entity \"" << entityName << "\" has no animations!"
              << std::endl;
    m_currentAnimation = "none";
  }

  m_currentAnimation =
      animations.at(0).getAnimationName(); // Default is first loaded animation,
                                           // change manually
  m_visable = visable;
  m_layer = layer;
  m_moveableByCamera = moveableByCamera;
  m_moved = false;
  m_anchor = Position(0, 0);
  Sprite m_spriteBeforeMove = Sprite();
};

std::string Entity::getEntityName() { return m_entityName; }

void Entity::setEntityName(std::string entityName) {
  m_entityName = entityName;
};