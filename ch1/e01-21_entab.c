/*
 * Replace blanks with tabs and blanks that keep the same spacing.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE	10000
#define TABSIZE	8

size_t getaline(char *, size_t);
void entab(char *, const char *);

/*
 * Replace blanks with tabs and blanks that keep the same spacing.
 * Assume that the input file is free of tabs.
 */
int
main(void)
{
	int len;
	char line[MAXLINE];	/* Current input line. */
	char tabbed[MAXLINE];	/* Cooked string with tabs. */

	while ((len = getaline(line, MAXLINE)) != -1) {
		entab(tabbed, line);
		printf("%s", tabbed);
	}

	return (0);
}

/* getaline:  read a line into `s'; return length, or -1 if EOF. */
size_t
getaline(char *s, size_t lim)
{
	int c;
	size_t i;

	c = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == EOF)
		return (-1);	/* POSIX */
	if (c == '\n')
		s[i++] = c;
	s[i++] = '\0';

	return (i);
}

/* entab:  replace blanks with tabs and blanks. */
void
entab(char *cooked, const char *raw)
{
	char *dst = cooked;
	const char *src = raw;
	size_t n, mark, tabcolumn;
	char *tok;
	int tflag;

	n = 0;

	while (*src != '\0') {
		/* Copy characters that are not blanks. */
		while (*src != ' ' || *src != '\0') {
			*dst++ = *src++;
			n++;
		}

		tok = (char *)src;
		mark = n;
		tflag = 0;
		tabcolumn += TABSIZE;

		while (*src++ == ' ') {
			n++;
			if (n % tabcolumn == 0) {
				tflag = 1;
				break;
			}
		}
		if (tflag == 1) {
			tflag = 0;
			*dst++ = '\t';
		} else {
			src = tok;
			while (mark++ != n)
				*dst++ = *src++;
		}
	}
}
