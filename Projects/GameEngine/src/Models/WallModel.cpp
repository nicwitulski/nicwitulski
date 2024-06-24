#include "WallModel.h"

bool m_visible;
bool m_solid;

// public -----------------------------------------------------------------------------
WallModel::WallModel()
{
   m_visible = true;
   m_solid   = true;
   this->setAlias("wall");
};

// public -----------------------------------------------------------------------------
void WallModel::setVisible(bool visible)
{
   m_visible = visible;
};

// public -----------------------------------------------------------------------------
void WallModel::setSolid(bool solid)
{
   m_solid = solid;
};

// public -----------------------------------------------------------------------------
bool WallModel::isSolid()
{
   if (m_solid)
   {
      return true;
   }
   return false;
};

// public -----------------------------------------------------------------------------
bool WallModel::isVisible()
{
   if (m_visible)
   {
      return true;
   }
   return false;
};
