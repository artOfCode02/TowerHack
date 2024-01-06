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
int playerMove(int y, int x, Player * user, char nextTile) {
  switch (user -> tile.tile) {
    case '=':
      mvprintw(user -> position.y, user -> position.x, "=");
      break;

    case '`':
      mvprintw(user -> position.y, user -> position.x, "`");
      break;

    case '.':
      mvprintw(user -> position.y, user -> position.x, ".");
      break;
    
    default:
      break;
  }

  user -> tile.tile = nextTile;

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


int playerMoveStart(Player * user) {
  srand(time(NULL));

  int rNum;
  rNum = rand() % 9 + 1;

  int y = user -> startRoom -> position.y + 9;
  int x = user -> startRoom -> position.x + rNum;

  playerMove(y, x, user, mvinch(y, x));
  user -> currentRoom = user -> startRoom;

  mvprintw(0, 0, " ");
  move(user -> position.y, user -> position.x);

  return 0;
}
