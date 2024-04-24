/**
 * \file fonctions_niveau_4.c
 * \brief Fichier contenant les fonctions servant à la gestion du niveau 2  
*/
#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_2.h>

/** 
 * \fn void initialisation_objets_niveau_2(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_fond_niveau_2, SDL_Texture **texture_image_dossier_niveau_2, SDL_Texture **texture_image_sol_niveau_2, SDL_Texture **texture_image_mur_mini_jeu, SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal, SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit, SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche, SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine)
 * \brief Fonction qui permet d'initialiser les différents objets du niveau 2 
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Surface SDL.
 * \param texture_image_fond_niveau_2 Texture de l'image de fond du niveau 2.
 * \param texture_image_dossier_niveau_2 Texture de l'image du dossier du niveau 2.
 * \param texture_image_sol_niveau_2 Texture de l'image du sol du niveau 2.
 * \param texture_image_mur_mini_jeu Texture de l'image du mur du mini-jeu.
 * \param texture_image_pipe_vertical Texture de l'image du tuyau vertical.
 * \param texture_image_pipe_horizontal Texture de l'image du tuyau horizontal.
 * \param texture_image_pipe_haut_droit Texture de l'image du tuyau haut droit.
 * \param texture_image_pipe_bas_droit Texture de l'image du tuyau bas droit.
 * \param texture_image_pipe_bas_gauche Texture de l'image du tuyau bas gauche.
 * \param texture_image_pipe_haut_gauche Texture de l'image du tuyau haut gauche.
 * \param texture_image_pipe_courant Texture de l'image du tuyau courant.
 * \param texture_image_mur_termine Texture de l'image du mur terminé.
 * \see chargement_image
 */
void initialisation_objets_niveau_2(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_2, SDL_Texture **texture_image_dossier_niveau_2,
                                    SDL_Texture **texture_image_sol_niveau_2, SDL_Texture **texture_image_mur_mini_jeu,
                                    SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                                    SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                                    SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                                    SDL_Texture **texture_image_pipe_courant,
                                    SDL_Texture **texture_image_mur_termine) {

    /* Chargement des images pour le niveau 2 */

    chargement_image(renderer, surface, texture_image_fond_niveau_2, "./images/niveau_2/fond_niveau_2.png");
    chargement_image(renderer, surface, texture_image_dossier_niveau_2, "./images/niveau_2/dossier_linux.png");
    chargement_image(renderer, surface, texture_image_sol_niveau_2, "./images/niveau_2/sol_niveau_2.png");
    chargement_image(renderer, surface, texture_image_mur_mini_jeu, "./images/labyrinthe/mur_mini_jeux.png");
    chargement_image(renderer, surface, texture_image_pipe_vertical, "./images/pipe/pipe_vertical.png");
    chargement_image(renderer, surface, texture_image_pipe_horizontal, "./images/pipe/pipe_horizontal.png");
    chargement_image(renderer, surface, texture_image_pipe_haut_droit, "./images/pipe/pipe_HD.png");
    chargement_image(renderer, surface, texture_image_pipe_bas_droit, "./images/pipe/pipe_BD.png");
    chargement_image(renderer, surface, texture_image_pipe_bas_gauche, "./images/pipe/pipe_BG.png");
    chargement_image(renderer, surface, texture_image_pipe_haut_gauche, "./images/pipe/pipe_HG.png");
    chargement_image(renderer, surface, texture_image_pipe_courant, "./images/pipe/pipe_courant.png");
    chargement_image(renderer, surface, texture_image_mur_termine, "./images/labyrinthe/mur_fin_mini_jeux.png");
}

/** 
 * \fn void mini_jeu_1_niveau_2(int *position_x, int *position_y, int tile_map[19][27]) 
 * \brief Fonction qui permet d'initialiser le premier mini-jeu du niveau 2
 * \param position_x position horizontal du personnage sur le tile map
 * \param position_y position verticale du personnage sur le tile map
 * \param tile_map map ou se trouve le personnage
 */
