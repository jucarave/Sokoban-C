#include "level.h"

static Level level_1 = {
 .data = {
  "#######",
  "#.....#",
  "##....#",
  "#.....#",
  "#.#.#.#",
  "#...#.#",
  "#######"
 },
 .width = 7,
 .height = 7,
 .playerX = 3,
 .playerY = 1
};

Level* Data_getLevel(int index) {
  if (index == 1) {
    return &level_1;
  }
}