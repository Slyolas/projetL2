/**
 * \file fonctions_arrivee_niveaux_2_3.c
 * \brief Fichier contenant les fonctions s'occupant du hub du niveau 2 et 3 
*/


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

    /* Positionnement du personnage au début du salon */

    (*position_x) = 2;
    (*position_y) = 16;
    
    /* Création du salon pour le niveau 2 */
    if(page_active == NIVEAU_2){

	    /* Définition du salon pour le niveau 2 */
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
    
    /* Création du salon pour le niveau 3 */
    else if(page_active == NIVEAU_3) {

        /* Définition du salon pour le niveau 3 */
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

        /* Copie de l'arrivee dans le niveau 2 ou 3 */
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
                                           int position_x, int position_y, int tile_map[18][32], niveaux *avancee_niveaux, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
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

            /* Définition de la position de la tuile */
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

    /* Cas pour le début de la barre windows dans le niveau 3 */
    if(page_active == NIVEAU_3) {
 
        /* Affiche tout le salon en fonction des valeurs */
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
 * \fn void explications(SDL_Renderer **renderer, SDL_Rect *rectangle_explications, SDL_Keycode touche_interagir, SDL_Keycode touche_sauter_monter, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur, itemMenu *itemsExplications, int largeur, int hauteur, int numero_mini_jeu)
 * \brief  Fonction qui permet d'afficher des explications pour chaque mini-jeux.
 * \param renderer Renderer SDL.
 * \param rectangle_explications Rectangle pour les explications.
 * \param touche_interagir Touche pour interagir.
 * \param touche_sauter_monter Touche pour sauter ou monter.
 * \param surface Surface SDL.
 * \param texture_texte Texture pour le texte.
 * \param police Police de caractères.
 * \param couleur Couleur du texte.
 * \param itemsExplications Éléments des explications.
 * \param largeur Largeur.
 * \param hauteur Hauteur.
 * \param numero_mini_jeu Numéro du mini-jeu.
 * \see affichage_texte
 */

void explications(SDL_Renderer **renderer, SDL_Rect *rectangle_explications, SDL_Keycode touche_interagir, SDL_Keycode touche_sauter_monter,
                  SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur,
                  itemMenu *itemsExplications, int largeur, int hauteur, int numero_mini_jeu) {

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Affichage du rectangle des explications */

    rectangle_explications->x = 0;
    rectangle_explications->y = 0;
    rectangle_explications->w = largeur;
    rectangle_explications->h = hauteur;

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 200);
    SDL_RenderFillRect((*renderer), rectangle_explications);

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 0);

    /* Initialisation du texte pour la première ligne des explications */

    if(numero_mini_jeu == 1)
        sprintf(itemsExplications[0].texte, "Il semblerait que la structure de refroidissement de la machine ait un soucis.");

    else if(numero_mini_jeu == 2)
        sprintf(itemsExplications[0].texte, "                     Des virus ont envahi l'ordinateur !!!                     ");

    else if(numero_mini_jeu == 3)
        sprintf(itemsExplications[0].texte, "     Un composant n'est plus fonctionnel car un appareil vient de chuter.     ");

    else if(numero_mini_jeu == 4)
        sprintf(itemsExplications[0].texte, "   Une information confidentielle n'a pas pu atteindre la fin du transfert.   ");

    /* Affichage du rectangle de la première phrase des explications */

    itemsExplications[0].rectangle.x = largeur / 15;
    itemsExplications[0].rectangle.y = hauteur / 4 + hauteur / 20;
    itemsExplications[0].rectangle.w = largeur - largeur / 15 * 2;
    itemsExplications[0].rectangle.h = hauteur / 10;
    
    affichage_texte(renderer, surface, texture_texte, &(itemsExplications[0]), 
                    police, couleur);

    /* Initialisation du texte pour la seconde ligne des explications */

    if(numero_mini_jeu == 1)
        sprintf(itemsExplications[0].texte, "                 Interagissez (touche %s) avec les tuyaux et                 ", SDL_GetKeyName(touche_interagir));

    else if(numero_mini_jeu == 2)
        sprintf(itemsExplications[0].texte, "               Eliminez les tous en sautant dessus (touche %s).               ", SDL_GetKeyName(touche_sauter_monter));

    else if(numero_mini_jeu == 3)
        sprintf(itemsExplications[0].texte, "       Reconstruisez-le en bougeant les divers morceaux avec la souris       ");

    else if(numero_mini_jeu == 4)
        sprintf(itemsExplications[0].texte, "             Ramenez-la au plus vite vers la fin de ce labyrinthe             ");

    /* Affichage du rectangle de la troisième phrase des explications */

    itemsExplications[0].rectangle.y = hauteur / 4 + hauteur / 20 + hauteur / 10;
    
    affichage_texte(renderer, surface, texture_texte, &(itemsExplications[0]), 
                    police, couleur);

    itemsExplications[0].rectangle.y = hauteur / 4 + hauteur / 20 + hauteur / 10 * 2;

    /* Initialisation du texte pour la seconde ligne des explications */

    if(numero_mini_jeu == 1)
        sprintf(itemsExplications[0].texte, "          activez la valve afin de remettre la structure en marche.          ");

    else if(numero_mini_jeu == 3)
        sprintf(itemsExplications[0].texte, "                     pour le faire fonctionner de nouveau.                     ");

    else if(numero_mini_jeu == 4)
        sprintf(itemsExplications[0].texte, "     en poussant et en tirant le bloc (rester appuyer sur la touche %s)      ", SDL_GetKeyName(touche_interagir));

    /* Affichage du rectangle de la troisième phrase des explications */
    if(numero_mini_jeu != 2)
        affichage_texte(renderer, surface, texture_texte, &(itemsExplications[0]), 
                        police, couleur);

    itemsExplications[1].rectangle.x = largeur / 3 * 2;
    itemsExplications[1].rectangle.y = hauteur - hauteur / 4 - hauteur / 20;
    itemsExplications[1].rectangle.w = largeur / 7;
    itemsExplications[1].rectangle.h = hauteur / 10;

    /* Initialisation du texte pour sortir de l'explication */

    sprintf(itemsExplications[1].texte, " C'est parti ! ");

    SDL_SetRenderDrawColor((*renderer), 200, 200, 200, 255);
    SDL_RenderDrawRect((*renderer), &(itemsExplications[1].rectangle));

    /* Affichage du texte et du rectangle pour sortir de l'explication */

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 0);

    affichage_texte(renderer, surface, texture_texte, &(itemsExplications[1]), 
                    police, couleur);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}