void mini_jeu_1_niveau_2(int *position_x, int *position_y, int tile_map[19][27]) {

    int x, y;

    /* Positionnement du curseur en haut à gauche */

    (*position_x) = 0;
    (*position_y) = 0;

    /* Création du premier mini-jeu */
    int initialisation_tile_map[19][27] = {

        {0,     0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,      0},

        {0,     4, 4, 6, 5, 2, 4, 3, 5, 4, 1, 2, 5,     0,  4, 6, 2, 6, 3, 4, 6, 4, 6, 2, 4, 0,      0},
        {0,     2, 3, 4, 5, 4, 1, 4, 4, 2, 0, 5, 4,     0,  1, 5, 4, 1, 6, 4, 2, 6, 2, 1, 0, 0,      0},
        {0,     1, 4, 2, 6, 1, 5, 4, 2, 3, 2, 3, 6,     0,  4, 5, 0, 6, 2, 5, 1, 3, 4, 6, 5, 0,      0},
        {0,     2, 6, 3, 4, 5, 0, 0, 3, 1, 3, 6, 5,     0,  5, 6, 0, 6, 2, 3, 5, 2, 3, 0, 1, 4,      0},
        {0,     3, 5, 1, 4, 4, 5, 0, 6, 2, 0, 0, 1,     0,  1, 4, 2, 3 ,6, 0, 5, 3, 4, 0, 4, 6,      0},
        {0,     4, 2, 3, 1, 6, 1, 3, 4, 6, 6, 1, 6,     0,  6, 2, 1, 4, 4, 1, 3, 4, 1, 0, 0, 1,      0},
        {0,     0, 6, 3, 5, 4, 4, 3, 2, 6, 6, 2, 2,     0,  5, 3, 6, 2, 3, 4, 6, 5, 2, 2, 5, 4,      0},
        {0,     0, 0, 5, 2, 1, 3, 1, 1, 4, 0, 6, 6,     0,  4, 3, 0, 0, 4, 2 ,3, 6, 4, 5, 1, 3,      0},

        {0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,     0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,      0},

        {0,     4, 2, 1, 3, 4, 5, 4, 3, 3, 1, 2, 3,     0,  4, 6, 3, 2, 6, 4, 5, 3, 0, 4, 2, 4,      0},
        {0,     6, 1, 0, 4, 1, 5, 3, 2, 4, 6, 2, 1,     0,  2, 5, 0, 3, 2, 6, 5, 4, 0, 5, 1, 3,      0},
        {0,     4, 4, 0, 6, 2, 3, 5, 6, 2, 3, 6, 6,     0,  5, 1, 0, 6, 2, 3, 2, 4, 3, 6, 5, 4,      0},
        {0,     6, 5, 3, 1, 2, 4, 3, 4, 5, 6, 0, 0,     0,  3, 4, 6, 0, 2, 3, 4, 3, 2, 4, 2, 6,      0},
        {0,     4, 2, 2, 0, 0, 1, 6, 4, 3, 1, 5, 4,     0,  4, 6, 1, 6, 0, 0, 0, 1, 2, 6, 0, 2,      0},
        {0,     5, 6, 0, 5, 4, 3, 1, 3, 3, 3, 0, 4,     0,  5, 4, 6, 2, 1, 0, 3, 4, 2, 1, 0, 1,      0},
        {0,     5, 4, 1, 2, 6, 5, 6, 2, 4, 5, 2, 1,     2,  4, 3, 1, 4, 3, 6, 2, 1, 5, 4, 6, 4,      0},
        {0,     5, 3, 5, 2, 1, 6, 1, 3, 5, 6, 3, 0,     0,  6, 5, 3, 5, 1, 3, 4, 3, 5, 4, 1, 3,      0},

        {0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0}
        
    };

    /* Copie du tilemap */
    for (y = 0; y < 19; y++)
        for (x = 0; x < 27; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];
}

/** 
 * \fn int verification_chemin(int x, int y, int x_precedent, int y_precedent, int tilemap[19][27], int x_arrivee, int y_arrivee)
 * \brief Fonction de vérification du chemin 
 * \param x position actuelle verticale dans la vérification du chemin
 * \param y position actuelle horizontale dans la vérification du chemin
 * \param x_precedent position précédente à la position actuelle de x
 * \param y_precedent position précédente à la position actuelle de y
 * \param tilemap map à vérifier
 * \param x_arrivee coordonnée x ou se trouve la sortie
 * \param y_arrivee coordonnée y ou se trouve la sortie
 * \return booléen (1 si le chemin est bon sinon 0)
 */
