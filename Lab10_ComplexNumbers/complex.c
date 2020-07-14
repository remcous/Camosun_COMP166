/*
*	Contains the function definitions for the complex.h library
*/

/* 
* File:   complex.c
* Author: Remi Coussement
*         C0450402
*
* Created on March 15, 2017, 11:08 PM
*/
#include <math.h>
#include <stdio.h>
#include "complex.h"

/* Function to perform addition of two complex numbers */
Complex add (const Complex a, const Complex b){
	Complex result={a.re+b.re, a.im+b.im};
	return result;
}

/* Function to perform subtraction of two complex numbers */
Complex subtract (const Complex a, const Complex b){
	Complex result={a.re-b.re, a.im-b.im};
	return result;
}

/* Function to perform multiplication of two complex numbers */
Complex multiply (const Complex a, const Complex b){
	Complex result;

	// calculates the product of two complex numbers using F.O.I.L
	result.re=a.re * b.re - a.im * b.im;
	result.im=a.re * b.im + a.im * b.re;

	return result;
}

/* Function to perform division of two complex numbers */
Complex divide (const Complex a, const Complex b){
	Complex result;

	// calculates the real and imaginary parts of the quotient of a and b
	result.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	result.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);

	return result;
}

/* Function to return the complex conjugate of a complex number */
Complex conjugate (const Complex a){
	Complex result = {a.re, -1 * a.im};
	return result;
}

/* Function to return the magnitude of a complex number */
double magnitude (const Complex a){
	return sqrt(a.re * a.re + a.im * a.im);
}
/* Returned angle must be in the correct quadrant! */
double angle (const Complex a){
	double value = atan(a.im/a.re);

	// corrects for the quadrant of the complex number
	if(a.re>=0){
		return value;
	}else{
		if(a.im >= 0){
			return M_PI - value;
		}
		else{
			return M_PI + value;
		}
	}
}