#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "level.h"

int trapdoorXPos(Room * room) {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  srand(tv.tv_usec);

  int x;
  x = (((rand() % 9) + 1) + (room -> position.x));

  return x;
}

int drawRoom(Room * room) {
  int x = room -> position.x;
  int y = room -> position.y;
  
  /*Top*/
  mvprintw(y, x, "|---------|");

  for(int i = 1; i < 10; i++) {
		if(room -> hasTrapdoor){
			switch(room -> trapdoor.x) {
				case 1:
				case 11:
				case 21:
					mvprintw(y + i, x, "|=........|");
					break;
				case 2:
				case 12:
				case 22:
					mvprintw(y + i, x, "|.=.......|");
					break;
				case 3:
				case 13:
				case 23:
					mvprintw(y + i, x, "|..=......|");
					break;
				case 4:
				case 14:
				case 24:
					mvprintw(y + i, x, "|...=.....|");
					break;
				case 5:
				case 15:
				case 25:
					mvprintw(y + i, x, "|....=....|");
					break;
				case 6:
				case 16:
				case 26:
					mvprintw(y + i, x, "|.....=...|");
					break;
				case 7:
				case 17:
				case 27:
					mvprintw(y + i, x, "|......=..|");
					break;
				case 8:
				case 18:
				case 28:
					mvprintw(y + i, x, "|.......=.|");
					break;
				case 9:
				case 19:
				case 29:
					mvprintw(y + i, x, "|........=|");
					break;
				default:
					break;
			}
		} else {
			mvprintw(y + i, x, "|.........|");
		}
  }

  /*Bottom*/
  mvprintw(y + 10, x, "|---------|");

  for(int i = 0; i < 2; i++) {
    mvprintw((room -> door[i].y), (room -> door[i].x), "+");
  }

  mvprintw((room -> trapdoor.y), (room -> trapdoor.x), "+");


  return 0;
}

Room * createRoom(int y, int x, bool hasTrapdoor,int doorLayout) {
  Room * newRoom;
  newRoom = malloc(sizeof(Room));

  newRoom -> position.y = y;
  newRoom -> position.x = x;

  Position leftDoor;
  leftDoor.y = (newRoom -> position.y) + 9;
  leftDoor.x = newRoom -> position.x;

  Position rightDoor;
  rightDoor.y = leftDoor.y;
  rightDoor.x = leftDoor.x + 10;

  int trapdoorY;
  trapdoorY = newRoom -> position.y;

  if(hasTrapdoor){
    newRoom -> trapdoor.y = trapdoorY;
    newRoom -> trapdoor.x = trapdoorXPos(newRoom);

    newRoom -> hasTrapdoor = true;
  } else {
		newRoom -> hasTrapdoor = false;
	}

  switch(doorLayout) {
    case 1:
      newRoom -> door[1].y = rightDoor.y;
      newRoom -> door[1].x = rightDoor.x;

      break;
    case 11:
      newRoom -> door[0].y = leftDoor.y;
      newRoom -> door[0].x = leftDoor.x;

      newRoom -> door[1].y = rightDoor.y;
      newRoom -> door[1].x = rightDoor.x;

      break;
    case 10:
      newRoom -> door[0].y = leftDoor.y;
      newRoom -> door[0].x = leftDoor.x;

      break;
    default:
        break;
  }

  drawRoom(newRoom);

  return newRoom;
}



Room ** mapSetUp() {
  Room ** level = malloc(sizeof(Room) * 9);

  // struct timeval tv;
  // gettimeofday(&tv, NULL);
  srand(time(NULL));

  int ladderRoomMiddle;
  int ladderRoomBottom;

  ladderRoomMiddle = rand() % 3;
  ladderRoomBottom = rand() % 3;


  //First row
  level[0] = createRoom(1, 0, 0, 1);
  level[1] = createRoom(1, 10, 0, 11);
  level[2] = createRoom(1, 20, 0, 10);

  switch(ladderRoomMiddle){
    case 0:
      level[3] = createRoom(11, 0, 1, 1);
      level[4] = createRoom(11, 10, 0, 11);
      level[5] = createRoom(11, 20, 0, 10);

			break;
    case 1:
      level[3] = createRoom(11, 0, 0, 1);
      level[4] = createRoom(11, 10, 1, 11);
      level[5] = createRoom(11, 20, 0, 10);

			break;
    case 2:
      level[3] = createRoom(11, 0, 0, 1);
      level[4] = createRoom(11, 10, 0, 11);
      level[5] = createRoom(11, 20, 1, 10);
  }

  switch(ladderRoomBottom){
    case 0:
      level[6] = createRoom(21, 0, 1, 1);
      level[7] = createRoom(21, 10, 0, 11);
      level[8] = createRoom(21, 20, 0, 10);

			break;
    case 1:
      level[6] = createRoom(21, 0, 0, 1);
      level[7] = createRoom(21, 10, 1, 11);
      level[8] = createRoom(21, 20, 0, 10);

			break;
    case 2:
      level[6] = createRoom(21, 0, 0, 1);
      level[7] = createRoom(21, 10, 0, 11);
      level[8] = createRoom(21, 20, 1, 10);

			break;
  }
 
  return level;
}

