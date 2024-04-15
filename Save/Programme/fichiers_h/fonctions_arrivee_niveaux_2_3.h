#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction salon_arrivee_niveaux_2_3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], int niveau_appel);

/* Squelette de la fonction mise_a_jour_rendu_arrivee_niveaux_2_3 */
void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                           SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier,
                                           SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                                           SDL_Texture **barre_windows_4, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                           int position_x, int position_y, int tile_map[18][32],
                                           int largeur, int hauteur, int largeur_tile, int hauteur_tile);

/* Squelette de la fonction arrivee_niveaux_2_3 */
void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer,
                         SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                         SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                         SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
                         SDL_Keycode *touche_sauter_monter, SDL_Texture **texture_image_dossier,
                         SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                         SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile,
                         itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire,
                         SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter,
                         int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
                         int *position_x, int *position_y,
                         int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active);