/**
 * \fn void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, int *mini_jeu, SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int *mini_jeu_termine, int *mini_jeu_1_termine, int *mini_jeu_2_termine, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Texture **texture_image_dossier, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile, int *mouvement_monstre, modes_t *modeActif, int *mode_difficile, itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Color couleurNoire, int tile_map_mini_jeu_niveau_2[19][27], SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter, time_t *timestamp, SDL_Texture **texture_image_perso_gagnant, int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,  int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active, SDL_Texture **texture_image_mur_mini_jeu, int collectibles_intermediaires[3], SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal, SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit, SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche, SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine, int *valide, SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45], int *piece_selectionnee, int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle, Mix_Music **musique, int tile_map_mini_jeu_niveau_3[24][32], int *descendre, int *interagir, int *bloc_x, int *bloc_y, SDL_Texture **texture_image_sol_labyrinthe, SDL_Texture **texture_image_bordure_labyrinthe, SDL_Texture **texture_image_fin_labyrinthe) 
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le salon en arrivant dans le niveau 2 ou 3
 *
 * Cette fonction prend en charge la gestion de l'arrivée aux niveaux 2 et 3 du jeu.
 *
 * \param event Événement SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param programme_lance Booléen pour vérifier si le programme est en cours d'exécution.
 * \param mini_jeu Indicateur de mini-jeu en cours.
 * \param texture_image_fin_premiers_niveaux Texture pour l'image de fin des premiers niveaux.
 * \param texture Texture générale.
 * \param surface Surface SDL.
 * \param rectangle_plein_ecran Rectangle représentant l'écran entier.
 * \param texture_image_plein_ecran Texture pour l'écran entier.
 * \param plein_ecran Booléen pour vérifier si le jeu est en mode plein écran.
 * \param texture_image_personnage Texture pour le personnage.
 * \param rectangle_personnage Rectangle pour le personnage.
 * \param mini_jeu_termine Booléen pour vérifier si le mini-jeu est terminé.
 * \param mini_jeu_1_termine Booléen pour vérifier si le mini-jeu 1 est terminé.
 * \param mini_jeu_2_termine Booléen pour vérifier si le mini-jeu 2 est terminé.
 * \param texture_image_fond Texture pour l'image de fond.
 * \param texture_image_sol Texture pour l'image du sol.
 * \param texture_image_monstre_terrestre Texture pour le monstre terrestre.
 * \param texture_image_monstre_volant Texture pour le monstre volant.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_interagir Touche pour interagir.
 * \param texture_image_porte Texture pour l'image de la porte.
 * \param avancee_niveaux Avancée des niveaux.
 * \param touche_sauter_monter Touche pour sauter ou monter.
 * \param touche_descendre Touche pour descendre.
 * \param texture_image_dossier Texture pour l'image du dossier.
 * \param barre_windows_1 Texture pour la barre Windows 1.
 * \param barre_windows_2 Texture pour la barre Windows 2.
 * \param barre_windows_3 Texture pour la barre Windows 3.
 * \param barre_windows_4 Texture pour la barre Windows 4.
 * \param tile_map Carte des tuiles.
 * \param rectangle_tile Rectangle pour la tuile.
 * \param mouvement_monstre Mouvement du monstre.
 * \param modeActif Mode de jeu actif.
 * \param mode_difficile Booléen pour le mode difficile.
 * \param itemsDemandeQuitter Tableau des éléments de demande de quitter.
 * \param tailleDemande Taille du tableau des éléments de demande de quitter.
 * \param couleurNoire Couleur noire.
 * \param tile_map_mini_jeu_niveau_2 Carte des tuiles pour le mini-jeu niveau 2.
 * \param texture_texte Texture pour le texte.
 * \param police Police de caractères.
 * \param rectangle_demande Rectangle pour la demande.
 * \param timestamp Horodatage.
 * \param texture_image_perso_gagnant Texture pour l'image du personnage gagnant.
 * \param avancer Booléen pour avancer.
 * \param reculer Booléen pour reculer.
 * \param sauter Booléen pour sauter.
 * \param position_avant_saut Position avant le saut.
 * \param saut Booléen pour vérifier si le personnage est en train de sauter.
 * \param tombe Booléen pour vérifier si le personnage tombe.
 * \param position_x_initiale Position initiale en x.
 * \param position_y_initiale Position initiale en y.
 * \param position_x Position en x.
 * \param position_y Position en y.
 * \param largeur Largeur.
 * \param hauteur Hauteur.
 * \param largeur_tile Largeur de la tuile.
 * \param hauteur_tile Hauteur de la tuile.
 * \param page_active Page active.
 * \param texture_image_mur_mini_jeu Texture pour l'image du mur du mini-jeu.
 * \param collectibles_intermediaires Tableau des collectibles intermédiaires.
 * \param itemsExplications Tableau des éléments d'explications.
 * \param texture_image_pipe_vertical Texture pour le tuyau vertical.
 * \param texture_image_pipe_horizontal Texture pour le tuyau horizontal.
 * \param texture_image_pipe_haut_droit Texture pour le tuyau haut droit.
 * \param texture_image_pipe_bas_droit Texture pour le tuyau bas droit.
 * \param texture_image_pipe_bas_gauche Texture pour le tuyau bas gauche.
 * \param texture_image_pipe_haut_gauche Texture pour le tuyau haut gauche.
 * \param texture_image_pipe_courant Texture pour le tuyau courant.
 * \param texture_image_mur_termine Texture pour l'image du mur terminé.
 * \param valide Booléen pour valider.
 * \param rectangle_piece Rectangle pour la pièce.
 * \param piece_bloquee Pièce bloquée.
 * \param rectangle_emplacement_piece Rectangle pour l'emplacement de la pièce.
 * \param piece_selectionnee Pièce sélectionnée.
 * \param decalage_x Décalage en x.
 * \param decalage_y Décalage en y.
 * \param texture_image_puzzle Texture pour l'image du puzzle.
 * \param musique Musique.
 * \param texture_image_croix Texture pour l'image de la croix.
 * \param rectangle_croix Rectangle pour la croix.
 * \param tile_map_mini_jeu_niveau_3 Carte des tuiles pour le mini-jeu niveau 3.
 * \param descendre Descendre.
 * \param interagir Interagir.
 * \param bloc_x Bloc en x.
 * \param bloc_y Bloc en y.
 * \param texture_image_sol_labyrinthe Texture pour l'image du sol du labyrinthe.
 * \param texture_image_bordure_labyrinthe Texture pour l'image de la bordure du labyrinthe.
 * \param texture_image_fin_labyrinthe Texture pour l'image de fin du labyrinthe.
 * \param couleurTitre Couleur du titre.
 * \param itemsDemandeSauvegarde Tableau des éléments de demande de sauvegarde.
 * \param barre_de_son Barre de son.
 * \param pseudo Pseudo.
 * \param personnageActif Personnage actif.
 * \param positionActive Position active.
 * \param tailleNiveaux Taille du tableau des niveaux.
 * \param temps_debut_partie Temps de début de la partie.
 * \param compteur_mort Compteur de mort.
 * \param avancee_succes Avancée des succès.
 * \param avancee_succes_intermediaires Avancée des succès intermédiaires.
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
 * \see explications
 */
