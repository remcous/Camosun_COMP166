/*
 * Function definitions for deque.h a double ended queue library
*/

/* 
* File:   deque.h
* Author: Remi Coussement
*         C0450402
*
* Created on March 22, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue (Queue *queue, ItemType *item, int enqueueFront){
	// dynamically allocates memory for a new ListNode
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

	// If malloc fails to allocate a new block of memory, return the NULL address
	if(newNode == NULL){
		return NULL;
	}

	// sets the newNode item member as the function argument item
	newNode->item = item;

	// Handles the case of a queue with no elements in it
	if(queue->size == 0){
		// sets the newNode to have NULL pointers in its next and prev members
		newNode->next = NULL;
		newNode->prev = NULL;

		// sets the newNode as the front and rear of the queue
		queue->front = newNode;
		queue->rear = newNode;
		queue->size++;

		// returns the item member of the newly added queue member
		return queue->front->item;
	}

	// Tests the condition to determine if the newNode is to be added to the front
	// or the rear of the queue
	if(enqueueFront){
		// sets the newNode to have its next member as the current queue front
		newNode->next = queue->front;
		newNode->prev = NULL;

		// sets the newNode as the new front of the queue with the previous front as the prev
		queue->front->prev = newNode;
		queue->front = newNode;
		queue->size++;

		// returns the item member of the newly added front queue member
		return queue->front->item;
	}
	else{
		// sets the newNode to have its prev member as the current queue rear
		newNode->prev = queue->rear;
		newNode->next = NULL;

		// sets the newNode as the new rear of the queue with the previous rear as the next
		queue->rear->next = newNode;
		queue->rear = newNode;
		queue->size++;

		// return the item member of the newly added rear queue member
		return queue->rear->item;
	}
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queue, int dequeueFront){
	// if the queue doesn't contain objects return NULL
	if(queue->size == 0){
		return NULL;
	}

	// creates local variables to hold the queue's element to be removed and its item member
	ItemType *thing;
	ListNode *oldElement;

	if(dequeueFront){
		// sets the thing and oldElement placeholder as the item to be removed from the queue
		thing = queue->front->item;
		oldElement = queue->front;

		// sets the new front of the queue after removing the old front
		queue->front = queue->front->next;
	}
	else{
		// sets the thing and oldElement placeholder as the item to be removed from the queue
		thing = queue->rear->item;
		oldElement = queue->rear;

		// sets the new rear of the queue after removing the old rear
		queue->rear = queue->rear->prev;
	}

	// Decrements the queue size
	queue->size--;

	// frees up the dynamically allocated member
	free((void*)oldElement);

	// returns the value 
	return thing;
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue){
	// returns the size element of the queue
	return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream){
	Queue tempQueue = queue;
	while(tempQueue.size > 0){
		fprintf(stream, ITEM_FORMAT, *tempQueue.front->item);
		dequeue(&tempQueue, 1);
		fprintf(stream, "\n");
	}
}