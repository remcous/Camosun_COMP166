/* 
 * File:   Lab3_Nonlinear_Drag_Force.c
 * Author: Coussement, Remi
 *         C0450402
 * Due: 8 February, 2017
 *
 * Created on January 25, 2017, 1:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        
        // loop to iterate either until height < 0 or 1 million iterations 
	for(int i=0; i<1000000 && height > 0; i++){
                // Prints data in tabular form to console
		printf("%8.2lf  %6.1lf    %4.1lf\n",time,height,velocity);
		
                // Iterate the time step
                time += timeStep;
                
                // Calculate the following case properties
		acceleration = (mass * Gravity - dragCoefficient * AirDensity * area * velocity * velocity / 2)/ mass;
		velocity += acceleration * timeStep;
		height -= velocity * timeStep;
	}
        
        // Calculate the terminal velocity and print to console
	terminal_velocity = sqrt((2* mass * Gravity)/(dragCoefficient * AirDensity * area));
	printf("Theoretical terminal velocity is %.1lf m/s", terminal_velocity);

	return EXIT_SUCCESS;
}