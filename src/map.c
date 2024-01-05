#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "map.h"

Map * makeMap(Room ** rooms) {
  Map * newMap;
  newMap = malloc(sizeof(Map));

  newMap -> trapdoors = malloc(sizeof(Door));

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

  return newMap;
}


