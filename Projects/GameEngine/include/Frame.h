#ifndef FRAME_H
#define FRAME_H

#include "Sprite.h"

class Frame {
private:
  Sprite m_sprite;
  int m_duration; // 60 fps default, duration = 60, frame lasts for one sec

public:
  Frame();
  Frame(Sprite sprite, int duration);
  int getDuration();
  Sprite &getSprite();
  void setSprite(Sprite sprite);
  void displace(int dx, int dy);
};

#endif