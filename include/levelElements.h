/**
 * @file levelElements.h
 * @brief Simple struct to hold level map and player for updates,
 */
#pragma once

#include "player.h"
#include "map.h"

/**
 * @struct LevelElements
 * @brief Container for pointers to player and map for easy passing to input handler.
 */
typedef struct LevelElements {
    Player *user;
    Map *map;
} LevelElements;