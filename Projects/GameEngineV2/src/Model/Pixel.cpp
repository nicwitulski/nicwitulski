#include "Pixel.h"
#include <cstdint>

Pixel::Pixel() {
  m_x = 0;
  m_y = 0;
  m_character = ' ';
};

Pixel::Pixel(int16_t x, int16_t y, char character) {
  m_x = x;
  m_y = y;
  m_character = character;
};

void Pixel::setX(int16_t x) { m_x = x; };

void Pixel::setY(int16_t y) { m_y = y; };

void Pixel::setCharacter(char character) { m_character = character; };

void Pixel::setPosition(int16_t x, int16_t y) {
  setX(x);
  setY(y);
};

int16_t Pixel::getX() { return m_x; };

int16_t Pixel::getY() { return m_y; };

char Pixel::getCharacter() { return m_character; };
