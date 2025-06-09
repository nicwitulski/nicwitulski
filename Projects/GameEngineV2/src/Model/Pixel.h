#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>

class Pixel {
private:
  int16_t m_x;
  int16_t m_y;
  char m_character;

public:
  Pixel();
  Pixel(int16_t x, int16_t y, char character);
  void setX(int16_t x);
  void setY(int16_t y);
  void setPosition(int16_t x, int16_t y);
  void setCharacter(char character);
  int16_t getX();
  int16_t getY();
  char getCharacter();
};

#endif
