#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

/* Turning input into action */
int handleInput(char input, Player * user, Door ** doors, Door ** trapdoors){
  int newX;
  int newY;

  bool isTrapdoor;
  
  switch(input){
    // Left
    case 'h':
      newY = user -> position.y;
      newX = user -> position.x - 1;
      isTrapdoor = false;
      break;
    
    // Down
    case 'j':
      newY = user -> position.y + 1;
      newX = user -> position.x;
      isTrapdoor = true;
      break;
    
    // Up
    case 'k':
      newY = user -> position.y - 1;
      newX = user -> position.x;
      isTrapdoor = true;
      break;
    
    // Right
    case 'l':
      newY = user -> position.y;
      newX = user -> position.x + 1;
      isTrapdoor = false;
      break;

    case 'o':
      mvprintw(0, 0, "Which direction.");
      char ch = getch();

      switch(ch){
        case 'h':
          isTrapdoor = false;
          changeDoorState(user -> position.y, user -> position.x - 1, doors, isTrapdoor, true);
          break;

        case 'j':
          isTrapdoor = true;
          changeDoorState(user -> position.y + 1, user -> position.x, trapdoors, isTrapdoor, true);
          break;

        case 'k':
          isTrapdoor = true;
          changeDoorState(user -> position.y - 1, user -> position.x, trapdoors, isTrapdoor, true);
          break;

        case 'l':
          isTrapdoor = false;
          changeDoorState(user -> position.y, user -> position.x + 1, doors, isTrapdoor, true);
          break;

        default:
          mvprintw(0, 0, "That is not a direction.");
          break;
      }

      break;

    case 'c':
      mvprintw(0, 0, "Which direction.");
      char c = getch();

      switch(c){
        case 'h':
          isTrapdoor = false;
          changeDoorState(user -> position.y, user -> position.x - 1, doors, isTrapdoor, false);
          break;

        case 'j':
          isTrapdoor = true;
          changeDoorState(user -> position.y + 1, user -> position.x, trapdoors, isTrapdoor, false);
          break;

        case 'k':
          isTrapdoor = true;
          changeDoorState(user -> position.y - 1, user -> position.x, trapdoors, isTrapdoor, false);
          break;

        case 'l':
          isTrapdoor = false;
          changeDoorState(user -> position.y, user -> position.x + 1, doors, isTrapdoor, false);
          break;

        default:
          mvprintw(0, 0, "That is not a direction.");
          break;
      }

      break;

    
    default:
      break;
  }

  Door ** inputDoors;
  if (isTrapdoor) {
    inputDoors = malloc(sizeof(Door) * 2);
    inputDoors = trapdoors;
  } else {
    inputDoors = malloc(sizeof(Door) * 6);
    inputDoors = doors;
  }

  Door * targetDoor;
  targetDoor = malloc(sizeof(Door));
  targetDoor = checkDoorPositionAgainstPosition(newY, newX, inputDoors, isTrapdoor);
  
  checkPosition(newY, newX, user, targetDoor);

  return 0;
}

/* Collision detection */
int checkPosition(int newY, int newX, Player * user, Door * targetDoor){
  char nextTile;
  nextTile = mvinch(newY, newX);

  char tileBelow;
  tileBelow = mvinch(newY + 1, newX);


  switch (nextTile){
    case '=':
      switch (user -> tile.tile) {
        case '=':
          playerMove(newY, user -> position.x, user, '=');
          break;

        case '`':
          if((tileBelow == '=') || (tileBelow == '@')){
            playerMove(newY, user -> position.x, user, '=');
          } else {
            playerMove(user -> position.y, newX, user, '=');
          }

          break;

        case '.':
          playerMove(user -> position.y, newX, user, '=');
          break;
      }
      break;

    case '`':
      switch (user -> tile.tile) {
        case '=':
          if((tileBelow == '@') || (tileBelow == '=')){
            playerMove(newY, user -> position.x, user, '`');
          } else {
            playerMove(user -> position.y, newX, user, '`');
          }
          break;

        case '.':
          if(tileBelow == '='){
            playerMove(newY, user -> position.x, user, '`');
          } else {
            playerMove(user -> position.y, newX, user, '`');
          }
          break;

        default:
          break;
      }
      break;

    case '.':
      switch (user -> tile.tile) {
        case '=':
          if (tileBelow != '.'){
            playerMove(user -> position.y, newX, user, '.');
          }
          break;

        case '.':
          playerMove(user -> position.y, newX, user, '.');
          break;

        case '`':
          if(tileBelow == '@') {
            playerMove(newY, user -> position.x, user, '.');
          } else {
            playerMove(user -> position.y, newX, user, '.');
          }

        default:
          break;
      }
      break;
    default:
      break;
  }
  
  move(user -> position.y, user -> position.x);

  return 0;
}

int changeDoorState(int y, int x, Door ** doors, bool isTrapdoor, bool openDoor) {
  Door * door;
  door = malloc(sizeof(Door));

  door = NULL;

  door = checkDoorPositionAgainstPosition(y, x, doors, isTrapdoor);

  if(door == NULL) {
    mvprintw(0, 0, "There is no door at that position.");
  } else {
    if(openDoor){
      door -> isOpen = true;
    } else {
      door -> isOpen = false;
    }
  }

  drawDoor(door);

  return 0;
}
