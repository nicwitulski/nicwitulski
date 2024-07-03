#include "ReadSpriteFile.h"

SpriteModel getSpriteFromFile(std::string fileLocation)
{
   std::ifstream inputFile(fileLocation);

   if (!inputFile.is_open())
   {
      std::cerr << "Error opening the file!" << std::endl;
      std::vector<PixelModel> errorPixels;
      errorPixels.push_back(PixelModel(PositionModel(), '~'));
      return SpriteModel(errorPixels);
   }

   std::string             line;
   std::vector<PixelModel> pixels;

   int x    = 0;
   int maxX = 0;
   int y    = 0;
   while (getline(inputFile, line))
   {
      x = 0;
      while (x < line.size())
      {
         pixels.push_back(PixelModel(PositionModel(x, y), line.at(x)));
         x++;
      }

      if (x > maxX)
      {
         maxX = x;
      }
      y++;
   }
   inputFile.close();

   return SpriteModel(pixels, PositionModel(maxX, y));
}
