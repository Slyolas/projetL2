#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_3.h>

void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active);

/* Fonction qui permet d'initialiser les différents objets du niveau 2 */
void initialisation_objets_niveau_3(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_3, SDL_Texture **texture_image_dossier_niveau_3,
                                    SDL_Texture **texture_image_sol_niveau_3, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, 
                                    SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4,
                                    SDL_Texture **texture_image_puzzle) {

    /* Chargement des images pour le niveau 3 */

    chargement_image(renderer, surface, texture_image_fond_niveau_3, "./images/niveau_3/fond_niveau_3.jpg");
    chargement_image(renderer, surface, texture_image_dossier_niveau_3, "./images/niveau_3/dossier_windows_xp.png");
    chargement_image(renderer, surface, texture_image_sol_niveau_3, "./images/niveau_3/sol_niveau_3.jpg");
    chargement_image(renderer, surface, barre_windows_1, "./images/niveau_3/windows_1.png");
    chargement_image(renderer, surface, barre_windows_2, "./images/niveau_3/windows_2.png");
    chargement_image(renderer, surface, barre_windows_3, "./images/niveau_3/windows_3.png");
    chargement_image(renderer, surface, barre_windows_4, "./images/niveau_3/windows_4.png");

    chargement_image(renderer, surface, texture_image_puzzle, "./images/ventilo.png");
}

/* Fonction pour obtenir un rectangle représentant une pièce de puzzle aléatoire */
SDL_Rect rectangle_piece_aleatoire(int largeur, int hauteur) {

    SDL_Rect rectangle_aleatoire;

    rectangle_aleatoire.x = rand() % (largeur - largeur/9);
    rectangle_aleatoire.y = rand() % (hauteur - hauteur/5);
    rectangle_aleatoire.w = largeur/9;
    rectangle_aleatoire.h = hauteur/5;

    return rectangle_aleatoire;
}

/* Fonction pour afficher le rendu du puzzle */
void mise_a_jour_mini_jeu_1_niveau_3(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle, SDL_Rect rectangle_piece[45]) {

    int i;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    
    // Nettoyer le rendu
    SDL_RenderClear((*renderer));

    for (i = 0; i < 45; i++) {

        SDL_Rect rectangle_piece_bis = {i % 9 * 800 / 9, i / 9 * 260 / 5, 800 / 9, 260 / 5};
        SDL_RenderCopy((*renderer), (*texture_image_puzzle), &rectangle_piece_bis, &rectangle_piece[i]);
    }

    SDL_RenderPresent((*renderer));
}

/* Fonction pour vérifier si une pièce est proche de sa position correcte */
int piece_proche_position_correcte(SDL_Rect rectangle_piece, SDL_Rect rectangle_correct) {

    return ((abs(rectangle_piece.x - rectangle_correct.x) <= 20) && (abs(rectangle_piece.y - rectangle_correct.y) <= 20));
}

