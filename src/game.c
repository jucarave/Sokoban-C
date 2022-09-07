#include <stdio.h>
#include "level.h"
#include "player.h"
#include "gameData.h"
#include "movement.h"

static Player player;
static int currentLevel = 1;

void Game_loop() {
  Player_update(&player);
}

void Game_render() {
  Level_drawMap();
  Level_drawPlayer(player.x, player.y);
  Level_drawBoxes();
  Level_render();
}

void Game_loadLevel() {
  Level *level = Data_loadLevel(currentLevel);
  if (level == NULL) {
    return;
  }

  Player_setPosition(&player, level->playerX, level->playerY);
  Level_set(level);
  Data_freeLevel(level);
}

void Game_nextLevel() {
  currentLevel += 1;

  Movement_clearList();
  Game_loadLevel();
}

void Game_start() {
  char option;

  printf("Welcome to warehose!\n");
  printf("\na) New Game.\n");
  
  printf("\nChoose your option: ");
  scanf("%c", &option);

  Game_loadLevel();
}