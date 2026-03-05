/**
 * @file map.h
 * @brief Map container and helper functions.
 */

#pragma once

#include "position.h"
#include "level.h"
#include "door.h"

/**
 * @struct Map
 * @brief Represents the full map for the current tower level.
 */
typedef struct Map {
  /** Array of rooms forming the level */
  Room **rooms;

  /** Array of all doors in the level */
  Door **doors;

  /** Trapdoors found in the level */
  Door **trapdoors;

  /** Position of the level exit/ladder */
  Position endLevel;
} Map;

/**
 * @brief Build a Map from an array of Room pointers.
 * @param rooms Array of rooms created by mapSetUp().
 * @return Pointer to a newly allocated Map.
 */
Map *makeMap(Room **rooms);

/**
 * @brief Draw the end-of-level ladder on screen.
 * @param map Pointer to the Map containing the end position.
 * @return 0 on success.
 */
int drawEndLadder(Map *map);
