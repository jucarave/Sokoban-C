#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <stdbool.h>

void Level_drawMap();
void Level_drawPlayer(int x, int y);
void Level_render();
bool Level_isSolid(int x, int y);

#endif