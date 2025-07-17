#include "../../../include/Animation.h"

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

std::vector<Frame> Animation::getFrames() { return m_frames; }

void Animation::update(float deltaTime) {
  if (m_frames.empty())
    return;

  frameTimer += deltaTime * 60.0f;

  previousFrameIndex = currentFrameIndex;

  while (frameTimer >= m_frames[currentFrameIndex].getDuration()) {
    frameTimer -= m_frames[currentFrameIndex].getDuration();
    currentFrameIndex = (currentFrameIndex + 1) % m_frames.size();
  }
};

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

void Animation::displace(int dx, int dy) {
  for (Frame &frame : m_frames) {
    frame.displace(dx, dy);
  }
}