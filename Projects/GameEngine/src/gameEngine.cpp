#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "ncurses.h"
#include "Models/MapModel.h"
#include "Models/PlayerModel.h"
#include "Models/TileModel.h"

void openCurseWindow(MapModel mainMap, PlayerModel player)
{
   initscr();
   raw();
   noecho();
   keypad(stdscr, TRUE);
   timeout(250);

   char input;
   while (input != '`')
   {
      std::string contentString = mainMap.PrintableModel::getContentString();
      mvprintw(0, 0, "%s", contentString.c_str());
      input = getch();
      if (input != ERR)
      {
         player.setUserInput(input);
      }
      refresh();
   }
   endwin();
}

int main()
{
   int         length = 80;
   int         height = 24;
   MapModel    mainMap(length, height, "Main Map");
   PlayerModel player(PositionModel(length / 2 - 1, height / 2 - 1));

   mainMap.addEntity(player);

   openCurseWindow(mainMap, player);

   return 0;
}