int verification_chemin(int x, int y, int x_precedent, int y_precedent, int tilemap[19][27], int x_arrivee, int y_arrivee) {

    /* Vérifier si les coordonnées actuelles correspondent aux coordonnées de l'arrivée */
    if ((x == x_arrivee) && (y == y_arrivee)) {
        return 1;
    }
    /* Vérification du premier tuyau car il n'est pas dans la boucle de vérification */
    if(tilemap[1][2] != 3){
        return 0;
    }

    /* Vérifier si le tuyau actuel est correctement aligné avec le précédent */

    switch (tilemap[y][x]) {

        case 1: /* Tuyau vertical */
            /* On vient du dessus */
            if (y_precedent == (y - 1)) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if((tilemap[y+1][x] != 2) && (tilemap[y+1][x] != 4) && (tilemap[y+1][x] != 5))
                    return verification_chemin(x, y + 1, x, y, tilemap, x_arrivee, y_arrivee) ; /* On va en bas */
            }

            /* On vient d'en dessous */
            else
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if((tilemap[y-1][x] != 2) && (tilemap[y-1][x] != 3) && (tilemap[y-1][x] != 6))
                    return verification_chemin(x, y - 1, x, y, tilemap, x_arrivee, y_arrivee); /* On va en haut */
                
            break;

        case 2: /* Tuyau horizontal */
            /* On vient de la gauche */
            if (x_precedent == (x - 1)) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1) && (tilemap[y][x+1] != 3) && (tilemap[y][x+1] != 4))
                    return verification_chemin(x + 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à droite */
            }

            /* On vient de la droite */
            else
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if((tilemap[y][x-1] != 1) && (tilemap[y][x-1] != 5) && (tilemap[y][x-1] != 6))
                    return verification_chemin(x - 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à gauche */
                
            break;

        case 3: /* Tuyau HD */
            /* On vient du dessus */
            if (y_precedent == (y - 1)) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1) && (tilemap[y][x+1] != 3) && (tilemap[y][x+1] != 4))
                    return verification_chemin(x + 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à droite */
            }
                
            /* On vient de la droite */
            else
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if((tilemap[y-1][x] != 2) && (tilemap[y-1][x] != 3) && (tilemap[y-1][x] != 6))
                    return verification_chemin(x, y - 1, x, y, tilemap, x_arrivee, y_arrivee); /* On va en haut */
                
            break;

        case 4: /* Tuyau BD */
            /* On vient de la droite */
            if (x_precedent == (x + 1)) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if((tilemap[y+1][x] != 2) && (tilemap[y+1][x] != 4) && (tilemap[y+1][x] != 5))
                    return verification_chemin(x, y + 1, x, y, tilemap, x_arrivee, y_arrivee); /* On va en bas */
            }
                
            /* On vient du bas */
            else
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1) && (tilemap[y][x+1] != 3) && (tilemap[y][x+1] != 4))
                    return verification_chemin(x + 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à droite */
                
            break;

        case 5: /* Tuyau BG */
            /* On vient de la gauche */
            if (x_precedent == (x - 1)) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if((tilemap[y+1][x] != 2) && (tilemap[y+1][x] != 4) && (tilemap[y+1][x] != 5))
                    return verification_chemin(x, y + 1, x, y, tilemap, x_arrivee, y_arrivee); /* On va en bas */
            }
                
            /* On vient du bas */
            else
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if((tilemap[y][x-1] != 1) && (tilemap[y][x-1] != 5) && (tilemap[y][x-1] != 6))
                    return verification_chemin(x - 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à gauche */
                
            break;

        case 6: /* Tuyau HG */
            /* On vient du haut */
            if (y_precedent == (y - 1)) {
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if((tilemap[y][x-1] != 1) && (tilemap[y][x-1] != 5) && (tilemap[y][x-1] != 6))
                    return verification_chemin(x - 1, y, x, y, tilemap, x_arrivee, y_arrivee); /* On va à gauche */
            }
                
            /* On vient de la gauche */
            else
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if((tilemap[y-1][x] != 2) && (tilemap[y-1][x] != 3) && (tilemap[y-1][x] != 6))
                    return verification_chemin(x, y - 1, x, y, tilemap, x_arrivee, y_arrivee); /* On va au haut */
                
            break;
        
        default:
            return 0;

            break;
    }
    return 0;
}

/** 
 * \fn int mise_a_jour_bordures_niveau_2(SDL_Renderer* renderer, SDL_Texture* texture_image_mur_termine, int tilemap[19][27], int x_tile, int y_tile, int x, int y, SDL_Rect *rectangle_tile, int largeur_tile, int hauteur_tile)
 * \brief Fonction pour mettre à jour les tuiles de bordure lorsque le bloc atteint la 9 du labyrinthe 
 * \param renderer Renderer SDL.
 * \param texture_image_mur_termine Texture de l'image du mur terminé.
 * \param tilemap Carte de tuiles du niveau 2.
 * \param x_tile Position x de la tuile à mettre à jour.
 * \param y_tile Position y de la tuile à mettre à jour.
 * \param x Position x de la tuile dans l'écran.
 * \param y Position y de la tuile dans l'écran.
 * \param rectangle_tile Rectangle pour chaque tuile.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * \return appel récursif pour mettre les différents rectangle à jour jusqu'à la fin (appel se finissant par un 0)
 */
