#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"
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
  std::string getAnimationName();
  std::vector<Frame> getFrames();
  float getFrameTimer();
  void setFrameTimer();
  void setAnimationName(std::string animationName);
  void displace(int dx, int dy);
};

#endif