#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

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
