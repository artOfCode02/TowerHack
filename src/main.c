#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "level.h"
#include "map.h"
#include "player.h"
#include "door.h"
#include "input.h"

int screenSetUp();

int main(int argc, char * argv[]){
  Player * user;
  Room ** level;
  Door ** doors;
  Map * map;

  screenSetUp();
  level = mapSetUp();

  map = makeMap(level);

  doors = makeLevelDoors();

  user = playerSetUp();
  playerStartPos(level, user);
  playerMoveStart(user);
  displayPlayerInfo(user);

  char ch = getch();
  
  /* Main Game Loop */
  while(ch != 'Q'){
    handleInput(ch, user, doors, map -> trapdoors, level, map);
    displayPlayerInfo(user);
    ch = getch();
  }
  
  endwin();
  
  return 0;
}

int screenSetUp(){
  initscr();
  noecho();
  refresh();
  
  return 0;
}
