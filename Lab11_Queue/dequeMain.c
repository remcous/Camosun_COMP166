/*
* Program to test the double ended queue library deque.h
*/

/* 
* File:   dequeMain.c
* Author: Remi Coussement
*         C0450402
*
* Created on March 22, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(int argc, char *argv[]) {
	// Initializes a queue containing only NULL pointers and a size element set to 0
	Queue queue = {NULL, NULL, 0};
	int done = 0;

	// looping structure will iterate until user input changes the value of done to end loop
	while(!done){
		int choice, nValid, direction;

		// gets user input for what action should be performed, 
		// and ensures that exactly one value is input from the console
		do{
			printf("Enter 1 to add to queue or 0 to remove "
				"(-1 to quit): ");
			nValid = scanf("%d", &choice);
		}while(nValid != 1 || choice < -1 || choice > 1);

		// switch statement to perform the selected operation on the queue
		switch(choice){
			// case to handle removing a node from the queue
			case 0:{
				ItemType *item;

				// requests the user to select wether to remove from the front
				// or the rear of the queue
				printf ("Enter 1 to remove from front of queue, 0 for rear: ");
				if (scanf("%d", &direction) != 1) {
					fprintf(stderr, "Unable to read an Integer\n");
					break;
				}

				// informs the user if the dequeueing was successful or if the queue was empty
				if((item = dequeue(&queue, direction)) != NULL){
					printf("Removed " ITEM_FORMAT "\n", *item);
				}
				else{
					printf("Queue is empty\n");
				}
				break;
			}

			// case to handle adding a node to the queue
			case 1:{
				// dynamically allocates memory for an item to be held in the queue
				ItemType *item = malloc (sizeof(ItemType));

				// informs the user that there was an error allocating memory, and exits the program
				if (item == NULL) {
					fprintf(stderr, "%s: Error allocating memory for item.\n", argv[0]);
					return EXIT_FAILURE;
				}

				// gets a value for the dynamically allocated item, or informs the user that the input failed
				printf ("Enter " ITEM_PROMPT ": ");
				if (scanf(ITEM_FORMAT, item) != 1) {
					fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
					break;
				}

				// requests the user to select wether the new item should be placed in the front
				// or the rear of the queue
				printf ("Enter 1 to add to the front of queue, 0 for rear: ");
				if (scanf("%d", &direction) != 1) {
					fprintf(stderr, "Unable to read an Integer\n");
					break;
				}

				// informs the user if the enqueueing was successful, or memory could not be allocated
				if ((item = enqueue(&queue, item, direction)) != NULL) {
					printf("Added " ITEM_FORMAT "\n", *item);
				} else {
					fprintf(stderr, "%s: Error allocating memory to queue.\n", argv[0]);
					return EXIT_FAILURE;
				}
				break;
			}

			// handles the case to exit the looping structure
			case -1:{
				done = 1;
				break;
			}

			// informs the user that their choice was invalid
			default:
				printf("Invalid choice entered");
		}
	}

	// prints the remaining items in the queue
	printf ("Items remaining in the queue:\n");
	printQueue (queue, stdout);
	
	return 0;
}

