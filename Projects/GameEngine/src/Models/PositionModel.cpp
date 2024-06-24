#include "PositionModel.h"

int m_x;
int m_y;

PositionModel::PositionModel()
{
   m_x = 0;
   m_y = 0;
};

PositionModel::PositionModel(int x, int y)
{
   m_x = x;
   m_y = y;
}

void PositionModel::setLocation(int x, int y)
{
   m_x = x;
   m_y = y;
};

int PositionModel::getX()
{
   return m_x;
};

int PositionModel::getY()
{
   return m_y;
};
