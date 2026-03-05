#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <signal.h>

#include "level.h"
#include "map.h"
#include "player.h"
#include "door.h"
#include "input.h"
#include "makeLevel.h"
/**
 * @file main.c
 * @brief Program entry point, initialization and main game loop.
 */

// Variable initialization
Player *user;
Room **level;
Door **doors;
Map *map;

int screenSetUp();

void cleanup(void);

void signal_handler(int sig);

int main(int argc, char *argv[]){
  // Register cleanup function
  if (atexit(cleanup) != 0) {
    fprintf(stderr, "Failed to register atexit handler\n");
    return EXIT_FAILURE;
  }

  // Register signal handlers
  signal(SIGINT, signal_handler); // Handles Ctrl + C
  signal(SIGTERM, signal_handler); // Handles termination signal

  // Set up ncurses
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


  return 0;
}

/**
 * @brief Initialize ncurses screen settings.
 * @return 0 on success.
 */
int screenSetUp(){
  initscr();
  noecho();
  refresh();
  
  return 0;
}

/**
 * @brief Cleanup allocated resources and end ncurses mode.
 */
void cleanup(void) {
  // Frees elements from memory
  free(user);
  free(level);
  free(doors);
  free(map);

  // Ends ncurses
  endwin();
}

/**
 * @brief Signal handler that performs cleanup and re-raises the signal.
 * @param sig Signal number received.
 */
void signal_handler(int sig) {
  // Run cleanup function
  cleanup();

  // Re-raise signal for default handling
  signal(sig, SIG_DFL);
  raise(sig);
}