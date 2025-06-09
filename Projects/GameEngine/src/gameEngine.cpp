#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unistd.h>

#include "Controllers/SpriteUtilsController.h"
#include "Models/MapModel.h"
#include "Models/PlayerModel.h"
#include "Models/TileModel.h"
#include "ncurses.h"

void openCurseWindow(std::map<int, PrintableModel> layerPrintableMap) {
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  timeout(250);

  char input;
  while (input != '`') {
    std::string printablesString = getStringFromPrintables(layerPrintableMap);

    mvprintw(0, 0, "%s", printablesString.c_str());

    input = getch();
    if (input != ERR) {
      layerPrintableMap.at(1).doMovement(input);
    }
    refresh();
  }
  endwin();
}

int main() {
  PlayerModel player;
  SpriteModel sprite = getSpriteFromFile("Views/Sprites/player.txt");
  MapModel mainMap;

  sprite.moveWholeSpriteToMiddlePosition(
      mainMap.getSprite().getMiddlePixel().getPosition());
  player.setSprite(sprite);

  std::map<int, PrintableModel> layerPrintableMap;
  layerPrintableMap[1] = player;
  layerPrintableMap[0] = mainMap;

  openCurseWindow(layerPrintableMap);

  return 0;
}
