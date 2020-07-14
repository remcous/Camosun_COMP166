/*
*	Source file containing definitions for vectorMath.h a vector mathematics library
*/

/* 
* File:   vectorMath.c
* Author: Remi Coussement
*         C0450402
*
* Created on March 13, 2017, 2:57 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

/* Perform math on the contents of two vectors and put the result in the
 * third vector.
 * The mathematical operator 'op' must be one of '+', '-', '*', '/'.
 * If the vectors are of incompatible size or if the operator is
 * invalid, the return value is NULL */
Vector *vectorMath (const Vector v1, const Vector v2, Vector *result, const char op){
	// if the input vectors have a different size return NULL
	// to indicate that operation cannot be performed
	if(v1.vector_size != v2.vector_size){
		return NULL;
	}

	// sets the vector_size argument for the result Vector
	(*result).vector_size = v1.vector_size;

	// checks the char op against specific mathematical operators and performs the associated operation
	switch(op){
		case '+':
			for(int i = 0; i < v1.vector_size; i++){
				(*result).words[i] = v1.words[i] + v2.words[i];
			}
			break;
		case '-':
			for(int i = 0; i < v1.vector_size; i++){
				(*result).words[i] = v1.words[i] - v2.words[i];
			}
			break;
		case '/':
			for(int i = 0; i < v1.vector_size; i++){
				(*result).words[i] = (double)v1.words[i] / (double)v2.words[i];
			}
			break;
		case '*':
			for(int i = 0; i < v1.vector_size; i++){
				(*result).words[i] = v1.words[i] * v2.words[i];
			}
			break;
		default:
			fprintf(stderr, "Error: Invalid operator \"%c\"\n", op);
			return NULL;
	}

	// returns a non-null Vector* to signify that the operation was performed successfully
	return result;
}

/* Print the values in a Vector using the print format WORD_FORMAT */
void printVector (const Vector v){
	// Loop iterates through the elements of the vector and prints them to the console
	for(int i = 0; i < v.vector_size; i++){
		printf(WORD_FORMAT, *(v.words)+i);
	}
	printf("\n");
} 