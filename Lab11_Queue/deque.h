/* Header file for a double ended queue data structure.
 * To be implemented using dynamic allocation.
*/

/* 
* File:   deque.h
* Author: Remi Coussement
*         C0450402
*
* Created on March 22, 2017
*/

#ifndef QUEUE_H
#define	QUEUE_H

#include <stdio.h>

// The following 3 lines must all be in agreement
typedef int ItemType;
#define ITEM_PROMPT "an integer"
#define ITEM_FORMAT "%d"

// A node for a singly-linked list
typedef struct listNode {
    struct listNode *next;
    struct listNode *prev;
    ItemType *item;
} ListNode;

// A queue data structure
typedef struct {
    ListNode *front;
    ListNode *rear;
    int size; // Number of items currently in the queue
} Queue;

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue (Queue *queue, ItemType *item, int enqueueFront);

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queue, int dequeueFront);

/* Returns:  number of items in the queue */
int queueSize (const Queue queue);

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream);

#endif	/* QUEUE_H */

