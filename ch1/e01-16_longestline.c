/*
 * Print the longest input line.
 */

#include <stdio.h>

#define MAXLINE 10000	/* Max input line size. */

int	getaline(char *, int);
void	copyaline(char *, char *);

/* Print longest input line. */
int
main(void)
{
	int	len;			/* Current line length. */
	int	max;			/* Maximum length seen so far. */
	char	line[MAXLINE];		/* Current input line. */
	char	longest[MAXLINE];	/* Longest line saved here. */

	max = 0;

	while ((len = getaline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copyaline(longest, line);
		}
	}
	/* There was a line. */
	if (max > 0) {
		printf("The longest line has %d characters.\n", max);
		printf("%s", longest);
	}

	return 0;
}

/* getaline:  read a line into `s'; return length. */
int
getaline(char *s, int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

/* copyaline:  copy `from' into `to'; assume `to' is big enough. */
void
copyaline(char *to, char *from)
{
	int i;

	for (i = 0; (to[i] = from[i]) != '\0'; ++i)
		;
}
