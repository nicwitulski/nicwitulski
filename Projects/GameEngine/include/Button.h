#ifndef BUTTON_H
#define BUTTON_H

#include "UIElement.h"
#include <functional>

class Button : public UIElement {
private:
  std::function<void()> m_function;

public:
  Button();
  Button(std::vector<Animation> animations, bool visable, int layer,
         bool movableByCamera, std::function<void()> function);
  void setFunction(std::function<void()> func);
  void executeFunction();
  bool mouseInBounds(int x, int y);
};

#endif