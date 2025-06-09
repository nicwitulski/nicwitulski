#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>

class Camera {
private:
  int16_t m_xOffset;
  int16_t m_yOffset;
  int16_t m_viewPortMaxX;
  int16_t m_viewPortMaxY;

public:
  Camera();
  Camera(int16_t xOffset, int16_t yOffset, int16_t viewPortMaxX,
         int16_t viewPortMaxY);
  void displaceViewPort(int16_t dx, int16_t dy);
};

#endif