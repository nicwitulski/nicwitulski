#include "SpriteModel.h"

std::vector<PixelModel> m_pixels;
int                     m_spriteSize;
PositionModel           m_maxPosition;
PixelModel              m_middlePixel;

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel()
{
   std::vector<PixelModel> pixelVector;
   m_pixels      = pixelVector.push_back(PixelModel());
   m_spriteSize  = 1;
   m_maxPosition = m_pixels.at(0).getPosition();
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel(std::vector<PixelModel> pixels)
{
   m_pixels      = pixels;
   m_spriteSize  = m_pixels.size();
   m_maxPosition = m_pixels.at(0).getPosition();
   setMaxPosition();
   setMiddlePixel();
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

PixelModel SpriteModel::getMiddlePixel()
{
   return m_middlePixel;
}

// private ----------------------------------------------------------------------------
int SpriteModel::getPixelIndexAtPosition(PositionModel position)
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      if (pixel.getPosition() == position)
      {
         return i;
      }
   }
   return -1;
};

// public -----------------------------------------------------------------------------
PixelModel SpriteModel::getPixelAtPosition(PositionModel position)
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      if (pixel.getPosition() == position)
      {
         return pixel;
      }
   }
   return PixelModel(PositionModel(), NULL);
}

// private ----------------------------------------------------------------------------
void SpriteModel::setMaxPosition(PositionModel candidate)
{
   if (candidate.getX() > m_maxPosition.getX())
   {
      m_maxPosition.setLocation(candidate.getX(), m_maxPosition.getY());
   }
   if (candidate.getY() > m_maxPosition.getY())
   {
      m_maxPosition.setLocation(m_maxPosition.getX(), candidate.getX());
   }
};

// private ----------------------------------------------------------------------------
void SpriteModel::setMaxPosition()
{
   for (int i = 1; i < m_spriteSize; i++)
   {
      PositionModel candidate = m_pixels.at(i).getPosition();

      if (candidate.getX() > m_maxPosition.getX())
      {
         m_maxPosition.setLocation(candidate.getX(), m_maxPosition.getY());
      }
      if (candidate.getY() > m_maxPosition.getY())
      {
         m_maxPosition.setLocation(m_maxPosition.getX(), candidate.getX());
      }
   }
};

// private ----------------------------------------------------------------------------
void SpriteModel::setMiddlePixel()
{
   PositionModel middlePosition = PositionModel(m_maxPosition.getX() / 2, m_maxPosition.getY() / 2);
   PixelModel    middlePixel    = getPixelAtPosition(middlePosition);
   m_middlePixel                = PixelModel(middlePosition, middlePixel.getCharacter());
}

// public -----------------------------------------------------------------------------
void SpriteModel::editSprite(std::vector<PixelModel> pixels, bool overwrite)
{
   int previousSize = m_spriteSize;
   for (int i = 0; i < previousSize; i++)
   {
      bool       samePosition = false;
      int        samePositionIndex;
      PixelModel newPixel = pixels.at(i);
      for (int j = 0; j < pixels.size(); j++)
      {
         PixelModel oldPixel = m_pixels.at(j);
         if (newPixel.getPosition() == oldPixel.getPosition())
         {
            samePositionIndex = j;
            samePosition      = true;
            break;
         }
      }
      if (samePosition)
      {
         if (overwrite)
         {
            m_pixels.at(samePositionIndex) = newPixel;
         }
      }
      else
      {
         addPixel(newPixel);
      }
   }
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
void SpriteModel::resetSprite()
{
   std::vector<PixelModel> pixelVector;
   m_pixels      = pixelVector.push_back(PixelModel());
   m_spriteSize  = 1;
   m_maxPosition = m_pixels.at(0).getPosition();
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
void SpriteModel::setPixelAtPosition(PositionModel position, char character)
{
   int pixelIndex = getPixelIndexAtPosition(position);
   if (pixelIndex == -1)
   {
      return;
   }
   m_pixels.at(pixelIndex).setCharacter(character);
};

// public -----------------------------------------------------------------------------
void SpriteModel::addPixel(PixelModel pixel)
{
   m_pixels.push_back(pixel);
   m_spriteSize++;
   setMaxPosition(pixel.getPosition());
}

// public -----------------------------------------------------------------------------
void SpriteModel::moveUp()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() + 1));
   }
   m_middlePixel = m_middlePixel.setPosition(
         PositionModel(m_middlePixel.getPosition().getX(), m_middlePixel.getPosition().getY() + 1));
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveDown()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() - 1));
   }
   m_middlePixel = m_middlePixel.setPosition(
         PositionModel(m_middlePixel.getPosition().getX(), m_middlePixel.getPosition().getY() - 1));
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveLeft()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() - 1, pixel.getPosition().getY()));
   }
   m_middlePixel = m_middlePixel.setPosition(
         PositionModel(m_middlePixel.getPosition().getX() - 1, m_middlePixel.getPosition().getY()));
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveRight()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() + 1, pixel.getPosition().getY()));
   }
   m_middlePixel = m_middlePixel.setPosition(
         PositionModel(m_middlePixel.getPosition().getX() + 1, m_middlePixel.getPosition().getY()));
};
