#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"
#include <cstdint>
#include <string>

class Animation {
private:
  std::string m_animationName;
  std::vector<Frame> m_frames;
  bool m_repeats;

  size_t currentFrameIndex = 0;
  size_t previousFrameIndex = 0;
  float frameTimer = -1.0f;

public:
  Animation();
  Animation(std::string animationName, std::vector<Frame> frames, bool repeats);
  void update(float deltaTime);
  Sprite getCurrentFrameSprite();
  Sprite getPreviousFrameSprite();
  void displace(uint16_t dx, uint16_t dy);
  void eraseCurrentFrame();
  void eraseDisplace(uint16_t dx, uint16_t dy);
  void eraseDisplaceUpdate(float deltaTime, uint16_t dx, uint16_t dy);
  std::string getAnimationName();
  void setAnimationName(std::string animationName);
};

#endif