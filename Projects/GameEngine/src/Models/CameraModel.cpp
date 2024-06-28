#include "CameraModel.h"

#define DEFAULT_LENGTH 80
#define DEFAULT_HEIGHT 24

PositionModel m_middlePosition;
int           m_length;
int           m_height;
bool          m_lockedOntoPlayer;
PlayerModel   m_player;

CameraModel::CameraModel()
{
   m_lockedOntoPlayer = true;
   m_length           = DEFAULT_LENGTH;
   m_height           = DEFAULT_HEIGHT;
   setMiddlePosition();
};

CameraModel::CameraModel(int length, int height, PositionModel middlePosition, bool isLockedOntoPlayer,
                         PlayerModel player)
{
   m_length           = length;
   m_height           = height;
   m_lockedOntoPlayer = isLockedOntoPlayer;
   m_player           = player;
   if (m_lockedOntoPlayer && m_player != NULL)
   {
      setMiddlePosition();
   }
   else
   {
      m_middlePosition = middlePosition;
   }
};

void CameraModel::setMiddlePosition()
{
   if (m_lockedOntoPlayer)
   {
      m_middlePosition = PositionModel(m_player.PrintableModel::getSprite().getMiddlePixel().getPosition());
   }
}

void CameraModel::setMiddlePosition(PositionModel position)
{
   m_middlePosition = position;
};

PositionModel CameraModel::getMiddlePosition()
{
   return m_middlePosition;
};

void CameraModel::setDimensions(int length, int height)
{
   if (length < 0 || height < 0)
   {
      return;
   }
   m_length         = length;
   m_height         = height;
   m_middlePosition = PositionModel(length / 2 - 1, height / 2 - 1);
};

int CameraModel::getLength()
{
   return m_length;
};

int CameraModel::getHeight()
{
   return m_height;
};
