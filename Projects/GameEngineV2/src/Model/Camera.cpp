#include "Camera.h"

Camera::Camera() {
  m_viewPortMaxX = 80;
  m_viewPortMaxY = 24;
};

Camera::Camera(uint8_t viewPortMaxX, uint8_t viewPortMaxY) {
  m_viewPortMaxX = viewPortMaxX;
  m_viewPortMaxY = viewPortMaxY;
};