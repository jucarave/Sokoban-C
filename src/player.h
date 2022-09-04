#ifndef PLAYER_HEADER
#define PLAYER_HEADER

typedef struct {
  int x;
  int y;
} Player;

void Player_update(Player *player);

#endif