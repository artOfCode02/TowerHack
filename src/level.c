#include <ncurses.h>
#include <stdlib.h>

#include "level.h"

int drawRoom(Room * room) {
  int x = room -> position.x;
  int y = room -> position.y;
  
  /*Top*/
  mvprintw(y, x, "|---------|");

  for(int i = 1; i < 10; i++) {
    mvprintw(y + i, x, "|...=.....|");
  }

  /*Bottom*/
  mvprintw(y + 10, x, "|---------|");

  return 0;
}

Room * createRoom(int y, int x) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));

  newRoom -> position.y = y;
  newRoom -> position.x = x;

  drawRoom(newRoom);

  return newRoom;
}



Room ** mapSetUp() {
  Room ** level = malloc(sizeof(Room) * 9);

  //First row
  level[0] = createRoom(1, 0);
  level[1] = createRoom(1, 10);
  level[2] = createRoom(1, 20);

  //Second row
  level[3] = createRoom(11, 0);
  level[4] = createRoom(11, 10);
  level[5] = createRoom(11, 20);

  //Third row
  level[6] = createRoom(21, 0);
  level[7] = createRoom(21, 10);
  level[8] = createRoom(21, 20);
 
  return level;
}
