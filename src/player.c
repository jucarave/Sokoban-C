#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "player.h"
#include "level.h"

void Player_setPosition(Player *player, int x, int y) {
  player->x = x;
  player->y = y;
}

bool Player_moveTo(char direction, Player *player) {
  int xTo = player->x;
  int yTo = player->y;
  
  if (direction == 'w') {
    yTo -= 1;
  } else if (direction == 'a') {
    xTo -= 1;
  } else if (direction == 's') {
    yTo += 1;
  } else if (direction == 'd') {
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

  Player_moveTo(tolower(direction), player);
}