#ifndef SPRITE_H
#define SPRITE_H

#include "Pixel.h"
#include "ncurses.h"
#include <cstdint>
#include <vector>

class Sprite {
private:
  std::vector<Pixel> m_pixels;

public:
  Sprite();
  Sprite(std::vector<Pixel> pixels);
  void addPixel(Pixel pixel);
  void displace(int16_t dx, int16_t dy);
  void printToCurse();
  void displaceAndPrint(int16_t dx, int16_t dy);
  void eraseFromCurse();
  std::vector<Pixel> getPixels();
};

#endif
