#ifndef READSPRITEFILE_H
#define READSPRITEFILE_H

#include "../Models/PrintableModel.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

SpriteModel getSpriteFromFile(std::string fileLocation);
std::string getStringFromPrintables(std::map<int, PrintableModel> layerPrintableMap);

#endif
