#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "level.h"
#include "player.h"

int screenSetUp();

int handleInput(char input, Player * user);
int checkPosition(int newY, int newX, Player * user);

int main(int argc, char * argv[]){
  Player * user;
  Room ** map;
  
  screenSetUp();
  map = mapSetUp();
  
  user = playerSetUp();
  playerStartPos(map, user);
  playerMoveStart(user);

  char ch = getch();
  
  /* Main Game Loop */
  while(ch != 'Q'){
    handleInput(ch, user);
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

/* Turning input into action */
int handleInput(char input, Player * user){
  int newX;
  int newY;
  
  switch(input){
    // Left
    case 'H':
    case 'h':
      newY = user -> position.y;
      newX = user -> position.x - 1;
      break;
    
    // Down
    case 'j':
    case 'J':
      newY = user -> position.y + 1;
      newX = user -> position.x;
      break;
    
    // Up
    case 'k':
    case 'K':
      newY = user -> position.y - 1;
      newX = user -> position.x;
      break;
    
    // Right
    case 'l':
    case 'L':
      newY = user -> position.y;
      newX = user -> position.x + 1;
      break;
    
    default:
      break;
  }
  
  checkPosition(newY, newX, user);
}

/* Collision detection */
int checkPosition(int newY, int newX, Player * user){
  int space;
  switch (mvinch(newY, newX)) {
    case '.':
      playerMove(user -> position.y, newX, user);
      break;
    default:
      break;
  }

  move(user -> position.y, user -> position.x);
}
