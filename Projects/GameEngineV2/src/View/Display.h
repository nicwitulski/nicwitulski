#include "../Model/Entity.h"
#include "ncurses.h"
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>

void initCurse();

char getUserInput();

void closeCurseWindow();

void refreshCurse();

void refreshAllEntities(float deltaTime);