#include "EntityModel.h"

// public -----------------------------------------------------------------------------
EntityModel::EntityModel()
{
   m_isMovable = false;
   setSprite(SpriteModel());
   setAlias("entity");
};

// public -----------------------------------------------------------------------------
EntityModel::EntityModel(SpriteModel sprite, std::string alias, bool isMovable)
{
   setAlias(alias);
   setSprite(sprite);
   m_isMovable = isMovable;
};

// public -----------------------------------------------------------------------------
bool EntityModel::isMovable()
{
   return m_isMovable;
};

// public -----------------------------------------------------------------------------
void EntityModel::setMovable(bool isMovable)
{
   m_isMovable = isMovable;
};
