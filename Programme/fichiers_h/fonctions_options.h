#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_options */
void initialisation_objets_options(SDL_Renderer **renderer,
                                   SDL_Surface **image_hautParleurActif, SDL_Texture **texture_image_hautParleurActif,
                                   SDL_Surface **image_hautParleurDesactive, SDL_Texture **texture_image_hautParleurDesactive,
                                   itemMenu *titre, itemMenu *itemsMenu, itemMenu *itemsTouches, itemMenu *itemsBarres);

/* Squelette de la fonction mise_a_jour_rendu_options */
void mise_a_jour_rendu_options(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                               SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                               SDL_Texture **texture_image_hautParleurActif, 
                               SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
                               SDL_Rect *rectangles_boutons_sons, option_t ongletActif,
                               itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                               SDL_Color couleurNoire,
                               itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, 
                               barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres,
                               int largeur, int hauteur);

/* Squelette de la fonction options */
void options(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
             SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
             SDL_Texture **texture_image_hautParleurActif, 
             SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
             SDL_Rect *rectangles_boutons_sons, option_t *ongletActif,
             itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
             int *selection_touche, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
             SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, SDL_Color couleurNoire,
             itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, 
             barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres,
             int *largeur, int *hauteur, page_t *page_active, page_t *page_precedente);