int mise_a_jour_bordures_niveau_2(SDL_Renderer* renderer, SDL_Texture* texture_image_mur_termine, int tilemap[19][27], int x_tile, int y_tile, int x, int y,
                                  SDL_Rect *rectangle_tile, int largeur_tile, int hauteur_tile) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[y_tile][x_tile] = 9;

    rectangle_tile->x = x_tile * largeur_tile;
    rectangle_tile->y = y_tile * hauteur_tile;
    rectangle_tile->w = largeur_tile;
    rectangle_tile->h = hauteur_tile;

    SDL_RenderCopy(renderer, texture_image_mur_termine, NULL, rectangle_tile);

    SDL_RenderPresent(renderer);

    SDL_Delay(20);

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à gauche de la courante */
    if((!tilemap[y_tile][x_tile - 1]) && (x_tile > x) && (!y_tile)) 
        return mise_a_jour_bordures_niveau_2(renderer, texture_image_mur_termine, tilemap, x_tile - 1, y_tile, x, y,
                                             rectangle_tile, largeur_tile, hauteur_tile);
    
    else if(((tilemap[y_tile][x_tile - 1] == 8) || (tilemap[y_tile][x_tile - 1] == 1)) && (x_tile > x) && (!y_tile))
        return mise_a_jour_bordures_niveau_2(renderer, texture_image_mur_termine, tilemap, x_tile - 2, y_tile, x, y,
                                     rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile à droite de la courante */
    else if((!tilemap[y_tile][x_tile + 1]) && (x_tile < x) && (y_tile == (19 - 1))) 
        return mise_a_jour_bordures_niveau_2(renderer, texture_image_mur_termine, tilemap, x_tile + 1, y_tile, x, y,
                                             rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile en bas de la courante */
    else if((!tilemap[y_tile + 1][x_tile]) && (y_tile < y) && (!x_tile)) 
        return mise_a_jour_bordures_niveau_2(renderer, texture_image_mur_termine, tilemap, x_tile, y_tile + 1, x, y,
                                             rectangle_tile, largeur_tile, hauteur_tile);
    
    /* Tuile en haut de la courante */
    else if((!tilemap[y_tile - 1][x_tile]) && (y_tile > y) && (x_tile == (27 - 1))) 
        return mise_a_jour_bordures_niveau_2(renderer, texture_image_mur_termine, tilemap, x_tile, y_tile - 1, x, y,
                                             rectangle_tile, largeur_tile, hauteur_tile);

    return 0;
}

/** 

 * \fn void mise_a_jour_mini_jeu_1_niveau_2(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture, SDL_Rect *rectangle_tile, int position_x, int position_y, int tile_map_mini_jeu_niveau_2[19][27], int largeur, int hauteur, int largeur_tile, int hauteur_tile, SDL_Texture **texture_image_mur_mini_jeu, SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal, SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit, SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche, SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine)
 * \brief Fonction qui permet de mettre à jour le premier mini-jeu du niveau 2 
 * \param renderer Pointeur vers le renderer SDL.
 * \param rectangle_plein_ecran Rectangle pour le plein écran.
 * \param texture_image_plein_ecran Texture de l'image du plein écran.
 * \param texture Texture SDL.
 * \param rectangle_tile Rectangle pour chaque tuile.
 * \param position_x Position x du joueur.
 * \param position_y Position y du joueur.
 * \param tile_map_mini_jeu_niveau_2 Carte de tuiles du mini-jeu 1 du niveau 2.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * \param texture_image_mur_mini_jeu Texture de l'image du mur du mini-jeu.
 * \param texture_image_pipe_vertical Texture de l'image du tuyau vertical.
 * \param texture_image_pipe_horizontal Texture de l'image du tuyau horizontal.
 * \param texture_image_pipe_haut_droit Texture de l'image du tuyau haut droit.
 * \param texture_image_pipe_bas_droit Texture de l'image du tuyau bas droit.
 * \param texture_image_pipe_bas_gauche Texture de l'image du tuyau bas gauche.
 * \param texture_image_pipe_haut_gauche Texture de l'image du tuyau haut gauche.
 * \param texture_image_pipe_courant Texture de l'image du tuyau courant.
 * \param texture_image_mur_termine Texture de l'image du mur terminé.
 * \see erreur
 */
void mise_a_jour_mini_jeu_1_niveau_2(SDL_Renderer **renderer, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile,
                                     int position_x, int position_y, int tile_map_mini_jeu_niveau_2[19][27],
                                     int largeur, int hauteur, int largeur_tile, int hauteur_tile,
                                     SDL_Texture **texture_image_mur_mini_jeu,
                                     SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                                     SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                                     SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                                     SDL_Texture **texture_image_pipe_courant,
                                     SDL_Texture **texture_image_mur_termine) {

    int x, y;

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);

    /* Nettoyer le renderer */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Rendu tilemap */
    for (y = 0; y < hauteur / hauteur_tile; y++)
        for (x = 0; x < largeur / largeur_tile; x++)
            if ((x >= 0) && (x < largeur / largeur_tile) && (y >= 0) && (y < hauteur / hauteur_tile)) { 
                /* Rendu de chaque tuile en fonction de son type */

                (*texture) = NULL;

                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile;
                rectangle_tile->h = hauteur_tile;

                if(SDL_RenderCopy((*renderer), (*texture_image_mur_mini_jeu), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

                switch(tile_map_mini_jeu_niveau_2[y][x]){

                    case 1: 
                        (*texture) = (*texture_image_pipe_vertical);

                        break;

                    case 2: 
                        (*texture) = (*texture_image_pipe_horizontal);

                        break;

                    case 3: 
                        (*texture) = (*texture_image_pipe_haut_droit);

                        break;

                    case 4: 
                        (*texture) = (*texture_image_pipe_bas_droit);

                        break;

                    case 5: 
                        (*texture) = (*texture_image_pipe_bas_gauche);

                        break;

                    case 6: 
                        (*texture) = (*texture_image_pipe_haut_gauche);

                        break;

                    case 8: 
                        (*texture) = (*texture_image_pipe_courant);

                        break;

                    case 9: 
                        (*texture) = (*texture_image_mur_termine);

                        break;

                    default:
                        break;
                }

                if((*texture))
                    if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

    /* Rendu du curseur en rouge */
    SDL_SetRenderDrawColor((*renderer), 255, 0, 0, 255);

    rectangle_tile->x = position_x * largeur_tile - largeur / 320;
    rectangle_tile->y = position_y * hauteur_tile - hauteur / 180;
    rectangle_tile->w = largeur_tile + largeur / 320 * 2;
    rectangle_tile->h = hauteur_tile + hauteur / 180 * 2;

    SDL_RenderFillRect((*renderer), rectangle_tile);

    (*texture) = NULL;

    rectangle_tile->x = position_x * largeur_tile;
    rectangle_tile->y = position_y * hauteur_tile;
    rectangle_tile->w = largeur_tile;
    rectangle_tile->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_mur_mini_jeu), NULL, rectangle_tile) != 0)
        erreur("Copie de la texture");

    switch(tile_map_mini_jeu_niveau_2[position_y][position_x]){

        case 1: 
            (*texture) = (*texture_image_pipe_vertical);

            break;

        case 2: 
            (*texture) = (*texture_image_pipe_horizontal);

            break;

        case 3: 
            (*texture) = (*texture_image_pipe_haut_droit);

            break;

        case 4: 
            (*texture) = (*texture_image_pipe_bas_droit);

            break;

        case 5: 
            (*texture) = (*texture_image_pipe_bas_gauche);

            break;

        case 6: 
            (*texture) = (*texture_image_pipe_haut_gauche);

            break;

        case 8: 
            (*texture) = (*texture_image_pipe_courant);

            break;

        case 9: 
            (*texture) = (*texture_image_mur_termine);

            break;

        default:
            break;
    }

    if((*texture))
        if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile) != 0)
            erreur("Copie de la texture"); 

    /* Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur_tile * 26;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur_tile;
    rectangle_plein_ecran->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de la croix */

    rectangle_croix->x = 0;
    rectangle_croix->y = 0;
    rectangle_croix->w = largeur_tile;
    rectangle_croix->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_croix), NULL, rectangle_croix) != 0)
        erreur("Copie de la texture");

    /* Actualiser le renderer */
    SDL_RenderPresent((*renderer));
} 

