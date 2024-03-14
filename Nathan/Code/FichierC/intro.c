#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../FichierH/fonctionIntro.h"

int main(){

    // Variables globales dans main()
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    // Initialisation de SDL
    initialisation(&window, &renderer, &font, &largeur, &hauteur);
    
    // Affichage de l'introduction
    afficherIntro(renderer, font, largeur, hauteur);
    
    // Fermeture et libération des ressources
    fermeture(window, renderer, font);

    return EXIT_SUCCESS;
}