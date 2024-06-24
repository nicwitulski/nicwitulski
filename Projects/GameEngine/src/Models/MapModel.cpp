#include "MapModel.h"

std::vector<WallModel>   m_allWalls;
std::vector<EntityModel> m_allEntities;

// public -----------------------------------------------------------------------------
MapModel::MapModel()
{
   this->setAlias("map");
   this->setDimensions(80, 24, '\u25A6');

   std::vector<std::vector<char>> contents;
   for (int i = 0; i < 24; i++)
   {
      std::vector<char> tempVector;

      for (int j = 0; j < 80; j++)
      {
         tempVector.push_back('\u25A6');
      }
      contents.push_back(tempVector);
   }
   this->setContents(contents);
};

// public -----------------------------------------------------------------------------
MapModel::MapModel(int length, int height, std::string alias)
{
   this->setDimensions(length, height, '\u25A6');
   this->setAlias(alias);

   std::vector<std::vector<char>> contents;
   for (int i = 0; i < 24; i++)
   {
      std::vector<char> tempVector;

      for (int j = 0; j < 80; j++)
      {
         tempVector.push_back('\u25A6');
      }
      contents.push_back(tempVector);
   }
   this->setContents(contents);
};

// public -----------------------------------------------------------------------------
WallModel MapModel::getWallAtPosition(PositionModel position)
{
   for (int i = 0; i < m_allWalls.size(); i++)
   {
      WallModel wall = m_allWalls.at(i);
      if (wall.PrintableModel::getPosition() == position)
      {
         return wall;
      }
   }
   WallModel nullWall;
   nullWall.PrintableModel::setAlias("null");
   return nullWall;
};

// public -----------------------------------------------------------------------------
EntityModel MapModel::getEntityAtPosition(PositionModel position)
{
   for (int i = 0; i < m_allEntities.size(); i++)
   {
      EntityModel entity = m_allEntities.at(i);
      if (entity.PrintableModel::getPosition() == position)
      {
         return entity;
      }
   }
   EntityModel nullEntity;
   nullEntity.PrintableModel::setAlias("null");
   return nullEntity;
};

// public -----------------------------------------------------------------------------
WallModel MapModel::getWallWithAlias(std::string alias)
{
   for (int i = 0; i < m_allWalls.size(); i++)
   {
      WallModel wall = m_allWalls.at(i);
      if (wall.PrintableModel::getAlias() == alias)
      {
         return wall;
      }
   }
   WallModel nullWall;
   nullWall.PrintableModel::setAlias("null");
   return nullWall;
};

// public -----------------------------------------------------------------------------
EntityModel MapModel::getEntityWithAlias(std::string alias)
{
   for (int i = 0; i < m_allEntities.size(); i++)
   {
      EntityModel entity = m_allEntities.at(i);
      if (entity.PrintableModel::getAlias() == alias)
      {
         return entity;
      }
   }
   EntityModel nullEntity;
   nullEntity.PrintableModel::setAlias("null");
   return nullEntity;
};

// public -----------------------------------------------------------------------------
void MapModel::addWall(WallModel wall)
{
   m_allWalls.push_back(wall);
};

// public -----------------------------------------------------------------------------
void MapModel::addEntity(EntityModel entity)
{
   m_allEntities.push_back(entity);
};
