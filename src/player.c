#include <stdio.h>
#include <stdbool.h>
#include "player.h"

bool Player_moveTo(char direction, Player *player) {
  if (direction == 'w' || direction == 'W') {
    player->y -= 1;
  } else if (direction == 'a' || direction == 'A') {
    player->x -= 1;
  } else if (direction == 's' || direction == 'S') {
    player->y += 1;
  } else if (direction == 'd' || direction == 'D') {
    player->x += 1;
  } else {
    printf("Invalid direction! %c\n", direction);
  }
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