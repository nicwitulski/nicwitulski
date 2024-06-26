#include "EntityModel.h"

bool m_isMovable;
void (*m_movementFunction)();

// private ----------------------------------------------------------------------------
void EntityModel::immovable(){};

// public -----------------------------------------------------------------------------
EntityModel::EntityModel()
{
   m_isMovable         = false;
   *m_movementFunction = immovable;
   this->setSprite(SpriteModel());
   this->setAlias("entity");
};

// public -----------------------------------------------------------------------------
EntityModel::EntityModel(SpriteModel sprite, std::string alias, bool isMovable)
{
   this->setAlias(alias);
   this->setSprite(sprite);
   m_isMovable = false;
};

// public -----------------------------------------------------------------------------
bool EntityModel::isMovable()
{
   return m_isMovable;
};

// public -----------------------------------------------------------------------------
void EntityModel::setMovementLogic(void (*movementFunction)())
{
   *m_movementFunction = *movementFunction;
};

// public -----------------------------------------------------------------------------
void EntityModel::setMoveable(bool isMovable)
{
   m_isMovable = isMovable;
};
