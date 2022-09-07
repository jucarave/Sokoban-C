#ifndef GAME_DATA_HEADER
#define GAME_DATA_HEADER

#include "level.h"

Level *Data_loadLevel(int index);
void Data_freeLevel(Level *level);

#endif