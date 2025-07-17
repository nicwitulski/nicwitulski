#ifndef PARAMETERS_H
#define PARAMETERS_H

#pragma once
#include "Camera.h"
#include "Entity.h"
#include <memory>
#include <vector>

extern std::vector<std::shared_ptr<Entity>> allEntities;
extern std::shared_ptr<Camera> currentCamera;
extern std::shared_ptr<Entity> playerEntity;

extern int SCREEN_LENGTH;
extern int SCREEN_HEIGHT;
extern int FRAME_RATE;

extern int userInput;

#endif
