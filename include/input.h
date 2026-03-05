/**
 * @file input.h
 * @brief Player input handling and collision checks.
 */

#pragma once

#include "player.h"
#include "door.h"
#include "map.h"
#include "levelElements.h"

/**
 * @brief Handle a single user input character and perform actions.
 * 
 * @param input     The input character.
 * @param levelElements Struct containing pointers to player and map for state updates.
 * 
 * @return 0 on success.
 */
LevelElements handleInput(char input, LevelElements levelElements);

/**
 * @brief Check the tile at a proposed position and handle collisions/movement.
 * 
 * @param newY       Proposed Y coordinate.
 * @param newX       Proposed X coordinate.
 * @param targetDoor Pointer to a door at the target position (if any).
 * @param levelElements Struct containing pointers to player and map for state updates.
 * 
 * @return Updated map pointer if the level changes, otherwise the same map pointer, relayed to handleInput for state updates.
 */
LevelElements checkPosition(int newY, int newX, Door *targetDoor, LevelElements levelElements);

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
