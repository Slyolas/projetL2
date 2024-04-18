#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

/* Squelette de la fonction salon_arrivee_niveaux_2_3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active);

/* Squelette de la fonction mise_a_jour_rendu_arrivee_niveaux_2_3 */
void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_fin_premiers_niveaux,
                                           SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier,
                                           SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                                           SDL_Texture **barre_windows_4, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                           int position_x, int position_y, int tile_map[18][32], niveaux *avancee_niveaux,
                                           int largeur, int hauteur, int largeur_tile, int hauteur_tile, page_t page_active);

/* Squelette de la fonction arrivee_niveaux_2_3 */
void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, int *mini_jeu, SDL_Texture **texture_image_fin_premiers_niveaux,
                         SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int *mini_jeu_termine, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                         SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                         SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                         SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Texture **texture_image_dossier,
                         SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                         SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile, int *mouvement_monstre, modes_t *modeActif, int *mode_difficile,
                         itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire, int tile_map_mini_jeu_niveau_2[19][27],
                         SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter, time_t *timestamp, SDL_Texture **texture_image_perso_gagnant,
                         int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
                         int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y, 
                         int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active,
                         SDL_Texture **texture_image_mur_mini_jeu, int collectibles_intermediaires[3],
                         SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                         SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                         SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                         SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine, int *valide,
                         SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45],
                         int *piece_selectionnee, int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle, Mix_Music **musique,
                         int tile_map_mini_jeu_niveau_3[24][32], int *descendre, int *interagir, int *bloc_x, int *bloc_y,
                         SDL_Texture **texture_image_sol_labyrinthe, SDL_Texture **texture_image_bordure_labyrinthe,
                         SDL_Texture **texture_image_fin_labyrinthe);