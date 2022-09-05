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

Level* Data_getLevel(int index) {
  if (index == 1) {
    return &level_1;
  }
}