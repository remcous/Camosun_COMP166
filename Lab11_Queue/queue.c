#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue (Queue *queue, ItemType *item){
	// dynamically allocates memory for a new ListNode
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

	// If malloc fails to allocate a new block of memory, return the NULL address
	if(newNode == NULL){
		return NULL;
	}

	// sets the newNode to have the NULL pointer in next, and the argument item in its item member
	newNode->next=NULL;
	newNode->item=item;
	
	// checks if the queue contains Nodes and sets the next member of the rear Node to the newNode
	// otherwise if there are no Nodes and sets the node as the front of the queue
	if(queue->size>0){
		queue->rear->next=newNode;
	}
	else{
		queue->front=newNode;
	}

	// sets the newNode as the rear of the queue and increments the size member
	queue->rear=newNode;
	queue->size++;
	
	// returns the value of the new rear member of the queue's item member
	return queue->rear->item;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queue){
	// if the queue doesn't contain objects return NULL
	if(queue->size == 0){
		return NULL;
	}

	// creates local variables to hold the queue's former front and front item members
	ItemType *thing = queue->front->item;
	ListNode *oldFront = queue->front;

	// Sets the front of the queue to be the ListNode held in the next member of the front Node
	// and then decrements the size member
	queue->front = queue->front->next;
	queue->size--;

	// frees up the dynamically allocated member
	free((void*)oldFront);

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
		dequeue(&tempQueue);
		fprintf(stream, "\n");
	}
}