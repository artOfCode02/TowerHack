#pragma once

#include "position.h"

typedef struct Door {
  Position position;

  bool isOpen;
} Door;
/* Init functions */
int drawDoor(Door * door);
Door * createDoor(int y, int x);
Door ** makeLevelDoors();

/* Extra Functions */
Door * checkDoorPositionAgainstPosition(int y, int x, Door ** doors, bool isTrapdoor);
