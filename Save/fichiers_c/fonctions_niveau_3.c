/**
 * \file fonctions_niveau_4.c
 * \brief Fichier contenant les fonctions servant à la gestion du niveau 3  
*/

#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_3.h>

/* Fonction qui permet d'initialiser les différents objets du niveau 2 */
void initialisation_objets_niveau_3(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_3, SDL_Texture **texture_image_dossier_niveau_3,
                                    SDL_Texture **texture_image_sol_niveau_3, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, 
                                    SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4,
                                    SDL_Texture **texture_image_puzzle, SDL_Texture **texture_image_sol_labyrinthe,
                                    SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_fin_labyrinthe) {

    /* Chargement des images pour le niveau 3 */

    chargement_image(renderer, surface, texture_image_fond_niveau_3, "./images/niveau_3/fond_niveau_3.jpg");
    chargement_image(renderer, surface, texture_image_dossier_niveau_3, "./images/niveau_3/dossier_windows_xp.png");
    chargement_image(renderer, surface, texture_image_sol_niveau_3, "./images/niveau_3/sol_niveau_3.jpg");
    chargement_image(renderer, surface, barre_windows_1, "./images/niveau_3/windows_1.png");
    chargement_image(renderer, surface, barre_windows_2, "./images/niveau_3/windows_2.png");
    chargement_image(renderer, surface, barre_windows_3, "./images/niveau_3/windows_3.png");
    chargement_image(renderer, surface, barre_windows_4, "./images/niveau_3/windows_4.png");

    chargement_image(renderer, surface, texture_image_puzzle, "./images/niveau_3/ventilo.png");

    chargement_image(renderer, surface, texture_image_sol_labyrinthe, "./images/labyrinthe/sol_labyrinthe.png");
    chargement_image(renderer, surface, texture_image_bordure_labyrinthe, "./images/labyrinthe/bordure_labyrinthe.png");
    chargement_image(renderer, surface, texture_image_fin_labyrinthe, "./images/labyrinthe/fin_labyrinthe.png");
}

/* Fonction pour obtenir un rectangle représentant une pièce de puzzle aléatoire */
SDL_Rect rectangle_piece_aleatoire(int largeur, int hauteur) {

    SDL_Rect rectangle_aleatoire;

    rectangle_aleatoire.x = rand() % (largeur - largeur / 9);
    rectangle_aleatoire.y = rand() % (hauteur - hauteur / 5);
    rectangle_aleatoire.w = largeur/9;
    rectangle_aleatoire.h = hauteur/5;

    return rectangle_aleatoire;
}

/* Fonction pour afficher le rendu du puzzle */
void mise_a_jour_mini_jeu_1_niveau_3(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle, SDL_Rect rectangle_piece[45]) {

    int i;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    
    /* Nettoyer le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

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
            return 0; /* Au moins une pièce n'est pas verrouillée */
        

    return 1; /* Toutes les pièces sont verrouillées */
}

/* Fonction qui permet d'initialiser le second mini-jeu du niveau 3 */
void mini_jeu_2_niveau_3(int *position_x, int *position_y, int *bloc_x, int *bloc_y, int tile_map[24][32]) {

    int x, y;

    /* Positionnement du personnage en haut à gauche */

    (*position_x) = 1;
    (*position_y) = 1;

    /* Position initiale du bloc à deplacer en coordonnées de tuile */

    (*bloc_x) = 2;
    (*bloc_y) = 1;

    /* Création du second mini-jeu */
    int initialisation_tile_map[24][32] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 2},
        {2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2},
        {2, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 2},
        {2, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 2},
        {2, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 2},
        {2, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2},
        {2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 2},
        {2, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2},
        {2, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 2},
        {2, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 2},
        {2, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 3, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}        
        
    };

    /* Copie du tile-map */
    for (y = 0; y < 24; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];
}

