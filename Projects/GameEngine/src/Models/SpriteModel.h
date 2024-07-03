#ifndef SPRITE_H
#define SPRITE_H

#include "PixelModel.h"
#include "PositionModel.h"
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////
/// @class Position
///
/// Define's a sprite as a collection of pixels
///////////////////////////////////////////////////////////////////
class SpriteModel
{
private:
   std::vector<PixelModel> m_pixels;
   int                     m_spriteSize;
   PositionModel           m_maxPosition;
   PixelModel              m_middlePixel;
   PositionModel           m_minimumPosition;

   ///////////////////////////////////////////////////////////////////
   /// @fn setMaxPosition
   ///////////////////////////////////////////////////////////////////
   void setMaxPosition();

   ///////////////////////////////////////////////////////////////////
   /// @fn setMinimumPosition
   ///////////////////////////////////////////////////////////////////
   void setMinimumPosition();

   ///////////////////////////////////////////////////////////////////
   /// @fn setMaxPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   void setMaxPosition(PositionModel candidate);

   ///////////////////////////////////////////////////////////////////
   /// @fn setMinimumPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   void setMinimumPosition(PositionModel candidate);

   ///////////////////////////////////////////////////////////////////
   /// @fn setMaxPosition
   ///////////////////////////////////////////////////////////////////
   void setMiddlePixel();

   ///////////////////////////////////////////////////////////////////
   /// @fn getPixelIndexAtPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   int getPixelIndexAtPosition(PositionModel position);

public:
   ///////////////////////////////////////////////////////////////////
   /// @fn SpriteModel
   ///////////////////////////////////////////////////////////////////
   SpriteModel();

   ///////////////////////////////////////////////////////////////////
   /// @fn SpriteModel
   ///
   /// @param pixels
   ///////////////////////////////////////////////////////////////////
   SpriteModel(std::vector<PixelModel> pixels);

   ///////////////////////////////////////////////////////////////////
   /// @fn SpriteModel
   ///
   /// @param pixels
   /// @param maxPosition
   ///////////////////////////////////////////////////////////////////
   SpriteModel(std::vector<PixelModel> pixels, PositionModel maxPosition);

   ///////////////////////////////////////////////////////////////////
   /// @fn getPixels
   ///////////////////////////////////////////////////////////////////
   std::vector<PixelModel> getPixels();

   ///////////////////////////////////////////////////////////////////
   /// @fn getPixelAtPosition
   ///////////////////////////////////////////////////////////////////
   PixelModel getPixelAtPosition(PositionModel position);

   ///////////////////////////////////////////////////////////////////
   /// @fn getSpriteSize
   ///////////////////////////////////////////////////////////////////
   int getSpriteSize();

   ///////////////////////////////////////////////////////////////////
   /// @fn getMaxPosition
   ///////////////////////////////////////////////////////////////////
   PositionModel getMaxPosition();

   ///////////////////////////////////////////////////////////////////
   /// @fn getMinimumPosition
   ///////////////////////////////////////////////////////////////////
   PositionModel getMinimumPosition();

   ///////////////////////////////////////////////////////////////////
   /// @fn getMiddlePixel
   ///////////////////////////////////////////////////////////////////
   PixelModel getMiddlePixel();

   ///////////////////////////////////////////////////////////////////
   /// @fn getString
   ///////////////////////////////////////////////////////////////////
   std::string getString();

   ///////////////////////////////////////////////////////////////////
   /// @fn resetSprite
   ///////////////////////////////////////////////////////////////////
   void resetSprite();

   ///////////////////////////////////////////////////////////////////
   /// @fn setPixelAtPosition
   ///
   /// @param position
   /// @param character
   ///////////////////////////////////////////////////////////////////
   void setCharacterAtPosition(PositionModel position, char character);

   ///////////////////////////////////////////////////////////////////
   /// @fn moveWholeSpriteToMiddlePosition
   ///
   /// @param middle
   ///////////////////////////////////////////////////////////////////
   void moveWholeSpriteToMiddlePosition(PositionModel middle);

   ///////////////////////////////////////////////////////////////////
   /// @fn addPixel
   ///
   /// @param pixel
   ///////////////////////////////////////////////////////////////////
   void addPixel(PixelModel pixel);

   ///////////////////////////////////////////////////////////////////
   /// @fn moveUp
   ///////////////////////////////////////////////////////////////////
   void moveUp();

   ///////////////////////////////////////////////////////////////////
   /// @fn moveDown
   ///////////////////////////////////////////////////////////////////
   void moveDown();

   ///////////////////////////////////////////////////////////////////
   /// @fn moveLeft
   ///////////////////////////////////////////////////////////////////
   void moveLeft();

   ///////////////////////////////////////////////////////////////////
   /// @fn moveRight
   ///////////////////////////////////////////////////////////////////
   void moveRight();

   ///////////////////////////////////////////////////////////////////
   /// @fn Compare Functions
   ///////////////////////////////////////////////////////////////////
   int Compare(SpriteModel sprite) const;

   bool operator==(SpriteModel sprite) const { return 0 == Compare(sprite); }
   bool operator!=(SpriteModel sprite) const { return 0 != Compare(sprite); }
};

#endif
