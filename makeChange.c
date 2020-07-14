/*
 * Program to compute change due after a purchase
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
#include "changeItem.h"

int main(int argc, char** argv) {
	double price, tendered, changeDue;

	// Prompts the user for the purchase amount, and ensures a positive value
	do{
		printf("Enter the amount of the purchase: ");
		scanf("%lf", &price);
	}while(price < 0);

	// Prompts the user for the amount tendered, and ensures it is larger than price
	do{
		printf("Enter the amount tendered: ");
		scanf("%lf", &tendered);
	}while(tendered < price);

	// Calculates the change due on the purchase
	changeDue = tendered - price;
	printf("Change due is: $%.2lf\n", changeDue);

	// Calculates the change due to the nearest nickel (pennies don't exist)
	changeDue = 0.05 * (int)(changeDue / 0.05 + 0.5);
	printf("Rounded to the nearest nickel $%.2lf\n", changeDue);

	// Call the change function for every denomination of change
	changeDue = changeItem(changeDue,20,"Twenty","Twenties");
	changeDue = changeItem(changeDue,10,"Ten","Tens");
	changeDue = changeItem(changeDue,5,"Five","Fives");
	changeDue = changeItem(changeDue,2,"Toonie","Toonies");
	changeDue = changeItem(changeDue,1,"Loonie","Loonies");
	changeDue = changeItem(changeDue,0.25,"Quarter","Quarters");
	changeDue = changeItem(changeDue,0.10,"Dime","Dimes");
	changeDue = changeItem(changeDue,0.05,"Nickel","Nickels");
}
