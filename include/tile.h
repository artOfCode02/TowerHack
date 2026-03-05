/**
 * @file tile.h
 * @brief Tile type used to track characters drawn under entities.
 */

#pragma once

#include "position.h"

/**
 * @struct TILE_TYPE
 * @brief Simple tile descriptor storing a position and the character used.
 */
typedef struct TILE_TYPE {
  Position position;

  char tile;

} TILE_TYPE; 
