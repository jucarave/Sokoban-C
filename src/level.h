#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <stdbool.h>
#include "box.h"

#define MAX_LEVEL_WIDTH 20
#define MAX_LEVEL_HEIGHT 20
#define MAX_BOXES 10

typedef struct {
  char data[MAX_LEVEL_HEIGHT][MAX_LEVEL_WIDTH];
  int width;
  int height;

  int playerX;
  int playerY;

  int boxesCount;
  Box boxes[MAX_BOXES];
} Level;

void Level_set(Level *_level);
void Level_drawMap();
void Level_drawPlayer(int x, int y);
void Level_render();
bool Level_isSolid(int x, int y);
Box *Level_getBoxAt(int x, int y);
void Level_drawBoxes();

#endif