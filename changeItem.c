/*
 * Function definition for changeItem function
/*

/* 
 * File:   makeChange.c
 * Author: Remi Coussement
 *         C0450402
 *
 * Created on January 27, 2017, 11:25 AM
 */

 #include <stdio.h>
 #include <stdlib.h>

double changeItem (double change, const double itemValue,
		const char *singleName, const char *pluralName){
	// computes the number of denominations of the change
	int numOfChangeItems = change / itemValue;
	
	change -= numOfChangeItems * itemValue;

	if(numOfChangeItems == 1){
		printf("%d %s\n", numOfChangeItems, singleName);
	}
	else{
		printf("%d %s\n", numOfChangeItems, pluralName);
	}
	return change;
}