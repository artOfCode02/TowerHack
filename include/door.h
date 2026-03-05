/**
 * @file door.h
 * @brief Door type and door-related function declarations.
 */

#pragma once

#include "position.h"

/**
 * @struct Door
 * @brief Represents a door or trapdoor in a room.
 */
typedef struct Door {
  /** Position of the door on the screen */
  Position position;

  /** Whether the door is currently open */
  bool isOpen;
} Door;

/* Initialization and drawing functions */
/**
 * @brief Draw a door to the screen using ncurses.
 * @param door Pointer to the Door to draw.
 * @return 0 on success.
 */
int drawDoor(Door *door);

/**
 * @brief Create a new Door at coordinates (y, x).
 * @param y Y coordinate.
 * @param x X coordinate.
 * @return Pointer to a newly allocated Door (closed by default).
 */
Door *createDoor(int y, int x);

/**
 * @brief Create the default set of doors for a level.
 * @return Array of Door pointers for the level.
 */
Door **makeLevelDoors();

/* Utility functions */
/**
 * @brief Fetch a Door from a door array by its position.
 * @param y Y coordinate to search for.
 * @param x X coordinate to search for.
 * @param doors Array of Door pointers to search.
 * @param isTrapdoor True if searching trapdoor array (smaller size).
 * @return Pointer to the matching Door or NULL if not found.
 */
Door *fetchDoorFromDoorArrayUsingPosition(int y, int x, Door **doors, bool isTrapdoor);
