PROGS= \
		e01-01_hello \
		e01-03_f2c \
		e01-04_c2f \
		e01-05_f2c \
		e01-06_0or1 \
		e01-07_EOFvalue \
		e01-08_countbtn \
		e01-09_blankreplace \
		e01-10_tbsreplace \
		e01-11_wordcount \
		e01-12_wordline \
		e01-13_wordlengthhisthor \
		e01-13_wordlengthhistvert \
		e01-14_charfreqhist \
		e01-15_f2c \
		e01-16_longestline \
		e01-17_longerline \
		e01-18_rmblanks \
		e01-19_reverse \
		e01-20_detab \
		e01-21_entab \
		e01-22_foldline \
		e01-23_decomm

CFLAGS+=	-g
CFLAGS+=	-Wall -Werror -Wextra -std=c99 -Wcast-qual -Wformat=2
CFLAGS+=	-Wmissing-declarations -pedantic-errors -Wstrict-prototypes
CFLAGS+=	-Wpointer-arith -Wuninitialized -Wmissing-prototypes
CFLAGS+=	-Wsign-compare -Wshadow -Wdeclaration-after-statement
CFLAGS+=	-Wfloat-equal -Wcast-align -Wundef -Wstrict-aliasing=2

CLEANFILES+=	${PROGS}

all:		${PROGS}

.include <bsd.prog.mk>
