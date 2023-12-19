#pragma once

#include "level.h"

/* Player "class" */
typedef struct Player {
  int xPosition;
  int yPosition;
  int health;
  Room * startRoom;
} Player;

/* Function Declarations */
Player * playerSetUp();
int playerMove(int y, int x, Player * user);
int playerStartPos(Room ** level, Player * user);

