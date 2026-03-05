/**
 * @file level.h
 * @brief Room and level creation utilities.
 */

#pragma once

#include "position.h"
#include "door.h"

/**
 * @struct Room
 * @brief Represents a rectangular room in the level.
 */
typedef struct Room {
  /** Top-left position of the room */
  Position position;
  
  /** Optional trapdoor belonging to the room */
  Door *trapdoor;

  /** Whether this room contains a trapdoor */
  bool hasTrapdoor;

  //Monster ** monsters;
  //Item ** items;
  
} Room;

/**
 * @brief Draw a Room to the screen.
 * @param room Pointer to the Room to draw.
 * @return 0 on success.
 */
int drawRoom(Room *roomArray);

/**
 * @brief Create a Room at coordinates (y, x).
 * @param y Y coordinate.
 * @param x X coordinate.
 * @param hasTrapdoor True if a trapdoor should be created in the room.
 * @return Pointer to a newly allocated Room.
 */
Room *createRoom(int y, int x, bool hasTrapdoor);

/**
 * @brief Create a set of rooms that form a level.
 * @return Array of Room pointers (the level layout).
 */
Room **mapSetUp();

/**
 * @brief Choose an x coordinate for a trapdoor inside a room.
 * @param room Room to use as reference for bounds.
 * @return X coordinate for the trapdoor.
 */
int trapdoorXPos(Room *room);

/**
 * @brief Save or return the trapdoor for a room.
 * @param room Room containing the trapdoor.
 * @return Pointer to the trapdoor Door.
 */
Door *saveTrapdoor(Room *room);
