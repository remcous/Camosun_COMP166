/*
*	Header file for a vector mathematics library
*/

/* 
* File:   vectorMath.h
* Author: Remi Coussement
*         C0450402
*
* Created on March 13, 2017, 2:57 PM
*/

#ifndef VECTORMATH_H
#define VECTORMATH_H

// Sets the variable type of the elements contained within a Vector object
#ifndef WORD
#error WORD must be defined
//#define WORD double
#endif	// VECTOR

// Sets the print arguments for a printf of an element in the Vector array
#ifndef WORD_FORMAT
#error WORD_FORMAT must be defined
//#define WORD_FORMAT "% 8.4lf "
#endif	// WORD_FORMAT

// sets the maximum number of elements that can be held in the 
// array words of a Vector struct
#ifndef VECTORMAX
#define VECTORMAX 8
#endif	// VECTORMAX

// Definition for the new variable type Vector
typedef struct{
	int vector_size;
	WORD words[VECTORMAX];
}Vector;

/* Perform math on the contents of two vectors and put the result in the
 * third vector.
 * The mathematical operator 'op' must be one of '+', '-', '*', '/'.
 * If the vectors are of incompatible size or if the operator is
 * invalid, the return value is NULL */
Vector *vectorMath (const Vector v1, const Vector v2, Vector *result, const char op);

/* Print the values in a Vector using the print format WORD_FORMAT */
void printVector (const Vector v);

#endif	// VECTORMATH_H