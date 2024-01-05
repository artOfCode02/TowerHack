#pragma once

#include "level.h"
#include "door.h"

typedef struct Map {
  Room ** rooms;
  Door ** trapdoors;
} Map;

Map * makeMap(Room ** rooms);
