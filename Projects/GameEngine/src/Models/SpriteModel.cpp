#include "SpriteModel.h"

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel()
{
   std::vector<PixelModel> pixelVector;
   PixelModel              pixel;
   pixelVector.push_back(pixel);
   m_pixels          = pixelVector;
   m_spriteSize      = 1;
   m_minimumPosition = m_pixels.at(0).getPosition();
   m_maxPosition     = m_pixels.at(0).getPosition();
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel(std::vector<PixelModel> pixels)
{
   m_pixels          = pixels;
   m_spriteSize      = m_pixels.size();
   m_maxPosition     = m_pixels.at(0).getPosition();
   m_minimumPosition = m_pixels.at(0).getPosition();
   setMinimumPosition();
   setMaxPosition();
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
SpriteModel::SpriteModel(std::vector<PixelModel> pixels, PositionModel maxPosition)
{
   m_pixels      = pixels;
   m_spriteSize  = m_pixels.size();
   m_maxPosition = maxPosition;
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

// public -----------------------------------------------------------------------------
PositionModel SpriteModel::getMinimumPosition()
{
   return m_minimumPosition;
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
   PositionModel errorPosition(0, 0);
   PixelModel    errorPixel(errorPosition, '~');
   return errorPixel;
}

// public -----------------------------------------------------------------------------
std::string SpriteModel::getString()
{
   std::string result = "";
   for (int y = m_minimumPosition.getY(); y <= m_maxPosition.getY(); y++)
   {
      for (int x = m_minimumPosition.getX(); x <= m_maxPosition.getX(); x++)
      {
         PositionModel position(x, y);
         PixelModel    pixel = getPixelAtPosition(position);
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
void SpriteModel::setMinimumPosition(PositionModel candidate)
{
   if (candidate.getX() < m_minimumPosition.getX())
   {
      m_minimumPosition.setLocation(candidate.getX(), m_minimumPosition.getY());
   }
   if (candidate.getY() < m_minimumPosition.getY())
   {
      m_minimumPosition.setLocation(m_minimumPosition.getX(), candidate.getX());
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
void SpriteModel::setMinimumPosition()
{
   for (int i = 1; i < m_spriteSize; i++)
   {
      PositionModel candidate = m_pixels.at(i).getPosition();

      if (candidate.getX() < m_minimumPosition.getX())
      {
         m_minimumPosition.setLocation(candidate.getX(), m_minimumPosition.getY());
      }
      if (candidate.getY() < m_minimumPosition.getY())
      {
         m_minimumPosition.setLocation(m_minimumPosition.getX(), candidate.getX());
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
void SpriteModel::resetSprite()
{
   std::vector<PixelModel> pixelVector;
   PixelModel              pixel;
   pixelVector.push_back(pixel);
   m_pixels      = pixelVector;
   m_spriteSize  = 1;
   m_maxPosition = m_pixels.at(0).getPosition();
   setMiddlePixel();
};

// public -----------------------------------------------------------------------------
void SpriteModel::setCharacterAtPosition(PositionModel position, char character)
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
   for (int i = 0; i < m_spriteSize; i++)
   {
      if (pixel.getPosition() == m_pixels.at(i).getPosition())
      {
         return;
      }
   }
   m_pixels.push_back(pixel);
   m_spriteSize++;
   setMaxPosition(pixel.getPosition());
}

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
      setMinimumPosition(pixel.getPosition());
      setMaxPosition(pixel.getPosition());
      setMiddlePixel();
   }
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveUp()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() + 1));
      m_pixels.at(i) = pixel;
      setMinimumPosition(pixel.getPosition());
      setMaxPosition(pixel.getPosition());
      setMiddlePixel();
   }
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveDown()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX(), pixel.getPosition().getY() - 1));
      m_pixels.at(i) = pixel;
      setMinimumPosition(pixel.getPosition());
      setMaxPosition(pixel.getPosition());
      setMiddlePixel();
   }
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveLeft()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() - 1, pixel.getPosition().getY()));
      m_pixels.at(i) = pixel;
      setMinimumPosition(pixel.getPosition());
      setMaxPosition(pixel.getPosition());
      setMiddlePixel();
   }
};

// public -----------------------------------------------------------------------------
void SpriteModel::moveRight()
{
   for (int i = 0; i < m_spriteSize; i++)
   {
      PixelModel pixel = m_pixels.at(i);
      pixel.setPosition(PositionModel(pixel.getPosition().getX() + 1, pixel.getPosition().getY()));
      m_pixels.at(i) = pixel;
      setMinimumPosition(pixel.getPosition());
      setMaxPosition(pixel.getPosition());
      setMiddlePixel();
   }
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
}
