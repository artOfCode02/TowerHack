#pragma once

#include "level.h"
#include "position.h"

/* Player "class" */
typedef struct Player {
  Position position;
  int health;

  Room * startRoom;
} Player;

/* Function Declarations */
Player * playerSetUp();
int playerMove(int y, int x, Player * user, bool onLadder);
int playerStartPos(Room ** level, Player * user);
int playerMoveStart(Player * user);
