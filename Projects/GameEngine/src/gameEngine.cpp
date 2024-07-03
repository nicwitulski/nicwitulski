#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#include "ncurses.h"
#include "Controllers/ReadSpriteFile.h"
#include "Models/MapModel.h"
#include "Models/PlayerModel.h"
#include "Models/TileModel.h"

/*void openCurseWindow(MapModel mainMap, PlayerModel player)
{
   initscr();
   raw();
   noecho();
   keypad(stdscr, TRUE);
   timeout(250);

   char input;
   while (input != '`')
   {
      std::string mapString    = mainMap.getSpriteString();
      std::string playerString = player.getSpriteString();
      mvprintw(0, 0, "%s", mapString.c_str());

      PositionModel playerPosition = player.getSprite().getMinimumPosition();
      mvprintw(playerPosition.getX(), playerPosition.getY(), "%s", playerString.c_str());
      input = getch();
      if (input != ERR)
      {
         player.setUserInput(input);
         player.doMovement();
      }
      refresh();
   }
   endwin();
}*/

int main()
{
   /*   MapModel      mainMap;
   PositionModel cornerMapPosition = mainMap.PrintableModel::getSprite().getMaxPosition();

   SpriteModel playerSprite = getSpriteFromFile("Views/Sprites/player.txt");
   PlayerModel player = PlayerModel(PositionModel(cornerMapPosition.getX() / 2, cornerMapPosition.getY() / 2),
                                    playerSprite, "player");*/

   std::vector<PixelModel> pixels;
   pixels.push_back(PixelModel(PositionModel(0, 0), 'H'));
   pixels.push_back(PixelModel(PositionModel(1, 0), 'i'));

   SpriteModel sprite(pixels);

   std::cout << sprite.getString();

   //std::cout << sprite.getString();

   //mainMap.addEntity(player);

   //openCurseWindow(mainMap, player);

   return 0;
}
