#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <stdbool.h>

#define MAX_LEVEL_WIDTH 20
#define MAX_LEVEL_HEIGHT 20

typedef struct {
  char data[MAX_LEVEL_HEIGHT][MAX_LEVEL_WIDTH];
  int width;
  int height;
  int playerX;
  int playerY;
} Level;

void Level_set(Level *_level);
void Level_drawMap();
void Level_drawPlayer(int x, int y);
void Level_render();
bool Level_isSolid(int x, int y);

#endif