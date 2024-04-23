#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_2.h>
#include <../fichiers_h/fonctions_niveau_3.h>
#include <../fichiers_h/fonctions_arrivee_niveaux_2_3.h>

/**
 * \fn void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active)
 * \brief Fonction qui permet de créer le salon en arrivant dans le niveau 2 ou 3 
 * \param position_x pointeur sur la position du personnage sur l'horizontal du tilemap
 * \param position_y pointeur sur la position du perosnnage sur la verticale du tilemap 
 * \param tile_map Matrice représentant la map ou se trouve le personnage 
 * \param page_active Enumération représentant sur quel page on se trouve
 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active) {

    int x, y;

    /** Positionnement du personnage au début du salon */

    (*position_x) = 2;
    (*position_y) = 16;
    
    /** Création du salon pour le niveau 2 */
    if(page_active == NIVEAU_2){

	    /** Définition du salon pour le niveau 2 */
	    int initialisation_tile_map_1[18][32] = { 
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  
		
	    };

        /** Copie de l'arrivee dans le niveau 2 ou 3 */
        for (y = 0; y < 18; y++)
            for (x = 0; x < 32; x++)
                tile_map[y][x] = initialisation_tile_map_1[y][x];
    }
    
    /** Création du salon pour le niveau 3 */
    else if(page_active == NIVEAU_3) {

        /** Définition du salon pour le niveau 3 */
	    int initialisation_tile_map_2[18][32] = { 
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{13, 1, 14, 1, 15, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
		
	    };

        /** Copie de l'arrivee dans le niveau 2 ou 3 */
        for (y = 0; y < 18; y++)
            for (x = 0; x < 32; x++)
                tile_map[y][x] = initialisation_tile_map_2[y][x];
    }
}


/**
 * \fn void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int position_x, int position_y, int tile_map[18][32], niveaux *avancee_niveaux, int largeur, int hauteur, int largeur_tile, int hauteur_tile, page_t page_active) 
 * \brief Fonction qui permet de mettre à jour le rendu du salon en arrivant dans le niveau 2 ou 3
 * \param renderer Pointeur vers le renderer SDL.
 * \param texture_image_fond Texture de l'image de fond.
 * \param texture_image_sol Texture de l'image du sol.
 * \param rectangle_plein_ecran Rectangle plein écran SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param texture_image_fin_premiers_niveaux Texture de l'image de fin des premiers niveaux.
 * \param texture Texture SDL.
 * \param rectangle_tile Rectangle de la tuile SDL.
 * \param texture_image_dossier Texture de l'image du dossier.
 * \param barre_windows_1 Texture de la barre Windows 1.
 * \param barre_windows_2 Texture de la barre Windows 2.
 * \param barre_windows_3 Texture de la barre Windows 3.
 * \param barre_windows_4 Texture de la barre Windows 4.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle du personnage SDL.
 * \param position_x Position en x.
 * \param position_y Position en y.
 * \param tile_map Carte de tuiles.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \param largeur Largeur.
 * \param hauteur Hauteur.
 * \param largeur_tile Largeur de la tuile.
 * \param hauteur_tile Hauteur de la tuile.
 * \param page_active Page active.
 * \see erreur  
 */
