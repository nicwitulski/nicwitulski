#ifndef CAMERA_H
#define CAMERA_H

#include "Position.h"
#include <cstdint>

class Camera {
private:
  int m_length;
  int m_height;
  int m_lengthOffset;
  int m_heightOffset;

public:
  Camera();
  Camera(int length, int height);
  void displaceViewPort(int dx, int dy);
  int getLength();
  int getHeight();
  int getLengthOffset();
  int getHeightOffset();
};

#endif