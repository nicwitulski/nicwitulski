#include "Animation.h"

Animation::Animation() {
  m_animationName = "none";
  m_frames.push_back(Frame());
  m_repeats = true;
};

Animation::Animation(std::string animationName, std::vector<Frame> frames,
                     bool repeats) {
  m_animationName = animationName;
  m_frames = frames;
  m_repeats = repeats;
};

void Animation::update(float deltaTime) {
  if (m_frames.empty())
    return;

  frameTimer += deltaTime * 60.0f;

  int previousFrameIndex = currentFrameIndex;

  while (frameTimer >= m_frames[currentFrameIndex].getDuration()) {
    frameTimer -= m_frames[currentFrameIndex].getDuration();
    currentFrameIndex = (currentFrameIndex + 1) % m_frames.size();
  }

  // Only erase/draw if the frame changed
  // if (currentFrameIndex != previousFrameIndex) {
  m_frames[previousFrameIndex].getSprite().eraseFromCurse();
  m_frames[currentFrameIndex].getSprite().printToCurse();
  //}
};

void Animation::displace(uint16_t dx, uint16_t dy) {
  for (auto &frame : m_frames) {

    frame.getSprite().displace(dx, dy);
  }
}

void Animation::eraseCurrentFrame() {
  m_frames[currentFrameIndex].getSprite().eraseFromCurse();
}

void Animation::eraseDisplace(uint16_t dx, uint16_t dy) {
  eraseCurrentFrame();
  displace(dx, dy);
}

void Animation::eraseDisplaceUpdate(float deltaTime, uint16_t dx, uint16_t dy) {
  eraseCurrentFrame();
  displace(dx, dy);
  update(deltaTime);
}

Sprite Animation::getCurrentFrameSprite() {
  if (m_frames.empty())
    return Sprite();
  return m_frames[currentFrameIndex].getSprite();
};

Sprite Animation::getPreviousFrameSprite() {
  if (m_frames.empty())
    return Sprite();
  return m_frames[previousFrameIndex].getSprite();
};

std::string Animation::getAnimationName() { return m_animationName; };

void Animation::setAnimationName(std::string animationName) {
  m_animationName = animationName;
};