#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>

#include "player.h"


/* Set up player */
Player * playerSetUp() {
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));

  newPlayer -> health = 20;
  newPlayer -> maxHealth = 20;

  newPlayer -> shield = 20;
  newPlayer -> maxShield = 20;

  newPlayer -> mana = 20;
  newPlayer -> maxMana = 20;

  newPlayer -> towerLevel = 1;

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

int displayPlayerInfo(Player * user) {
  int xInfoBegin = 32;
  int yInfoBegin = 1;

  int HP = user -> health;
  int maxHP = user -> maxHealth;

  int SP = user -> shield;
  int maxSP = user -> maxShield;

  int MP = user -> mana;
  int maxMP = user -> maxMana;

  mvprintw(yInfoBegin, xInfoBegin, "HP:");
  displayBar(yInfoBegin, xInfoBegin + 4, HP, maxHP);
  displayStatNum(yInfoBegin, xInfoBegin + 17, HP, maxHP);

  mvprintw(yInfoBegin + 1, xInfoBegin, "SP:");
  displayBar(yInfoBegin + 1, xInfoBegin + 4, SP, maxSP);
  displayStatNum(yInfoBegin + 1, xInfoBegin + 17, SP, maxSP);

  mvprintw(yInfoBegin + 2, xInfoBegin, "MP:");
  displayBar(yInfoBegin+ 2, xInfoBegin + 4, MP, maxMP);
  displayStatNum(yInfoBegin + 2, xInfoBegin + 17, MP, maxMP);

  mvprintw(yInfoBegin + 30, xInfoBegin, "LEVEL:");
  mvprintw(yInfoBegin + 30, xInfoBegin + 8, "%d", user -> towerLevel);
  
  move(user -> position.y, user -> position.x);

  return 0;
}

int displayBar(int y, int x, int stat, int maxStat) {
  float rawStatPercent = (float) stat / (float) maxStat * 10;

  int statPercent = ceilf(rawStatPercent);

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
  char stringStat[20];
  char stringMaxStat[20];

  sprintf(stringStat, "%d", stat);
  sprintf(stringMaxStat, "%d", maxStat);



  mvprintw(y, x, "%s", stringStat);
  mvprintw(y, x + strlen(stringStat), "/");
  mvprintw(y, x + strlen(stringStat) + 1, "%s", stringMaxStat);

  return 0;
}
