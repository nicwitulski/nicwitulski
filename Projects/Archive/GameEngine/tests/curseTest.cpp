//============================================================================
// Name        : personal.cpp
// Author      : Nicholas Witulski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <string>

#include "ncurses.h"

int main()
{
   //------------------------------------------------------------------------------
   //init screen and sets up screen
   initscr();
   //disables line buffering
   raw();
   //disables echo
   noecho();
   //enables keys like F1 and arrows
   keypad(stdscr, TRUE);
   //if user doesn't input something before timeout period, execute logic
   //halfdelay()
   //sets a timeout period to wait for functions like wgetch in milliseconds
   timeout(250);
   //------------------------------------------------------------------------------
   std::string result   = " ";
   int         input    = 0;
   char        ch_input = '\0';
   while ((result != "123"))
   {
      input    = getch();
      ch_input = char(input);

      if (input != ERR)
      {
         if (ch_input == '/')
         {
            if (!result.length() < 1)
            {
               result.replace(result.length() - 1, 1, " ");
               //result.erase(result.length() - 1);
            }
         }
         else if (ch_input != '\0')
         {
            result += std::string(1, ch_input);
         }
      }

      mvprintw(0, 0, "%s", result.c_str());

      refresh();
   }
   endwin(); /* End curses mode		  */

   return 0;
}
