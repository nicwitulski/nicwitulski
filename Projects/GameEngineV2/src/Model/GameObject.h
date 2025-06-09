#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdint>

class GameObject {
protected:
  bool m_visable;
  uint8_t m_layer;

public:
  GameObject();
  GameObject(bool visable, uint8_t layer);
  bool isVisable();
  uint8_t getLayer();
  void setVisability(bool viable);
  void setLayer(uint8_t layer);
};

#endif