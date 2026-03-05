#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "level.h"

/**
 * @file level.c
 * @brief Level and Room creation and drawing logic.
 */

/**
 * @brief Outputs a random trapdoor x position.
 */
int trapdoorXPos(Room *room) {
  // rand() initialization from current time
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(tv.tv_usec);

  // Set x to a random number 1-9, plus the room's x position
  int x = (((rand() % 9) + 1) + (room -> position.x));

  return x;
}

/**
 * @brief Draws a room to the screen.
 */
int drawRoom(Room *room) {
  // Sets y and x to room positions stored in the room struct
  int y = room -> position.y;
  int x = room -> position.x;

  /*Top*/
  mvprintw(y, x, "|---------|");

  // Condition to draw if the room has a trapdoor
  if(room -> hasTrapdoor){
    int trapdoorY = room -> trapdoor -> position.y;
    int trapdoorX = room -> trapdoor -> position.x;

    // Create a char array for room row with ladder
    char trapdoorRoomRow[12];

    // Create one room row
    for (int i = 0; i < 11; i++) {
      if (i == 0 || i == 10) { trapdoorRoomRow[i] = '|'; } // Left and right walls
      else if (i == trapdoorX % 10) { trapdoorRoomRow[i] = '='; } // Ladder
      else { trapdoorRoomRow[i] = '.'; } // Empty '.' space
    }

    // End char array with null terminator
    trapdoorRoomRow[11] = '\0';

    // Iterate loop to print room to screen
    for (int i = 1; i < 10; i++) mvprintw(y + i, x, trapdoorRoomRow);

    // Print a '+' charachter at the trapdoor location
    mvprintw(trapdoorY, trapdoorX, "+");

  // Condition to draw if the room has no trapdoor
  } else {
    for(int i = 1; i < 10; i++) mvprintw(y + i, x, "|.........|");
  }

  /*Bottom*/
  mvprintw(y + 10, x, "|---------|");

  return 0;
}

/**
 * @brief Creates a new room and draws it.
 */
Room *createRoom(int y, int x, bool hasTrapdoor) {
  // Create and allocate room in memory
  Room *newRoom;
  newRoom = malloc(sizeof(Room));

  // Set room position
  newRoom -> position.y = y;
  newRoom -> position.x = x;

  if(hasTrapdoor){
    // Set room trapdoor settings
    int trapdoorY = newRoom -> position.y;
    int trapdoorX = trapdoorXPos(newRoom);
    
    // Create the trapdoor (as it is technically a door)
    newRoom -> trapdoor = createDoor(trapdoorY, trapdoorX);

    // Initialize the trapdoor to its closed state
    newRoom -> trapdoor -> isOpen = false;

    newRoom -> hasTrapdoor = true;
  } else {
		newRoom -> hasTrapdoor = false;

    // Free allocated trapdoor memory as it is unecessary
    free(newRoom -> trapdoor);
	}

  drawRoom(newRoom);

  return newRoom;
}

/**
 * @brief Create a level (array of 9 rooms).
 */
Room **mapSetUp() {
  // Allocates a room array
  Room **level = malloc(sizeof(Room) * 9);

  // rand() setup
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srand(time(NULL));

  // Initializes a random number 0-2 to determine which room has a ladder
  int ladderRoomMiddle = rand() % 3;
  int ladderRoomBottom = rand() % 3;


  //First row
  level[0] = createRoom(1, 0, 0);
  level[1] = createRoom(1, 10, 0);
  level[2] = createRoom(1, 20, 0);

  // For loops creates 3 rooms and assigns trapdoor status depending on if i == ladderRoomMiddle
  for (int i = 0; i < 3; i++) level[i + 3] = createRoom(11, i * 10, i == ladderRoomMiddle ? true : false); // Middle rooms
  for (int i = 0; i < 3; i++) level[i + 6] = createRoom(21, i * 10, i == ladderRoomBottom ? true : false); // Bottom rooms
 
  return level;
}

