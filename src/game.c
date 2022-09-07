#include <stdio.h>
#include <stdbool.h>
#include "level.h"
#include "player.h"
#include "gameData.h"
#include "movement.h"

static Player player;
static int currentLevel = 1;
static bool isGameOver;

void Game_loop() {
  Player_update(&player);
}

void Game_render() {
  Level_drawMap();
  Level_drawPlayer(player.x, player.y);
  Level_drawBoxes();
  Level_render();
}

int Game_loadLevel() {
  Level *level = Data_loadLevel(currentLevel);
  if (level == NULL) {
    return -1;
  }

  Player_setPosition(&player, level->playerX, level->playerY);
  Level_set(level);
  Data_freeLevel(level);

  return 0;
}

void Game_nextLevel() {
  currentLevel += 1;

  if (currentLevel == 3) {
    printf("\n\nYou've finished the last level!\n\n");
    isGameOver = true;
    return;
  } else {
    printf("\n\nLoading next Level!\n\n");
  }

  Movement_clearList();
  Game_loadLevel();
}

int Game_start() {
  char option;

  printf("Welcome to warehose!\n");
  printf("\na) New Game.\n");
  
  printf("\nChoose your option: ");
  scanf("%c", &option);

  return Game_loadLevel();
}

bool Game_isGameOver() {
  return isGameOver;
}