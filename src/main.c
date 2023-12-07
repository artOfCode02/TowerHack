#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "level.c"
#include "player.c"

int screenSetUp();

int handleInput(char input, Player * user);
int checkPosition(int newY, int newX, Player * user);

int main(int argc, char * argv[]){
  Player * user;
  
  screenSetUp();
  mapSetUp();
  
  user = playerSetUp();
  
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
      newY = user -> yPosition;
      newX = user -> xPosition - 1;
      break;
    
    // Down
    case 'j':
    case 'J':
      newY = user -> yPosition + 1;
      newX = user -> xPosition;
      break;
    
    // Up
    case 'k':
    case 'K':
      newY = user -> yPosition - 1;
      newX = user -> xPosition;
      break;
    
    // Right
    case 'l':
    case 'L':
      newY = user -> yPosition;
      newX = user -> xPosition + 1;
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
      playerMove(user -> yPosition, newX, user);
      break;
    default:
      break;
  }
}
