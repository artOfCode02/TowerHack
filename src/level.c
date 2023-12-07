#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Room{
  int xPosition;
  int yPosition;

  //Monster ** monsters;
  //Item ** items;
  
} Room;

int drawRoom(Room ** roomArray);

Room * createRoom(int y, int x);

Room ** mapSetUp();

int drawRoom(Room ** roomArray) {
  for(int i = 0; i < 9; i++){
    int x;
    int y;

    for(y = roomArray[i] -> yPosition;
    y < roomArray[i] -> yPosition + 10;
    y++
    ) {
      //Top
      mvprintw(y, roomArray[i] -> xPosition, "|");
      
      //Bottom
      mvprintw(y, roomArray[i] -> xPosition, "|");
    }
  }

  return 0;
}

Room * createRoom(int y, int x) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));

  newRoom -> yPosition = y;
  newRoom -> xPosition = x;

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
 
  drawRoom(level);

  return level;
}
