/*
 * Reverse the characters in each line.
 */

#include <stdio.h>

#define MAXLINE 10000		/* Max input line length. */

int	getaline(char *, int);
void	reverse(char *, int);

/* Reverse the characters in each line. */
int
main(void)
{
	int	len;		/* Current line length. */
	char	line[MAXLINE];	/* Current input line. */

	while ((len = getaline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s", line);
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
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* reverse:  Reverse the character string order. */
void
reverse(char *s, int len)
{
	int i, j, newline;
	char temp[MAXLINE];

	newline = 0;
	--len;			/* Skip \0. */
	if (s[len] == '\n') {
		newline = 1;
		--len;		/* Skip \n as well. */
	}
	for (j = 0, i = len; i >= 0; temp[j++] = s[i--])
		;
	for (i = 0; i <= len; s[i] = temp[i++])
		;
	if (newline)
		s[++len] = '\n';
	s[++len] = '\0';
}