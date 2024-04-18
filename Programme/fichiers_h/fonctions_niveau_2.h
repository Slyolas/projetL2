#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

/* Squelette de la fonction salon_arrivee_niveaux_2_3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active);

/* Squelette de la fonction initialisation_objets_niveau_2 */
void initialisation_objets_niveau_2(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_2, SDL_Texture **texture_image_dossier_niveau_2,
                                    SDL_Texture **texture_image_sol_niveau_2, SDL_Texture **texture_image_mur_mini_jeu,
                                    SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                                    SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                                    SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                                    SDL_Texture **texture_image_pipe_courant,
                                    SDL_Texture **texture_image_mur_termine);

/* Squelette de la fonction mini_jeu_1_niveau_2 */
void mini_jeu_1_niveau_2(int *position_x, int *position_y, int tile_map[19][27]);

/* Squelette de la fonction verification_chemin */
int verification_chemin(int x, int y, int x_precedent, int y_precedent, int tilemap[19][27], int x_arrivee, int y_arrivee);

/* Squelette de la fonction mise_a_jour_bordures */
int mise_a_jour_bordures_niveau_2(SDL_Renderer* renderer, SDL_Texture* texture_image_mur_termine, int tilemap[19][27], int x_tile, int y_tile, int x, int y,
                                  SDL_Rect *rectangle_tile, int largeur_tile, int hauteur_tile);

/* Squelette de la fonction mise_a_jour_mini_jeu_1_niveau_2 */
void mise_a_jour_mini_jeu_1_niveau_2(SDL_Renderer **renderer,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile,
                                     int position_x, int position_y, int tile_map_mini_jeu_niveau_2[19][27],
                                     int largeur, int hauteur, int largeur_tile, int hauteur_tile,
                                     SDL_Texture **texture_image_mur_mini_jeu,
                                     SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                                     SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                                     SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                                     SDL_Texture **texture_image_pipe_courant,
                                     SDL_Texture **texture_image_mur_termine);

/* Squelette de la fonction mini_jeu_2_niveau_2 */
void mini_jeu_2_niveau_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32], int mode_difficile);

/* Squelette de la fonction mise_a_jour_mini_jeu_2_niveau_2 */
void mise_a_jour_mini_jeu_2_niveau_2(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                                     SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int mini_jeu_termine,
                                     int position_x, int position_y, int tile_map[18][32], SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                                     int largeur, int hauteur, int largeur_tile, int hauteur_tile);

/* Squelette de la fonction mini_jeux_niveau_2 */
void mini_jeux_niveau_2(SDL_Event *event, SDL_Renderer **renderer, SDL_Window **window, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                        SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                        SDL_Texture **texture, SDL_Rect *rectangle_tile, int *mini_jeu, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                        SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int mini_jeu_termine,
                        int *position_x, int *position_y, int tile_map[18][32], int tile_map_mini_jeu_niveau_2[19][27], SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                        int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile,
                        SDL_Texture **texture_image_mur_mini_jeu, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir,
                        SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, int *valide,
                        SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                        SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                        SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                        SDL_Texture **texture_image_pipe_courant, SDL_Rect *rectangle_demande_quitter,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire,
                        itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int collectibles_intermediaires[3],
                        SDL_Texture **texture_image_mur_termine, page_t *page_active, Mix_Music **musique,
                        int *avancer, int *reculer, int *sauter, int *saut, int *tombe);