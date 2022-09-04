#include <stdbool.h>
#include "game.h"

int main() {
  bool gameOver = false;

  Game_start();
  Game_render();

  while (!gameOver) {
    Game_loop();
    Game_render();
  }

  return 0;
}