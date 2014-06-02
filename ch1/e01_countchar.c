/*
 * Count Characters
 * 2013-05-27
 */

#include <stdio.h>

int
main()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("\n%.0f\n", nc);

	return 0;
}
