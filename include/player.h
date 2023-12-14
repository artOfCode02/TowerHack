#pragma once

/* Player "class" */
typedef struct Player {
  int xPosition;
  int yPosition;
  int health;
} Player;

/* Function Declarations */
Player * playerSetUp();
int playerMove(int y, int x, Player * user);

