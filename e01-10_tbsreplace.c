/*
 * Tab, Backspace, and Backslash Replace
 * 2013-05-28
 */

#include <stdio.h>

int
main()
{
	int ch;

	while ((ch = getchar()) != EOF)
		switch (ch) {
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				putchar(ch);
				break;
		}

	return 0;
}
