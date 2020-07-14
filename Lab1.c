/* 
 * File:   main.c
 * Author: Coussement, Remi
 *         C0450402
 * Due: January 25, 2017
 *
 * Created on January 14, 2017, 1:54 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    double price, tendered, changeDue;
    int numOfChangeItems;

    // Prompts the user to input the price
    do {
        printf("Enter the amount of the purchase: ");
        scanf("%lf", &price);
    } while (price < 0);

    do {
        printf("Enter the amount tendered: ");
        scanf("%lf", &tendered);
    } while (tendered < 0 || tendered < price);

    // Calculates the amount of change due
    changeDue = tendered - price;
    printf("Change due is $%.2lf\n", changeDue);

    // Rounds the change due to the nearest nickel (pennies don't exist)
    changeDue = 0.05 * (int) (changeDue / 0.05 + 0.5);
    
    printf("Rounded to the nearest nickel $%.2lf\n", changeDue);

    // Calculates and outputs the amount 
    // of each denomination of currency 
    // to produce the correct change, 
    // using the largest denominations available
    numOfChangeItems = changeDue / 20;
    changeDue -= numOfChangeItems * 20;
    printf("%d Twenties\n", numOfChangeItems);
    numOfChangeItems = changeDue / 10;
    changeDue -= numOfChangeItems * 10;
    printf("%d Tens\n", numOfChangeItems);
    numOfChangeItems = changeDue / 5;
    changeDue -= numOfChangeItems * 5;
    printf("%d Fives\n", numOfChangeItems);
    numOfChangeItems = changeDue / 2;
    changeDue -= numOfChangeItems * 2;
    printf("%d Toonies\n", numOfChangeItems);
    numOfChangeItems = changeDue / 1;
    changeDue -= numOfChangeItems * 1;
    printf("%d Loonies\n", numOfChangeItems);
    numOfChangeItems = changeDue / .25;
    changeDue -= numOfChangeItems * .25;
    printf("%d Quarters\n", numOfChangeItems);
    numOfChangeItems = changeDue / .10;
    changeDue -= numOfChangeItems * .10;
    printf("%d Dimes\n", numOfChangeItems);
    numOfChangeItems = changeDue / .05;
    changeDue -= numOfChangeItems * .05;
    printf("%d Nickels\n", numOfChangeItems);

    return (EXIT_SUCCESS);
}

