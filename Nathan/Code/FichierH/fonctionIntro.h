#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctionCommun.h"

#define TEXT_BLINK_INTERVAL 500 // Intervalle de clignotement en millisecondes
#define TEXT_BLINK_TIMES 5      // Nombre de clignotements

// Déclarations des fonctions
void initialisation(SDL_Window **window, SDL_Renderer **renderer, TTF_Font **font, int *largeur, int *hauteur);
void fermeture(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font);
void afficherSkip(SDL_Renderer *renderer, TTF_Font *font, int largeur);
int gererClicSkip(SDL_Event event, int largeur);
void afficherTexte(SDL_Renderer *renderer, TTF_Font *font, const char *texte, int positionX, int positionY);
void afficherIntro(SDL_Renderer *renderer, TTF_Font *font, int largeur, int hauteur);