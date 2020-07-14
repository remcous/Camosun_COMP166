#include <stdio.h>
#include <math.h>
#define EPSILON 1.0e-5

main(){
	double num1 = 10.0, num2 = 9.5;
	double res1, res2;
	res1 = num2 / num1 * num1;
	res2 = num2;

	printf("num1 = %lf, num2 = %lf\nres1 = %lf, res2 = %lf\n\n", num1, num2, res1, res2);
	if(fabs(res2 - res1) < EPSILON){
		printf("EQUAL\n");
	}
	else{
		printf("NOT EQUAL\n");
	}
	return 0;
}