#pragma once

#include "position.h"
#include "level.h"
#include "door.h"

typedef struct Map {
  Room ** rooms;
  Door ** trapdoors;

  Position endLevel;
} Map;

Map * makeMap(Room ** rooms);
int drawEndLadder(Map * map);
