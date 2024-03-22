#include <stdio.h>
#include "commun.h"



void apply_surface(int x, int y, SDL_Surface * source, SDL_Surface* destination){
    SDL_RECt offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source,NULL, destination, &offset);
}