void arrivee_niveaux_2_3(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, int *mini_jeu, SDL_Texture **texture_image_fin_premiers_niveaux,
                         SDL_Texture **texture, SDL_Surface **surface, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, int *mini_jeu_termine, int *mini_jeu_1_termine, int *mini_jeu_2_termine,
                         SDL_Texture **texture_image_fond, SDL_Texture **texture_image_sol, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                         SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_interagir, SDL_Texture **texture_image_porte, niveaux *avancee_niveaux,
                         SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Texture **texture_image_dossier,
                         SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, SDL_Texture **barre_windows_3,
                         SDL_Texture **barre_windows_4, int tile_map[18][32], SDL_Rect *rectangle_tile, int *mouvement_monstre, modes_t *modeActif, int *mode_difficile,
                         itemMenu *itemsDemandeQuitter, int tailleDemande, SDL_Color couleurNoire, int tile_map_mini_jeu_niveau_2[19][27],
                         SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande, time_t *timestamp, SDL_Texture **texture_image_perso_gagnant,
                         int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
                         int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y, 
                         int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active,
                         SDL_Texture **texture_image_mur_mini_jeu, int collectibles_intermediaires[3], itemMenu *itemsExplications,
                         SDL_Texture **texture_image_pipe_vertical, SDL_Texture **texture_image_pipe_horizontal,
                         SDL_Texture **texture_image_pipe_haut_droit, SDL_Texture **texture_image_pipe_bas_droit,
                         SDL_Texture **texture_image_pipe_bas_gauche, SDL_Texture **texture_image_pipe_haut_gauche,
                         SDL_Texture **texture_image_pipe_courant, SDL_Texture **texture_image_mur_termine, int *valide,
                         SDL_Rect rectangle_piece[45], int piece_bloquee[45], SDL_Rect rectangle_emplacement_piece[45],
                         int *piece_selectionnee, int *decalage_x, int *decalage_y, SDL_Texture **texture_image_puzzle, Mix_Music **musique, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
                         int tile_map_mini_jeu_niveau_3[24][32], int *descendre, int *interagir, int *bloc_x, int *bloc_y,
                         SDL_Texture **texture_image_sol_labyrinthe, SDL_Texture **texture_image_bordure_labyrinthe,
                         SDL_Texture **texture_image_fin_labyrinthe, SDL_Color couleurTitre,
                         itemMenu *itemsDemandeSauvegarde, barreDeSon *barre_de_son, itemMenu *pseudo, 
                         personnage_t *personnageActif, position_t *positionActive, int tailleNiveaux,
                         time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    Mix_Chunk *effet_sonore = NULL;

    int x, y, i;

    /* Vérification si le joueur n'est pas dans un mini-jeu ou si le niveau est actif */
    if(((!((*mini_jeu) == 1)) && ((*page_active) == NIVEAU_2)) ||
       ((!(*mini_jeu)) && ((*page_active) == NIVEAU_3))) {

        /* Boucle de gestion d'événement */
        while(SDL_PollEvent(event)) {

            switch(event->type) {

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
                    
                    (*largeur_tile) = (*largeur) / 32;
                    (*hauteur_tile) = (*hauteur) / 18;

                    break;

                /* Si une touche au clavier est pressée */
                case SDL_KEYDOWN:

                    /* On met les valeurs à 1 pour dire qu'on a appuyer sur la touche correspondante */
                    /* Cela permet l'appuie de plusieurs touches en même temps */
                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 1;

                    if(event->key.keysym.sym == (*touche_interagir)) {

                        /* Cas où vous retournez sur la carte */
                        if (((*mini_jeu_termine)) && ((*position_x) == 20) && ((*position_y) == 16)) {

                            /* Effet sonore quand on passe dans une porte */
                            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                                erreur("Chargement de l'effet sonore");
                            
                            Mix_PlayChannel(1, effet_sonore, 0);

                            /* Musique du salon */
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

                /* Si une touche au clavier est relâchée  */
                case SDL_KEYUP:

                    /* On met les valeurs à 0 pour dire qu'on a relâchée la touche correspondante */
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

                                        if((*page_active) == NIVEAU_2)
                                            for(i = 0; i < 3; i++)
                                                avancee_niveaux[1].numero_collectible[i] = collectibles_intermediaires[i];
                                        
                                        else if((*page_active) == NIVEAU_3)
                                            for(i = 0; i < 3; i++)
                                                avancee_niveaux[2].numero_collectible[i] = collectibles_intermediaires[i];

                                        for(i = 0; i < 10; i++)
                                            avancee_succes[i] = avancee_succes_intermediaires[i];

                                        (*page_active) = CARTE;

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

                                    if((*page_active) == NIVEAU_2)
                                        for(i = 0; i < 3; i++)
                                            avancee_niveaux[1].numero_collectible[i] = collectibles_intermediaires[i];
                                        
                                    else if((*page_active) == NIVEAU_3)
                                        for(i = 0; i < 3; i++)
                                            avancee_niveaux[2].numero_collectible[i] = collectibles_intermediaires[i];

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

        /* Déplacement du personnage */
        deplacement_personnage(saut, tombe, position_x, position_y, position_avant_saut,
                              (*sauter), (*avancer), (*reculer), tile_map, (*personnageActif));

        /* Cas où le joueur est dans le second mini jeu */
        if(((*mini_jeu) == 2) && ((*page_active) == NIVEAU_2)) {

            /* Cas où le personnage tue un monstre */
            if((tile_map[(*position_y) + 1][(*position_x)] == 8) || (tile_map[(*position_y) + 1][(*position_x)] == 9)) {

                /* Effet sonore de la mort d'un monstre */
                if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_monstre.wav")) == NULL)
                    erreur("Chargement de l'effet sonore");
                    
                Mix_PlayChannel(1, effet_sonore, 0);

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

                (*compteur_mort)++;

                if((*personnageActif) == PERSONNAGE_1) {

                    if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_masculin.wav")) == NULL)
                        erreur("Chargement de l'effet sonore");
                }

                else if((*personnageActif) == PERSONNAGE_2) {

                    if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_feminin.wav")) == NULL)
                        erreur("Chargement de l'effet sonore");
                }
                    
                Mix_PlayChannel(1, effet_sonore, 0);

                (*saut) = 0;
                (*tombe) = 0;

                (*mouvement_monstre) = 0;

                (*mode_difficile) = 0;

                mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));
            }

            /* Déplacement des monstres */

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

    /* Si le niveau actif est le niveau 2 */
    if((*page_active) == NIVEAU_2) {

        /* Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 2) && ((*position_x <= 4)) && ((*position_y) >= 4) && ((*position_y <= 6)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            /* Musique des mini-jeux */
            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*largeur_tile) = (*largeur) / 27;
            (*hauteur_tile) = (*hauteur) / 19;

            (*mini_jeu) = 1;

            (*valide) = 0;

            mini_jeu_1_niveau_2(position_x, position_y, tile_map_mini_jeu_niveau_2);

            explications(renderer, rectangle_demande, (*touche_interagir), (*touche_sauter_monter),
                            surface, texture_texte, police, couleurTitre,
                            itemsExplications, (*largeur), (*hauteur), 1);

            SDL_SetWindowResizable((*window), SDL_FALSE);

            while(!clic_effectue) {

                while(SDL_PollEvent(&event_temporaire))

                    if(event_temporaire.type == SDL_MOUSEBUTTONDOWN)

                        if(clic_case(event_temporaire, itemsExplications[1].rectangle))
                            clic_effectue = SDL_TRUE;
            }

            SDL_SetWindowResizable((*window), SDL_TRUE);

            clic_effectue = SDL_FALSE; 
        }

        /* Cas où le joueur rentre dans le second dossier */   
        else if(((*position_x) >= 27) && ((*position_x <= 29)) && ((*position_y) >= 2) && ((*position_y <= 4)) && (!(*mini_jeu)) && (!(*mini_jeu_2_termine))) {

            /* Musique des mini-jeux */
            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);
            
            (*mini_jeu) = 2;

            (*sauter) = 0;
            (*avancer) = 0;
            (*reculer) = 0;
            (*tombe) = 0;
            (*saut) = 0;

            mini_jeu_2_niveau_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map, (*mode_difficile));

            explications(renderer, rectangle_demande, (*touche_interagir), (*touche_sauter_monter),
                            surface, texture_texte, police, couleurTitre,
                            itemsExplications, (*largeur), (*hauteur), 2);

            SDL_SetWindowResizable((*window), SDL_FALSE);

            while(!clic_effectue) {

                while(SDL_PollEvent(&event_temporaire))

                    if(event_temporaire.type == SDL_MOUSEBUTTONDOWN)

                        if(clic_case(event_temporaire, itemsExplications[1].rectangle))
                            clic_effectue = SDL_TRUE;
            }

            SDL_SetWindowResizable((*window), SDL_TRUE);

            clic_effectue = SDL_FALSE; 
        }

        if((*mini_jeu_1_termine) && (*mini_jeu_2_termine)) {
            tile_map[8][18] = 5;
            tile_map[16][16] = 7;
        }

        /* Cas où le joueur récupère un collectible dans le niveau 2 */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 6) && (!avancee_niveaux[1].numero_collectible[0])) {

            /* Effet sonore quand on ramasse un collectible */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[0] = 1;
        }

        if(((*mini_jeu) == 2) && (tile_map[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[1].numero_collectible[1])) {

            /* Effet sonore quand on ramasse un collectible */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[1] = 1;
        }

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 8) && (!avancee_niveaux[1].numero_collectible[2])) {

            /* Effet sonore quand on ramasse un collectible */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[1].numero_collectible[2] = 1;
        }

        /* Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /* Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_2(event, renderer, window, programme_lance, texture_image_fond, texture_image_sol,
                               rectangle_plein_ecran,texture_image_plein_ecran, plein_ecran, texture_image_porte, avancee_niveaux,
                               texture, rectangle_tile, mini_jeu, mini_jeu_1_termine, mini_jeu_2_termine,
                               texture_image_personnage, rectangle_personnage, (*mini_jeu_termine),
                               position_x, position_y, tile_map, tile_map_mini_jeu_niveau_2, texture_image_monstre_terrestre, texture_image_monstre_volant,
                               largeur, hauteur, largeur_tile, hauteur_tile, texture_image_croix, rectangle_croix,
                               texture_image_mur_mini_jeu, touche_aller_a_droite, touche_aller_a_gauche, touche_interagir,
                               touche_sauter_monter, touche_descendre, valide,
                               texture_image_pipe_vertical,texture_image_pipe_horizontal,
                               texture_image_pipe_haut_droit, texture_image_pipe_bas_droit,
                               texture_image_pipe_bas_gauche,texture_image_pipe_haut_gauche,
                               texture_image_pipe_courant, rectangle_demande,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemande, collectibles_intermediaires,
                               texture_image_mur_termine, page_active, musique,
                               avancer, reculer, sauter, saut, tombe,
                               itemsDemandeSauvegarde, barre_de_son, pseudo, 
                               modeActif, personnageActif, positionActive, tailleNiveaux,
                               temps_debut_partie, compteur_mort, avancee_succes, avancee_succes_intermediaires);
    }

    /* Si le niveau actif est le niveau 3 */
    else if((*page_active) == NIVEAU_3) {

        /* Cas où le joueur rentre dans le premier dossier */    
        if(((*position_x) >= 5) && ((*position_x <= 7)) && ((*position_y) >= 3) && ((*position_y <= 5)) && (!(*mini_jeu)) && (!(*mini_jeu_1_termine))) {

            /* Musique des mini-jeux */
            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*mini_jeu) = 1;

            (*piece_selectionnee) = -1;

            (*decalage_x) = 0;
            (*decalage_y) = 0;

            for(i = 0; i < 45; i++)
                piece_bloquee[i] = 0;

            explications(renderer, rectangle_demande, (*touche_interagir), (*touche_sauter_monter),
                            surface, texture_texte, police, couleurTitre,
                            itemsExplications, (*largeur), (*hauteur), 3);

            SDL_SetWindowResizable((*window), SDL_FALSE);

            while(!clic_effectue) {

                while(SDL_PollEvent(&event_temporaire))

                    if(event_temporaire.type == SDL_MOUSEBUTTONDOWN)

                        if(clic_case(event_temporaire, itemsExplications[1].rectangle))
                            clic_effectue = SDL_TRUE;
            }

            clic_effectue = SDL_FALSE; 

            if((*plein_ecran))
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
        }

        /* Cas où le joueur rentre dans le second dossier */    
        else if(((*position_x) >= 24) && ((*position_x <= 26)) && ((*position_y) >= 3) && ((*position_y <= 5)) && (!(*mini_jeu)) && (!(*mini_jeu_2_termine))) {

            /* Musique des mini-jeux */
            if(((*musique) = Mix_LoadMUS("./sons/musiques/mini_jeux.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
            Mix_PlayMusic((*musique), -1);

            (*mini_jeu) = 2;

            (*descendre) = 0;
            (*interagir) = 0;
            (*sauter) = 0;
            (*reculer) = 0;
            (*avancer) = 0;

            (*largeur_tile) = (*largeur) / 32;
            (*hauteur_tile) = (*hauteur) / 24;

            mini_jeu_2_niveau_3(position_x, position_y, bloc_x, bloc_y, tile_map_mini_jeu_niveau_3);

            explications(renderer, rectangle_demande, (*touche_interagir), (*touche_sauter_monter),
                            surface, texture_texte, police, couleurTitre,
                            itemsExplications, (*largeur), (*hauteur), 4);

            SDL_SetWindowResizable((*window), SDL_FALSE);

            while(!clic_effectue) {

                while(SDL_PollEvent(&event_temporaire))

                    if(event_temporaire.type == SDL_MOUSEBUTTONDOWN)

                        if(clic_case(event_temporaire, itemsExplications[1].rectangle))
                            clic_effectue = SDL_TRUE;
            }

            SDL_SetWindowResizable((*window), SDL_TRUE);

            clic_effectue = SDL_FALSE; 
        }

        if((*mini_jeu_1_termine) && (*mini_jeu_2_termine)) {
            tile_map[13][25] = 5;
            tile_map[16][16] = 7;
        }

        /* Cas où le joueur récupère un collectible dans le niveau 3 */

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 5) && (!avancee_niveaux[2].numero_collectible[0])) {

            /* Effet sonore quand on ramasse un collectible */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[2].numero_collectible[0] = 1;
        }

        if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 13) && (!avancee_niveaux[2].numero_collectible[2])) {

            /* Effet sonore quand on ramasse un collectible */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
                
            Mix_PlayChannel(1, effet_sonore, 0);

            avancee_niveaux[2].numero_collectible[2] = 1;
        }

        /* Cas où le joueur est dans un mini jeu */ 
        if((*mini_jeu))
            /* Mise à jour du rendu du mini jeu */
            mini_jeux_niveau_3(event, renderer, window, programme_lance,
                               rectangle_plein_ecran,texture_image_plein_ecran, plein_ecran,
                               avancee_niveaux, tile_map, texture_image_croix, rectangle_croix,
                               mini_jeu, mini_jeu_1_termine, mini_jeu_2_termine,
                               position_x, position_y, texture,
                               largeur, hauteur, rectangle_demande,
                               surface, texture_texte, police, couleurNoire,
                               itemsDemandeQuitter, tailleDemande, collectibles_intermediaires,
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
                               touche_sauter_monter, touche_descendre, modeActif,
                               itemsDemandeSauvegarde, barre_de_son, pseudo, 
                               personnageActif, positionActive, tailleNiveaux,
                               temps_debut_partie, compteur_mort, avancee_succes, avancee_succes_intermediaires);
    }

    /* Cas où vous avez fini le niveau */
    if((!(*mini_jeu)) && (tile_map[(*position_y)][(*position_x)] == 7)) {

        /* Effet sonore quand on finit un niveau */
        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/fin_niveaux.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
        
        Mix_PlayChannel(1, effet_sonore, 0);

        /* Mise à jour du rendu du salon */
        mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                                rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                                texture, rectangle_tile, texture_image_dossier,
                                                barre_windows_1, barre_windows_2, barre_windows_3,
                                                barre_windows_4, texture_image_perso_gagnant, rectangle_personnage,
                                                (*position_x), (*position_y), tile_map, avancee_niveaux, texture_image_croix, rectangle_croix,
                                                (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));

        SDL_Delay(1000); 

        if((*page_active) == NIVEAU_2)
            avancee_niveaux[1].niveau_fini = 1;

        else if((*page_active) == NIVEAU_3)
            avancee_niveaux[2].niveau_fini = 1;

        (*page_active) = CARTE;
    }
    /* Cas où le joueur n'est pas dans un mini jeu */ 
    if(!(*mini_jeu))
        /* Mise à jour du rendu du salon */
        mise_a_jour_rendu_arrivee_niveaux_2_3(renderer, texture_image_fond, texture_image_sol,
                                              rectangle_plein_ecran, texture_image_plein_ecran, texture_image_fin_premiers_niveaux,
                                              texture, rectangle_tile, texture_image_dossier,
                                              barre_windows_1, barre_windows_2, barre_windows_3,
                                              barre_windows_4, texture_image_personnage, rectangle_personnage,
                                              (*position_x), (*position_y), tile_map, avancee_niveaux, texture_image_croix, rectangle_croix,
                                              (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile), (*page_active));
}
