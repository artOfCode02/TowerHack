#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Room{
  int xPosition;
  int yPosition;

  int height;
  int width;

  // Monster ** monsters;
  // Item ** items;
} Room;

typedef struct Player{
  int xPosition;
  int yPosition;
  int health;
} Player;

Player * playerSetUp();

int screenSetUp();
int mapSetUp();

int handleInput(char input, Player * user);
int playerMove(int yPosition, int xPosition, Player * user);
int checkPosition(int newY, int newX, Player * user);

int main(){
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
  printw("Hello Screen!");
  noecho();
  refresh();
  
  return 0;
}

int mapSetUp(){
  mvprintw(13, 13, "#-^------------------------------------------#");
  mvprintw(14, 13, "#.=...=.......................=..............#");
  mvprintw(15, 13, "#-----=.......................=--------------#");
  mvprintw(16, 13, "#.....=.......................=..............#");
  mvprintw(17, 13, "#.....=..................=....=..............#");
  mvprintw(18, 13, "#.....=................--=-----..............#");
  mvprintw(19, 13, "#.....=...........=......=...................#");
  mvprintw(20, 13, "#-----------------=......=...................#");
  mvprintw(21, 13, "#.................=......=...................#");
  mvprintw(22, 13, "#.................=......=...................#");
  mvprintw(23, 13, "#--------------------------------------------#");
  
  /*
  mvprintw(2, 40, "-----------");
  mvprintw(3, 40, "|.........|");
  mvprintw(4, 40, "|.........|");
  mvprintw(5, 40, "|.........|");
  mvprintw(6, 40, "|.........|");
  mvprintw(7, 40, "-----------");
  
  mvprintw(10, 40, "--------");
  mvprintw(11, 40, "|......|");
  mvprintw(12, 40, "|......|");
  mvprintw(13, 40, "|......|");
  mvprintw(14, 40, "|......|");
  mvprintw(15, 40, "|......|");
  mvprintw(16, 40, "--------"); */
}

Player * playerSetUp(){
  Player * newPlayer;
  newPlayer = malloc(sizeof(Player));
  
  newPlayer -> health = 20;
  
  playerMove(22, 14, newPlayer);
  
  return newPlayer;
}

int handleInput(char input, Player * user){
  int newX;
  int newY;
  
  switch(input){
    //Left
    case 'H':
    case 'h':
      newY = user -> yPosition;
      newX = user -> xPosition - 1;
      break;
    
    //Down
    case 'j':
    case 'J':
      newY = user -> yPosition + 1;
      newX = user -> xPosition;
      break;
    
    //Up
    case 'k':
    case 'K':
      newY = user -> yPosition - 1;
      newX = user -> xPosition;
      break;
    
    //Right
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

int playerMove(int y, int x, Player * user){
  if (mvinch(user -> yPosition, user -> xPosition) == "=") {
    mvprintw(user -> yPosition, user -> xPosition, "=");
  } else {
  mvprintw(user -> yPosition, user -> xPosition, ".");
  }

  user -> yPosition = y;
  user -> xPosition = x;
  
  mvprintw(user -> yPosition, user -> xPosition, "@");
  move(user -> yPosition, user -> xPosition);
  
  return 0;
}