void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_fin_premiers_niveaux,
                                           SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier,
                                           SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                                           SDL_Texture **barre_windows_4, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                           int position_x, int position_y, int tile_map[18][32], niveaux *avancee_niveaux,
                                           int largeur, int hauteur, int largeur_tile, int hauteur_tile, page_t page_active) {

    int x, y;
                                
    /** Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /** Copie la texture de l'image de fond du salon */
    if(SDL_RenderCopy((*renderer), (*texture_image_fond), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /** Affiche tout le salon en fonction des valeurs */
    for (y = 0; y < hauteur / hauteur_tile; y++) {

        for (x = 0; x < largeur / largeur_tile; x++) {

            /** Définition de la position de la tuile */
            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile;
            rectangle_tile->h = hauteur_tile;

            if((tile_map[y][x] == 1))
                (*texture) = (*texture_image_sol);

            else
                (*texture) = NULL;

            if((*texture))
                SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile);

            if(page_active == NIVEAU_2) {

                if((tile_map[y][x] == 5) && (y == 6) && (avancee_niveaux[1].numero_collectible[0] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");

                if((tile_map[y][x] == 5) && (y == 8) && (avancee_niveaux[1].numero_collectible[2] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

            else if(page_active == NIVEAU_3) {

                if((tile_map[y][x] == 5) && (y == 5) && (avancee_niveaux[2].numero_collectible[0] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");

                if((tile_map[y][x] == 5) && (y == 13) && (avancee_niveaux[2].numero_collectible[2] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

            if(tile_map[y][x] == 6) {
                
                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile * 3;
                rectangle_tile->h = hauteur_tile * 3;

                if(SDL_RenderCopy((*renderer), (*texture_image_dossier), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");
            }

            if((tile_map[y][x] == 7) && ((position_x != 16) || (position_y != 16)))
                    if(SDL_RenderCopy((*renderer), (*texture_image_fin_premiers_niveaux), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
        }
    }

    if(page_active == NIVEAU_3) {
 
        /** Affiche tout le salon en fonction des valeurs */
        for (y = 0; y < hauteur / hauteur_tile; y++) {

            for (x = 0; x < largeur / largeur_tile; x++) {

                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile * 2;
                rectangle_tile->h = hauteur_tile;

                if(tile_map[y][x] == 13) 
                    if(SDL_RenderCopy((*renderer), (*barre_windows_1), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            
                if(tile_map[y][x] == 14)
                    if(SDL_RenderCopy((*renderer), (*barre_windows_2), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
                
                if(tile_map[y][x] == 15)
                    if(SDL_RenderCopy((*renderer), (*barre_windows_3), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
                
                if(tile_map[y][x] == 16)
                    if(SDL_RenderCopy((*renderer), (*barre_windows_4), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }
        }
    }

    /** Copie la texture de l'image du personnage */
            
    rectangle_personnage->x = position_x * largeur_tile;
    rectangle_personnage->y = position_y * hauteur_tile;
    rectangle_personnage->w = largeur_tile;
    rectangle_personnage->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_personnage), NULL, rectangle_personnage) != 0)
        erreur("Copie de la texture");

    /** Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur_tile * 31;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur_tile;
    rectangle_plein_ecran->h = hauteur_tile;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /** Affiche le rendu */
    SDL_RenderPresent((*renderer));
}   


/**
 * \fn void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, int *mini_jeu, SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int *mini_jeu_termine, int *mini_jeu_1_termine, int *mini_jeu_2_termine, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Texture **texture_image_dossier, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile, int *mouvement_monstre, modes_t *modeActif, int *mode_difficile, itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire, int tile_map_mini_jeu_niveau_2[19][27], SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter, time_t *timestamp, SDL_Texture **texture_image_perso_gagnant, int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,  int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active, SDL_Texture **texture_image_mur_mini_jeu, int collectibles_intermediaires[3], SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal, SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit, SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche, SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine, int *valide, SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45], int *piece_selectionnee, int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle, Mix_Music **musique, int tile_map_mini_jeu_niveau_3[24][32], int *descendre, int *interagir, int *bloc_x, int *bloc_y, SDL_Texture **texture_image_sol_labyrinthe, SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_fin_labyrinthe) 
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le salon en arrivant dans le niveau 2 ou 3
 *
 * Cette fonction prend en charge la gestion de l'arrivée aux niveaux 2 et 3 du jeu.
 *
 * \param event Pointeur vers l'événement SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param mini_jeu Pointeur vers le type de mini-jeu en cours.
 * \param texture_image_fin_premiers_niveaux Texture de l'image de fin des premiers niveaux.
 * \param texture Texture SDL.
 * \param surface Surface SDL.
 * \param rectangle_plein_ecran Rectangle plein écran SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param plein_ecran Booléen pour le plein écran.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle du personnage SDL.
 * \param mini_jeu_termine Booléen pour le mini-jeu terminé.
 * \param mini_jeu_1_termine Booléen pour le mini-jeu 1 terminé.
 * \param mini_jeu_2_termine Booléen pour le mini-jeu 2 terminé.
 * \param texture_image_fond Texture de l'image de fond.
 * \param texture_image_sol Texture de l'image du sol.
 * \param texture_image_monstre_terrestre Texture de l'image du monstre terrestre.
 * \param texture_image_monstre_volant Texture de l'image du monstre volant.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_interagir Touche pour interagir.
 * \param texture_image_porte Texture de l'image de porte.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \param touche_sauter_monter Touche pour sauter/monter.
 * \param touche_descendre Touche pour descendre.
 * \param texture_image_dossier Texture de l'image du dossier.
 * \param barre_windows_1 Texture de la barre Windows 1.
 * \param barre_windows_2 Texture de la barre Windows 2.
 * \param barre_windows_3 Texture de la barre Windows 3.
 * \param barre_windows_4 Texture de la barre Windows 4.
 * \param tile_map Carte de tuiles.
 * \param rectangle_tile Rectangle de la tuile SDL.
 * \param mouvement_monstre Mouvement du monstre.
 * \param modeActif Mode actif du jeu.
 * \param mode_difficile Niveau de difficulté.
 * \param itemsDemandeQuitter Tableau d'items pour la demande de quitter.
 * \param tailleDemandeQuitter Taille du tableau d'items pour la demande de quitter.
 * \param couleurNoire Couleur noire SDL.
 * \param tile_map_mini_jeu_niveau_2 Carte de tuiles pour le mini-jeu niveau 2.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param rectangle_demande_quitter Rectangle de la demande de quitter.
 * \param timestamp Timestamp.
 * \param texture_image_perso_gagnant Texture de l'image du personnage gagnant.
 * \param avancer Avancer.
 * \param reculer Reculer.
 * \param sauter Sauter.
 * \param position_avant_saut Position avant le saut.
 * \param saut Saut.
 * \param tombe Tomber.
 * \param position_x_initiale Position initiale en x.
 * \param position_y_initiale Position initiale en y.
 * \param position_x Position en x.
 * \param position_y Position en y.
 * \param largeur Largeur.
 * \param hauteur Hauteur.
 * \param largeur_tile Largeur de la tuile.
 * \param hauteur_tile Hauteur de la tuile.
 * \param page_active Page active.
 * \param texture_image_mur_mini_jeu Texture de l'image du mur pour le mini-jeu.
 * \param collectibles_intermediaires Collectibles intermédiaires.
 * \param texture_image_pipe_vertical Texture de l'image du tuyau vertical.
 * \param texture_image_pipe_horizontal Texture de l'image du tuyau horizontal.
 * \param texture_image_pipe_haut_droit Texture de l'image du tuyau haut droit.
 * \param texture_image_pipe_bas_droit Texture de l'image du tuyau bas droit.
 * \param texture_image_pipe_bas_gauche Texture de l'image du tuyau bas gauche.
 * \param texture_image_pipe_haut_gauche Texture de l'image du tuyau haut gauche.
 * \param texture_image_pipe_courant Texture de l'image du tuyau courant.
 * \param texture_image_mur_termine Texture de l'image du mur terminé.
 * \param valide Valide.
 * \param rectangle_piece Rectangle des pièces.
 * \param piece_bloquee Pièce bloquée.
 * \param rectangle_emplacement_piece Rectangle de l'emplacement de la pièce.
 * \param piece_selectionnee Pièce sélectionnée.
 * \param decalage_x Décalage en x.
 * \param decalage_y Décalage en y.
 * \param texture_image_puzzle Texture de l'image du puzzle.
 * \param musique Musique du jeu.
 * \param tile_map_mini_jeu_niveau_3 Carte de tuiles pour le mini-jeu niveau 3.
 * \param descendre Descendre.
 * \param interagir Interagir.
 * \param bloc_x Bloc en x.
 * \param bloc_y Bloc en y.
 * \param texture_image_sol_labyrinthe Texture de l'image du sol pour le labyrinthe.
 * \param texture_image_bordure_labyrinthe Texture de l'image de la bordure pour le labyrinthe.
 * \param texture_image_fin_labyrinthe Texture de l'image de fin pour le labyrinthe.
 * \see erreur
 * \see redimensionnement_fenetre
 * \see salon_arrivee_niveaux_2_3
 * \see demande_quitter_niveau
 * \see mini_jeux_niveau_2
 * \see mini_jeu_1_niveau_2
 * \see mini_jeu_2_niveau_2
 * \see clic_plein_ecran
 * \see clic_case
 * \see deplacement_personnage
 * \see rectangle_piece_aleatoire
 * \see mini_jeux_niveau_3
 * \see mise_a_jour_rendu_arrivee_niveaux_2_3
 */
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
                         SDL_Texture **texture_image_fin_labyrinthe) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    Mix_Chunk *effet_sonore;

    int x, y, i;

    /** Vérification si le joueur n'est pas dans un mini-jeu ou si le niveau est actif */
    if(((!((*mini_jeu) == 1)) && ((*page_active) == NIVEAU_2)) ||
       ((!(*mini_jeu)) && ((*page_active) == NIVEAU_3))) {

        /** Boucle de gestion d'événement */
        while(SDL_PollEvent(event)) {

            switch(event->type) {

                /** Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
                    
                    (*largeur_tile) = (*largeur) / 32;
                    (*hauteur_tile) = (*hauteur) / 18;

                    break;

                /** Si une touche au clavier est pressée */
                case SDL_KEYDOWN:

                    /** On met les valeurs à 1 pour dire qu'on a appuyer sur la touche correspondante */
                    /** Cela permet l'appuie de plusieurs touches en même temps */
                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 1;

                    if(event->key.keysym.sym == (*touche_interagir)) {

                        /** Cas où vous retournez sur la carte */
                        if (((*mini_jeu_termine)) && ((*position_x) == 20) && ((*position_y) == 16)) {

                            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                                erreur("Chargement de l'effet sonore");
                            
                            Mix_PlayChannel(1, effet_sonore, 0);

                            if(((*musique) = Mix_LoadMUS("./sons/musiques/salon.mp3")) == NULL)
                                erreur("Chargement de la musique");
                            
                            Mix_PlayMusic((*musique), -1);

                            (*mini_jeu) = 0;
                            (*mini_jeu_2_termine) = 1;

                            salon_arrivee_niveaux_2_3(position_x, position_y, tile_map, (*page_active));

                            tile_map[2][27] = 0;

                            if((*mini_jeu_1_termine)) {
                                tile_map[4][2] = 0;
                                tile_map[6][3] = 5;
                            }     
                        }
                    }
                    

                    break;

                /** Si une touche au clavier est relâchée  */
                case SDL_KEYUP:

                    /** On met les valeurs à 0 pour dire qu'on a relâchée la touche correspondante */
                    if(event->key.keysym.sym == (*touche_sauter_monter))
                            (*sauter) = 0;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                            (*avancer) = 0;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                            (*reculer) = 0;

                    break;

                /** Option plein écran */
                case SDL_MOUSEBUTTONDOWN:

                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window)) {

                        redimensionnement_fenetre((*event), largeur, hauteur);

                        (*largeur_tile) = (*largeur) / 32;
                        (*hauteur_tile) = (*hauteur) / 18;
                    }

                    break;

                /** Demande au joueur s'il veut quitter le niveau */
                case SDL_QUIT:

                    SDL_SetWindowResizable((*window), SDL_FALSE);

                    demande_quitter_niveau(renderer, rectangle_demande_quitter,
                                        surface, texture_texte, police, couleurNoire,
                                        itemsDemandeQuitter, tailleDemandeQuitter, (*largeur), (*hauteur));

                    while (!clic_effectue) {

                        while (SDL_PollEvent(&event_temporaire)) {

                            if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                if(clic_case(event_temporaire, itemsDemandeQuitter[1].rectangle)) {

                                    if((*page_active) == NIVEAU_2)
                                        for(i = 0; i < 3; i++)
                                            avancee_niveaux[1].numero_collectible[i] = collectibles_intermediaires[i];

                                    else if((*page_active) == NIVEAU_3)
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

        /** Déplacement du personnage */
        deplacement_personnage(saut, tombe, position_x, position_y, position_avant_saut,
                              (*sauter), (*avancer), (*reculer), tile_map);

        /** Cas où le joueur est dans le second mini jeu */
        if(((*mini_jeu) == 2) && ((*page_active) == NIVEAU_2)) {

            /** Cas où le personnage tue un monstre */
            if((tile_map[(*position_y) + 1][(*position_x)] == 8) || (tile_map[(*position_y) + 1][(*position_x)] == 9)) {

                tile_map[(*position_y) + 1][(*position_x)] = 0;

                (*tombe) = 0;
                (*saut) = 1;

                for (y = 0; y < 18; y++)
                    for (x = 0; x < 32; x++)
                        if((tile_map[y][x] == 8) || (tile_map[y][x] == 9))
                            (*mini_jeu_termine)++;

                if((*modeActif) == MODE_HARD) {

                    if((!(*mini_jeu_termine)) && (!(*mode_difficile))) {
                        (*mode_difficile) = 1;
                        mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));
                        (*mini_jeu_termine) = 0;
                    }

                    else if((!(*mini_jeu_termine)) && (*mode_difficile))
                        (*mini_jeu_termine) = 1;

                    else
                        (*mini_jeu_termine) = 0;
                }

                else if((*modeActif) == MODE_NORMAL) {

                    if(!(*mini_jeu_termine))
                        (*mini_jeu_termine) = 1;

                    else
                        (*mini_jeu_termine) = 0;
                }
            }

            /** Cas où le personnage meurt par des monstres */
            if((tile_map[(*position_y)][(*position_x)] == 8) || (tile_map[(*position_y)][(*position_x)] == 9)) {

                (*saut) = 0;
                (*tombe) = 0;

                (*mouvement_monstre) = 0;

                (*mode_difficile) = 0;

                mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));
            }

            else if((!((time(NULL) - 1) % 4)) && (!((time(NULL) - 1) % 4)))
                (*mouvement_monstre) = 1;

            if(((*timestamp) < time(NULL)) && (*mouvement_monstre)) {

                (*timestamp) = time(NULL);

                for (y = 0; y < 18; y++)
                    for (x = 0; x < 32; x++)
                        if(tile_map[y][x] == 8) {

                            if((!((*timestamp) % 4)) || (!(((*timestamp) - 1) % 4))) {

                                tile_map[y][x] = 0;
                                tile_map[y][x + 1] = 8;
                                x++;
                            }

                            else if(!((*timestamp) % 2) || (!(((*timestamp) + 1) % 4))) {

                                tile_map[y][x] = 0;
                                tile_map[y][x - 1] = 8;
                            }
                        }

                        else if(tile_map[y][x] == 9) {

                            if((!((*timestamp) % 4)) || (!(((*timestamp) - 1) % 4))) {

                                tile_map[y][x] = 0;
                                tile_map[y][x + 1] = 9;
                                x++;
                            }

                            else if(!((*timestamp) % 2) || (!(((*timestamp) + 1) % 4))) {

                                tile_map[y][x] = 0;
                                tile_map[y][x - 1] = 9;
                            }
                        }
            }
        }
    }

    /** Si le niveau actif est le niveau 2 */
    if((*page_active) == NIVEAU_2) {

        /** Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 2) && ((*position_x <= 4)) && ((*position_y) >= 4) && ((*position_y <= 6)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*largeur_tile) = (*largeur) / 27;
            (*hauteur_tile) = (*hauteur) / 19;

            (*mini_jeu) = 1;

            (*valide) = 0;

            mini_jeu_1_niveau_2(position_x, position_y, tile_map_mini_jeu_niveau_2);
        }

        /** Cas où le joueur rentre dans le second dossier */   
        else if(((*position_x) >= 27) && ((*position_x <= 29)) && ((*position_y) >= 2) && ((*position_y <= 4)) && (!(*mini_jeu)) && (!(*mini_jeu_2_termine))) {

            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);
            
            (*mini_jeu) = 2;

            mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));
        }

        if((*mini_jeu_1_termine) && (*mini_jeu_2_termine)) {
            tile_map[8][18] = 5;
            tile_map[16][16] = 7;
        }

        /** Cas où le joueur récupère un collectible */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 6) && (!avancee_niveaux[1].numero_collectible[0])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[0] = 1;
        }

        if(((*mini_jeu) == 2) && (tile_map[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[1].numero_collectible[1])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[1] = 1;
        }

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 8) && (!avancee_niveaux[1].numero_collectible[2])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[2] = 1;
        }

        /** Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /** Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_2(event, renderer, window, texture_image_fond, texture_image_sol,
                               rectangle_plein_ecran,texture_image_plein_ecran, plein_ecran, texture_image_porte, avancee_niveaux,
                               texture, rectangle_tile, mini_jeu, mini_jeu_1_termine, mini_jeu_2_termine,
                               texture_image_personnage, rectangle_personnage, (*mini_jeu_termine),
                               position_x, position_y, tile_map, tile_map_mini_jeu_niveau_2, texture_image_monstre_terrestre, texture_image_monstre_volant,
                               largeur, hauteur, largeur_tile, hauteur_tile,
                               texture_image_mur_mini_jeu, touche_aller_a_droite, touche_aller_a_gauche, touche_interagir,
                               touche_sauter_monter, touche_descendre, valide,
                               texture_image_pipe_vertical,texture_image_pipe_horizontal,
                               texture_image_pipe_haut_droit, texture_image_pipe_bas_droit,
                               texture_image_pipe_bas_gauche,texture_image_pipe_haut_gauche,
                               texture_image_pipe_courant, rectangle_demande_quitter,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemandeQuitter, collectibles_intermediaires,
                               texture_image_mur_termine, page_active, musique,
                               avancer, reculer, sauter, saut, tombe);
    }

    else if((*page_active) == NIVEAU_3) {

        /** Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 5) && ((*position_x <= 7)) && ((*position_y) >= 3) && ((*position_y <= 5)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*mini_jeu) = 1;

            (*piece_selectionnee) = -1;

            (*decalage_x) = 0;
            (*decalage_y) = 0;

            for(i = 0; i < 45; i++)
                piece_bloquee[i] = 0;

            if((*plein_ecran))
                SDL_SetWindowFullscreen((*window), 0);

            SDL_SetWindowSize((*window), 1600, 520);
            SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

            /** Initialisation de srand pour la génération de pièces aléatoires*/
            srand(time(NULL));

            /** Calcul des rectangles pour chaque pièce du puzzle et des emplacements corrects */
            for (y = 0; y < 5; y++)

                for (x = 0; x < 9; x++) {

                    rectangle_piece[y * 9 + x].w = 1600 / 9;
                    rectangle_piece[y * 9 + x].h = 520 / 5;
                    rectangle_piece[y * 9 + x].x = x * 1600 / 9;
                    rectangle_piece[y * 9 + x].y = y * 520 / 5;

                    rectangle_emplacement_piece[y * 9 + x].x = x * 1600 / 9;
                    rectangle_emplacement_piece[y * 9 + x].y = y * 520 / 5;
                    rectangle_emplacement_piece[y * 9 + x].w = 1600 / 9;
                    rectangle_emplacement_piece[y * 9 + x].h = 520 / 5;
                }

            for (i = 0; i < 45; i++)
                rectangle_piece[i] = rectangle_piece_aleatoire(1600, 520);

            SDL_SetWindowSize((*window), 1600, 520);
            SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

            SDL_SetWindowResizable((*window), SDL_FALSE);
        }

        /** Cas où le joueur rentre dans le second dossier */    
        else if(((*position_x) >= 24) && ((*position_x <= 26)) && ((*position_y) >= 3) && ((*position_y <= 5)) && (!(*mini_jeu)) && (!(*mini_jeu_2_termine))) {

            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*mini_jeu) = 2;

            (*descendre) = 0;
            (*interagir) = 0;

            (*largeur_tile) = (*largeur) / 32;
            (*hauteur_tile) = (*hauteur) / 24;

            mini_jeu_2_niveau_3(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3);
        }

        if((*mini_jeu_1_termine) && (*mini_jeu_2_termine)) {
            tile_map[13][25] = 5;
            tile_map[16][16] = 7;
        }

        /** Cas où le joueur récupère un collectible */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 5) && (!avancee_niveaux[2].numero_collectible[0])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[2].numero_collectible[0] = 1;
        }

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 13) && (!avancee_niveaux[2].numero_collectible[2])) {

            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[2].numero_collectible[2] = 1;
        }

        /** Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /** Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_3(event, renderer, window,
                               rectangle_plein_ecran,texture_image_plein_ecran, plein_ecran,
                               avancee_niveaux, tile_map,
                               mini_jeu, mini_jeu_1_termine, mini_jeu_2_termine,
                               position_x, position_y, texture,
                               largeur, hauteur, rectangle_demande_quitter,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemandeQuitter, collectibles_intermediaires,
                               page_active, rectangle_tile, largeur_tile, hauteur_tile,
                               avancer, reculer, sauter, saut, tombe,
                               rectangle_piece, piece_bloquee, rectangle_emplacement_piece, piece_selectionnee,
                               decalage_x, decalage_y, texture_image_puzzle,
                               tile_map_mini_jeu_niveau_3, descendre, interagir, bloc_x, bloc_y,
                               texture_image_sol_labyrinthe, texture_image_bordure_labyrinthe,
                               texture_image_fin_labyrinthe, musique,
                               texture_image_personnage, rectangle_personnage,
                               texture_image_mur_termine, texture_image_mur_mini_jeu,
                               touche_aller_a_droite, touche_aller_a_gauche, touche_interagir,
                               touche_sauter_monter, touche_descendre, modeActif);
    }

    /** Cas où vous avez fini le niveau */
    if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 7)) {

        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/fin_niveaux.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
        
        Mix_PlayChannel(1, effet_sonore, 0);

        /** Mise à jour du rendu du salon */
        mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                                rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                                texture, rectangle_tile, texture_image_dossier,
                                                barre_windows_1, barre_windows_2, barre_windows_3,
                                                barre_windows_4, texture_image_perso_gagnant, rectangle_personnage,
                                                (*position_x), (*position_y), tile_map, avancee_niveaux,
                                                (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));

        SDL_Delay(1000); 

        if((*page_active) == NIVEAU_2)
            avancee_niveaux[1].niveau_fini = 1;

        else if((*page_active) == NIVEAU_3)
            avancee_niveaux[2].niveau_fini = 1;

        (*page_active) = CARTE;
    }

    /** Cas où le joueur n'est pas dans un mini jeu */ 
    if(!(*mini_jeu))
        /** Mise à jour du rendu du salon */
        mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                              rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                              texture, rectangle_tile, texture_image_dossier,
                                              barre_windows_1, barre_windows_2, barre_windows_3,
                                              barre_windows_4, texture_image_personnage, rectangle_personnage,
                                              (*position_x), (*position_y), tile_map, avancee_niveaux,
                                              (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));
}
