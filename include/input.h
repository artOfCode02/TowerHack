/**
 * @file input.h
 * @brief Player input handling and collision checks.
 */

#pragma once

#include "player.h"
#include "door.h"
#include "map.h"

/**
 * @brief Handle a single user input character and perform actions.
 * 
 * @param input     The input character.
 * @param user      Pointer to the player.
 * @param doors     Array of regular doors.
 * @param trapdoors Array of trapdoors.
 * @param level     Current level rooms.
 * @param map       Current map information.
 * 
 * @return 0 on success.
 */
int handleInput(char input, Player *user, Door **doors, Door **trapdoors, Room **level, Map *map);

/**
 * @brief Check the tile at a proposed position and handle collisions/movement.
 * 
 * @param newY       Proposed Y coordinate.
 * @param newX       Proposed X coordinate.
 * @param user       Pointer to the player.
 * @param targetDoor Pointer to a door at the target position (if any).
 * @param level      Current level rooms.
 * @param map        Current map information.
 * @param doors      Array of regular doors.
 * 
 * @return 0 on success.
 */
int checkPosition(int newY, int newX, Player *user, Door *targetDoor, Room **level, Map *map, Door **doors);

/**
 * @brief Open or close a door at given coordinates.
 * 
 * @param y          Door Y coordinate.
 * @param x          Door X coordinate.
 * @param doors      Array of doors to search.
 * @param isTrapdoor True if the door array is trapdoors.
 * @param openDoor   True to open the door, false to close.
 * 
 * @return 0 on success.
 */
int changeDoorState(int y, int x, Door **doors, bool isTrapdoor, bool openDoor);
