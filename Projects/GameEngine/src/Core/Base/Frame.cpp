#include "../../../include/Frame.h"

Frame::Frame() {
  m_sprite = Sprite();
  m_duration = 30;
};

Frame::Frame(Sprite sprite, int duration) {
  m_sprite = sprite;
  m_duration = duration;
};

int Frame::getDuration() { return m_duration; };

Sprite &Frame::getSprite() { return m_sprite; };

void Frame::setSprite(Sprite sprite) { m_sprite = sprite; };

void Frame::displace(int dx, int dy) { m_sprite.displace(dx, dy); }