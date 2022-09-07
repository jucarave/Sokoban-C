#ifndef PLAYER_HEADER
#define PLAYER_HEADER

typedef struct {
  char x;
  char y;
} Player;

void Player_update(Player *player);
void Player_setPosition(Player *player, char x, char y);

#endif