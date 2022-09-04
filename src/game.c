#include<stdio.h>
#include "level.h"
#include "player.h"

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
  player.x = 3;
  player.y = 2;
}

void Game_start() {
  char option;

  printf("Welcome to warehose!\n");
  printf("\na) New Game.\n");
  
  printf("\nChoose your option: ");
  scanf("%c", &option);

  Game_new();
}