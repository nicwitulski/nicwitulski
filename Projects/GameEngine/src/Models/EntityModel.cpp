#include "EntityModel.h"

void immovable()
{
   return;
}

// public -----------------------------------------------------------------------------
EntityModel::EntityModel()
{
   m_isMovable        = false;
   m_movementFunction = immovable;
   this->setSprite(SpriteModel());
   this->setAlias("entity");
};

// public -----------------------------------------------------------------------------
EntityModel::EntityModel(SpriteModel sprite, std::string alias, bool isMovable)
{
   this->setAlias(alias);
   this->setSprite(sprite);
   m_isMovable        = isMovable;
   m_movementFunction = immovable;
};

// public -----------------------------------------------------------------------------
bool EntityModel::isMovable()
{
   return m_isMovable;
};

// public -----------------------------------------------------------------------------
void EntityModel::setMovementLogic(void (*movementFunction)(SpriteModel sprite))
{
   m_movementFunction = movementFunction;
};

// public -----------------------------------------------------------------------------
void EntityModel::doMovement()
{
   if (m_isMovable)
   {
      m_movementFunction(this->getSprite());
   }
}

// public -----------------------------------------------------------------------------
void EntityModel::setMoveable(bool isMovable)
{
   m_isMovable = isMovable;
};
