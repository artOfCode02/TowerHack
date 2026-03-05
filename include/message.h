/**
 * @file message.h
 * @brief Simple message helper types and stubs.
 */

#pragma once

/**
 * @struct Message
 * @brief Lightweight message container (not fully used yet).
 */
typedef struct Message {
	/** Numeric message identifier */
	int messageID;
	/** Human-readable message content */
	char *messageContent;
} Message;

/* Function Declarations */
/**
 * @brief Allocate a new Message for the provided ID.
 * @param ID Message identifier.
 * @return Pointer to newly allocated Message or NULL.
 */
Message *newMessage(int ID);

/**
 * @brief Emit or display a Message (stubbed).
 * @param message Pointer to the Message to emit.
 * @return 0 on success.
 */
int emitMessage(Message *message);
