#ifndef POSITION_H
#define POSITION_H

class Position {
private:
  int m_x;
  int m_y;

public:
  Position();
  Position(int x, int y);
  Position operator+(Position &other) {
    return Position(m_x + other.getX(), m_y + other.getY());
  }
  Position operator-(Position &other) {
    return Position(m_x + other.getX(), m_y - other.getY());
  };
  bool operator==(Position &other) {
    return (m_x == other.getX() && m_y == other.getY());
  };
  bool operator>(Position &other) {
    return (m_y > other.getY() || (m_y == other.getY() && m_x > other.getX()));
  };
  bool operator<(Position &other) {
    return (m_y < other.getY() || (m_y == other.getY() && m_x < other.getX()));
  }

  int getX();
  int getY();
  void setX(int x);
  void setY(int y);
  void setPosition(int x, int y);
};

#endif