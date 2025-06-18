#ifndef FILELOADING_H
#define FILELOADING_H

#include "Entity.h"
#include "Parameters.h"
#include "Printable.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

Sprite getSpriteFromTextFile(std::string fileLocation);
Frame getFrameFromTextFile(std::string fileLocation);
Animation loadAnimation(std::string entityName, std::string animationName,
                        bool repeats);
std::shared_ptr<Entity> loadEntity(const std::string entityName, bool visable,
                                   int layer, bool moveableByCamera);
#endif