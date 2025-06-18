#include "../../../include/Pixel.h"

Pixel::Pixel() {
  m_position = Position();
  m_character = ' ';
}

Pixel::Pixel(Position position, char character) {
  m_position = position;
  m_character = character;
};

void Pixel::setCharacter(char character) { m_character = character; };

void Pixel::setPosition(Position position) { m_position = position; };

Position Pixel::getPosition() { return m_position; }

char Pixel::getCharacter() { return m_character; };

void Pixel::displace(int dx, int dy) {
  int newX = m_position.getX() + dx;
  int newY = m_position.getY() + dy;
  m_position = Position(newX, newY);
}
