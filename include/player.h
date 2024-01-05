#pragma once

#include "level.h"
#include "position.h"
#include "tile.h"

/* Player "class" */
typedef struct Player {
  Position position;
  int health;

  TILE_TYPE tile;

  Room * startRoom;

  Room * currentRoom;
} Player;

/* Function Declarations */
Player * playerSetUp();
int playerMove(int y, int x, Player * user, char nextTile);
int playerStartPos(Room ** level, Player * user);
int playerMoveStart(Player * user);
Room * setPlayerRoom(int y, int x, Player * user);
