/*
* 
*/

/* 
* File:   vectorMain.c
* Author: Remi Coussement
*         C0450402
*
* Created on March 13, 2017, 2:57 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

int main(){
	Vector v1 = {1.0,4.0,-7.2,-6.6,1.23};
	Vector v2 = {-5.2,11.1,0.1,9.9,7.123};
	Vector r;

	printf("Vector #1\t");
	printVector(v1);
	
	printf("Vector #2\t");
	printVector(v2);

	printf("Sum\t\t");
	vectorMath(v1, v2, &r, '+');
	printVector(r);

	printf("Difference\t");
	vectorMath(v1, v2, &r, '-');
	printVector(r);

	printf("Product\t\t");
	vectorMath(v1, v2, &r, '*');
	printVector(r);

	printf("Quotient\t");
	vectorMath(v1, v2, &r, '/');
	printVector(r);

	return 0;
}