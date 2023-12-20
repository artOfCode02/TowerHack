#pragma once

#include "position.h"

typedef struct Room{
  Position position;

  //Monster ** monsters;
  //Item ** items;
  
} Room;


int drawRoom(Room * roomArray);
Room * createRoom(int y, int x);
Room ** mapSetUp();
