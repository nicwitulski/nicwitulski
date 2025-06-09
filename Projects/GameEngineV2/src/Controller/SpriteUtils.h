#ifndef SPRITEUTILS_H
#define SPRITEUTILS_H

#include "../Model/Animation.h"
#include "../Model/Frame.h"
#include "../Model/Sprite.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

Sprite getSpriteFromTextFile(std::string fileLocation);
Frame getFrameFromTextFile(std::string fileLocation);
Animation loadAnimation(std::string entityName, std::string animationName,
                        bool repeats);

#endif