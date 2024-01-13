#pragma once

#include "level.h"
#include "position.h"
#include "tile.h"

/* Player "class" */
typedef struct Player {
  Position position;

  int towerLevel;

  int health;
  int maxHealth;

  int shield;
  int maxShield;

  int mana;
  int maxMana;

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
int displayPlayerInfo(Player * user);
int displayBar(int y, int x, int stat, int maxStat);
int displayStatNum(int y, int x, int stat, int maxStat);
