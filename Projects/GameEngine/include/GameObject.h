#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Printable.h"

class GameObject : public Printable {
protected:
public:
  GameObject();
  GameObject(bool visable, int layer, bool moveableByCamera,
             std::vector<Animation> animations, std::string currentAnimation);
};

#endif