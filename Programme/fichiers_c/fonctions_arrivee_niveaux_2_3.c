#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_arrivee_niveaux_2_3.h>
#include <../fichiers_h/fonctions_niveau_2.h>

SDL_Rect rectangle_piece_aleatoire(int largeur, int hauteur);

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

/* Fonction qui permet de créer le salon en arrivant dans le niveau 2 ou 3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], page_t page_active) {

    int x, y;

    /* Positionnement du personnage au début du salon */

    (*position_x) = 2;
    (*position_y) = 16;
    
    if(page_active == NIVEAU_2){

	    /* Création du salon */
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

        /* Copie de l'arrivee dans le niveau 2 ou 3 */
        for (y = 0; y < 18; y++)
            for (x = 0; x < 32; x++)
                tile_map[y][x] = initialisation_tile_map_1[y][x];
    }
    
    else if(page_active == NIVEAU_3) {

	    /* Création du salon */
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
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{13, 1, 14, 1, 15, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
		
	    };

        /* Copie de l'arrivee dans le niveau 2 ou 3 */
        for (y = 0; y < 18; y++)
            for (x = 0; x < 32; x++)
                tile_map[y][x] = initialisation_tile_map_2[y][x];
    }
}

/* Fonction qui permet de mettre à jour le rendu du salon en arrivant dans le niveau 2 ou 3*/
void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_fin_premiers_niveaux,
                                           SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier,
                                           SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                                           SDL_Texture **barre_windows_4, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                           int position_x, int position_y, int tile_map[18][32], niveaux *avancee_niveaux,
                                           int largeur, int hauteur, int largeur_tile, int hauteur_tile, page_t page_active) {

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

                if((tile_map[y][x] == 5) && (y == 6) && (avancee_niveaux[1].numero_collectible[0] == 0) )
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");

                if((tile_map[y][x] == 5) && (y == 8) && (avancee_niveaux[1].numero_collectible[2] == 0))
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");

                if((tile_map[y][x] == 7) && ((position_x != 16) || (position_y != 16)))
                    if(SDL_RenderCopy((*renderer), (*texture_image_fin_premiers_niveaux), NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

            else if(page_active == NIVEAU_3) {

                if((tile_map[y][x] == 5) && (x == 3) && (avancee_niveaux[2].numero_collectible[0] == 0) )
                    if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_tile) != 0)
                        erreur("Copie de la texture");
            }

            if(tile_map[y][x] == 6) {
                
                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile * 3;
                rectangle_tile->h = hauteur_tile * 3;

                SDL_RenderCopy((*renderer), (*texture_image_dossier), NULL, rectangle_tile);
            }
        }
    }

    /* Affiche tout le salon en fonction des valeurs */
    for (y = 0; y < hauteur / hauteur_tile; y++) {

        for (x = 0; x < largeur / largeur_tile; x++) {

            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile * 2;
            rectangle_tile->h = hauteur_tile;

            if(tile_map[y][x] == 13) 
                SDL_RenderCopy((*renderer), (*barre_windows_1), NULL, rectangle_tile);
        
            if(tile_map[y][x] == 14)
                SDL_RenderCopy((*renderer), (*barre_windows_2), NULL, rectangle_tile);
            
            if(tile_map[y][x] == 15)
                SDL_RenderCopy((*renderer), (*barre_windows_3), NULL, rectangle_tile);
            
            if(tile_map[y][x] == 16)
                SDL_RenderCopy((*renderer), (*barre_windows_4), NULL, rectangle_tile);
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

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}   

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le salon en arrivant dans le niveau 2 ou 3 */
void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, int *mini_jeu, SDL_Texture **texture_image_fin_premiers_niveaux,
                         SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int *mini_jeu_termine, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                         SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                         SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                         SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Texture **texture_image_dossier,
                         SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                         SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile, int *mouvement_monstre, modes_t *modeActif, int *mode_difficile,
                         itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire, int tile_map_mini_jeu[19][27],
                         SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter, time_t *timestamp, SDL_Texture **texture_image_perso_gagnant,
                         int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
                         int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y, 
                         int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active,
                         SDL_Texture **texture_image_mur_mini_jeu, int collectibles_intermediaires[3],
                         SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                         SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                         SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                         SDL_Texture **texture_image_pipe_courant,
                         SDL_Texture **texture_image_mur_termine,
                         SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45],
                         int *piece_selectionnee, int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    int x, y, i;

    if(((!((*mini_jeu) == 1)) && ((*page_active) == NIVEAU_2)) ||
       ((!(*mini_jeu)) && ((*page_active) == NIVEAU_3))) {

        while(SDL_PollEvent(event)) {

            switch(event->type) {

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
                    
                    (*largeur_tile) = (*largeur) / 32;
                    (*hauteur_tile) = (*hauteur) / 18;

                    break;

                case SDL_KEYDOWN:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 1;

                    if(event->key.keysym.sym == (*touche_interagir)) {

                        /* Cas où vous retournez sur la carte */
                        if (((*mini_jeu_termine)) && ((*position_x) == 20) && ((*position_y) == 16)) {

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

                case SDL_KEYUP:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                            (*sauter) = 0;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                            (*avancer) = 0;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                            (*reculer) = 0;

                    break;

                /* Option plein écran */
                case SDL_MOUSEBUTTONDOWN:

                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window)) {

                        redimensionnement_fenetre((*event), largeur, hauteur);

                        (*largeur_tile) = (*largeur) / 32;
                        (*hauteur_tile) = (*hauteur) / 18;
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

        /* Déplacement du personnage */
        deplacement_personnage(saut, tombe, position_x, position_y, position_avant_saut,
                              (*sauter), (*avancer), (*reculer), tile_map);

        /* Cas où le joueur est dans le second mini jeu */
        if(((*mini_jeu) == 2) && ((*page_active) == NIVEAU_2)) {

            /* Cas où le personnage tue un monstre */
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

            /* Cas où le personnage meurt par des monstres */
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

    if((*page_active) == NIVEAU_2) {

        /* Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 2) && ((*position_x <= 4)) && ((*position_y) >= 4) && ((*position_y <= 6)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            (*largeur_tile) = (*largeur) / 27;
            (*hauteur_tile) = (*hauteur) / 19;

            (*mini_jeu) = 1;

            mini_jeu_1_niveau_2(position_x, position_y, tile_map_mini_jeu);
        }

        /* Cas où le joueur rentre dans le second dossier */   
        else if(((*position_x) >= 27) && ((*position_x <= 29)) && ((*position_y) >= 2) && ((*position_y <= 4)) && (!(*mini_jeu)) && (!(*mini_jeu_2_termine))) {
            
            (*mini_jeu) = 2;

            mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));
        }

        if((*mini_jeu_1_termine) && (*mini_jeu_2_termine)) {
            tile_map[8][18] = 5;
            tile_map[16][16] = 7;
        }

        /* Cas où le joueur récupère un collectible */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 6))
            avancee_niveaux[1].numero_collectible[0] = 1;

        if(((*mini_jeu) == 2) && (tile_map[(*position_y)][(*position_x)] == 5))
            avancee_niveaux[1].numero_collectible[1] = 1;

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 8))
            avancee_niveaux[1].numero_collectible[2] = 1;

        /* Cas où vous avez fini le niveau */
        if (tile_map[(*position_y)][(*position_x)] == 7) {

            /* Mise à jour du rendu du salon */
            mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                                  rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                                  texture, rectangle_tile, texture_image_dossier,
                                                  barre_windows_1, barre_windows_2, barre_windows_3,
                                                  barre_windows_4, texture_image_perso_gagnant, rectangle_personnage,
                                                  (*position_x), (*position_y), tile_map, avancee_niveaux,
                                                  (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));

            SDL_Delay(1000); 

            avancee_niveaux[1].niveau_fini = 1;

            (*page_active) = CARTE;
        }

        /* Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /* Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_2(renderer, window, texture_image_fond, texture_image_sol,
                               rectangle_plein_ecran,texture_image_plein_ecran, plein_ecran, texture_image_porte, avancee_niveaux,
                               texture, rectangle_tile, mini_jeu, mini_jeu_1_termine, mini_jeu_2_termine,
                               texture_image_personnage, rectangle_personnage, (*mini_jeu_termine),
                               position_x, position_y, tile_map, tile_map_mini_jeu, texture_image_monstre_terrestre, texture_image_monstre_volant,
                               largeur, hauteur, largeur_tile, hauteur_tile,
                               texture_image_mur_mini_jeu, touche_aller_a_droite, touche_aller_a_gauche, touche_interagir,
                               touche_sauter_monter, touche_descendre,
                               texture_image_pipe_vertical,texture_image_pipe_horizontal,
                               texture_image_pipe_haut_droit, texture_image_pipe_bas_droit,
                               texture_image_pipe_bas_gauche,texture_image_pipe_haut_gauche,
                               texture_image_pipe_courant, rectangle_demande_quitter,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemandeQuitter, collectibles_intermediaires,
                               texture_image_mur_termine, page_active,
                               avancer, reculer, sauter, saut, tombe);
    }

    else if((*page_active) == NIVEAU_3) {

        /* Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 5) && ((*position_x <= 7)) && ((*position_y) >= 3) && ((*position_y <= 5)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            (*mini_jeu) = 1;

            (*piece_selectionnee) = -1;

            (*decalage_x) = 0;
            (*decalage_y) = 0;

            for(i = 0; i < 45; i++)
                piece_bloquee[i] = 0;

            if ((*plein_ecran))
                SDL_SetWindowFullscreen((*window), 0);

            SDL_SetWindowSize((*window), 1600, 520);
            SDL_SetWindowPosition((*window), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

            /* Initialisation de srand pour la génération de pièces aléatoires*/
            srand(time(NULL));

            /* Calcul des rectangles pour chaque pièce du puzzle et des emplacements corrects */
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

        /* Cas où le joueur récupère un collectible */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_x) == 3))
            avancee_niveaux[2].numero_collectible[0] = 1;

        /* Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /* Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_3(renderer, window, 
                               avancee_niveaux, tile_map,
                               mini_jeu, mini_jeu_1_termine,
                               position_x, position_y,
                               largeur, hauteur, rectangle_demande_quitter,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemandeQuitter, collectibles_intermediaires,
                               page_active,
                               avancer, reculer, sauter, saut, tombe,
                               rectangle_piece, piece_bloquee, rectangle_emplacement_piece, piece_selectionnee,
                               decalage_x, decalage_y, texture_image_puzzle);
    }

    /* Cas où le joueur n'est pas dans un mini jeu */ 
    if(!(*mini_jeu))
        /* Mise à jour du rendu du salon */
        mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                              rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                              texture, rectangle_tile, texture_image_dossier,
                                              barre_windows_1, barre_windows_2, barre_windows_3,
                                              barre_windows_4, texture_image_personnage, rectangle_personnage,
                                              (*position_x), (*position_y), tile_map, avancee_niveaux,
                                              (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));
}
