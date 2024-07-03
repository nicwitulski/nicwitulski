#include "PositionModel.h"

// public -----------------------------------------------------------------------------
PositionModel::PositionModel()
{
   m_x = 0;
   m_y = 0;
};

// public -----------------------------------------------------------------------------
PositionModel::PositionModel(int x, int y)
{
   m_x = x;
   m_y = y;
};

// public -----------------------------------------------------------------------------
void PositionModel::setLocation(int x, int y)
{
   m_x = x;
   m_y = y;
};

// public -----------------------------------------------------------------------------
int PositionModel::getX()
{
   return m_x;
};

// public -----------------------------------------------------------------------------
int PositionModel::getY()
{
   return m_y;
};

// public -----------------------------------------------------------------------------
int PositionModel::Compare(PositionModel position) const
{
   if ((position.getY() > m_y) || (position.getY() == m_y && position.getX() > m_x))
   {
      return 1;
   }
   else if (position.getY() == m_y && position.getX() == m_x)
   {
      return 0;
   }
   else
   {
      return -1;
   }
}
