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
  if (mvinch(user -> position.y, user -> position.x) == '=') {
    mvprintw(user -> position.y, user -> position.x, "=");
  } else {
    mvprintw(user -> position.y, user -> position.x, ".");
  }

  user -> position.y = y;
  user -> position.x = x;
  
  mvprintw(user -> position.y, user -> position.x, "@");
  move(user -> position.y, user -> position.x);
  
  return 0;
}

int playerStartPos(Room ** level, Player * user) {
  srand(time(NULL));

  int roomNumber;
  roomNumber = (rand() % 3) + 6;

  user -> startRoom = level[roomNumber];

  return 0;
}

