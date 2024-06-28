#include "PixelModel.h"

PositionModel m_position;
char          m_character;

// public -----------------------------------------------------------------------------
PixelModel::PixelModel()
{
   m_position  = PositionModel();
   m_character = ' ';
};

// public -----------------------------------------------------------------------------
PixelModel::PixelModel(PositionModel position, char character)
{
   m_position  = position;
   m_character = character;
};

// public -----------------------------------------------------------------------------
void PixelModel::setPosition(PositionModel position)
{
   m_position = position;
};

// public -----------------------------------------------------------------------------
void PixelModel::setCharacter(char character)
{
   m_character = character;
};

// public -----------------------------------------------------------------------------
PositionModel PixelModel::getPosition()
{
   return m_position;
};

// public -----------------------------------------------------------------------------
char PixelModel::getCharacter()
{
   return m_character;
}
