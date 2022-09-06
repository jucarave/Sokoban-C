#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "player.h"
#include "level.h"
#include "box.h"
#include "movement.h"

void Player_setPosition(Player *player, int x, int y) {
  player->x = x;
  player->y = y;
}

bool Player_moveTo(Player *player, int xTo, int yTo) {
  Box *box = Level_getBoxAt(player->x + xTo, player->y + yTo);
  if (box != NULL && !Box_moveTo(box, xTo, yTo)) {
    return false;
  }

  if (!Level_isSolid(player->x + xTo, player->y + yTo)) {
    player->x += xTo;
    player->y += yTo;

    Movement_add(xTo, yTo, box);

    return true;
  }

  return false;
}

void Player_undoMovement(Player *player) {
  Movement *move = Movement_getLast();
  if (move == NULL) {
    printf("Can't undo more actions.\n");
    return;
  }

  player->x -= move->xTo;
  player->y -= move->yTo;

  if (move->box != NULL) {
    Box_moveTo(move->box, -move->xTo, -move->yTo);
  }

  Movement_removeLast();
}

bool Player_updateMovement(Player *player, char direction) {
  int xTo = 0;
  int yTo = 0;
  
  if (direction == 'w') {
    yTo -= 1;
  } else if (direction == 'a') {
    xTo -= 1;
  } else if (direction == 's') {
    yTo += 1;
  } else if (direction == 'd') {
    xTo += 1;
  } else if (direction == 'z') {
    Player_undoMovement(player);
    return true;
  } else {
    printf("Invalid direction! %c\n", direction);
    return false;
  }

  return Player_moveTo(player, xTo, yTo);
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
      printf("Invalid direction, should be 'W','A','S' or 'D'. Or press 'Z' to undo the last movement\n");
    }
  } while (!correctValues);

  Player_updateMovement(player, tolower(direction));
}