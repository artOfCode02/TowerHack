#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "level.h"
#include "map.h"
#include "player.h"
#include "door.h"
#include "input.h"
#include "makeLevel.h"

/* DOCUMENTATION SECTION: 
  Purpose: 
    This file is responsible for initializing player, level, map, and doors. It contains the main game loop.

  Functions:
    * screenSetUp: Initializes the ncurses screen.
    * mapSetUp: Initializes the level and returns a pointer to it, refer to level.c for more details.
    * makeLevelDoors: Initializes the doors for the level and returns a pointer to them, refer to door.c for more details.
    * playerSetUp: Initializes the player and returns a pointer to it, refer to player.c for more details.
    * playerStartPos: Sets the player's starting position, refer to player.c for more details.
    * playerMoveStart: Displays the player on the map, refer to player.c for more details.
    * displayPlayerInfo: Displays the player's information, refer to player.c for more details.
    * handleInput: Takes in user input and turns it into an action, refer to input.c for more details.
*/


int screenSetUp();


int main(int argc, char * argv[]){
  // Variable initialization
  Player * user;
  Room ** level;
  Door ** doors;
  Map * map;

  screenSetUp();
  level = mapSetUp(); // From level.c

  map = makeMap(level); // From map.c

  doors = makeLevelDoors(); // From door.c

  // Player set up
  user = playerSetUp(); // From player.c
  playerStartPos(level, user); // From player.c
  playerMoveStart(user); // From player.c
  displayPlayerInfo(user); // From player.c

  char ch = getch();
  
  /* Main Game Loop:
    * runs handleInput
    * displays updated player info
    * reads new charachter and iterates the loop
  */
  while(ch != 'Q'){
    handleInput(ch, user, doors, map -> trapdoors, level, map); // From input.c
    displayPlayerInfo(user); // From player.c
    ch = getch();
  }
  
  // Ends ncurses
  endwin();

  return 0;
}

// Initializes ncurses
int screenSetUp(){
  initscr();
  noecho();
  refresh();
  
  return 0;
}
