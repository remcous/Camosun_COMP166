/*
 * Program to open a file, input numerical values, and determine the mean
 * and standard deviation of the set
 * Correct terminal command to open a specific file: ./statsMain numbers.txt
 */

/* 
 * File:   statsMain.c
 * Author: Remi Coussement
 *         C0450402
 *
 * Created on January 31, 2017, 8:13 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"

// function prototype for printStats()
void printStats (FILE *dest, const int count, const double mean,
const double ssdev);

int main(int argc, char** argv) {
    double sum = 0, sumsq = 0, input;
    int count = 0;
    char destName[50];
    
    // Determines if enough command line arguments were entered
    if(argc>1){
        // Opens the file specified on command line for reading
        FILE *fp = fopen(argv[1], "r");
        
        // Determines if the file opened correctly
        if(fp != NULL){
            // input values from file one by one
            while(fscanf(fp, "%lf", &input) != EOF){
                count++;
                sum += input;
                sumsq += (input * input);
            }
            
            // closes input file and frees fp
            fclose(fp);
            
            if(count < 2){
                printf("%s: Invalid file - less than 2 values in file", argv[0]);
            }
            else{
                // stores the filename of the destination file in a char array
                strcpy(destName, "Result_");
                strcat(destName, argv[1]);

                // opens destination file at destName for writing
                fp = fopen(destName, "w");

                if(fp != NULL){
                    // calls the printStats function for the data set
                    printStats(fp, count, mean(sum, count), ssdev(sum, sumsq, count));
                }
                else{
                    printf("%s: Unable to open destination file: %s\n", argv[0], destName);
                }

                fclose(fp);
            }
        }
        else{
            // informs the user that the file was not found
            printf("%s: Unable to open input file \"%s\"\n", argv[0], argv[1]);
        }
        
        fclose(fp);
    }
    else{
        // informs the user that they did not
        printf("%s: Invalid input - no filename argument\n", argv[0]);
    }
    
    return EXIT_SUCCESS;
}

// Function definition for printStats, which will print the statistics
// for the data set to console AND to a output file
void printStats (FILE *dest, const int count, const double mean,
const double ssdev){
    // Outputs the statistic results to the console
    printf("%d Values, Mean = %lf, Sample Standard Deviation = %lf\n", count, mean, ssdev);
    
    // Outputs the statistic results to the output file defined by dest
    fprintf(dest, "%d Values, Mean = %lf, Sample Standard Deviation = %lf\n", count, mean, ssdev);
}