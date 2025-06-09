#include "Frame.h"

Frame::Frame() {
  m_sprite = Sprite();
  m_duration = 30;
};

Frame::Frame(Sprite sprite, uint8_t duration) {
  m_sprite = sprite;
  m_duration = duration;
};

uint8_t Frame::getDuration() { return m_duration; };

Sprite &Frame::getSprite() { return m_sprite; };

void Frame::setSprite(Sprite sprite) { m_sprite = sprite; };