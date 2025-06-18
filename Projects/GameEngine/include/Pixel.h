#ifndef PIXEL_H
#define PIXEL_H

#include "Position.h"

class Pixel {
private:
  Position m_position;
  char m_character;

public:
  Pixel();
  Pixel(Position position, char character);
  void setPosition(Position position);
  Position getPosition();
  void setCharacter(char character);
  char getCharacter();
  void displace(int dx, int dy);
};

#endif
