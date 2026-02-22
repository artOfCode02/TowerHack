#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>

#include "player.h"

/* DOCUMENTATION SECTION:
  Purpose: 
    This file is responsible for the handling of the Player class, as well as the display stats for the player

  Functions:
    * playerSetUp: Sets up the player class and initializes default values for player stats
    * playerMove: Moves player to a new location.
    * playerStartPos: Randomizes which of the bottom 3 rooms the player's starting in
    * playerMoveStart: Moves player to starting room
    * displayPlayerInfo: Displays the player info to the right
    * displayBar: Sets the display bar for the player stat
*/


/* Set up player */
Player * playerSetUp() {
  // Initializes new player and allocates space in memory for it
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  // Sets default base and max player health
  newPlayer -> health = 20;
  newPlayer -> maxHealth = 20;

  // Sets default base and max player shields
  newPlayer -> shield = 20;
  newPlayer -> maxShield = 20;

  // Sets default base and max player mana
  newPlayer -> mana = 20;
  newPlayer -> maxMana = 20;

  // Sets default tower level
  newPlayer -> towerLevel = 1;

  return newPlayer;
}

/* Move player */
int playerMove(int y, int x, Player * user, char nextTile) {

  // Replace player '@' in old position with the tile type under
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

  // Set tile type under to the new position's tile
  user -> tile.tile = nextTile;

  // Set player coords to new position
  user -> position.y = y;
  user -> position.x = x;

  // NCURSES draw player charachter at new position
  mvprintw(user -> position.y, user -> position.x, "@");

  // NCURSES move cursor to new player position
  move(user -> position.y, user -> position.x);
  
  return 0;
}

/* Sets the starting room the player will start in */
int playerStartPos(Room ** level, Player * user) {
  srand(time(NULL));

  int roomNumber = (rand() % 3) + 6; // Room numbers 6-8, bottom 3 rooms

  user -> startRoom = level[roomNumber];

  return 0;
}

/* Moves the player to its initial position */
int playerMoveStart(Player * user) {
  srand(time(NULL));

  int rNum = (rand() % 9) + 1; // Random number 1-9

  int y = user -> startRoom -> position.y + 9; // Set y to the bottom level of startRoom
  int x = user -> startRoom -> position.x + rNum; // Set x to a random number from 1-9, within bounds of room

  // Move player to y and x, and set currentRoom to startRoom
  playerMove(y, x, user, (char)mvinch(y, x));
  user -> currentRoom = user -> startRoom;

  // Set (0,0) to blank and move cursor to player position
  mvprintw(0, 0, " ");
  move(user -> position.y, user -> position.x);

  return 0;
}

/* Displays player info */
int displayPlayerInfo(Player * user) {
  // Sets the position where the info will be displayed
  int yInfoBegin = 1;
  int xInfoBegin = 32;

  /*---Sets variable parameters---*/
  int HP = user -> health;
  int maxHP = user -> maxHealth;

  int SP = user -> shield;
  int maxSP = user -> maxShield;

  int MP = user -> mana;
  int maxMP = user -> maxMana;
  /*------------------------------*/

  // Prints the HP (Health) stat
  mvprintw(yInfoBegin, xInfoBegin, "HP:");
  displayBar(yInfoBegin, xInfoBegin + 4, HP, maxHP);
  displayStatNum(yInfoBegin, xInfoBegin + 17, HP, maxHP);

  // Prints the SP (Shield) stat
  mvprintw(yInfoBegin + 1, xInfoBegin, "SP:");
  displayBar(yInfoBegin + 1, xInfoBegin + 4, SP, maxSP);
  displayStatNum(yInfoBegin + 1, xInfoBegin + 17, SP, maxSP);

  // Prints the MP (Mana) stat
  mvprintw(yInfoBegin + 2, xInfoBegin, "MP:");
  displayBar(yInfoBegin+ 2, xInfoBegin + 4, MP, maxMP);
  displayStatNum(yInfoBegin + 2, xInfoBegin + 17, MP, maxMP);

  // Print the user's current tower level
  mvprintw(yInfoBegin + 30, xInfoBegin, "LEVEL:");
  mvprintw(yInfoBegin + 30, xInfoBegin + 8, "%d", user -> towerLevel);
  
  // Resets cursor to current player position
  move(user -> position.y, user -> position.x);

  return 0;
}

int displayBar(int y, int x, int stat, int maxStat) {
  // Gives a stat rating from 0-10
  float rawStatPercent = ((float)stat / (float)maxStat) * 10;

  // Ceilings the stat percentage so it can be processed by the switch statement
  int statPercent = ceilf(rawStatPercent);

  // Draws the stat accordingly with the statPercent
  switch (statPercent) {
    case 1:
      mvprintw(y, x, "[#         ]");
      break;

    case 2:
      mvprintw(y, x, "[##        ]");
      break;

    case 3:
      mvprintw(y, x, "[###       ]");
      break;

    case 4:
      mvprintw(y, x, "[####      ]");
      break;
      
    case 5:
      mvprintw(y, x, "[#####     ]");
      break;

    case 6:
      mvprintw(y, x, "[######    ]");
      break;

    case 7:
      mvprintw(y, x, "[#######   ]");
      break;

    case 8:
      mvprintw(y, x, "[########  ]");
      break;

    case 9:
      mvprintw(y, x, "[######### ]");
      break;

    case 10:
      mvprintw(y, x, "[##########]");
      break;
    
    default:
      break;
  } 

  return 0;
}


int displayStatNum(int y, int x, int stat, int maxStat) {
  // Initializes stat array
  char displayStat[40];

  // ^_^
  snprintf(displayStat, sizeof(displayStat), "%d / %d", stat, maxStat);

  mvprintw(y, x, "%s", displayStat);

  return 0;
}
