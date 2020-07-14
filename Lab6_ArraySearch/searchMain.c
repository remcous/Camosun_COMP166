#include <stdio.h>
#include <stdlib.h>
#include "arraySearch.h"

int main(int argc, char** argv){
	int n_nums, address, value;
	char input[10];
	FILE *fp;

	// Checks that the correct number of command line arguments are used, otherwise
	// prints an error
	if(argc < 3){
		fprintf(stderr, "Usage: search numberFileName nNumbers\n", argv[0]);
		return -1;
	}

	// Opens the file specified in the first command line argument as a binary text file
	fp = fopen(argv[1], "rb");

	// Checks that the file has opened correctly, otherwise prints an error
	if(fp == NULL){
		fprintf(stderr, "%s: File \"%s\" could not be opened\n", argv[0], argv[1]);
		return -1;
	}

	// sets up the array to hold the number of values specified in the second
	// command line argument
	n_nums = atoi(argv[2]);
	int nums[n_nums];

	// reads the values from the file as a single continuous block of binary data
	fread(nums, sizeof(int), n_nums, fp);

	// closes the file, as the file operations are completed
	fclose(fp);
	
	// Loop to facilitate user interaction with the data in the array
	do{
		// gets user input for a value to search the array for as a character string
		printf("Enter the integer value to find (\'q\' to quit): ");
		scanf("%10s", input);

		// clears the buffer
		while(getchar() != '\n');

		// checks the exit condition of the loop and prints a message to the console
		if(input[0] == 'q'){
			printf("Bye\n");
		}
		else{
			// converts the input into an integer value
			value = atoi(input);

			// uses the linearSearch function to return the address of an integer
			// if it is contained in the array, alternatively returns -1
			address = linearSearch(value, nums, n_nums);
			
			// checks the value returned by the linearSearch function and prints an appropriate
			// message to the console
			if(address < 0){
				printf("%d was not found\n", value);
			}
			else{
				printf("%d was found at position %d\n", value, address);
			}
		}
	}while(input[0] != 'q');

	return 0;
}