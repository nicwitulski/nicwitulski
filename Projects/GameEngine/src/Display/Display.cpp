#include "../../include/Display.h"
#include <ncurses.h>

void Display::initCurse() {
  initscr();             // Start curses mode
  noecho();              // Don't echo keypresses
  cbreak();              // Disable line buffering
  keypad(stdscr, TRUE);  // Enable function keys and arrow keys
  nodelay(stdscr, TRUE); // Non-blocking getch
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION,
            NULL);  // Enable mouse events
  mouseinterval(0); // No delay for mouse clicks
  curs_set(0);

  printf("\033[?1003h\n"); // Enable mouse tracking in xterm
};

char Display::getUserInput() { return getch(); }

void Display::closeCurseWindow() {
  printf("\033[?1003l\n"); // Disable mouse tracking
  endwin();
};

void Display::refreshDisplay(float deltaTime) {
  clear();
  std::sort(
      allEntities.begin(), allEntities.end(),
      [](const std::shared_ptr<Entity> &a, const std::shared_ptr<Entity> &b) {
        return a->getLayer() < b->getLayer();
      });
  refreshEntities(deltaTime);
  refresh();
}

void Display::printPixel(Pixel pixel, bool isMoveableByCamera) {
  int printedX = 0;
  int printedY = 0;

  if (isMoveableByCamera) {
    printedX = pixel.getPosition().getX() + currentCamera->getLengthOffset();
    printedY = pixel.getPosition().getY() + currentCamera->getHeightOffset();
  } else {
    printedX = pixel.getPosition().getX();
    printedY = pixel.getPosition().getY();
  }

  if (printedX >= 0 && printedX <= currentCamera->getLength() &&
      printedY >= 0 && printedY <= currentCamera->getHeight()) {

    mvprintw(printedY, printedX, "%c", pixel.getCharacter());
  }
};

void Display::printSprite(Sprite sprite, bool isMoveableByCamera) {
  for (std::size_t i = 0; i < sprite.getPixels().size(); i++) {
    Pixel pixel = sprite.getPixels().at(i);
    printPixel(pixel, isMoveableByCamera);
  }
};

void Display::eraseSprite(Sprite sprite, bool isMoveableByCamera) {
  for (std::size_t i = 0; i < sprite.getPixels().size(); i++) {
    Pixel pixel = sprite.getPixels().at(i);
    printPixel(
        Pixel(Position(pixel.getPosition().getX(), pixel.getPosition().getY()),
              ' '),
        isMoveableByCamera);
  }
}

void Display::updateAnimation(float deltaTime, Animation &animation,
                              bool isMoveableByCamera) {
  animation.update(deltaTime);
  eraseSprite(animation.getPreviousFrameSprite(), isMoveableByCamera);
  printSprite(animation.getCurrentFrameSprite(), isMoveableByCamera);
}

void Display::refreshEntities(float deltaTime) {
  for (auto &entity : allEntities) {
    if (entity->didMove()) {
      eraseSprite(entity->getSpriteBeforeMove(), entity->isMoveableByCamera());
      entity->setMoved(false);
    }
    for (Animation &animation : entity->getAnimations()) {
      if (animation.getAnimationName() == entity->getCurrentAnimationName()) {
        updateAnimation(deltaTime, animation, entity->isMoveableByCamera());
      }
    }
  }
}