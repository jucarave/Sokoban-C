#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "level.h"

static char screen[MAX_LEVEL_HEIGHT][MAX_LEVEL_WIDTH];
static Level level;

void Level_set(Level *_level) {
  level = *_level;
}

bool Level_isSolid(int x, int y) {
  char tile = level.data[y][x];

  return tile == '#';
}

Box *Level_getBoxAt(int x, int y) {
  for (int i=0;i<level.boxesCount;i++) {
    Box *box = &level.boxes[i];

    if (box->x == x && box->y == y) {
      return box;
    }
  }

  return NULL;
}

void Level_drawMap() {
  for (int y=0;y<level.width;y++) {
    for (int x=0;x<level.height;x++) {
      screen[y][x] = level.data[y][x];
    }
  }
}

void Level_drawPlayer(int x, int y) {
  screen[y][x] = '@';
}

void Level_drawBoxes() {
  for (int i=0;i<level.boxesCount;i++) {
    Box *box = &level.boxes[i];

    screen[box->y][box->x] = 'B';
  }
}

void Level_render() {
  printf("\n");
  for (int i=0;i<level.height;i++) {
    printf("    %.*s\n", level.width, screen[i]);
  }
  printf("\n");
}