/* Fonction pour vérifier si toutes les pièces du puzzle sont bloquées (à leur position correcte) */
int verification_puzzle_fini(const int piece_bloquee[]) {

    int i;
    
    for (i = 0; i < 45; i++) 

        if (!piece_bloquee[i])
            return 0; // Au moins une pièce n'est pas verrouillée
        

    return 1; // Toutes les pièces sont verrouillées
}

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
                        int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle) {

    if((*mini_jeu) == 1) {

        int i;

        SDL_Event event_temporaire;
        SDL_bool clic_effectue = SDL_FALSE;

        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {

            switch(event.type){

                case SDL_MOUSEBUTTONDOWN :

                    SDL_GetMouseState(position_x, position_y);

                    for (i = 44; i >= 0; i--)

                        /* Vérifier si l'utilisateur a cliqué sur une pièce non bloquée */
                        if ((!piece_bloquee[i]) && ((*position_x) >= rectangle_piece[i].x) && ((*position_x) < rectangle_piece[i].x + 1600 / 9) &&
                            ((*position_y) >= rectangle_piece[i].y) && ((*position_y) < rectangle_piece[i].y + 520 / 5)) {

                            /* Sélectionner la pièce et calculer le décalage de position */
                            (*piece_selectionnee) = i;

                            (*decalage_x) = (*position_x) - rectangle_piece[i].x;
                            (*decalage_y) = (*position_y) - rectangle_piece[i].y;

                            break;
                        }

                    break;

                case SDL_MOUSEMOTION:

                    if ((*piece_selectionnee) != -1) {

                        (*position_x) = event.motion.x;
                        (*position_y) = event.motion.y;

                        /* Assurer que la pièce ne sort pas de l'écran */
                        rectangle_piece[(*piece_selectionnee)].x = (*position_x) - (*decalage_x);
                        rectangle_piece[(*piece_selectionnee)].y = (*position_y) - (*decalage_y);

                        /* Correction pour empêcher la pièce de sortir de l'écran */
                        if(rectangle_piece[(*piece_selectionnee)].x < 0) 
                            rectangle_piece[(*piece_selectionnee)].x = 0;

                        else if(rectangle_piece[(*piece_selectionnee)].x > 1600 - 1600 / 9) 
                            rectangle_piece[(*piece_selectionnee)].x = 1600 - 1600 / 9;
                        
                        if(rectangle_piece[(*piece_selectionnee)].y < 0)
                            rectangle_piece[(*piece_selectionnee)].y = 0;

                        else if(rectangle_piece[(*piece_selectionnee)].y > 520 - 520 / 5) 
                            rectangle_piece[(*piece_selectionnee)].y = 520 - 520 / 5;
                        
                    }

                    break;

                case SDL_MOUSEBUTTONUP:

                    if ((*piece_selectionnee) != -1) {

                        /* Vérifier si la pièce est à proximité de sa position correcte */
                        if (piece_proche_position_correcte(rectangle_piece[(*piece_selectionnee)], rectangle_emplacement_piece[(*piece_selectionnee)])) {
                            
                            /* Déplacer la pièce à sa position correcte et bloquer son mouvement */
                            rectangle_piece[(*piece_selectionnee)] = rectangle_emplacement_piece[(*piece_selectionnee)];
                            piece_bloquee[(*piece_selectionnee)] = 1; /* Verrouiller la pièce */
                        }

                        (*piece_selectionnee) = -1; /* Réinitialiser la pièce sélectionnée */
                    }
                    
                    break;

                /* Demande au joueur s'il veut quitter le niveau */
                case SDL_QUIT:

                    SDL_SetWindowResizable((*window), SDL_FALSE);

                    demande_quitter_niveau(renderer, rectangle_demande_quitter,
                                            surface, texture_texte, police, couleurNoire,
                                            itemsDemandeQuitter, tailleDemandeQuitter, 1600, 520);

                    while (!clic_effectue) {

                        while (SDL_PollEvent(&event_temporaire)) {

                            if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                if(clic_case(event_temporaire, itemsDemandeQuitter[1].rectangle)) {

                                    (*page_active) = CARTE;

                                    for(i = 0; i < 3; i++)
                                        avancee_niveaux[2].numero_collectible[i] = collectibles_intermediaires[i];

                                    clic_effectue = SDL_TRUE;

                                    (*largeur) = 960;
                                    (*hauteur) = 540;

                                    SDL_SetWindowSize((*window), (*largeur), (*hauteur));
                                    SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
                                }

                                else if(clic_case(event_temporaire, itemsDemandeQuitter[2].rectangle))
                                    clic_effectue = SDL_TRUE; 
                            }
                        }
                    }

                    SDL_SetWindowResizable((*window), SDL_TRUE);

                    break;

                default:
                    break;
            }
        }

        /* Vérifier si toutes les pièces sont bloquées à leur position correcte */
        if (verification_puzzle_fini(piece_bloquee)) {

            (*mini_jeu) = 0;
            (*mini_jeu_1_termine) = 1;

            (*sauter) = 0;
            (*avancer) = 0;
            (*reculer) = 0;
            (*tombe) = 0;
            (*saut) = 0;

            salon_arrivee_niveaux_2_3(position_x, position_y, tile_map, (*page_active));

            tile_map[3][5] = 0;
            tile_map[5][6] = 5;

            (*largeur) = 960;
            (*hauteur) = 540;

            SDL_SetWindowSize((*window), (*largeur), (*hauteur));
            SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

            SDL_SetWindowResizable((*window), SDL_TRUE);
        }

        mise_a_jour_mini_jeu_1_niveau_3(renderer, texture_image_puzzle, rectangle_piece);
    }

}