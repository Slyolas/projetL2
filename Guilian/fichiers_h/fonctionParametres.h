#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctionCommun.h"

// Constantes pour les onglets
#define ONGLET_SON 0
#define ONGLET_TOUCHES 1

/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[40];
} itemMenu;


void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur);

void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_hautParleurActif, SDL_Texture **texture_image_hautParleurActif,
                           SDL_Surface **image_hautParleurDesactive, SDL_Texture **texture_image_hautParleurDesactive,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, itemMenu *itemsTouches);

void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_hautParleurActif, 
                       SDL_Texture **texture_image_hautParleurDesactive, SDL_bool sonActif,
                       SDL_Rect *rectangle_bouton_son, int ongletActif, itemMenu *titre, 
                       SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                       SDL_Color couleurNoire, itemMenu *itemsMenu, int tailleMenu, 
                       itemMenu *itemsTouches, int tailleTouches, int largeur, int hauteur);

int clic_case(SDL_Event event, SDL_Rect rectangle);
void detruire_objets(TTF_Font **police);
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window);