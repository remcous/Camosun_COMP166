#include <stdio.h>
#include <stdlib.h>
#include "arraySearch.h"

/* Search an array for a given value.
 * A linear search is used, so the data need not be sorted
 * Returns: the zero-based index of the number (if found)
 * otherwise -1
 */
int linearSearch (const int value, const int numbers[], const int
nNumbers){
	int i;

	// loop will return the array location of a value if it is contained in the array
	for(i = 0; i < nNumbers; i++){
		if(value == numbers[i]){
			return i;
		}
	}

	// if the value is not found within the array return -1
	return -1;
}