/** 
 * \fn void mini_jeu_2_niveau_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32], int mode_difficile) 
 * \brief Fonction qui permet d'initialiser le second mini-jeu du niveau 2 
 * \param position_x position verticale du joueur à l'apparition dans le niveau
 * \param position_y position horizontale du joueur à l'apparition dans le niveau
 * \param position_x_initiale position du joueur verticale si il venait à revenir dans le niveau ou si il venait à mourir 
 * \param position_y_initiale position du joueur horizontale si il venait à revenir dans le niveau ou si il venait à mourir
 * \param tile_map map ou se trouve le personnage
 * \param mode_difficile booléen indiquant la présence du mode difficile 
 */
void mini_jeu_2_niveau_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32], int mode_difficile) {

    int x, y;

    /* Positionnement du personnage au début du mini-jeu */

    if(!mode_difficile) {
        (*position_x) = 2;
        (*position_y) = 16;
    }

    (*position_x_initiale) = 2;
    (*position_y_initiale) = 16;

    /* Création du second mini-jeu */
    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 9, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
        
    };

    /* Copie du tilemap */
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];
}

/** 
 * \fn void mise_a_jour_mini_jeu_2_niveau_2(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int mini_jeu_termine, int position_x, int position_y, int tile_map[18][32], SDL_Texture **texture_image_porte, niveaux *avancee_niveaux, int largeur, int hauteur, int largeur_tile, int hauteur_tile) {
 * \brief Fonction qui permet de mettre à jour le second mini-jeu du niveau 2 
 * \param renderer Pointeur vers le renderer SDL.
 * \param texture_image_fond Texture de l'image de fond.
 * \param texture_image_sol Texture de l'image du sol.
 * \param rectangle_plein_ecran Rectangle pour le plein écran.
 * \param texture_image_plein_ecran Texture de l'image du plein écran.
 * \param texture Texture SDL.
 * \param rectangle_tile Rectangle pour chaque tuile.
 * \param texture_image_monstre_terrestre Texture de l'image du monstre terrestre.
 * \param texture_image_monstre_volant Texture de l'image du monstre volant.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle pour le personnage.
 * \param mini_jeu_termine Indicateur de la fin du mini-jeu.
 * \param position_x Position x du joueur.
 * \param position_y Position y du joueur.
 * \param tile_map Carte de tuiles du niveau.
 * \param texture_image_porte Texture de l'image de la porte.
 * \param avancee_niveaux Pointeur vers l'état d'avancement des niveaux.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * 
 * 
 */
void mise_a_jour_mini_jeu_2_niveau_2(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                     SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                                     SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int mini_jeu_termine,
                                     int position_x, int position_y, int tile_map[18][32], SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                                     int largeur, int hauteur, int largeur_tile, int hauteur_tile) {

    int x, y;
                                
    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Copie la texture de l'image de fond du salon */
    if(SDL_RenderCopy((*renderer), (*texture_image_fond), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /* Affiche tout le salon en fonction des valeurs */
    for (y = 0; y < hauteur / hauteur_tile; y++) {

        for (x = 0; x < largeur / largeur_tile; x++) {

            if(tile_map[y][x] == 1)
                (*texture) = (*texture_image_sol);

            else
                (*texture) = NULL;

            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile;
            rectangle_tile->h = hauteur_tile;

            if((*texture))
                if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile))
                    erreur("Copie de la texture");

            if(mini_jeu_termine) {

                if(tile_map[y][x] == 4)
                    if(SDL_RenderCopy((*renderer), (*texture_image_porte), NULL, rectangle_tile))
                        erreur("Copie de la texture");

                if((tile_map[y][x] == 5) && (avancee_niveaux[1].numero_collectible[1] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_tile))
                        erreur("Copie de la texture");
            }

            if(tile_map[y][x] == 8)
                if(SDL_RenderCopy((*renderer), (*texture_image_monstre_terrestre), NULL, rectangle_tile))
                    erreur("Copie de la texture");

            if(tile_map[y][x] == 9)
                if(SDL_RenderCopy((*renderer), (*texture_image_monstre_volant), NULL, rectangle_tile))
                    erreur("Copie de la texture");
        }
    }

    /* Copie la texture de l'image du personnage */
            
    rectangle_personnage->x = position_x * largeur_tile;
    rectangle_personnage->y = position_y * hauteur_tile;
    rectangle_personnage->w = largeur_tile;
    rectangle_personnage->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_personnage), NULL, rectangle_personnage) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur_tile * 31;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur_tile;
    rectangle_plein_ecran->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de la croix */

    rectangle_croix->x = 0;
    rectangle_croix->y = 0;
    rectangle_croix->w = largeur_tile;
    rectangle_croix->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_croix), NULL, rectangle_croix) != 0)
        erreur("Copie de la texture");

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
} 


