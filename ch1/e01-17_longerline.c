/*
 * Print all input lines that are longer than 80 characters.
 * 2013-10-27
 */

#include <stdio.h>

#define MAXLINE 10000		/* Max input line size. */
#define MINLEN	(80 + 1)	/* Min line size to be printed. */

int	getaline(char *, int);

/* Print all input lines that are longer than MINLEN characters. */
int
main(void)
{
	int	len;			/* Current line length. */
	char	line[MAXLINE];		/* Current input line. */

	while ((len = getaline(line, MAXLINE)) > 0) {
		/* Don't consider NULL to be one of the characters. */
		if (len > MINLEN)
			printf("%s", line);
	}

	return 0;
}

/* getaline:  read a line into `s'; return length. */
int
getaline(char *s, int lim)
{
	int c, i;

	c = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
