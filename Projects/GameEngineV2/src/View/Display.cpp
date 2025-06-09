#include "Display.h"
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

void refreshAllEntities(std::vector<Entity *> refreshedEntities,
                        float deltaTime) {
  std::sort(refreshedEntities.begin(), refreshedEntities.end(),
            [](Entity *a, Entity *b) { return a->getLayer() < b->getLayer(); });

  for (auto &entity : refreshedEntities) {
    entity->refresh(deltaTime);
  }
}