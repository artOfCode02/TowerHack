#pragma once

#include "player.h"
#include "map.h"

typedef struct LevelElements {
    Player *user;
    Map *map;
} LevelElements;