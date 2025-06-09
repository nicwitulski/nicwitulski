#ifndef BUTTON_H
#define BUTTON_H

#include "UIElement.h"
#include <functional>

class Button : public UIElement {
private:
  std::function<void()> m_function;

public:
  Button();
  Button(int8_t minX, int8_t minY, bool moveableByCamera, Entity entity,
         std::function<void()> function);
  void setFunction(std::function<void()> func);
  void executeFunction();
  bool mouseInBounds(int x, int y);
};

#endif