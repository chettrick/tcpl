/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
 */

#include <stdio.h>
#include <string.h>

#define TABSIZ 8

static size_t getaline(char *, size_t);
static void entab(char *, const char *);

/*
 * Replace blanks with tabs and blanks as to keep the same spacing.
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
static size_t
getaline(char *s, size_t lim)
{
	int c;
	size_t i;

	c = 0;

	for (i = 0; ((c = getchar()) != EOF) && (i < lim - 1) &&
	    (c != '\n'); ++i)
		s[i] = c;
	if (c == EOF)
		return (-1);	/* POSIX */
	if (c == '\n')
		s[i++] = c;
	s[i++] = '\0';

	return (i);
}

/* entab:  replace blanks with tabs and blanks. */
static void
entab(char *dst, const char *src)
{
	int blanks, mark, n, tflag;
	const char *tok;

	const char delim = ' ';
	blanks = mark = n = tflag = 0;

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
