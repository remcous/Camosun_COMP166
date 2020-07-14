/* 
 * File:   main.c
 * Author: Coussement, Remi
 *         C0450402
 * Due: February 1, 2017
 *
 * Created on January 16, 2017, 3:53 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    double inputTemp, kelvin, celsius, fahrenheit;
    char line[11];
    
    // Inputs the temperature and unit from the user
    printf("Enter a temperature followed by F, C, or K. eg., 24.5F :");
    scanf("%lf%10s", &inputTemp, line);
    
    // Handles the conversion depending upon which temperature unit is used
    switch(line[0]){
        case 'f':
        case 'F':   // data input in Fahrenheit
            fahrenheit = inputTemp;
            celsius = (fahrenheit - 32) * 5/9;
            kelvin = celsius + 273.15;
            printf("%8.3lfK = %8.3lfC = %8.3lfF\n", kelvin, celsius, fahrenheit);
            break;
        case 'c':
        case 'C':   // data input in Celsius
            celsius = inputTemp;
            fahrenheit = (celsius * 9/5) + 32;
            kelvin = celsius + 273.15;
            printf("%8.3lfK = %8.3lfC = %8.3lfF\n", kelvin, celsius, fahrenheit);
            break;
        case 'k':
        case 'K':   // data input in Kelvin
            kelvin = inputTemp;
            celsius = kelvin - 273.15;
            fahrenheit = (celsius * 9/5) + 32;
            printf("%8.3lfK = %8.3lfC = %8.3lfF\n", kelvin, celsius, fahrenheit);
            break;
        default:    // invalid unit input
            printf("Unknown temperature type '%c'\n", line[0]);
    }
    
    return (EXIT_SUCCESS);
}

