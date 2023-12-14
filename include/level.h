#pragma once

typedef struct Room{
  int xPosition;
  int yPosition;

  //Monster ** monsters;
  //Item ** items;
  
} Room;


int drawRoom(Room * roomArray);

Room * createRoom(int y, int x);

Room ** mapSetUp();
