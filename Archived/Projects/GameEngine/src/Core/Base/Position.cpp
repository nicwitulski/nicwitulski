#include "../../../include/Position.h"

Position::Position() {
  m_x = 0;
  m_y = 0;
}

Position::Position(int x, int y) {
  m_x = x;
  m_y = y;
};

int Position::getX() { return m_x; };

int Position::getY() { return m_y; };

void Position::setX(int x) { m_x = x; };

void Position::setY(int y) { m_y = y; };

void Position::setPosition(int x, int y) {
  setX(x);
  setY(y);
};