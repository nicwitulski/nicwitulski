#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "ncurses.h"
#include "Models/MapModel.h"
#include "Models/PlayerModel.h"
#include "Models/WallModel.h"

void openCurseWindow(Frame frame)
{
   initscr();
   raw();
   noecho();
   keypad(stdscr, TRUE);
   timeout(250);

   char input;
   while (input != '`')
   {
      std::string contentString = frame.getContentString();
      mvprintw(0, 0, "%s", contentString.c_str());
      input = getch();
      if (input != ERR)
      {
         frame.setContentChar((frame.getMaxX() / 2) - 1, (frame.getMaxY() / 2) - 1, input);
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

   openCurseWindow(frame);

   return 0;
}
