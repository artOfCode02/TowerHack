#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "map.h"

Map * makeMap(Room ** rooms) {
  Map * newMap;
  newMap = malloc(sizeof(Map));

  newMap -> trapdoors = malloc(sizeof(Door) * 2);

  newMap -> rooms = malloc(sizeof(Room) * 9);
  newMap -> rooms = rooms;

  Door * trapdoorOne = malloc(sizeof(Door));
  Door * trapdoorTwo = malloc(sizeof(Door));

  for (int i = 3; i < 6; i++) {
    if(rooms[i] -> hasTrapdoor){
      trapdoorOne = rooms[i] -> trapdoor;
      newMap -> trapdoors[0] = trapdoorOne; 
      break;
    }
  }

  for (int i = 6; i < 9; i++) {
    if(rooms[i] -> hasTrapdoor){
      trapdoorTwo = rooms[i] -> trapdoor;
      newMap -> trapdoors[1] = trapdoorTwo; 
      break;
    }
  }

  srand(time(NULL));

  int endLevelX;
  
  while ((endLevelX == 0 || endLevelX == 10) || endLevelX == 20) {
    endLevelX = rand() % 30;
  }

  newMap -> endLevel.y = 1;
  newMap -> endLevel.x = endLevelX;

  drawEndLadder(newMap);

  return newMap;
}

int drawEndLadder(Map * map) {
  int y = map -> endLevel.y;
  int x = map -> endLevel.x;

  mvprintw(y, x, "^");

  for(int i = 1; i < 10; i++){
    mvprintw(y + i, x, "=");
  }

  return 0;
}
