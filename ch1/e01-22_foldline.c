/*
 * Fold long lines.
 */

#include <stdio.h>

#define MAXCOL 80	/* Max column width in characters. */

static int getaline(char *, int);
static const char *strrpbrkl(const char *, const char *, size_t);

/*
 * Fold long lines at MAXCOL. Split on whitespace to preserve words.
 * Lines without whitespace are split at MAXCOL.
 */
int
main(void)
{
	int len;
	char line[BUFSIZ];	/* Current input line. */
	const char *s;
	const char *tokens = " \t";

	while ((len = getaline(line, BUFSIZ)) != -1) {
		s = strrpbrkl(line, tokens, MAXCOL);
		printf("%s", s);
	}

	return (0);
}

/*
 * getaline:  read a line into `s'; return length, or -1 if EOF.
 */
static int
getaline(char *s, int lim)
{
	int c, i;

	c = 0;

	for (i = 0; ((c = getchar()) != EOF) && (i < lim - 1) &&
	    (c != '\n'); i++)
		s[i] = c;
	if (c == EOF)
		return (-1);	/* POSIX */
	if (c == '\n')
		s[i++] = c;
	s[i++] = '\0';

	return (i);
}

/*
 * The strrpbrkl() function locates in the NUL-terminated string s the
 * last occurrence of any character in the NUL-terminated string tok up
 * to len characters and returns a pointer to this character.  If len is
 * NUL then all of s is searched.  If no characters in tok occur anywhere
 * in s within len characters, strrpbrkl() returns NULL.
 */
static const char *
strrpbrkl(const char *s, const char *tok, size_t len)
{
	size_t i;
	const char *ptok;
	const char *ret = NULL;

	for (i = 1; ((i <= len) || (len == '\0')) &&
	    (*s != '\0'); i++, s++) {
		for (ptok = tok; *ptok != '\0'; ptok++) {
			if (*ptok == *s) {
				ret = s;
				break;
			}
		}
	}

	return (ret);
}
