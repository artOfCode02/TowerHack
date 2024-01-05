#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "door.h"

int drawDoor(Door * door) {
  int y;
  int x;

  y = door -> position.y;
  x = door -> position.x;

  if(door -> isOpen) {
    mvprintw(y, x, ":");
  } else {
    mvprintw(y, x, "+");
  }

  return 0;
}

Door * createDoor(int y, int x) {
  Door * newDoor;
  newDoor = malloc(sizeof(Door));
  
  newDoor -> position.y = y;
  newDoor -> position.x = x;

  newDoor -> isOpen = false;

  drawDoor(newDoor);

  return newDoor;
}

Door ** makeLevelDoors() {
  Door ** doors = malloc(sizeof(Door) * 6);

  doors[0] = createDoor(10, 10);
  doors[1] = createDoor(10, 20);
  doors[2] = createDoor(20, 10);
  doors[3] = createDoor(20, 20);
  doors[4] = createDoor(30, 10);
  doors[5] = createDoor(30, 20);
  
  return doors;
}

Door * checkDoorPositionAgainstPosition(int y, int x, Door ** doors, bool isTrapdoor) {
  Door * door = NULL;
  door = malloc(sizeof(Door));

  int maxDoors;

  if(isTrapdoor) {
    maxDoors = 2;
  } else {
    maxDoors = 6;
  }

  for(int i = 0; i < maxDoors; i++) {
    if(y == doors[i] -> position.y && x == doors[i] -> position.x)
      door = doors[i];
  }
  
  if(door == NULL) {
    mvprintw(0, 0, "No door at that position.");
  }

  return door;
}