/* Fonction pour traiter les commandes utilisateur */
void traitement_touches(int *position_x, int *position_y, int *bloc_x, int *bloc_y, int tilemap[24][32], int direction) {

    /* Vérification si le joueur est à côté du bloc */
    if ((((*position_x) == (*bloc_x) - 1) && ((*position_y) == (*bloc_y))) ||   /* Le joueur est à gauche du bloc */
        (((*position_x) == (*bloc_x) + 1) && ((*position_y) == (*bloc_y))) ||   /* Le joueur est à droite du bloc */
        (((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y) - 1)) ||   /* Le joueur est au dessus du bloc */
        (((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y) + 1))) {   /* Le joueur est en dessous du bloc */

        /* Le personnage est au dessus du bloc */
        if (((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y) - 1)) { 

            /* On veut pousser le bloc */
            if(direction == 1) {
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if ((tilemap[*bloc_y + 1][*bloc_x] == 0) || (tilemap[*bloc_y + 1][*bloc_x] == 3)) {

                    (*bloc_y)++;
                    (*position_y)++;
                    SDL_Delay(150);
                }
            }

            /* On veut tirer le bloc */
            if(direction == 0){
                /* On regarde si le personnage peut être sur la case de derrière */
                if ((tilemap[*position_y - 1][*position_x] == 0) || (tilemap[*position_y - 1][*position_x] == 3)) {

                    (*position_y)--;
                    (*bloc_y)--;
                    SDL_Delay(150);
                }
            }
        } 
        
        /* Le personnage est en dessous du bloc */
        else if (((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y + 1))) {

            /* On veut pousser le bloc */
            if(direction == 0) {
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if ((tilemap[*bloc_y - 1][*bloc_x] == 0) || (tilemap[*bloc_y - 1][*bloc_x] == 3)) {

                    (*bloc_y)--;
                    (*position_y)--;
                    SDL_Delay(150);
                }
            }

            /* On veut tirer le bloc */
            if(direction == 1) {
                /* On regarde si le personnage peut être sur la case de derrière */
                if ((tilemap[*position_y + 1][*position_x] == 0) || (tilemap[*position_y + 1][*position_x] == 3)) {

                    (*position_y)++;
                    (*bloc_y)++;
                    SDL_Delay(150);
                }
            }
        } 
        
        /* Le personnage est à gauche du bloc */
        else if (((*position_x) == (*bloc_x - 1)) && ((*position_y) == (*bloc_y))) {  

            /* On veut pousser le bloc */
            if(direction == 3) {
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if ((tilemap[*bloc_y][*bloc_x + 1] == 0) || (tilemap[*bloc_y][*bloc_x + 1] == 3)) {

                    (*bloc_x)++;
                    (*position_x)++;
                    SDL_Delay(150);
                }
            }

            /* On veut tirer le bloc */
            if(direction == 2) {
                /* On regarde si le personnage peut être sur la case de derrière */
                if ((tilemap[*position_y][*position_x - 1] == 0) || (tilemap[*position_y][*position_x - 1] == 3)) {

                    (*position_x)--;
                    (*bloc_x)--;
                    SDL_Delay(150);
                }
            }
        } 
        
        /* Le personnage est à droite du bloc */
        else if (((*position_x) == (*bloc_x + 1)) && ((*position_y) == (*bloc_y))) {

            /* On veut pousser le bloc */
            if(direction == 2) {
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if ((tilemap[*bloc_y][*bloc_x - 1] == 0) || (tilemap[*bloc_y][*bloc_x - 1] == 3)) {

                    (*bloc_x)--;
                    (*position_x)--;
                    SDL_Delay(150);
                }
            }

            /* On veut tirer le bloc */
            if(direction == 3) {
                /* On regarde si le personnage peut être sur la case de derrière */
                if ((tilemap[*position_y][*position_x + 1] == 0) || (tilemap[*position_y][*position_x + 1] == 3)) {
                    (*position_x)++;
                    (*bloc_x)++;
                    SDL_Delay(150);
                }
            }
        }
    }
}

