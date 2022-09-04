#include <stdio.h>
#include "level.h"
#include "player.h"
#include "gameData.h"

static Player player;

void Game_loop() {
  Player_update(&player);
}

void Game_render() {
  Level_drawMap();
  Level_drawPlayer(player.x, player.y);
  Level_render();
}

void Game_new() {
  Level *level = Data_getLevel(1);

  Player_setPosition(&player, level->playerX, level->playerY);
  Level_set(level);
}

void Game_start() {
  char option;

  printf("Welcome to warehose!\n");
  printf("\na) New Game.\n");
  
  printf("\nChoose your option: ");
  scanf("%c", &option);

  Game_new();
}