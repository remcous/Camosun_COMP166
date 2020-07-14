/*
 * Program to calculate the dynamics of an object in free-fall
 * subject to nonlinear drag forces
 */

/* 
 * File:   Lab3.c
 * Author: Coussement, Remi
 *         C0450402
 * Due: 8 February, 2017
 *
 * Created on January 25, 2017, 1:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ITERATIONS 1000000

int main(void)
{
	// variable declarations
	static const double AirDensity = 1.2754, Gravity = 9.80667;
	double mass, dragCoefficient, area, velocity = 0.0, 
                acceleration, height, timeStep, time = 0.0;
        double terminal_velocity;

	// User inputed values for the specific case to be solved
	printf("Enter the height in meters: ");
	scanf("%lf", &height);
	printf("Enter the mass in kg: ");
	scanf("%lf", &mass);
	printf("Enter the drag coefficient: ");
	scanf("%lf", &dragCoefficient);
	printf("Enter the cross-sectional area: ");
	scanf("%lf", &area);
	printf(" Enter the time step size: ");
	scanf("%lf", &timeStep);
        
        // Prints table headings
	printf("   Time   Height  Velocity\n");
        
        // Calculates the terminal velocity for the user supplied values
	terminal_velocity = sqrt((2* mass * Gravity)/(dragCoefficient 
                * AirDensity * area));
        
        // loop to iterate either until height < 0 or 1 million iterations 
	for(int i=0; i< MAX_ITERATIONS && height > 0; i++){
                // Prints data in tabular form to console
		printf("%8.2lf  %6.1lf    %4.1lf\n",time,height,velocity);
		                
                // Iterate the time step
                time += timeStep;
                
                // Calculate the following case properties
		acceleration = (mass * Gravity - dragCoefficient * AirDensity 
                        * area * velocity * velocity / 2)/ mass;
		velocity += acceleration * timeStep;
                
                // corrects for large time step resulting 
                // in speeds over terminal velocity
                if(velocity > terminal_velocity){
                    velocity = terminal_velocity;
                }        
                
		height -= velocity * timeStep;
	}
        
        // Prints the terminal velocity to the console
	printf("Theoretical terminal velocity is %.1lf m/s\n", 
                terminal_velocity);

	return EXIT_SUCCESS;
}