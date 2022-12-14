#include <stdbool.h>
#include "box.h"
#include "level.h"

bool Box_moveTo(Box *box, char xTo, char yTo) {
  if (!Level_isSolid(box->x + xTo, box->y + yTo)) {
    box->x += xTo;
    box->y += yTo;

    return true;
  }

  return false;
}