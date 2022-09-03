#include <stdio.h>
#include <string.h>

#define LEVEL_WIDTH 5
#define LEVEL_HEIGHT 5

static char screen[LEVEL_HEIGHT][LEVEL_WIDTH];
static char level[LEVEL_HEIGHT][LEVEL_WIDTH] = {
  "#####",
  "#...#",
  "##..#",
  "#...#",
  "#####"
};

void Level_copyMap() {
  for (int y=0;y<LEVEL_HEIGHT;y++) {
    for (int x=0;x<LEVEL_WIDTH;x++) {
      screen[y][x] = level[y][x];
    }
  }
}

void Level_copyPlayer() {
  screen[1][2] = '@';  
}

void Level_render() {
  Level_copyMap();
  Level_copyPlayer();

  for (int i=0;i<LEVEL_HEIGHT;i++) {
    printf("%.*s\n", LEVEL_WIDTH, screen[i]);
  }
}