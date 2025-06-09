#include "GameObject.h"
#include <cstdint>

GameObject::GameObject() {
  m_visable = false;
  m_layer = 0;
};

GameObject::GameObject(bool visable, uint8_t layer) {
  m_visable = visable;
  m_layer = layer;
};

bool GameObject::isVisable() { return m_visable; };

uint8_t GameObject::getLayer() { return m_layer; };

void GameObject::setVisability(bool visable) { m_visable = visable; };

void GameObject::setLayer(uint8_t layer) { m_layer = layer; }