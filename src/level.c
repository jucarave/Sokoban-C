#include <stdio.h>
#include <string.h>

#define MAX_LEVEL_WIDTH 20
#define MAX_LEVEL_HEIGHT 20
#define LEVEL_WIDTH 7
#define LEVEL_HEIGHT 7

static char screen[MAX_LEVEL_HEIGHT][MAX_LEVEL_WIDTH];
static char level[LEVEL_HEIGHT][LEVEL_WIDTH] = {
  "#######",
  "#.....#",
  "##....#",
  "#.....#",
  "#.#.#.#",
  "#...#.#",
  "#######"
};

void Level_drawMap() {
  for (int y=0;y<LEVEL_HEIGHT;y++) {
    for (int x=0;x<LEVEL_WIDTH;x++) {
      screen[y][x] = level[y][x];
    }
  }
}

void Level_drawPlayer(int x, int y) {
  screen[y][x] = '@';
}

void Level_render() {
  printf("\n");
  for (int i=0;i<LEVEL_HEIGHT;i++) {
    printf("    %.*s\n", LEVEL_WIDTH, screen[i]);
  }
  printf("\n");
}