/* Fonction pour mettre à jour les tuiles de bordure lorsque le bloc atteint la fin du labyrinthe */
int mise_a_jour_bordures_niveau_3(SDL_Renderer* renderer, SDL_Texture* texture_image_mur_termine, int tilemap[24][32], int x_tile, int y_tile,
                                SDL_Rect *rectangle_tile, int largeur_tile, int hauteur_tile) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[y_tile][x_tile] = 3;

    rectangle_tile->x = x_tile * largeur_tile;
    rectangle_tile->y = y_tile * hauteur_tile;
    rectangle_tile->w = largeur_tile;
    rectangle_tile->h = hauteur_tile;

    SDL_RenderCopy(renderer, texture_image_mur_termine, NULL, rectangle_tile);

    SDL_RenderPresent(renderer);

    SDL_Delay(20); 

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à droite de la courante */
    if((tilemap[y_tile][x_tile + 1] == 2) && (x_tile < 31)) 
        return mise_a_jour_bordures_niveau_3(renderer, texture_image_mur_termine, tilemap, x_tile + 1, y_tile,
                                            rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile à gauche de la courante */
    else if((tilemap[y_tile][x_tile - 1] == 2) && (x_tile > 0))
        return mise_a_jour_bordures_niveau_3(renderer, texture_image_mur_termine, tilemap, x_tile - 1, y_tile,
                                            rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile en dessous de la courante */
    else if((tilemap[y_tile + 1][x_tile] == 2) && (y_tile < 31))
        return mise_a_jour_bordures_niveau_3(renderer, texture_image_mur_termine, tilemap, x_tile, y_tile + 1,
                                            rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile au dessus de la courante */
    else if((tilemap[y_tile - 1][x_tile] == 2) && (y_tile > 0))
        return mise_a_jour_bordures_niveau_3(renderer, texture_image_mur_termine, tilemap, x_tile, y_tile - 1,
                                            rectangle_tile, largeur_tile, hauteur_tile);

    return 0;
}

/* Fonction qui permet de mettre à jour le second mini-jeu du niveau 2 */
void mise_a_jour_mini_jeu_2_niveau_3(SDL_Renderer **renderer, modes_t *modeActif, SDL_Texture **texture_image_sol_labyrinthe,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture_image_mur_mini_jeu, SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_mur_termine,
                                     SDL_Texture **texture_image_fin_labyrinthe,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile, int bloc_x, int bloc_y,
                                     SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                     int position_x, int position_y, int tile_map_mini_jeu_niveau_3[24][32], niveaux *avancee_niveaux,
                                     int largeur_tile, int hauteur_tile) {

    int x, y;

    Mix_Chunk *effet_sonore;

    /* Nettoyer le renderer */
    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
    
    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Rendu tilemap */
    /* Mode Normal */
    if((*modeActif) == MODE_NORMAL) 
        for(y = 0; y < 24; y++)
            for(x = 0; x < 32; x++) {

                /* Rendu de chaque tuile en fonction de son type */

                if((!tile_map_mini_jeu_niveau_3[y][x]) || (tile_map_mini_jeu_niveau_3[y][x] == 5))
                    (*texture) = (*texture_image_sol_labyrinthe);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 1)
                    (*texture) = (*texture_image_mur_mini_jeu);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 2)
                    (*texture) = (*texture_image_bordure_labyrinthe);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 3)
                    (*texture) = (*texture_image_mur_termine);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 4)
                    (*texture) = (*texture_image_mur_mini_jeu);

                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile;
                rectangle_tile->h = largeur_tile;

                if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
                    erreur("Copie de la texture");

                if((tile_map_mini_jeu_niveau_3[y][x] == 5) && (avancee_niveaux[2].numero_collectible[1] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

    /* Mode Difficile */
    else if((*modeActif) == MODE_HARD)
        for(y = position_y - 2; y <= position_y + 2; y++)
            for(x = position_x - 2; x <= position_x + 2; x++) {

                /* Rendu de chaque tuile en fonction de son type */

                if(!tile_map_mini_jeu_niveau_3[y][x] || (tile_map_mini_jeu_niveau_3[y][x] == 5))
                    (*texture) = (*texture_image_sol_labyrinthe);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 1)
                    (*texture) = (*texture_image_mur_mini_jeu);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 2)
                    (*texture) = (*texture_image_bordure_labyrinthe);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 3)
                    (*texture) = (*texture_image_mur_termine);
                
                else if(tile_map_mini_jeu_niveau_3[y][x] == 4)
                    (*texture) = (*texture_image_mur_mini_jeu);

                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile;
                rectangle_tile->h = largeur_tile;

                if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
                    erreur("Copie de la texture");

                if((tile_map_mini_jeu_niveau_3[y][x] == 5) && (avancee_niveaux[2].numero_collectible[1] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

    /* Passage secret vers un collectible */
    if((position_x == 12) && (position_y == 11) && (tile_map_mini_jeu_niveau_3[position_y][position_x] == 4)){

        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/tient_tient_tient.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
        
        Mix_PlayChannel(1, effet_sonore, 0);

        tile_map_mini_jeu_niveau_3[11][12] = 0;
        tile_map_mini_jeu_niveau_3[12][12] = 0;
        tile_map_mini_jeu_niveau_3[12][13] = 5;

        (*texture) = (*texture_image_sol_labyrinthe);

        rectangle_tile->x = 12 * largeur_tile;
        rectangle_tile->y = 11 * hauteur_tile;
        rectangle_tile->w = largeur_tile;
        rectangle_tile->h = largeur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");

        rectangle_tile->y = 12 * hauteur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");

        rectangle_tile->x = 13 * largeur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");
    }

    /* Remise à l'état initial */
    if((position_x == 12) && (position_y == 10) && (!tile_map_mini_jeu_niveau_3[11][12])){

        tile_map_mini_jeu_niveau_3[11][12] = 4;
        tile_map_mini_jeu_niveau_3[12][12] = 4;
        tile_map_mini_jeu_niveau_3[12][13] = 4;
        
        (*texture) = (*texture_image_mur_mini_jeu);

        rectangle_tile->x = 12 * largeur_tile;
        rectangle_tile->y = 11 * hauteur_tile;
        rectangle_tile->w = largeur_tile;
        rectangle_tile->h = largeur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");

        rectangle_tile->y = 12 * hauteur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");

        rectangle_tile->x = 13 * largeur_tile;

        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
            erreur("Copie de la texture");
    }

    /* Rendu du bloc à deplacer */

    rectangle_tile->x = bloc_x * largeur_tile;
    rectangle_tile->y = bloc_y * hauteur_tile;
    rectangle_tile->w = largeur_tile;
    rectangle_tile->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_fin_labyrinthe), NULL, rectangle_tile))
        erreur("Copie de la texture");

    /* Rendu du bloc d'arriver */

    rectangle_tile->x = 30 * largeur_tile;
    rectangle_tile->y = 22 * hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_mur_termine), NULL, rectangle_tile))
        erreur("Copie de la texture");

    /* Rendu du joueur */

    rectangle_personnage->x = position_x * largeur_tile;
    rectangle_personnage->y = position_y * hauteur_tile;
    rectangle_personnage->w = largeur_tile;
    rectangle_personnage->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_personnage), NULL, rectangle_personnage))
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur_tile * 31;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur_tile;
    rectangle_plein_ecran->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
} 

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans les mini-jeux du niveau 3 */
void mini_jeux_niveau_3(SDL_Event *event, SDL_Renderer **renderer, SDL_Window **window,
                        SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                        niveaux *avancee_niveaux, int tile_map[18][32],
                        int *mini_jeu, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                        int *position_x, int *position_y, SDL_Texture **texture,
                        int *largeur, int *hauteur, SDL_Rect *rectangle_demande_quitter,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire,
                        itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int collectibles_intermediaires[3],
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
                        SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, modes_t *modeActif) {

    int i;

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    Mix_Chunk *effet_sonore;

    if((*mini_jeu) == 1) {

        while (SDL_PollEvent(event) != 0) {

            switch(event->type){

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

                        (*position_x) = event->motion.x;
                        (*position_y) = event->motion.y;

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

            if(((*musique) = Mix_LoadMUS("./sons/musiques/salon.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

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

            if((*mini_jeu_2_termine))
                tile_map[3][24] = 0;

            (*largeur) = 960;
            (*hauteur) = 540;

            SDL_SetWindowSize((*window), (*largeur), (*hauteur));
            SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

            SDL_SetWindowResizable((*window), SDL_TRUE);
        }

        mise_a_jour_mini_jeu_1_niveau_3(renderer, texture_image_puzzle, rectangle_piece);
    }

    else if((*mini_jeu) == 2) {

        while (SDL_PollEvent(event)) {

            switch(event->type) {

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
                    
                    (*largeur_tile) = (*largeur) / 32;
                    (*hauteur_tile) = (*hauteur) / 24;

                    break;
    
                /* 
                    On peut pas traiter l'appui de 2 touches en même temps donc 
                    On stocke une valeur pour permettre l'appuie de 2 touches en même 
                    Et ainsi pouvoir traiter cette information 
                */
                case SDL_KEYDOWN:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 1;
                    
                    if(event->key.keysym.sym == (*touche_descendre))
                        (*descendre) = 1;
                    
                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 1;
                    
                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 1;
                    
                    if(event->key.keysym.sym == (*touche_interagir))
                        (*interagir) = 1;
                    
                    break;

                case SDL_KEYUP:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 0;
                    
                    if(event->key.keysym.sym == (*touche_descendre))
                        (*descendre) = 0;
                    
                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 0;
                    
                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 0;
                    
                    if(event->key.keysym.sym == (*touche_interagir))
                        (*interagir) = 0;
                    
                    break;

                /* Option plein écran */
                case SDL_MOUSEBUTTONDOWN:

                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window)) {

                        redimensionnement_fenetre((*event), largeur, hauteur);

                        (*largeur_tile) = (*largeur) / 32;
                        (*hauteur_tile) = (*hauteur) / 24;
                    }

                    break;

                /* Demande au joueur s'il veut quitter le niveau */
                case SDL_QUIT:

                    SDL_SetWindowResizable((*window), SDL_FALSE);

                    demande_quitter_niveau(renderer, rectangle_demande_quitter,
                                           surface, texture_texte, police, couleurNoire,
                                           itemsDemandeQuitter, tailleDemandeQuitter, (*largeur), (*hauteur));

                    while (!clic_effectue) {

                        while (SDL_PollEvent(&event_temporaire)) {

                            if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                if(clic_case(event_temporaire, itemsDemandeQuitter[1].rectangle)) {

                                    for(i = 0; i < 3; i++)
                                        avancee_niveaux[2].numero_collectible[i] = collectibles_intermediaires[i];

                                    (*page_active) = CARTE;

                                    clic_effectue = SDL_TRUE; 
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

        /* Traitement de l'appuie des touches */
        if((*sauter)) {

            if((*interagir))
                traitement_touches(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3, 0);

            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if (((tile_map_mini_jeu_niveau_3[(*position_y) - 1][(*position_x)] == 0) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y) - 1][(*position_x)] == 3) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y) - 1][(*position_x)] == 4) ||
                      (tile_map_mini_jeu_niveau_3[(*position_y) - 1][(*position_x)] == 5)) &&
                     (!(((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y) + 1)))) {

                (*position_y)--;
                SDL_Delay(150);
            }
        }

        if((*descendre)) {

            if((*interagir))
                traitement_touches(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3, 1);

            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if (((tile_map_mini_jeu_niveau_3[(*position_y) + 1][(*position_x)] == 0) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y) + 1][(*position_x)] == 3) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y) + 1][(*position_x)] == 4) ||
                      (tile_map_mini_jeu_niveau_3[(*position_y) + 1][(*position_x)] == 5)) &&
                     (!(((*position_x) == (*bloc_x)) && ((*position_y) == (*bloc_y) - 1)))) {

                (*position_y)++;
                SDL_Delay(150);
            }
        }

        if((*reculer)) {

            if((*interagir))
                traitement_touches(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3, 2);

            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if (((tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) - 1] == 0) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) - 1] == 3) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) - 1] == 4) ||
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) - 1] == 5)) &&
                     (!(((*position_x) == (*bloc_x) + 1) && ((*position_y) == (*bloc_y))))) {

                (*position_x)--;
                SDL_Delay(150);
            }
        }

        if((*avancer)) {

            if((*interagir))
                traitement_touches(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3, 3);

            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if (((tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) + 1] == 0) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) + 1] == 3) || 
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) + 1] == 4) ||
                      (tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x) + 1] == 5)) &&
                     (!(((*position_x) == (*bloc_x) - 1) && ((*position_y) == (*bloc_y))))) {

                (*position_x)++;
                SDL_Delay(150);
            }
        }

        /* Cas où le joueur récupère le second collectible */
        if((tile_map_mini_jeu_niveau_3[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[2].numero_collectible[1])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[2].numero_collectible[1] = 1;
        }

        /* Vérifier si le bloc atteint la fin du labyrinthe et mettre à jour les tuiles de bordure si nécessaire */
        if(((*bloc_x) == 30) && ((*bloc_y) == 22)) {
            mise_a_jour_bordures_niveau_3((*renderer), (*texture_image_mur_termine), tile_map_mini_jeu_niveau_3, 31, 23,
                                          rectangle_tile, (*largeur_tile), (*hauteur_tile));

            if(((*musique) = Mix_LoadMUS("./sons/musiques/salon.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);
            
            (*mini_jeu) = 0;
            (*mini_jeu_2_termine) = 1;  

            (*largeur_tile) = (*largeur) / 32;
            (*hauteur_tile) = (*hauteur) / 18;

            (*sauter) = 0;
            (*avancer) = 0;
            (*reculer) = 0;
            (*tombe) = 0;
            (*saut) = 0;

            salon_arrivee_niveaux_2_3(position_x, position_y, tile_map, (*page_active));

            tile_map[3][24] = 0;

            if((*mini_jeu_1_termine)) {
                tile_map[3][5] = 0;
                tile_map[5][6] = 5;
            }
        }

        mise_a_jour_mini_jeu_2_niveau_3(renderer, modeActif, texture_image_sol_labyrinthe,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        texture_image_mur_mini_jeu, texture_image_bordure_labyrinthe, texture_image_mur_termine,
                                        texture_image_fin_labyrinthe,
                                        texture, rectangle_tile, (*bloc_x), (*bloc_y),
                                        texture_image_personnage, rectangle_personnage,
                                        (*position_x), (*position_y), tile_map_mini_jeu_niveau_3, avancee_niveaux,
                                        (*largeur_tile), (*hauteur_tile));
    }
}