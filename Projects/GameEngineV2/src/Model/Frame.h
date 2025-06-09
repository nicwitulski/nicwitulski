#ifndef FRAME_H
#define FRAME_H

#include "Sprite.h"

class Frame {
private:
  Sprite m_sprite;
  uint8_t m_duration; // 60 fps default, duration = 60, frame lasts for one sec

public:
  Frame();
  Frame(Sprite sprite, uint8_t duration);
  uint8_t getDuration();
  Sprite &getSprite();
  void setSprite(Sprite sprite);
};

#endif