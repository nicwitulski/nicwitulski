#include "MapModel.h"

#define DEFAULT_LENGTH 80
#define DEFAULT_HEIGHT 24

std::vector<TileModel>   m_allTiles;
std::vector<EntityModel> m_allEntities;

// public -----------------------------------------------------------------------------
MapModel::MapModel()
{
   this->setAlias("map");
   SpriteModel sprite = SpriteModel();
   for (int i = 0; i < DEFAULT_HEIGHT; i++)
   {
      for (int j = 0; j < DEFAULT_LENGTH; j++)
      {
         PixelModel pixel(PositionModel(i, j), '+');
         sprite.addPixel(pixel);
      }
   }
   this->setSprite(sprite);
};

// public -----------------------------------------------------------------------------
MapModel::MapModel(SpriteModel sprite, std::string alias)
{
   this->setSprite(sprite);
   this->setAlias(alias);
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
EntityModel MapModel::getEntityAtPosition(PositionModel position)
{
   for (int i = 0; i < m_allEntities.size(); i++)
   {
      EntityModel entity = m_allEntities.at(i);
      for (int j = 0; j < entity.getSprite().getSpriteSize(); j++)
      {
         if (position == entity.getSprite().getPixels().at(j).getPosition())
         {
            return entity;
         }
      }
   }
   return EntityModel(SpriteModel(), "null", false);
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
EntityModel MapModel::getEntityWithAlias(std::string alias)
{
   for (int i = 0; i < m_allEntities.size(); i++)
   {
      EntityModel entity = m_allEntities.at(i);
      if (alias == entity.PrintableModel::getAlias())
      {
         return entity;
      }
   }
   return EntityModel(SpriteModel(), "null", false);
};

// public -----------------------------------------------------------------------------
void MapModel::addTile(TileModel tile)
{
   m_allTiles.push_back(tile);
};

// public -----------------------------------------------------------------------------
void MapModel::addEntity(EntityModel entity)
{
   m_allEntities.push_back(entity);
};
