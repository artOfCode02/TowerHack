#pragma once

#include "player.h"
#include "door.h"
#include "map.h"

int handleInput(char input, Player * user, Door ** doors, Door ** trapdoors, Room ** level, Map * map);
int checkPosition(int newY, int newX, Player * user, Door * targetDoor, Room ** level, Map * map, Door ** doors);
int changeDoorState(int y, int x, Door ** doors, bool isTrapdoor, bool openDoor);
