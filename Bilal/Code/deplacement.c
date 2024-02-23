#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>


int main(int argc, char ** argv){
    SDL_Surface *ecran = NULL;
    SDL_Surface *menu = NULL;
    SDL_Rect positionMenu;


    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_LOAD("barbare.w"),NULL);

    ecran = SDL_SetVideoMode()


    return 0;
}