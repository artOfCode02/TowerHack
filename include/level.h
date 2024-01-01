#pragma once

#include "position.h"
#include "door.h"

typedef struct Room{
  Position position;
  
  Door door[2];
  Door trapdoor;

  bool hasTrapdoor;

  //Monster ** monsters;
  //Item ** items;
  
} Room;


int drawRoom(Room * roomArray);
Room * createRoom(int y, int x, bool hasTrapdoor, int doorLayout);
Room ** mapSetUp();
int trapdoorXPos(Room * room);
