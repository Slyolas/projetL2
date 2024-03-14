#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctionCommun.h"

/* Définir le nombre d'FPS (100 / nombre_FPS) */
#define FPS_LIMIT 16

/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[20];
    int fontSize; // Taille de la police
} itemMenu;

void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur);
void SDL_LimitFPS(unsigned int limit);
void detruire_objets(TTF_Font **police);
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window);
int verification_sauvegarde();

void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_menu, SDL_Texture **texture_image_menu,
                           SDL_Surface **image_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, int tailleMenu);

void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_menu,
                       SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                       itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                       SDL_Color couleurTitre, SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur);

void clic_case(SDL_Event event, itemMenu *itemsMenu, int numero_case, int tailleMenu);