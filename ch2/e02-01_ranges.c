/*
 * Determine the ranges of basic variables in C.
 */

#include <limits.h>
#include <stdio.h>

/*
 * Determine the ranges of basic variables in C.
 */
int
main(void)
{
	printf("SCHAR_MAX:\t%d\n", SCHAR_MAX);
	printf("SCHAR_MIN:\t%d\n", SCHAR_MIN);
	printf("UCHAR_MAX:\t%d\n", UCHAR_MAX);
	printf("UCHAR_MIN:\t%d\n", 0);
	printf("CHAR_MAX:\t%d\n", CHAR_MAX);
	printf("CHAR_MIN:\t%d\n", CHAR_MIN);
	printf("USHRT_MAX:\t%d\n", USHRT_MAX);
	printf("USHRT_MIN:\t%d\n", 0);
	printf("SHRT_MAX:\t%d\n", SHRT_MAX);
	printf("SHRT_MIN:\t%d\n", SHRT_MIN);
	printf("UINT_MAX:\t%u\n", UINT_MAX);
	printf("UINT_MIN:\t%u\n", 0U);
	printf("INT_MAX:\t%d\n", INT_MAX);
	printf("INT_MIN:\t%d\n", INT_MIN);
	printf("ULONG_MAX:\t%lu\n", ULONG_MAX);
	printf("ULONG_MIN:\t%ld\n", 0L);
	printf("LONG_MAX:\t%ld\n", LONG_MAX);
	printf("LONG_MIN:\t%ld\n", LONG_MIN);
	printf("ULLONG_MAX:\t%llu\n", ULLONG_MAX);
	printf("ULLONG_MIN:\t%llu\n", 0ULL);
	printf("LLONG_MAX:\t%lld\n", LLONG_MAX);
	printf("LLONG_MIN:\t%lld\n", LLONG_MIN);

	return (0);
}
