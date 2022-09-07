#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "level.h"
#include "movement.h"

void onLevelComplete() {
  printf("\n\nCongratulations, You finished the level!");
  printf("\n\nLoading next Level!\n\n");

  Game_nextLevel();
  Game_render();
}

int main() {
  bool gameOver = false;

  if (Game_start() != 0) {
    return -1;
  }

  Game_render();

  while (!gameOver) {
    Game_loop();
    Game_render();

    if (Level_isComplete()) {
      onLevelComplete();
    }
  }

  Movement_clearList();

  return 0;
}