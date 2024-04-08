#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Fonction qui permet d'initialiser les différents objets du menu principal */
void initialisation_objets_niveau_4(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                    SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique);

/* Fonction qui permet de créer l'étage 1 */
void etage_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Fonction qui permet de créer l'étage 2 */
void etage_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Fonction qui permet de créer l'étage 3 */
void etage_3(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Fonction qui permet de créer l'étage 4 */
void etage_4(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

/* Fonction qui permet de créer l'étage 4 */
void etage_5(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur);

void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,
                            int position_x_initiale, int position_y_initiale, int sauter, int avancer, int reculer, int tile_map[18][32]);

/* Fonction qui permet de mettre à jour le rendu du niveau 4 */
void mise_a_jour_rendu_niveau_4(SDL_Renderer **renderer, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile,
                                SDL_Texture **texture_image_porte,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                SDL_Texture **texture_image_pique,
                                int position_x, int position_y, int tile_map[18][32],
                                int largeur, int hauteur, int largeur_tile, int hauteur_tile);


void niveau_4(SDL_Event *event, SDL_Renderer **renderer, SDL_bool *programme_lance,
              SDL_Texture **texture,
              SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
              SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond,
              SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte,
              SDL_Texture **texture_image_pique,
              SDL_Surface **surface,
              SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
              SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_interagir,
              int tile_map[18][32], SDL_Rect *rectangle_tile, direction_t *direction,
              int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *numero_etage,
              int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
              int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active);