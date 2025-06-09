#include "Display.h"
#include "../Controller/Parameters.h"
#include <algorithm>
#include <ncurses.h>

void initCurse() {
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
}

char getUserInput() { return getch(); }

void closeCurseWindow() {
  printf("\033[?1003l\n"); // Disable mouse tracking
  endwin();
}

void refreshCurse() { refresh(); }

void refreshAllEntities(float deltaTime) {
  std::sort(
      allEntities.begin(), allEntities.end(),
      [](const std::shared_ptr<Entity> &a, const std::shared_ptr<Entity> &b) {
        return a->getLayer() < b->getLayer();
      });

  for (const auto &entity : allEntities) {
    entity->refresh(deltaTime);
  }
}