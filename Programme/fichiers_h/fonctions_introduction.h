#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

void mise_a_jour_rendu_introduction(SDL_Renderer **renderer, int indice, char *ligne,
                                    SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                                    SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, 
                                    TTF_Font **police, SDL_Color couleurBlanche,
                                    int largeur, int hauteur);

void introduction(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                  SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                  SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                  personnage_t *personnageActif, SDL_Color couleurBlanche,
                  int *largeur, int *hauteur, page_t *page_active);