/*
 * detab: Replace tabs with blanks.
 */

#include <stdio.h>

#define MAXLINE 10000	/* Max input line length. */
#define TABSTOP	8	/* Set tab stop to eight characters. */

int	getaline(char *, int);
void	detab(char *);

/* detab:  Replace tabs with blanks. */
int
main(void)
{
	char	line[MAXLINE];	/* Current input line. */

	while (getaline(line, MAXLINE) > 0) {
		detab(line);
		printf("%s", line);
	}

	return 0;
}

/* getaline:  Read a line into `s'; return length. */
int
getaline(char *s, int lim)
{
	int c, i;

	c = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* detab:  Replace tabs with blanks. */
void
detab(char *s)
{
	int i, j;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t') {
			for (j = 0; j <= (i % TABSTOP + TABSTOP); ++j)
				s[i + j] = ' ';
			i += j;
		}
	}
}
