#include "../Models/SpriteModel.h"
#include <fstream>
#include <iostream>
#include <string>

SpriteModel getSpriteFromFile(std::string fileLocation)
{
   std::ifstream inputFile(fileLocation);

   if (!inputFile.is_open())
   {
      std::cerr << "Error opening the file!" << std::endl;
      return 1;
   }

   std::string line;
}
