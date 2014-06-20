/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 */

#include <stdio.h>
#include <string.h>

#define TABSIZ 8

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
	char line[BUFSIZ];	/* Current input line. */
	char tabbed[BUFSIZ];	/* Cooked string with tabs. */

	while ((len = getaline(line, BUFSIZ)) != -1) {
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
	int blanks, mark, n, tflag;
	const char *tok;
	const char delim = ' ';
	const char *src = raw;
	char *dst = cooked;

	n = blanks = 0;

	while (*src != '\0') {
		/* Copy characters that are not blanks. */
		for (; *src != delim; n++)
			*dst++ = *src++;

		tok = src;	/* Save the location of the first blank. */
		mark = n;
		tflag = 0;

		while (*src++ == delim) {
			n++;
			blanks++;
			if ((n % TABSIZ == 0) && (blanks > 1)) {
				tflag = 1;
				break;
			}
		}
		blanks = 0;
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
