#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "level.h"
#include "movement.h"

int main() {
  bool gameOver = false;

  Game_start();
  Game_render();

  while (!gameOver) {
    Game_loop();
    Game_render();

    if (Level_isComplete()) {
      printf("Congratulations, You finished the level!\n");
      gameOver = true;
    }
  }

  Movement_clearList();

  return 0;
}