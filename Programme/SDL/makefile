CC=gcc -g
PROG=parametre
TEST=test

CFLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer


all: ${PROG}

${PROG}: ${PROG}.c
	${CC} ${PROG}.c -o ${PROG} ${CFLAGS}

clean: 
	rm -f ${PROG} ${test}
	rm -f *.o
