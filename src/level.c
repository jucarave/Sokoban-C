#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "level.h"
#include "target.h"
#include "box.h"

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
  for (int i = 0; i < level.boxesCount; i++) {
    Box *box = &level.boxes[i];

    if (box->x == x && box->y == y) {
      return box;
    }
  }

  return NULL;
}

void Level_drawMap() {
  for (int y = 0; y < level.height; y++) {
    for (int x = 0; x < level.width; x++) {
      screen[y][x] = level.data[y][x];
    }
  }
}

void Level_drawPlayer(int x, int y) {
  screen[y][x] = '@';
}

void Level_drawBoxes() {
  for (int i = 0; i < level.boxesCount; i++) {
    Box *box = &level.boxes[i];

    screen[box->y][box->x] = 'B';
  }
}

void Level_render() {
  printf("\n");
  for (int i = 0; i < level.height; i++) {
    printf("    %.*s\n", level.width, screen[i]);
  }
  printf("\n");
}

bool Level_isComplete() {
  for (int i = 0; i < level.boxesCount; i++) {
    Target *target = &level.targets[i];
    bool isBoxOnTarget = false;

    for (int b = 0; b < level.boxesCount; b++) {
      Box *box = &level.boxes[i];

      if (box->x == target->x && box->y == target->y) {
        b = level.boxesCount;
        isBoxOnTarget = true;
      }
    }

    if (!isBoxOnTarget) {
      return false;
    }
  }

  return true;
}