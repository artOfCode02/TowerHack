#pragma once

#include "position.h"

typedef struct Room{
  Position position;
  
  Position door[2];
  Position trapdoor;

  //Monster ** monsters;
  //Item ** items;
  
} Room;


int drawRoom(Room * roomArray);
Room * createRoom(int y, int x, int doorLayout);
Room ** mapSetUp();
int trapdoorXPos(Room * room);
