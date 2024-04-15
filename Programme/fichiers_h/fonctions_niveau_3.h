#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Squelette de la fonction initialisation_objets_niveau_3 */
void initialisation_objets_niveau_3(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_3, SDL_Texture **texture_image_dossier_niveau_3,
                                    SDL_Texture **texture_image_sol_niveau_3, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, 
                                    SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4,
                                    SDL_Texture **texture_image_puzzle);

/* Squelette de la fonction rectangle_piece_aleatoire */
SDL_Rect rectangle_piece_aleatoire(int largeur, int hauteur);

/* Squelette de la fonction mise_a_jour_mini_jeu_1_niveau_3 */
void mise_a_jour_mini_jeu_1_niveau_3(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle, SDL_Rect rectangle_piece[45]);

/* Squelette de la fonction piece_proche_position_correcte */
int piece_proche_position_correcte(SDL_Rect rectangle_piece, SDL_Rect rectangle_correct);

/* Squelette de la fonction verification_puzzle_fini */
int verification_puzzle_fini(const int piece_bloquee[]);

/* Squelette de la fonction mini_jeux_niveau_3 */
void mini_jeux_niveau_3(SDL_Renderer **renderer, SDL_Window **window,
                        niveaux *avancee_niveaux, int tile_map[18][32],
                        int *mini_jeu, int *mini_jeu_1_termine,
                        int *position_x, int *position_y,
                        int *largeur, int *hauteur, SDL_Rect *rectangle_demande_quitter,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire,
                        itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int collectibles_intermediaires[3],
                        page_t *page_active,
                        int *avancer, int *reculer, int *sauter, int *saut, int *tombe,
                        SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45], int *piece_selectionnee,
                        int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle);