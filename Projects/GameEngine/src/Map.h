#ifndef MAP_H
#define MAP_H

#include "Entity.h"
#include "Printable.h"
#include "Solid.h"
#include <vector>

class Map : private Printable
{
private:
   std::vector<Solid>  allSolids;
   std::vector<Entity> allEntities;
};

#endif
