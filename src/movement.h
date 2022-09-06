#ifndef MOVEMENT_HEADER
#define MOVEMENT_HEADER

#include "box.h"

typedef struct {
  Box *box;
  int xTo;
  int yTo;
} Movement;

void Movement_add(int xTo, int yTo, Box *box);
void Movement_clearList();
void Movement_removeLast();
Movement *Movement_getLast();

#endif