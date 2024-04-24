#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

/* Squelette de la fonction salon_arrivee_niveaux_2_3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active);

/* Squelette de la fonction initialisation_objets_niveau_3 */
void initialisation_objets_niveau_3(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_3, SDL_Texture **texture_image_dossier_niveau_3,
                                    SDL_Texture **texture_image_sol_niveau_3, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, 
                                    SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4,
                                    SDL_Texture **texture_image_puzzle, SDL_Texture **texture_image_sol_labyrinthe,
                                    SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_fin_labyrinthe);

/* Squelette de la fonction rectangle_piece_aleatoire */
SDL_Rect rectangle_piece_aleatoire(int largeur, int hauteur);

/* Squelette de la fonction mise_a_jour_mini_jeu_1_niveau_3 */
void mise_a_jour_mini_jeu_1_niveau_3(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle, SDL_Rect rectangle_piece[45],
                                     SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix);

/* Squelette de la fonction piece_proche_position_correcte */
int piece_proche_position_correcte(SDL_Rect rectangle_piece, SDL_Rect rectangle_correct);

/* Squelette de la fonction verification_puzzle_fini */
int verification_puzzle_fini(const int piece_bloquee[]);

/* Squelette de la fonction mini_jeu_2_niveau_3 */
void mini_jeu_2_niveau_3(int *position_x, int *position_y, int *bloc_x, int *bloc_y, int tile_map[24][32]);

/* Squelette de la fonction traitement_touches */
void traitement_touches(int *position_x, int *position_y, int *bloc_x, int *bloc_y, int tilemap[24][32], int direction);

/* Squelette de la fonction mise_a_jour_bordures_niveau_3 */
int mise_a_jour_bordures_niveau_3(SDL_Renderer* renderer, SDL_Texture* texture_image_mur_termine, int tilemap[24][32], int x_tile, int y_tile,
                                SDL_Rect *rectangle_tile, int largeur_tile, int hauteur_tile);

/* Squelette de la fonction mise_a_jour_mini_jeu_2_niveau_3 */
void mise_a_jour_mini_jeu_2_niveau_3(SDL_Renderer **renderer, modes_t *modeActif, SDL_Texture **texture_image_sol_labyrinthe,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture_image_mur_mini_jeu, SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_mur_termine,
                                     SDL_Texture **texture_image_fin_labyrinthe, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile, int bloc_x, int bloc_y,
                                     SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                     int position_x, int position_y, int tile_map_mini_jeu_niveau_3[24][32], niveaux *avancee_niveaux,
                                     int largeur_tile, int hauteur_tile);

/* Squelette de la fonction mini_jeux_niveau_3 */
void mini_jeux_niveau_3(SDL_Event *event, SDL_Renderer **renderer, SDL_Window **window, SDL_bool *programme_lance,
                        SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                        niveaux *avancee_niveaux, int tile_map[18][32], SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                        int *mini_jeu, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                        int *position_x, int *position_y, SDL_Texture **texture,
                        int *largeur, int *hauteur, SDL_Rect *rectangle_demande,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire,
                        itemMenu *itemsDemandeQuitter, int tailleDemande, int collectibles_intermediaires[3],
                        page_t *page_active, SDL_Rect *rectangle_tile, int *largeur_tile, int *hauteur_tile,
                        int *avancer, int *reculer, int *sauter, int *saut, int *tombe,
                        SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45], int *piece_selectionnee,
                        int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle,
                        int tile_map_mini_jeu_niveau_3[24][32], int *descendre, int *interagir, int *bloc_x, int *bloc_y,
                        SDL_Texture **texture_image_sol_labyrinthe, SDL_Texture **texture_image_bordure_labyrinthe,
                        SDL_Texture **texture_image_fin_labyrinthe, Mix_Music **musique,
                        SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                        SDL_Texture **texture_image_mur_termine, SDL_Texture **texture_image_mur_mini_jeu, 
                        SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir,
                        SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, modes_t *modeActif,
                        itemMenu *itemsDemandeSauvegarde, barreDeSon *barre_de_son, itemMenu *pseudo, 
                        personnage_t *personnageActif, position_t *positionActive, int tailleNiveaux,
                        time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]);