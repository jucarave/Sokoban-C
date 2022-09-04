#ifndef PLAYER_HEADER
#define PLAYER_HEADER

typedef struct {
  int x;
  int y;
} Player;

void Player_update(Player *player);
void Player_setPosition(Player *player, int x, int y);

#endif