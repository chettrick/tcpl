/*
 * Print Fahrenheit to Celsuis table
 * 2013-05-27
 */

#include <stdio.h>

int
main()
{
	float fahr, celsuis;
	int lower, upper, step;

	lower = 0;	/* Lower limit of temperature table */
	upper = 300;	/* Upper limit of temperature table */
	step = 20;	/* Step size of temperature table */

	printf("Fahr Celsuis\n");

	fahr = lower;
	while (fahr <= upper) {
		celsuis = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsuis);
		fahr += step;
	}

	return 0;
}

