#include "TileModel.h"

bool m_visible;
bool m_solid;

// public -----------------------------------------------------------------------------
TileModel::TileModel()
{
   m_visible = true;
   m_solid   = true;
   this->setAlias("tile");
   this->setSprite(SpriteModel());
};

// public -----------------------------------------------------------------------------
TileModel::TileModel(bool isVisible, bool isSolid, std::string alias, SpriteModel sprite)
{
   m_visible = isVisible;
   m_solid   = isSolid;
   this->setAlias(alias);
   this->setSprite(sprite);
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
