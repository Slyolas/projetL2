#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_menu_principal */
void initialisation_objets_menu_principal(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_menu,
                                          itemMenu *titre, itemMenu *itemsMenu, int tailleMenu);

/* Squelette de la fonction mise_a_jour_rendu_menu_principal */
void mise_a_jour_rendu_menu_principal(SDL_Renderer **renderer, SDL_Texture **texture_image_menu,
                                      SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                      itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                                      SDL_Color couleurTitre, SDL_Color couleurNoire,
                                      itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur,
                                      int indice_menu_selectionne);

/* Squelette de la fonction menu_principal */
void menu_principal(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_menu,
                    SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                    itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                    SDL_Color couleurTitre, SDL_Color couleurNoire, itemMenu *itemsMenu, int tailleMenu, 
                    int *largeur, int *hauteur, page_t *page_active, int *indice_menu_selectionne);