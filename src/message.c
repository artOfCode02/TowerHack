/**
 * @file message.c
 * @brief Simple message allocation and display helpers.
 */

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"


Message *newMessage(int ID) {
  Message *msg = malloc(sizeof(Message));
  if (!msg) return NULL;

  msg->messageID = ID;
  msg->messageContent = NULL;

	switch (ID) {
		case 1:
			msg->messageContent = strdup("Really save and quit game? [Y/n]");
			break;
		case 2:
			msg->messageContent = strdup("In which direction?");
			break;
		default:
			msg->messageContent = strdup("");
			break;
	}

	return msg;
}

int emitMessage(Message *message){
	if (!message) return -1;
	mvprintw(0, 0, "%s", message->messageContent ? message->messageContent : "");
	return 0;
}