/** 
 * \fn 
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans les mini-jeux du niveau 2 
 * \param event Événement SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param texture_image_fond Texture de l'image de fond.
 * \param texture_image_sol Texture de l'image du sol.
 * \param rectangle_plein_ecran Rectangle pour le plein écran.
 * \param texture_image_plein_ecran Texture de l'image du plein écran.
 * \param plein_ecran Indicateur de mode plein écran.
 * \param texture_image_porte Texture de l'image de la porte.
 * \param avancee_niveaux Pointeur vers l'état d'avancement des niveaux.
 * \param texture Texture SDL.
 * \param rectangle_tile Rectangle pour chaque tuile.
 * \param mini_jeu Indicateur du mini-jeu en cours.
 * \param mini_jeu_1_termine Indicateur de la fin du mini-jeu 1.
 * \param mini_jeu_2_termine Indicateur de la fin du mini-jeu 2.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle pour le personnage.
 * \param mini_jeu_termine Indicateur de la fin du mini-jeu.
 * \param position_x Position x du joueur.
 * \param position_y Position y du joueur.
 * \param tile_map Carte de tuiles du niveau.
 * \param tile_map_mini_jeu_niveau_2 Carte de tuiles du mini-jeu 1 du niveau 2.
 * \param texture_image_monstre_terrestre Texture de l'image du monstre terrestre.
 * \param texture_image_monstre_volant Texture de l'image du monstre volant.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * \param texture_image_mur_mini_jeu Texture de l'image du mur du mini-jeu.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_interagir Touche pour interagir.
 * \param touche_sauter_monter Touche pour sauter/monter.
 * \param touche_descendre Touche pour descendre.
 * \param valide Indicateur de la validité de l'action.
 * \param texture_image_pipe_vertical Texture de l'image du tuyau vertical.
 * \param texture_image_pipe_horizontal Texture de l'image du tuyau horizontal.
 * \param texture_image_pipe_haut_droit Texture de l'image du tuyau haut droit.
 * \param texture_image_pipe_bas_droit Texture de l'image du tuyau bas droit.
 * \param texture_image_pipe_bas_gauche Texture de l'image du tuyau bas gauche.
 * \param texture_image_pipe_haut_gauche Texture de l'image du tuyau haut gauche.
 * \param texture_image_pipe_courant Texture de l'image du tuyau courant.
 * \param rectangle_demande_quitter Rectangle pour la demande de quitter.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte.
 * \param police Police de caractères.
 * \param couleurNoire Couleur noire.
 * \param itemsDemandeQuitter Liste des items pour la demande de quitter.
 * \param tailleDemandeQuitter Taille de la liste des items pour la demande de quitter.
 * \param collectibles_intermediaires Tableau des collectibles intermédiaires.
 * \param texture_image_mur_termine Texture de l'image du mur terminé.
 * \param page_active Page active.
 * \param musique Musique SDL.
 * \param avancer Indicateur de déplacement vers l'avant.
 * \param reculer Indicateur de déplacement vers l'arrière.
 * \param sauter Indicateur de saut.
 * \param saut Indicateur de saut en cours.
 * \param tombe Indicateur de chute.
 * \see redimensionnement_fenetre
 * \see clic_plein_ecran
 * \see demande_quitter_niveau
 * \see clic_case
 * \see verification_chemin
 * \see mise_a_jour_bordures_niveau_2
 * \see salon_arrivee_niveaux_2_3
 * \see mise_a_jour_mini_jeu_1_niveau_2
 */
