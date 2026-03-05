/**
 * @file player.h
 * @brief Player data structure and player-related function declarations.
 */

#pragma once

#include "level.h"
#include "position.h"
#include "tile.h"

/**
 * @struct Player
 * @brief Holds player state and stats.
 */
typedef struct Player {
  /** Current position of the player */
  Position position;

  /** Current tower (level) the player is on */
  int towerLevel;

  int health;
  int maxHealth;

  int shield;
  int maxShield;

  int mana;
  int maxMana;

  /** Tile type currently beneath the player */
  TILE_TYPE tile;

  /** Starting room for the player */
  Room *startRoom;

  /** Current room the player is located in */
  Room *currentRoom;
} Player;

/* Function Declarations, implemented in player.c */
/**
 * @brief Allocate and initialize a new Player with default stats.
 * @return Pointer to a new Player.
 */
Player *playerSetUp();

/**
 * @brief Move the player to a new coordinate and update underlying tile.
 * @param y Destination Y.
 * @param x Destination X.
 * @param user Pointer to the Player.
 * @param nextTile Character representing the tile at the destination.
 * @return 0 on success.
 */
int playerMove(int y, int x, Player *user, char nextTile);

/**
 * @brief Pick a starting room for the player from the level.
 * @param level Array of rooms (level).
 * @param user Pointer to the Player.
 * @return 0 on success.
 */
int playerStartPos(Room **level, Player *user);

/**
 * @brief Move the player to the computed start position.
 * @param user Pointer to the Player.
 * @return 0 on success.
 */
int playerMoveStart(Player *user);

/**
 * @brief Set the player's current room based on coordinates.
 * @param y Y coordinate.
 * @param x X coordinate.
 * @param user Pointer to the Player.
 * @return Pointer to the Room that contains (y,x).
 */
Room *setPlayerRoom(int y, int x, Player *user);

/**
 * @brief Display player stats on the side panel.
 * @param user Pointer to the Player.
 * @return 0 on success.
 */
int displayPlayerInfo(Player *user);

/**
 * @brief Draw a stat bar (HP/SP/MP) at the given location.
 * @param y Y coordinate.
 * @param x X coordinate.
 * @param stat Current stat value.
 * @param maxStat Maximum stat value.
 * @return 0 on success.
 */
int displayBar(int y, int x, int stat, int maxStat);

/**
 * @brief Display stat numbers (e.g. "12 / 20").
 * @param y Y coordinate.
 * @param x X coordinate.
 * @param stat Current stat value.
 * @param maxStat Maximum stat value.
 * @return 0 on success.
 */
int displayStatNum(int y, int x, int stat, int maxStat);
