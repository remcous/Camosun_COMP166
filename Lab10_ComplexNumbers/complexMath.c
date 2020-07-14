/*
*	Program to test the functions contained in the complex.h library for complex number arithmetic
*/

/* 
* File:   complexMath.c
* Author: Remi Coussement
*         C0450402
*
* Created on March 15, 2017, 11:08 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

// defines the printout format for a complex number to be a+bi
#define Z_FORMAT "%9.4lf%+9.4lfi"

int main(int argc, char** argv){
	Complex x,y,r;
	char ignored;

	// Checks that the command line arguments are exactly equal to 3, meaning two potential complex number arguments
	if(argc != 3){
		fprintf(stderr, "%s: Error - Invalid command line arguments\n"
						"Usage example - ./complexMath 5.4-23.4i -5.32+2.1j\n", argv[0]);
		return 1;
	}

	// Parses the command line argument to assign values to the Complex structs x and y respectively
	if(sscanf(argv[1], "%lf%lf[ij]", &x.re, &x.im, &ignored) != 2){
		fprintf(stderr, "%s: Error - Command line argument could not be read correctly\n", argv[0]);
		return 1;
	}
	if(sscanf(argv[2], "%lf%lf[ij]", &y.re, &y.im, &ignored) != 2){
		fprintf(stderr, "%s: Error - Command line argument could not be read correctly\n", argv[0]);
		return 1;
	}

	// prints the Complex structs x and y
	printf("x\t\t= " Z_FORMAT "\n", x.re, x.im);
	printf("y\t\t= " Z_FORMAT "\n", y.re, y.im);

	// performs a complex addition and prints the resultant
	r = add(x,y);
	printf("Sum\t\t= " Z_FORMAT "\n", r.re, r.im);

	// performs a complex subtraction and prints the resultant
	r = subtract(x,y);
	printf("Difference\t= " Z_FORMAT "\n", r.re, r.im);

	// performs a complex multiplication and prints the resultant
	r = multiply(x,y);
	printf("Product\t\t= " Z_FORMAT "\n", r.re, r.im);

	// performs a complex division and prints the resultant
	r = divide(x,y);
	printf("Quotient\t= " Z_FORMAT "\n", r.re, r.im);

	// returns the complex conjugate of x and y respectively and prints them
	r = conjugate(x);
	printf("x conjugate\t= " Z_FORMAT "\n", r.re, r.im);
	r = conjugate(y);
	printf("y conjugate\t= " Z_FORMAT "\n", r.re, r.im);

	// prints the magnitude and angle for the complex numbers x and y on a complex plane
	printf("x: Magnitude \t= %9.4lf, Angle = %9.4lf rads\n", magnitude(x), angle(x));
	printf("y: Magnitude \t= %9.4lf, Angle = %9.4lf rads\n", magnitude(y), angle(y));

	return 0;
}