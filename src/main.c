#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "level.h"
#include "movement.h"

void onLevelComplete() {
  printf("\n\nCongratulations, You finished the level!");
  
  Game_nextLevel();

  if (!Game_isGameOver()) {
    Game_render();
  }
}

int main() {
  if (Game_start() != 0) {
    return -1;
  }

  Game_render();

  while (!Game_isGameOver()) {
    Game_loop();
    Game_render();

    if (Level_isComplete()) {
      onLevelComplete();
    }
  }

  Movement_clearList();

  return 0;
}