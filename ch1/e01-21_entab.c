/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 10000
#define TABSIZE 8

size_t getaline(char *, size_t);
void entab(char *, const char *);

/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 * Assume that the input file is free of tabs (run through detab).
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
	int mark, n, tabcolumn, tflag;
	const char *tok;
	const char delim = ' ';
	const char *src = raw;
	char *dst = cooked;

	n = tabcolumn = 0;

	while (*src != '\0') {
		/* Copy characters that are not blanks. */
		for (; *src != delim; n++)
			*dst++ = *src++;

		tok = src;	/* Save the location of the first blank. */
		mark = n;
		tflag = 0;
		tabcolumn += TABSIZE;

		while (*src++ == delim) {
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
			src = tok;	/* Not enough blanks for a tab. */
			while (mark++ != n)
				*dst++ = *src++;
		}
	}
}
