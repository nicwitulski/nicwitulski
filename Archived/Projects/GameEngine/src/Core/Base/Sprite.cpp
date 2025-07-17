#include "../../../include/Sprite.h"

Sprite::Sprite() { m_pixels = std::vector<Pixel>(); };

Sprite::Sprite(std::vector<Pixel> pixels) { m_pixels = pixels; };

void Sprite::addPixel(Pixel pixel) { m_pixels.emplace_back(pixel); };

std::vector<Pixel> Sprite::getPixels() { return m_pixels; }

void Sprite::displace(int dx, int dy) {
  for (Pixel &pixel : m_pixels) {
    pixel.displace(dx, dy);
  }
}