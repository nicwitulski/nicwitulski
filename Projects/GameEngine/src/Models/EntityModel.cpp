#include "EntityModel.h"

bool m_isMovable;
void (*m_movementFunction)();

// private ----------------------------------------------------------------------------
void EntityModel::immovable()
{
   this->setPosition(this->getPosition());
};

// public -----------------------------------------------------------------------------
EntityModel::EntityModel()
{
   m_isMovable         = false;
   *m_movementFunction = immovable;
   this->setAlias("entity");
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
