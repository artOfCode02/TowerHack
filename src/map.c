#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "level.c"

srand((unsigned) time(NULL))

Level * levelSetUp();

Level * levelSetUp(){
  level -> type = rand() % 19;
  switch (level -> type) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    default:
      break;
  }
}