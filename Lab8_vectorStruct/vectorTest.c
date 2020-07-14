/* 
 * Test the mathematical Vector functions in the library vectorMath.c
 *
 * Dale Shpak
 * June 17, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

int main (void) {
  Vector vec1 = {5, {1.0, 4.0, -7.2, -6.66, 1.23 }};
  Vector vec2 = {5, {-5.2, 11.1, 0.1, 9.9, 7.123 }};
  Vector vec3 = {7 };
  Vector result;

  printf("Vector #1  ");
  printVector (vec1);
  printf("Vector #2  ");
  printVector (vec2);

  // Check that the math operators work.
  if (vectorMath(vec1, vec2, &result, '+') != NULL) {
    printf ("Sum        ");
    printVector (result);
  } else {
    fprintf(stderr, "Addition failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '-') != NULL) {
    printf ("Difference ");
    printVector (result);
  } else {
    fprintf(stderr, "Subtraction failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '*') != NULL) {
    printf ("Product    ");
    printVector (result);
  } else {
    fprintf(stderr, "Kronecker product failed\n");
  }
  if (vectorMath(vec1, vec2, &result, '/') != NULL) {
    printf ("Quotient   ");
    printVector (result);
  } else {
    fprintf(stderr, "Division failed\n");
  }

  // Check that the error handling works - Negative Testing
  // 1) Vector size mismatch
  if (vectorMath(vec1, vec3, &result, '/') != NULL) {
    printf ("Quotient   ");
    printVector (result);
  } else {
    fprintf(stderr, "Division failed\n");
  }
  // 2) Invalid operator
  if (vectorMath(vec1, vec2, &result, '^') != NULL) {
    printf ("Exponent   ");
    printVector (result);
  } else {
    fprintf(stderr, "Exponentiation failed\n");
  }
  
  return EXIT_SUCCESS;

}
