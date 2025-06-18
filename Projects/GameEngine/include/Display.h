#ifndef DISPLAY_H
#define DISPLAY_H

#include "Animation.h"
#include "Parameters.h"
#include "ncurses.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>

class Display {
public:
  static void initCurse();
  static char getUserInput();
  static void closeCurseWindow();
  static void refreshDisplay(float deltaTime);
  static void printPixel(Pixel pixel, bool isMoveableByCamera);
  static void printSprite(Sprite sprite, bool isMoveableByCamera);
  static void eraseSprite(Sprite sprite, bool isMoveableByCamera);
  static void updateAnimation(float deltaTime, Animation &animation,
                              bool isMoveableByCamera);
  static void refreshEntities(float deltaTime);
};

#endif