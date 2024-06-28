#include "PositionModel.h"

int m_x;
int m_y;

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
