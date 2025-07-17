#include <fstream>
#include <iostream>
#include <string>

int main()
{
   std::ifstream inputFile("../src/Views/Sprites/player.txt");

   if (!inputFile.is_open())
   {
      std::cerr << "Error opening the file!" << std::endl;
   }

   std::string line;

   while (getline(inputFile, line))
   {
      std::cout << line << std::endl;
   }
   return 0;
}
