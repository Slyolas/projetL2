#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctionCommun.h"

/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[20];
} itemMenu;

void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur);

void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_normal_mode, SDL_Texture **texture_image_normal_mode,
                           SDL_Surface **image_hard_mode, SDL_Texture **texture_image_hard_mode,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, int tailleMenu);


void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_normal_mode, SDL_Rect *rectangle_normal_mode,
                       SDL_Texture **texture_image_hard_mode, SDL_Rect *rectangle_hard_mode,
                       itemMenu *titre, SDL_Surface **texte_difficultee, SDL_Texture **texture_texte_difficultee, 
                       TTF_Font **police, SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int largeur, int hauteur);

void clic_case(SDL_Event event, itemMenu *itemsMenu, int numero_case, int tailleMenu, SDL_Rect *rectangle_mode, int mode);
void detruire_objets(TTF_Font **police);
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window);