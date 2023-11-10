#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "define.h"

/* Player "class" */
typedef struct Player {
  int xPosition;
  int yPosition;
  int health;
} Player;

/* Function Declarations */
Player * playerSetUp();
int playerMove(int y, int x, Player * user);

/* Set up player */
Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer -> health = 20;

  return newPlayer;
}

/* Move player */
int playerMove(int y, int x, Player * user) {
  if (mvinch(user -> yPosition, user -> xPosition) == LADDER) {
    mvprintw(user -> yPosition, user -> xPosition, LADDER);
  } else {
    mvprintw(user -> yPosition, user -> xPosition, EMPTY);
  }

  user -> yPosition = y;
  user -> xPosition = x;
  
  mvprintw(user -> yPosition, user -> xPosition, PLAYER);
  move(user -> yPosition, user -> xPosition);
  
  return 0;
}
