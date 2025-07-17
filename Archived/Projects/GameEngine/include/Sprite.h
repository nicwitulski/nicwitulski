#ifndef SPRITE_H
#define SPRITE_H

#include "Pixel.h"
#include <vector>

class Sprite {
private:
  std::vector<Pixel> m_pixels;

public:
  Sprite();
  Sprite(std::vector<Pixel> pixels);
  void addPixel(Pixel pixel);
  std::vector<Pixel> getPixels();
  void displace(int dx, int dy);
};

#endif
