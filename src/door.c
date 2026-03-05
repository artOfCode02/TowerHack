#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "door.h"

/**
 * @file door.c
 * @brief Implementation of door creation, drawing and lookup.
 */


/**
 * @brief Draw a door character ('+' for closed, grave-accent for open) at the door's position.
 */
int drawDoor(Door *door) {
  int y;
  int x;

  y = door -> position.y;
  x = door -> position.x;

  if(door -> isOpen) {
    mvprintw(y, x, "`");
  } else {
    mvprintw(y, x, "+");
  }

  return 0;
}

/**
 * @brief Creates a new door at the given coordinates.
 */
Door *createDoor(int y, int x) {
  Door *newDoor = malloc(sizeof(Door));
  
  newDoor -> position.y = y;
  newDoor -> position.x = x;

  newDoor -> isOpen = false;

  drawDoor(newDoor);

  return newDoor;
}

/**
 * @brief Creates a grid of 6 doors for a level.
 */
Door **makeLevelDoors() {
  Door **doors = malloc(sizeof(Door) * 6);

  doors[0] = createDoor(10, 10);
  doors[1] = createDoor(10, 20);

  doors[2] = createDoor(20, 10);
  doors[3] = createDoor(20, 20);

  doors[4] = createDoor(30, 10);
  doors[5] = createDoor(30, 20);
  
  return doors;
}

/**
 * @brief Fetch a Door from a door array by its position.
 */
Door *fetchDoorFromDoorArrayUsingPosition(int y, int x, Door **doors, bool isTrapdoor) {
  Door *door = malloc(sizeof(Door));

  // The size of the trapdoor array is 2, the size of the door array is 6
  int maxDoors = isTrapdoor ? 2 : 6;

  for(int i = 0; i < maxDoors; i++) {
    // Set door to the current door in the array if its position matches the given position
    if(y == doors[i] -> position.y && x == doors[i] -> position.x) door = doors[i];
  }
  
  return door;
}
