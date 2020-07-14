/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statistics.h
 * Author: Remi Coussement
 *         C0450402
 *
 * Created on January 31, 2017, 8:13 AM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

/* Compute mean from sum and count */
double mean(const double sum, const int count);

/* Compute sample standard deviation from sum, sum of squares, and count */
double ssdev(const double sum, const double sumsq, const int count);

#endif /* STATISTICS_H */

