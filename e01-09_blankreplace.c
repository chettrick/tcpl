/*
 * Blank Replace
 * 2013-05-28
 */

#include <stdio.h>

int
main()
{
	int ch, prevch;

	ch = prevch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' && prevch == ' ')
			continue;
		prevch = ch;
		putchar(ch);
	}

	return 0;
}
