#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_niveau_4 */
void initialisation_objets_niveau_4(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                    SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique,
                                    SDL_Texture **texture_image_fin_dernier_niveau);

/* Squelette de la fonction etage_1 */
void etage_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Squelette de la fonction etage_2 */
void etage_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Squelette de la fonction etage_3 */
void etage_3(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Squelette de la fonction etage_4 */
void etage_4(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Squelette de la fonction etage_5 */
void etage_5(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Squelette de la fonction mise_a_jour_rendu_niveau_4 */
void mise_a_jour_rendu_niveau_4(SDL_Renderer **renderer, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                SDL_Texture **texture_image_porte, SDL_Texture **texture_image_fin_dernier_niveau,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, int numero_etage,
                                int position_x, int position_y, int tile_map[18][32],
                                int largeur, int hauteur, int largeur_tile, int hauteur_tile);

/* Squelette de la fonction niveau_4 */
void niveau_4(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer,
              SDL_Texture **texture, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
              SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
              SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond,
              SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte,
              SDL_Texture **texture_image_pique, niveaux *avancee_niveaux,
              SDL_Surface **surface, modes_t *modeActif, int collectibles_intermediaires[3],
              SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
              SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_interagir,
              int tile_map[18][32], SDL_Rect *rectangle_tile, SDL_Texture **texture_image_perso_gagnant,
              itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter,
              SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter,
              SDL_Color couleurNoire, SDL_Texture **texture_image_fin_dernier_niveau,
              int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *numero_etage,
              int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
              int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active);