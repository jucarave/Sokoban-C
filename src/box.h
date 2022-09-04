#ifndef BOX_HEADER
#define BOX_HEADER

#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Box;

bool Box_moveTo(Box *box, int xTo, int yTo);

#endif