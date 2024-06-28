#include "PrintableModel.h"

std::string m_alias;
SpriteModel m_sprite;

// public -----------------------------------------------------------------------------
PrintableModel::PrintableModel(void)
{
   m_alias  = "null";
   m_sprite = SpriteModel();
};

// public -----------------------------------------------------------------------------
PrintableModel::PrintableModel(SpriteModel sprite, std::string alias)
{
   m_sprite = sprite;
   m_alias  = alias;
};

// public -----------------------------------------------------------------------------
std::string PrintableModel::getAlias()
{
   return m_alias;
};

// public -----------------------------------------------------------------------------
SpriteModel PrintableModel::getSprite()
{
   return m_sprite;
}

// public -----------------------------------------------------------------------------
std::string PrintableModel::getSpriteString()
{
   std::string result;

   for (int i = 0; i < m_sprite.getMaxPosition().getX(); i++)
   {
      for (int j = 0; j < m_sprite.getMaxPosition().getY(); j++)
      {
         PositionModel position(i, j);
         PixelModel    pixel = m_sprite.getPixelAtPosition(position);
         if (pixel.getCharacter() == NULL)
         {
            result.push_back(' ');
         }
         else
         {
            result.push_back(pixel.getCharacter());
         }
      }
      result.push_back('\n');
   }

   return result;
};
// public -----------------------------------------------------------------------------
void PrintableModel::setSprite(SpriteModel sprite)
{
   m_sprite = sprite;
}
