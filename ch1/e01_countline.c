/*
 * Count Lines
 * 2013-05-27
 */

#include <stdio.h>

int
main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("\n%d\n%d", nl, EOF);

	return 0;
}
