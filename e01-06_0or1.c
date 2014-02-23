/*
 * Verify that `getchar() != EOF' is 0 or 1.
 * 2013-10-27
 */

#include <stdio.h>

int
main()
{
	int c;

	c = getchar() != EOF;
	printf("%d\n", c);

	return 0;
}
