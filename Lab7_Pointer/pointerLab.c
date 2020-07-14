/*
 * Uses typedef, arrays, pointers and functions to manipulate data
 */

/* 
 * File:   pointerLab.c
 * Author: Remi Coussement
 *         C0450402
 *
 * Created on March 7, 2017, 1:28 PM
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of constants
#ifndef START
#define START 1011
#endif	// START

const int N_NUMS = 10;

// User defined name for variable of type int
typedef int WORD;
#define WORD_FORMAT "%d "

void swap (WORD *x, WORD *y);
void printVector (const WORD *vec, const int N);
void printBytes (const WORD *vec, const int N);
void printVectorReverseEndian (const WORD *vec, const int N);

int main(){
	WORD words[N_NUMS];

	// Sets the values for the array of WORD variables
	for(int i = 0; i < N_NUMS; i++){
		words[i] = START + i;
	}

	// prints the original vector of WORD variables using printVector()
	printf("Original Vector:\n");
	printVector(words, sizeof(words)/sizeof(WORD));
	printf("\n");

	// Swaps the order of adjacent values in the WORD array
	for(int i = 1; i < N_NUMS; i+=2){
		swap(words+i, words-1+i);
	}

	// Prints the values that have been swapped using printVector
	printf("Adjacent words swapped:\n");
	printVector(words, sizeof(words)/sizeof(WORD));
	printf("\n");
	
	// Swaps the order of adjacent values in the WORD array 
	// to get back to the original order
	for(int i = 1; i < N_NUMS; i+=2){
		swap(&words[i], &words[i-1]);
	}

	// Prints the WORD array that has been swapped twice
	printf("Words swapped back:\n");
	printVector(words, sizeof(words)/sizeof(WORD));
	printf("\n");

	// Prints the WORD array as a series of bytes
	printf("Data Bytes:\n");
	printBytes(words, sizeof(words)/sizeof(WORD));
	printf("\n");

	// Prints the WORD array as a series of bytes in reverse endian order
	printf("Word bytes with endian reversal:\n");
	printVectorReverseEndian(words, sizeof(words)/sizeof(WORD));
	printf("\n");

	return 0;
}

/* Swap the values pointed at by x and y */
void swap (WORD *x, WORD *y){
	WORD temp = *x;
	*x=*y;
	*y=temp;
}

/* Print all of the values in a 1-D array where the array size is N
 * and WORD_FORMAT has been #define'd */
void printVector (const WORD *vec, const int N){
	for(int i = 0; i < N; i++){
		printf(WORD_FORMAT, *(vec+i));
	}
}

/* Print all of the values in a 1-D array one byte at a time where the
 * array size is N.
 * Prints an extra space after each word */
void printBytes (const WORD *vec, const int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < sizeof(vec[0])/sizeof(char); j++){
			printf(WORD_FORMAT, (*(vec)+i >> (8*j)) & 0xff);
		}
		printf(" ");
	}
}

/* Print all of the values in a 1-D array one byte at a time in reverse
 * byte order for each word where the array size is N.
 * Prints an extra space after each word */
void printVectorReverseEndian (const WORD *vec, const int N){
	for(int i = 0; i < N; i++){
		for(int j = sizeof(vec[0])/sizeof(char) -1; j>=0; j--){
			printf(WORD_FORMAT, (*(vec)+i >> (8*j)) & 0xff);
		}
		printf(" ");
	}
}