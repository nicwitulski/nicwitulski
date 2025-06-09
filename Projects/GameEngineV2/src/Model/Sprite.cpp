#include "Sprite.h"

Sprite::Sprite() { m_pixels = std::vector<Pixel>(); };

Sprite::Sprite(std::vector<Pixel> pixels) { m_pixels = pixels; };

void Sprite::addPixel(Pixel pixel) { m_pixels.emplace_back(pixel); };

void Sprite::displace(int16_t dx, int16_t dy) {
  for (auto &pixel : m_pixels) {
    int16_t newX = pixel.getX() + dx;
    int16_t newY = pixel.getY() + dy;
    pixel.setPosition(newX, newY);
  }
};

void Sprite::printToCurse() {
  for (uint8_t i = 0; i < m_pixels.size(); i++) {
    Pixel pixel = m_pixels.at(i);
    mvprintw(pixel.getY(), pixel.getX(), "%c", pixel.getCharacter());
  }
};

void Sprite::eraseFromCurse() {
  for (uint8_t i = 0; i < m_pixels.size(); i++) {
    Pixel pixel = m_pixels.at(i);
    mvprintw(pixel.getY(), pixel.getX(), "%c", ' ');
  }
};

void Sprite::displaceAndPrint(int16_t dx, int16_t dy) {
  for (uint8_t i = 0; i < m_pixels.size(); i++) {
    auto &pixel = m_pixels.at(i);
    mvprintw(pixel.getY(), pixel.getX(), "%c", ' ');
  }
  for (uint8_t i = 0; i < m_pixels.size(); i++) {
    auto &pixel = m_pixels.at(i);
    int16_t newX = pixel.getX() + dx;
    int16_t newY = pixel.getY() + dy;
    pixel.setPosition(newX, newY);
    mvprintw(newY, newX, "%c", pixel.getCharacter());
  }
}

std::vector<Pixel> Sprite::getPixels() { return m_pixels; }