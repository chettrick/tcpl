/*
 * Print Fahrenheit to Celsuis table
 * 2013-05-27
 */

#include <stdio.h>

#define	LOWER	0	/* Lower limit of table */
#define	UPPER	300	/* Upper limit of table */
#define	STEP	20	/* Step size of table */

int
main()
{
	int fahr;

	printf("Fahr Celsuis\n");

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	
	return 0;
}

