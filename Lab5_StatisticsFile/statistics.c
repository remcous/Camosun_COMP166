/*
 * Function definitions for statistics.h functions
 */

/* 
 * File:   statistics.c
 * Author: Remi Coussement
 *         C0450402
 *
 * Created on January 31, 2017, 8:13 AM
 */

#include <math.h>

/* Compute mean from sum and count */
double mean(const double sum, const int count){
    return sum/count;
}

/* Compute sample standard deviation from sum, sum of squares, and count */
double ssdev(const double sum, const double sumsq, const int count){
    return sqrt(((count * sumsq) - (sum * sum))/(count * (count - 1)));
}