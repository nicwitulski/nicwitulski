#ifndef UIELEMENT_H
#define UIELEMENT_H

#include "Printable.h"

class UIElement : public Printable {
protected:
  Position m_maxPosition;
  Position m_minPosition;

  void setPositions();

public:
  UIElement();
  UIElement(std::vector<Animation> animations, bool visable, int layer,
            bool movableByCamera);
};

#endif