#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>

#include "player.h"


/* Set up player */
Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer -> health = 20;

  return newPlayer;
}

/* Move player */
int playerMove(int y, int x, Player * user) {
  if (mvinch(user -> yPosition, user -> xPosition) == '=') {
    mvprintw(user -> yPosition, user -> xPosition, "=");
  } else {
    mvprintw(user -> yPosition, user -> xPosition, ".");
  }

  user -> yPosition = y;
  user -> xPosition = x;
  
  mvprintw(user -> yPosition, user -> xPosition, "@");
  move(user -> yPosition, user -> xPosition);
  
  return 0;
}

int playerStartPos(Room ** level, Player * user) {
  srand(time(NULL));

  int roomNumber;
  roomNumber = (rand() % 3) + 6;

  user -> startRoom = level[roomNumber];
}
