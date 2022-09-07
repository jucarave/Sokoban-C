#ifndef BOX_HEADER
#define BOX_HEADER

#include <stdbool.h>

typedef struct {
  char x;
  char y;
} Box;

bool Box_moveTo(Box *box, char xTo, char yTo);

#endif