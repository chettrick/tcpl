CFLAGS+=	-g
CFLAGS+=	-Werror -Wextra -pedantic-errors -std=c99
CFLAGS+=	-Wmissing-declarations -Wcast-qual -Wbounded -Wformat
CLEANFILES+=	${PROGS}

WARNINGS=	yes

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
	e01-22_foldline

all:	${PROGS}

.include <bsd.prog.mk>
