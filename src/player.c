#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "level.h"

void Player_setPosition(Player *player, int x, int y) {
  player->x = x;
  player->y = y;
}

bool Player_moveTo(char direction, Player *player) {
  int xTo = player->x;
  int yTo = player->y;
  
  if (direction == 'w' || direction == 'W') {
    yTo -= 1;
  } else if (direction == 'a' || direction == 'A') {
    xTo -= 1;
  } else if (direction == 's' || direction == 'S') {
    yTo += 1;
  } else if (direction == 'd' || direction == 'D') {
    xTo += 1;
  } else {
    printf("Invalid direction! %c\n", direction);
    return false;
  }

  if (!Level_isSolid(xTo, yTo)) {
    player->x = xTo;
    player->y = yTo;

    return true;
  }

  return false;
}

void Player_update(Player *player) {
  char direction;
  bool correctValues = false;

  do {
    printf("Where to you want to move? ");

    while (getchar() != '\n');
    if (scanf("%c", &direction) == 1) {
      correctValues = true;
    } else {
      printf("Invalid direction, should be W,A,S or D.\n");
    }
  } while (!correctValues);

  Player_moveTo(direction, player);
}