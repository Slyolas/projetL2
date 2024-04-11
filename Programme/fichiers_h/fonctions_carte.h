#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_carte */
void initialisation_objets_carte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_carte,
                                 SDL_Texture **texture_image_perso_1_bas_1, SDL_Texture **texture_image_perso_1_bas_2,
                                 SDL_Texture **texture_image_perso_1_haut_1, SDL_Texture **texture_image_perso_1_haut_2,
                                 SDL_Texture **texture_image_perso_1_bas_gauche_1, SDL_Texture **texture_image_perso_1_bas_gauche_2,
                                 SDL_Texture **texture_image_perso_1_haut, SDL_Texture **texture_image_perso_1_droite,
                                 SDL_Texture **texture_image_perso_1_gauche, SDL_Texture **texture_image_perso_1_pose,
                                 SDL_Texture **texture_image_perso_2_bas_1, SDL_Texture **texture_image_perso_2_bas_2,
                                 SDL_Texture **texture_image_perso_2_haut_1, SDL_Texture **texture_image_perso_2_haut_2,
                                 SDL_Texture **texture_image_perso_2_bas_gauche_1, SDL_Texture **texture_image_perso_2_bas_gauche_2,
                                 SDL_Texture **texture_image_perso_2_haut, SDL_Texture **texture_image_perso_2_droite,
                                 SDL_Texture **texture_image_perso_2_gauche, SDL_Texture **texture_image_perso_2_pose,
                                 itemMenu *itemsNiveaux);

/* Squelette de la fonction mise_a_jour_rendu_carte */
void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte,
                             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                             SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                             SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso,
                             SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                             position_t positionActive, SDL_Color couleurNoire,
                             itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur);

/* Squelette de la fonction deplacement_personnage_carte */
void deplacement_personnage_carte(SDL_Renderer **renderer, SDL_Window **window, SDL_Texture **texture_image_carte,
                                  SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                  SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                  SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso_1, SDL_Texture **texture_image_perso_2, 
                                  SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                                  position_t *positionActive, SDL_Color couleurNoire,
                                  itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur,
                                  int valeur_maximale, direction_t direction);

/* Squelette de la fonction carte */
void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte,
           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
           SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
           SDL_Texture **texture_image_perso_bas_1, SDL_Texture **texture_image_perso_bas_2,
           SDL_Texture **texture_image_perso_haut_1, SDL_Texture **texture_image_perso_haut_2,
           SDL_Texture **texture_image_perso_bas_gauche_1, SDL_Texture **texture_image_perso_bas_gauche_2,
           SDL_Texture **texture_image_perso_haut, SDL_Texture **texture_image_perso_droite,
           SDL_Texture **texture_image_perso_gauche, SDL_Texture **texture_image_perso_pose,
           SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso, niveaux *avancee_niveaux,
           SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, direction_t *direction, int *touche_pressee,
           SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde,
           position_t *positionActive, barreDeSon *barre_de_son, itemMenu *pseudo, modes_t *modeActif, personnage_t *personnageActif,
           SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir,
           itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active);