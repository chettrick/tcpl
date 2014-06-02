/*
 * Copy Input to Output
 * 2013-05-27
 */

#include <stdio.h>

int
main()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}