void mini_jeux_niveau_2(SDL_Event *event, SDL_Renderer **renderer, SDL_Window **window, SDL_bool *programme_lance, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                        SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                        SDL_Texture **texture, SDL_Rect *rectangle_tile, int *mini_jeu, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                        SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int mini_jeu_termine,
                        int *position_x, int *position_y, int tile_map[18][32], int tile_map_mini_jeu_niveau_2[19][27], SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                        int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                        SDL_Texture **texture_image_mur_mini_jeu, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir,
                        SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, int *valide,
                        SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                        SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                        SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                        SDL_Texture **texture_image_pipe_courant, SDL_Rect *rectangle_demande,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire,
                        itemMenu *itemsDemandeQuitter, int tailleDemande, int collectibles_intermediaires[3],
                        SDL_Texture **texture_image_mur_termine, page_t *page_active, Mix_Music **musique,
                        int *avancer, int *reculer, int *sauter, int *saut, int *tombe,
                        itemMenu *itemsDemandeSauvegarde, barreDeSon *barre_de_son, itemMenu *pseudo, 
                        modes_t *modeActif, personnage_t *personnageActif, position_t *positionActive, int tailleNiveaux,
                        time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]) {

    /* Cas où on est dans le premier mini-jeu */
    if((*mini_jeu) == 1) {

        SDL_Event event_temporaire;
        SDL_bool clic_effectue = SDL_FALSE;

        int courant_active = 0;

        int i;

        while(SDL_PollEvent(event)) {

            switch(event->type){

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
                    
                    (*largeur_tile) = (*largeur) / 27;
                    (*hauteur_tile) = (*hauteur) / 19;

                    break;

                case SDL_KEYDOWN:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        if((*position_y) > 0) 
                            (*position_y)--;

                    if(event->key.keysym.sym == (*touche_descendre))
                        if((*position_y) < (19 - 1))
                            (*position_y)++;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        if((*position_x) > 0) 
                            (*position_x)--;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        if((*position_x) < (27 - 1))
                            (*position_x)++;

                    if(event->key.keysym.sym == (*touche_interagir)) {

                        if((tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] != 0) && (tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] != 7) && (tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] != 8)) {
                            
                            if(((*valide) == 1) && ((*position_x) <= 12) && ((*position_y) <= 9))
                                break;
                            
                            if(((*valide) == 2) && ((*position_x) <= 12) && ((*position_y) <= 18))
                                break;
                            
                            if((*valide) == 3 && (((*position_x) <= 12 && (*position_y) <= 18) || ((*position_x) >= 12 && ((*position_y) >= 9))))
                                break;
                                                     

                            if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 1 && (*position_y) != 0 && (*position_y) != 0)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 2;
                            
                            else if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 2)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 1;
                            
                            else if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 3)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 4;
                            
                            else if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 4)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 5;
                            
                            else if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 5)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 6;
                            
                            else if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 6)
                                tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] = 3;
                        }
                            
                        if(tile_map_mini_jeu_niveau_2[(*position_y)][(*position_x)] == 8 && (*position_y) == 0 && (*position_x) == 2)
                            courant_active = 1;
                    }
                    
                    break;

                /* Option plein écran */
                case SDL_MOUSEBUTTONDOWN:

                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window)) {

                        redimensionnement_fenetre((*event), largeur, hauteur);

                        (*largeur_tile) = (*largeur) / 27;
                        (*hauteur_tile) = (*hauteur) / 19;
                    }

                    /* Demande au joueur s'il veut quitter le niveau */
                    if(clic_case((*event), (*rectangle_croix))) {

                        SDL_SetWindowResizable((*window), SDL_FALSE);

                        demande_quitter_niveau(renderer, rectangle_demande,
                                            surface, texture_texte, police, couleurNoire,
                                            itemsDemandeQuitter, tailleDemande, (*largeur), (*hauteur));

                        while (!clic_effectue) {

                            while (SDL_PollEvent(&event_temporaire)) {

                                if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                    if(clic_case(event_temporaire, itemsDemandeQuitter[1].rectangle)) {

                                        (*page_active) = CARTE;

                                        for(i = 0; i < 3; i++)
                                            avancee_niveaux[1].numero_collectible[i] = collectibles_intermediaires[i];

                                        for(i = 0; i < 10; i++)
                                            avancee_succes[i] = avancee_succes_intermediaires[i];

                                        clic_effectue = SDL_TRUE; 
                                    }

                                    else if(clic_case(event_temporaire, itemsDemandeQuitter[2].rectangle))
                                        clic_effectue = SDL_TRUE; 
                                }
                            }
                        }

                        SDL_SetWindowResizable((*window), SDL_TRUE);
                    }

                    break;

                /* Quitter le programme en demandant s'il faut sauvarger la partie */
                case SDL_QUIT:

                    SDL_SetWindowResizable((*window), SDL_FALSE);

                    demande_sauvegarde(renderer, rectangle_demande,
                                        surface, texture_texte, police, couleurNoire,
                                        itemsDemandeSauvegarde, tailleDemande, (*largeur), (*hauteur));

                    while (!clic_effectue) {

                        while (SDL_PollEvent(&event_temporaire)) {

                            if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                if(clic_case(event_temporaire, itemsDemandeSauvegarde[1].rectangle)) {

                                    for(i = 0; i < 3; i++)
                                        avancee_niveaux[1].numero_collectible[i] = collectibles_intermediaires[i];

                                    sauvegarder_partie(touche_aller_a_droite, touche_aller_a_gauche, touche_sauter_monter,
                                                        touche_descendre, touche_interagir, barre_de_son, pseudo,
                                                        (*modeActif), (*personnageActif), (*positionActive),
                                                        avancee_niveaux, tailleNiveaux, temps_debut_partie, (*compteur_mort), avancee_succes);

                                    (*programme_lance) = SDL_FALSE;
                                    clic_effectue = SDL_TRUE; 
                                }

                                else if(clic_case(event_temporaire, itemsDemandeSauvegarde[2].rectangle)) {
                                    (*programme_lance) = SDL_FALSE;
                                    clic_effectue = SDL_TRUE; 
                                }

                                else if(!clic_case(event_temporaire, (*rectangle_demande)))
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

        /* Vérifier le chemin */
        if(courant_active){

            /* Vérifier si le joueur a gagné */
            if (verification_chemin(2, 0 + 1, 2, 0, tile_map_mini_jeu_niveau_2, 11, 9)){
                mise_a_jour_bordures_niveau_2((*renderer), (*texture_image_mur_termine), tile_map_mini_jeu_niveau_2, 12, 0, 0, 9,
                                              rectangle_tile, (*largeur_tile), (*hauteur_tile));
                (*valide) = 1;
            }
                

            if ((verification_chemin(2, 0 + 1, 2, 0, tile_map_mini_jeu_niveau_2, 11, 9)) &&
                (verification_chemin(11, 9 + 1, 11, 9, tile_map_mini_jeu_niveau_2, 13, 16))){
                mise_a_jour_bordures_niveau_2((*renderer), (*texture_image_mur_termine), tile_map_mini_jeu_niveau_2, 0, 10, 12, (19 - 1),
                                              rectangle_tile, (*largeur_tile), (*hauteur_tile));
                (*valide) = 2;
                }

            if ((verification_chemin(2, 0 + 1, 2, 0, tile_map_mini_jeu_niveau_2, 11, 9)) &&
                (verification_chemin(11, 9 + 1, 11, 9, tile_map_mini_jeu_niveau_2, 13, 16)) &&
                verification_chemin(13, 16, 13 - 1, 16, tile_map_mini_jeu_niveau_2, 23, 9)){
                mise_a_jour_bordures_niveau_2((*renderer), (*texture_image_mur_termine), tile_map_mini_jeu_niveau_2, 13, (19 - 1), (27 - 1), 9,
                                              rectangle_tile, (*largeur_tile), (*hauteur_tile));
                (*valide) = 3;
                }

            if((verification_chemin(2, 0 + 1, 2, 0, tile_map_mini_jeu_niveau_2, 11, 9)) &&
                (verification_chemin(11, 9 + 1, 11, 9, tile_map_mini_jeu_niveau_2, 13, 16)) &&
                verification_chemin(13, 16, 13 - 1, 16, tile_map_mini_jeu_niveau_2, 23, 9) &&
                verification_chemin(23, 9 - 1, 23, 9, tile_map_mini_jeu_niveau_2, 24, 0)) {

                mise_a_jour_bordures_niveau_2((*renderer), (*texture_image_mur_termine), tile_map_mini_jeu_niveau_2, (27 - 1), 9, 13, 0,
                                              rectangle_tile, (*largeur_tile), (*hauteur_tile));

                /* Musique du salon */
                if(((*musique) = Mix_LoadMUS("./sons/musiques/salon.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
                Mix_PlayMusic((*musique), -1);

                (*mini_jeu) = 0;
                (*mini_jeu_1_termine) = 1;

                (*largeur_tile) = (*largeur) / 32;
                (*hauteur_tile) = (*hauteur) / 18;

                (*sauter) = 0;
                (*avancer) = 0;
                (*reculer) = 0;
                (*tombe) = 0;
                (*saut) = 0;

                salon_arrivee_niveaux_2_3(position_x, position_y, tile_map, (*page_active));

                tile_map[4][2] = 0;
                tile_map[6][3] = 5;

                if((*mini_jeu_2_termine))
                    tile_map[2][27] = 0;
            }

            courant_active = 0;
        }

        /* Mise à jour du rendu */
        mise_a_jour_mini_jeu_1_niveau_2(renderer, texture_image_croix, rectangle_croix,
                                   rectangle_plein_ecran, texture_image_plein_ecran,
                                    texture, rectangle_tile,
                                    (*position_x), (*position_y), tile_map_mini_jeu_niveau_2,
                                     (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile),
                                    texture_image_mur_mini_jeu,
                                    texture_image_pipe_vertical, texture_image_pipe_horizontal,
                                    texture_image_pipe_haut_droit, texture_image_pipe_bas_droit,
                                    texture_image_pipe_bas_gauche, texture_image_pipe_haut_gauche,
                                    texture_image_pipe_courant,
                                    texture_image_mur_termine);
    }
        
    /* Cas où on est dans le deuxième mini-jeu */
    else if((*mini_jeu) == 2) {


        if(mini_jeu_termine) {
            tile_map[2][29] = 5;
            tile_map[16][20] = 4;
        }

        /* Mise à jour du rendu */
        mise_a_jour_mini_jeu_2_niveau_2(renderer, texture_image_fond,texture_image_sol, texture_image_croix, rectangle_croix,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        texture, rectangle_tile, texture_image_monstre_terrestre, texture_image_monstre_volant,
                                        texture_image_personnage, rectangle_personnage, mini_jeu_termine,
                                        (*position_x),(*position_y), tile_map, texture_image_porte, avancee_niveaux,
                                        (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));
    }
}