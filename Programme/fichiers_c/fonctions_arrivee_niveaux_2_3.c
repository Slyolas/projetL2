#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_arrivee_niveaux_2_3.h>

/* Fonction qui permet de créer le salon en arrivant dans le niveau 2 ou 3 */
void salon_arrivee_niveaux_2_3(int *position_x, int *position_y, int tile_map[18][32], int niveau_appel) {

    int x, y;

    /* Positionnement du personnage au début du salon */

    (*position_x) = 2;
    (*position_y) = 16;
    
    if(niveau_appel == 2){

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
    
    else if(niveau_appel == 3) {

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
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  
		
	    };

        /* Copie de l'arrivee dans le niveau 2 ou 3 */
        for (y = 0; y < 18; y++)
            for (x = 0; x < 32; x++)
                tile_map[y][x] = initialisation_tile_map_2[y][x];
    }
}

/* Fonction qui permet de mettre à jour le rendu du salon en arrivant dans le niveau 2 ou 3*/
void mise_a_jour_rendu_arrivee_niveaux_2_3(SDL_Renderer **renderer, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                                           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                           SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Texture **texture_image_dossier,
                                           SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                           int position_x, int position_y, int tile_map[18][32],
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

            if((*texture)) {

                rectangle_tile->x = x * largeur_tile;
                rectangle_tile->y = y * hauteur_tile;
                rectangle_tile->w = largeur_tile;
                rectangle_tile->h = hauteur_tile;

                SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile);
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
void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer,
                         SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                         SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol,
                         SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
                         SDL_Keycode *touche_sauter_monter, SDL_Texture **texture_image_dossier,
                         int tile_map[18][32], SDL_Rect *rectangle_tile,
                         itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire,
                         SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter,
                         int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
                         int *position_x, int *position_y,
                         int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

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

    /* Mise à jour du rendu */
    mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                          rectangle_plein_ecran, texture_image_plein_ecran,
                                          texture, rectangle_tile, texture_image_dossier,
                                          texture_image_personnage, rectangle_personnage,
                                          (*position_x), (*position_y), tile_map, 
                                          (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));
}
