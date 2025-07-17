#include "MapModel.h"

#define DEFAULT_LENGTH 80
#define DEFAULT_HEIGHT 24

// public -----------------------------------------------------------------------------
MapModel::MapModel()
{
   initialize();

   SpriteModel sprite = SpriteModel();
   for (int i = 0; i < DEFAULT_LENGTH; i++)
   {
      for (int j = 0; j < DEFAULT_HEIGHT; j++)
      {
         PixelModel pixel = PixelModel(PositionModel(i, j), '+');
         sprite.addPixel(pixel);
      }
   }
   setSprite(sprite);
};

// public -----------------------------------------------------------------------------
MapModel::MapModel(SpriteModel sprite, std::string alias)
{
   initialize();

   setSprite(sprite);
   setAlias(alias);
};

// private ----------------------------------------------------------------------------
void MapModel::initialize()
{
   m_allTiles = std::vector<TileModel>();
   setSprite(SpriteModel());
   setAlias("map");
};

// public -----------------------------------------------------------------------------
std::vector<TileModel> MapModel::getTiles()
{
   return m_allTiles;
};

// public -----------------------------------------------------------------------------
TileModel MapModel::getTileAtPosition(PositionModel position)
{
   for (int i = 0; i < m_allTiles.size(); i++)
   {
      TileModel tile = m_allTiles.at(i);
      for (int j = 0; j < tile.getSprite().getSpriteSize(); j++)
      {
         if (position == tile.getSprite().getPixels().at(j).getPosition())
         {
            return tile;
         }
      }
   }
   return TileModel(false, false, "null", SpriteModel());
};

// public -----------------------------------------------------------------------------
TileModel MapModel::getTileWithAlias(std::string alias)
{
   for (int i = 0; i < m_allTiles.size(); i++)
   {
      TileModel tile = m_allTiles.at(i);
      if (alias == tile.PrintableModel::getAlias())
      {
         return tile;
      }
   }
   return TileModel(false, false, "null", SpriteModel());
};

// public -----------------------------------------------------------------------------
void MapModel::addTile(TileModel tile)
{
   m_allTiles.push_back(tile);
};
