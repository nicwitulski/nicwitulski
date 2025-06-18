#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"
#include <iostream>

class Entity : public GameObject {
private:
  std::string m_entityName;

public:
  Entity();
  Entity(std::string entityName, std::vector<Animation> animations,
         bool visable, int layer, bool moveableByCamera);
  Entity(std::string entityName, bool visable, int layer,
         bool moveableByCamera);
  std::string getEntityName();
  void setEntityName(std::string entityName);
};

#endif