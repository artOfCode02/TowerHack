#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"

const int levelXPos = 0;
const int levelYPos = 1;
const int levelWidth = 40;
const int levelHeight = 40;

int createLevel();

typedef struct Level{
  int number;
  int type;
  // Item ** items;
  // Monster ** monsters;
} Level;

Level * level;
