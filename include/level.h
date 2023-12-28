#pragma once

#include "position.h"

typedef struct Room{
  Position position;
  
  Position door[2];
  Position trapdoor;

  bool hasTrapdoor;

  //Monster ** monsters;
  //Item ** items;
  
} Room;


int drawRoom(Room * roomArray);
Room * createRoom(int y, int x, bool hasTrapdoor, int doorLayout);
Room ** mapSetUp();
int trapdoorXPos(Room * room);
