#include "../../../include/Camera.h"

Camera::Camera() {
  m_length = 80;
  m_height = 24;
  m_lengthOffset = 0;
  m_heightOffset = 0;
};

Camera::Camera(int length, int height) {
  m_length = length;
  m_height = height;
  m_lengthOffset = 0;
  m_heightOffset = 0;
};

void Camera::displaceViewPort(int dx, int dy) {
  m_lengthOffset = m_lengthOffset + dx;
  m_heightOffset = m_heightOffset + dy;
};

int Camera::getLength() { return m_length; }

int Camera::getHeight() { return m_height; }

int Camera::getHeightOffset() { return m_heightOffset; }

int Camera::getLengthOffset() { return m_lengthOffset; }