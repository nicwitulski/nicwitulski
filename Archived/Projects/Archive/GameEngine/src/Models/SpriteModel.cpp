#include "SpriteModel.h"

#include <iostream>
#include <sstream>
#include <string>

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel()
{
   initialize();

   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel(std::vector<PixelModel> pixels)
{
   initialize();
   m_pixels     = pixels;
   m_spriteSize = pixels.size();

   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel(std::vector<PixelModel> pixels, PositionModel maxPosition)
{
   initialize();
   m_pixels      = pixels;
   m_spriteSize  = pixels.size();
   m_maxPosition = maxPosition;
};

// private ----------------------------------------------------------------------------
void SpriteModel::initialize()
{
   m_pixels = std::vector<PixelModel>();
   m_pixels.push_back(PixelModel());
   m_spriteSize = 1;

   m_minimumPosition = PositionModel();
   m_maxPosition     = PositionModel();

   m_middlePixel = PixelModel();
};

// public -----------------------------------------------------------------------------
std::vector<PixelModel> SpriteModel::getPixels()
{
   return m_pixels;
};

// public -----------------------------------------------------------------------------
int SpriteModel::getSpriteSize()
{
   return m_spriteSize;
};

// public -----------------------------------------------------------------------------
PositionModel SpriteModel::getMaxPosition()
{
   return m_maxPosition;
};

// public -----------------------------------------------------------------------------
PositionModel SpriteModel::getMinimumPosition()
{
   return m_minimumPosition;
};

// public -----------------------------------------------------------------------------
PixelModel SpriteModel::getMiddlePixel()
{
   return m_middlePixel;
};

// public -----------------------------------------------------------------------------
PixelModel SpriteModel::getPixelAtPosition(PositionModel position)
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      if (m_pixels.at(i).getPosition() == position)
      {
         return m_pixels.at(i);
      }
   }
   return PixelModel(PositionModel(), '~');
};

// public -----------------------------------------------------------------------------
std::string SpriteModel::getString()
{
   std::string result = "";
   for (int y = 0; y <= m_maxPosition.getY(); y++)
   {
      for (int x = 0; x <= m_maxPosition.getX(); x++)
      {
         PositionModel position(x, y);
         PixelModel    pixel;
         pixel = getPixelAtPosition(position);
         if (pixel.getCharacter() != '~')
         {
            result.push_back(pixel.getCharacter());
         }
         else
         {
            result.push_back(' ');
         }
      }
      result.push_back('\n');
   }
   return result;
};

// private ----------------------------------------------------------------------------
void SpriteModel::setMinMaxMid()
{
   PositionModel min = m_pixels.at(0).getPosition();
   PositionModel max = m_pixels.at(0).getPosition();

   for (int i = 1; i < m_spriteSize; i++)
   {
      PixelModel pixel      = m_pixels.at(i);
      int        xCandidate = pixel.getPosition().getX();
      int        yCandidate = pixel.getPosition().getY();

      if (xCandidate < min.getX())
      {
         min.setX(xCandidate);
      }
      if (xCandidate > max.getX())
      {
         max.setX(xCandidate);
      }
      if (yCandidate < min.getY())
      {
         min.setY(yCandidate);
      }
      if (yCandidate > max.getY())
      {
         max.setY(yCandidate);
      }
   }
   m_maxPosition     = max;
   m_minimumPosition = min;

   PositionModel middlePosition = PositionModel(m_maxPosition.getX() / 2.0, m_maxPosition.getY() / 2.0);
   m_middlePixel                = getPixelAtPosition(middlePosition);
};

// public -----------------------------------------------------------------------------
void SpriteModel::setCharacterAtPosition(PositionModel position, char character)
{
   if (position == m_middlePixel.getPosition())
   {
      m_middlePixel.setCharacter(character);
   }
   else
   {
      for (int i = 0; i < m_spriteSize; i++)
      {
         if (position == m_pixels.at(i).getPosition())
         {
            m_pixels.at(i).setCharacter(character);
            return;
         }
      }
      m_pixels.push_back(PixelModel(position, character));
      m_spriteSize++;
      setMinMaxMid();
   }
};

// public -----------------------------------------------------------------------------
void SpriteModel::addPixel(PixelModel pixel)
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      if (pixel.getPosition() == m_pixels.at(i).getPosition())
      {
         return;
      }
   }
   m_pixels.push_back(pixel);
   m_spriteSize++;
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveWholeSpriteToMiddlePosition(PositionModel middle)
{
   int xDiff = middle.getX() - m_middlePixel.getPosition().getX();
   int yDiff = middle.getY() - m_middlePixel.getPosition().getY();

   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel    pixel = m_pixels.at(i);
      PositionModel newPosition;
      newPosition.setLocation(xDiff + pixel.getPosition().getX(), yDiff + pixel.getPosition().getY());
      pixel.setPosition(newPosition);
      m_pixels.at(i) = pixel;
   }
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveUp()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() - 1));
      m_pixels.at(i) = pixel;
   }
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveDown()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() + 1));
      m_pixels.at(i) = pixel;
   }
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveLeft()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() - 1, pixel.getPosition().getY()));
      m_pixels.at(i) = pixel;
   }
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveRight()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() + 1, pixel.getPosition().getY()));
      m_pixels.at(i) = pixel;
   }
   setMinMaxMid();
};

// public -----------------------------------------------------------------------------
int SpriteModel::Compare(SpriteModel sprite) const
{
   if (sprite.getSpriteSize() == m_spriteSize && sprite.getMaxPosition() == m_maxPosition)
   {
      for (int i = 0; i < m_spriteSize; i++)
      {
         if (sprite.getPixels().at(i) != m_pixels.at(i))
         {
            return -1;
         }
      }
      return 0;
   }
   return -1;
};
