#include "Camera.h"
#include "../Controller/Parameters.h"

Camera::Camera() {
  m_xOffset = 0;
  m_yOffset = 0;
  m_viewPortMaxX = 80;
  m_viewPortMaxY = 24;
};

Camera::Camera(int16_t topLeftX, int16_t topLeftY, int16_t viewPortMaxX,
               int16_t viewPortMaxY) {
  m_viewPortMaxX = viewPortMaxX;
  m_viewPortMaxY = viewPortMaxY;
  m_xOffset = topLeftX;
  m_yOffset = topLeftY;
};

void Camera::displaceViewPort(int16_t dx, int16_t dy) {
  int16_t oldX = m_xOffset;
  int16_t oldY = m_yOffset;

  m_xOffset += dx;
  m_yOffset += dy;

  int16_t deltaX = m_xOffset - oldX;
  int16_t deltaY = m_yOffset - oldY;

  for (auto &entity : allEntities) {
    entity->displace(deltaX, deltaY);
  }
};