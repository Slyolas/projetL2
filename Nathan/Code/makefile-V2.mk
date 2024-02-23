#makefile à executer avec l'installation de SDL dans les salles TP
#Version du 09/02/23 
CC=gcc

 
SDLLIB_DIR=/usr/lib/x86_64-linux-gnu
SDLINC_DIR= /usr/include/SDL2

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

PROG=sdl_text

all: sdl_text

sdl_text: sdl_test.c
	${CC} -o ${PROG} sdl_test.c ${LIBS} ${INCLUDES}

clean: 
	rm -f ${PROG}
	rm -f *.o


