#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_carte */
void initialisation_objets_carte(SDL_Renderer **renderer, SDL_Surface **image_carte, SDL_Texture **texture_image_carte,
                                 itemMenu *itemsNiveaux);

/* Squelette de la fonction mise_a_jour_rendu_carte */
void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte,
                             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                             SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                             SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso,
                             SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                             position_t positionActive, SDL_Color couleurNoire,
                             itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur);

/* Squelette de la fonction carte */
void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte,
           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
           SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
           SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso, personnage_t *personnageActif,
           SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
           position_t *positionActive, SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir,
           itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active);