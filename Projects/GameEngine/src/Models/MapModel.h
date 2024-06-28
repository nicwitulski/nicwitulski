#ifndef MAP_H
#define MAP_H

#include "EntityModel.h"
#include "PrintableModel.h"
#include "TileModel.h"

///////////////////////////////////////////////////////////////////
/// @class MapModel
///
/// defines a map and the walls and entities within
///////////////////////////////////////////////////////////////////
class MapModel : private PrintableModel
{
private:
   ///////////////////////////////////////////////////////////////////
   /// @fn UpdateContents
   ///////////////////////////////////////////////////////////////////
   void UpdateContents();

public:
   ///////////////////////////////////////////////////////////////////
   /// @fn MapModel
   ///////////////////////////////////////////////////////////////////
   MapModel();

   ///////////////////////////////////////////////////////////////////
   /// @fn MapModel
   ///
   /// @param sprite
   /// @param alias
   ///////////////////////////////////////////////////////////////////
   MapModel(SpriteModel sprite, std::string alias);

   ///////////////////////////////////////////////////////////////////
   /// @fn getWallAtPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   TileModel getTileAtPosition(PositionModel position);

   ///////////////////////////////////////////////////////////////////
   /// @fn getEntityAtPosition
   ///
   /// @param position
   ///////////////////////////////////////////////////////////////////
   EntityModel getEntityAtPosition(PositionModel position);

   ///////////////////////////////////////////////////////////////////
   /// @fn getWallWithAlias
   ///
   /// @param alias
   ///////////////////////////////////////////////////////////////////
   TileModel getTileWithAlias(std::string alias);

   ///////////////////////////////////////////////////////////////////
   /// @fn getEntityWithAlias
   ///
   /// @param alias
   ///////////////////////////////////////////////////////////////////
   EntityModel getEntityWithAlias(std::string alias);

   ///////////////////////////////////////////////////////////////////
   /// @fn setWallAtPosition
   ///
   /// @param wall
   ///////////////////////////////////////////////////////////////////
   void addTile(TileModel tile);

   ///////////////////////////////////////////////////////////////////
   /// @fn setEntityAtPosition
   ///
   /// @param entity
   ///////////////////////////////////////////////////////////////////
   void addEntity(EntityModel entity);
};

#endif
