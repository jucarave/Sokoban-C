#include <stdio.h>
#include "level.h"

static Level level_1 = {
  .data = {
    "#######",
    "#..._.#",
    "##....#",
    "#.....#",
    "#.#.#.#",
    "#...#.#",
    "#######"
  },
  .width = 7,
  .height = 7,

  .playerX = 3,
  .playerY = 1,

  .boxesCount = 1,
  .boxes = {
    { .x = 3, .y = 4 }
  },

  .targets = {
    { .x = 4, .y = 1 }
  }
};

static Level level_2 = {
  .data = {
    "  #####   ",
    "###...####",
    "#........#",
    "#..#..#..#",
    "#.._._#..#",
    "##########"
  },
  .width = 10,
  .height = 6,

  .playerX = 7,
  .playerY = 4,

  .boxesCount = 2,
  .boxes = {
    { .x = 7, .y = 2 },
    { .x = 7, .y = 3 }
  },

  .targets = {
    { .x = 3, .y = 4 },
    { .x = 5, .y = 4 }
  }
};

Level* Data_getLevel(int index) {
  if (index == 1) {
    return &level_1;
  } else if (index == 2) {
    return &level_2;
  }

  return NULL;
}