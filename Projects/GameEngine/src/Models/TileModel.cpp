#include "TileModel.h"

// public -----------------------------------------------------------------------------
TileModel::TileModel()
{
   m_visible = true;
   m_solid   = true;
   setSprite(SpriteModel());
   setAlias("Tile");
};

// public -----------------------------------------------------------------------------
TileModel::TileModel(bool isVisible, bool isSolid, std::string alias, SpriteModel sprite)
{
   m_visible = isVisible;
   m_solid   = isSolid;
   setSprite(sprite);
   setAlias(alias);
};

// public -----------------------------------------------------------------------------
void TileModel::setVisible(bool visible)
{
   m_visible = visible;
};

// public -----------------------------------------------------------------------------
void TileModel::setSolid(bool solid)
{
   m_solid = solid;
};

// public -----------------------------------------------------------------------------
bool TileModel::isSolid()
{
   if (m_solid)
   {
      return true;
   }
   return false;
};

// public -----------------------------------------------------------------------------
bool TileModel::isVisible()
{
   if (m_visible)
   {
      return true;
   }
   return false;
};
