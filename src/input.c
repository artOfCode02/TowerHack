#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "message.h"
/**
 * @file input.c
 * @brief Handle player input, door interactions and collision detection.
 */

/**
 * @copydoc handleInput
 */
int handleInput(char input, Player *user, Door **doors, Door **trapdoors, Room **level, Map *map){
  int newY = user->position.y;
  int newX = user->position.x;
  bool isTrapdoor = false;

  /* Direction offsets for movement */
  int offY = 0, offX = 0;

  switch (input) {
    case 'h': offY = 0;  offX = -1; isTrapdoor = false; break; // left
    case 'j': offY = +1; offX = 0;  isTrapdoor = true;  break; // down
    case 'k': offY = -1; offX = 0;  isTrapdoor = true;  break; // up
    case 'l': offY = 0;  offX = +1; isTrapdoor = false; break; // right

    case 'o': // open door in a direction
    case 'c': { // close door in a direction
      mvprintw(0, 0, "Which direction (h/j/k/l)?");
      int dir = getch();

      switch (dir) {
        case 'h': offY = 0;  offX = -1; isTrapdoor = false; break;
        case 'j': offY = +1; offX = 0;  isTrapdoor = true;  break;
        case 'k': offY = -1; offX = 0;  isTrapdoor = true;  break;
        case 'l': offY = 0;  offX = +1; isTrapdoor = false; break;
        default:
          mvprintw(0, 0, "That is not a direction.");
          move(user->position.y, user->position.x);
          return 0;
      }

      int ty = user->position.y + offY;
      int tx = user->position.x + offX;
      Door **searchDoors = isTrapdoor ? trapdoors : doors;

      changeDoorState(ty, tx, searchDoors, isTrapdoor, input == 'o');
      // clear prompt and return
      mvprintw(0, 0, "                ");
      move(user->position.y, user->position.x);
      return 0;
    }

    default:
      // unsupported input -> no action
      return 0;
  }

  // For movement keys, compute target and resolve collision
  newY += offY;
  newX += offX;

  // clear any top-line prompt
  int curY, curX;
  getyx(stdscr, curY, curX);
  move(0, 0);
  clrtoeol();
  move(curY, curX);

  Door **searchDoors = isTrapdoor ? trapdoors : doors;
  Door *targetDoor = fetchDoorFromDoorArrayUsingPosition(newY, newX, searchDoors, isTrapdoor);

  checkPosition(newY, newX, user, targetDoor, level, map, doors);

  // ensure cursor is on player
  mvprintw(0, 0, "                ");
  move(user->position.y, user->position.x);

  return 0;
}

/**
 * @brief Check the tile at a proposed location and resolve movement/collisions.
 */
/**
 * @copydoc checkPosition
 */
int checkPosition(int newY, int newX, Player *user, Door *targetDoor, Room **level, Map *map, Door **doors){
  // Get the tile type of the target position
  char nextTile = (char)mvinch(newY, newX);

  // Get the current tile type under the player (for movement logic)
  char currentTile = user->tile.tile;

  // Get the tile type of the position below the target (for trapdoor and ladder logic)
  char tileBelow = (char)mvinch(newY + 1, newX);

  // Get current x and y
  int currentY = user->position.y;
  int currentX = user->position.x;

  /* Main switch statement to determine if the player can move to the target position,
     based on the tile types and any doors present */
  switch (nextTile){

    case '=':
      switch (currentTile) {
        case '`':
          if (tileBelow == '@' || tileBelow == '=') playerMove(newY, currentX, user, '=');
          else                                      playerMove(currentY, newX, user, '=');
          break;

        case '=': playerMove(newY, currentX, user, '='); break;
        case '.': playerMove(currentY, newX, user, '='); break;

        default: break;
      } 
      break;

    case '`':
      switch (currentTile) {
        case '=':
          if (tileBelow == '@' || tileBelow == '=') {
            playerMove(newY, user->position.x, user, '`');
          } else {
            playerMove(user->position.y, newX, user, '`');
          }
          break;

        case '.':
          if (tileBelow == '=') {
            playerMove(newY, user->position.x, user, '`');
          } else {
            playerMove(user->position.y, newX, user, '`');
          }
          break;

        default:
          break;
      }
      break;

    case '.':
      switch (currentTile) {
        case '=':
          if (tileBelow != '.') {
            playerMove(user->position.y, newX, user, '.');
          }
          break;

        case '.':
          playerMove(user->position.y, newX, user, '.');
          break;

        case '`':
          if (tileBelow == '@') {
            playerMove(newY, user->position.x, user, '.');
          } else {
            playerMove(user->position.y, newX, user, '.');
          }

        default:
          break;
      }
      break;

     case '^':
       if (newY < user->position.y) {
         user->towerLevel++;
       } else {
         user->towerLevel--;
       }

       level = mapSetUp();
       doors = makeLevelDoors();
       map = makeMap(level);

       playerStartPos(level, user);
       playerMoveStart(user);

       if (user->towerLevel != 1)
         mvprintw(user->position.y + 1, user->position.x, "^");
    
       break;
       
    default:
      break;
  }
  
  move(user->position.y, user->position.x);

  return 0;
}

/**
 * @brief Open or close a door at the given coordinates.
 */
/**
 * @copydoc changeDoorState
 */
int changeDoorState(int y, int x, Door **doors, bool isTrapdoor, bool openDoor) {
  Door *door = fetchDoorFromDoorArrayUsingPosition(y, x, doors, isTrapdoor);

  if (!door) return -1;

  if (openDoor) {
    door->isOpen = true;
  } else {
    door->isOpen = false;
  }

  drawDoor(door);

  return 0;
}
