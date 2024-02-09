#include <stdio.h>
#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0
SDL_Window* window = NULL;

int initialisation_fenetre(void){
    SDL_Init(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Erreur à l'initialisation de la fenêtre")
        return FALSE;
    }
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW,BORDERLESS
    );
    if(window == NULL){
        fprintf(stderr, "Génération de la fenêtre non effectué\n");
        return FALSE;
    }

    
    return TRUE;
}

