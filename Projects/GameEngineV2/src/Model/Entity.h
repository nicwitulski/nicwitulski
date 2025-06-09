#ifndef ENTITY_H
#define ENTITY_H

#include "Animation.h"
#include "GameObject.h"

class Entity : public GameObject {
private:
  std::string m_entityName;
  std::vector<Animation> m_animations;
  std::string m_currentAnimationName;

public:
  Entity();
  Entity(std::string entityName, std::vector<Animation> animations,
         bool visable, uint8_t layer);
  std::vector<Animation> &getAnimations();
  std::string getEntityName();
  void setEntityName(std::string entityName);
  std::string getCurrentAnimationName();
  bool setCurrentAnimation(
      std::string animationName); // int for codes. true = set animation, false
                                  // = no animation with name
  void setCurrentAnimation(Animation animation);
  void addAnimation(Animation animation);
  void displace(uint16_t dx, uint16_t dy);
  void refresh(float deltaTime);
};

#endif