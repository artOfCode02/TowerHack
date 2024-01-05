#pragma once

#include "player.h"
#include "door.h"

int handleInput(char input, Player * user, Door ** doors, Door ** trapdoors);
int checkPosition(int newY, int newX, Player * user, Door * targetDoor);
int openDoor(int y, int x, Door ** doors, bool isTrapdoor);
