#include "SpriteUtilsController.h"

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
};

std::string getStringFromPrintables(std::map<int, PrintableModel> layerPrintableMap)
{
   std::string   result;
   PositionModel maxPosition = PositionModel(0, 0);
   int           maxLayer    = 0;
   for (auto it : layerPrintableMap)
   {
      int            layer     = it.first;
      PrintableModel printable = it.second;

      if (printable.getSprite().getMaxPosition().getY() > maxPosition.getY() ||
          (printable.getSprite().getMaxPosition().getY() == maxPosition.getY() &&
           printable.getSprite().getMaxPosition().getX() > maxPosition.getX()))
      {
         maxPosition = printable.getSprite().getMaxPosition();
      }
      if (layer > maxLayer)
      {
         maxLayer = layer;
      }
   }

   for (int i = 0; i < maxPosition.getY(); i++)
   {
      for (int j = 0; j < maxPosition.getX(); j++)
      {
         char character;
         for (int k = maxLayer; k >= 0; k--)
         {
            character =
                  layerPrintableMap.at(k).getSprite().getPixelAtPosition(PositionModel(j, i)).getCharacter();
            if (character != '~')
            {
               break;
            }
         }
         if (character == '~')
         {
            result.push_back(' ');
         }
         else
         {
            result.push_back(character);
         }
      }
      result.push_back('\n');
   }
   return result;
};
