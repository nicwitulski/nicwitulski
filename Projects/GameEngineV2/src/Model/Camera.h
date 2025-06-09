#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>

class Camera {
private:
  uint8_t m_viewPortMaxX;
  uint8_t m_viewPortMaxY;

public:
  Camera();
  Camera(uint8_t viewPortMaxX, uint8_t viewPortMaxY);
};

#endif