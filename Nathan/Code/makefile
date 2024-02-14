
CC=gcc -g

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

PROG=fonctionMenu

all: fonctionMenu

fonctionMenu: fonctionMenu.c
	${CC} -o ${PROG} fonctionMenu.c

clean: 
	rm -f ${PROG}
	rm -f *.o
