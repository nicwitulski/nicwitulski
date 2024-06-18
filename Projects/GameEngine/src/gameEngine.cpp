#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "Frame.h"
#include "ncurses.h"

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
   Frame frame;

   openCurseWindow(frame);

   return 0;
}
