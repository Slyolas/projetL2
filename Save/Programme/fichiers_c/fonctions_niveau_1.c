#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_1.h>

/* Fonction qui permet d'initialiser les différents objets du niveau 4 */
void initialisation_objets_niveau_1(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_sol_surface_niveau_1, SDL_Texture **texture_image_sol_profondeur_niveau_1,
                                    SDL_Texture **texture_image_fond_niveau_1) {

    /* Chargement des images pour le niveau 1 */

    chargement_image(renderer, surface, texture_image_sol_surface_niveau_1, "./images/niveau_1/sol_niveau_1_surface.jpg");
    chargement_image(renderer, surface, texture_image_sol_profondeur_niveau_1, "./images/niveau_1/sol_niveau_1_profondeur.jpg");
    chargement_image(renderer, surface, texture_image_fond_niveau_1, "./images/niveau_1/fond_niveau_1.png");

}

/* Fonction qui permet de créer l'étage 1 */
void chargement_niveau_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map_niveau_1[18][110]) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 2;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 1 */
    int initialisation_tile_map[18][110] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 10, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 10, 10, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1, 10, 10, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 10, 12, 12, 12, 12, 11, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 10, 10, 10, 10, 10, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 2}
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++)
        for (x = 0; x < 110; x++)
            tile_map_niveau_1[y][x] = initialisation_tile_map[y][x];
}

/* Fonction qui permet de mettre à jour le rendu du niveau 4 */
void mise_a_jour_rendu_niveau_1(SDL_Renderer **renderer, SDL_Texture **texture_image_sol_surface, SDL_Texture **texture_image_sol_profondeur, SDL_Texture **texture_image_fond,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                                SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, SDL_Texture **texture_image_fin_premiers_niveaux,
                                int position_x, int position_y, int tile_map[18][32], int secret,
                                int largeur, int hauteur, int largeur_tile, int hauteur_tile) {
                                
    int x, y;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Affiche tout l'étage en fonction des valeurs */
    for (y = 0; y < hauteur / hauteur_tile; y++) {

        for (x = 0; x < largeur / largeur_tile; x++) {

            if((tile_map[y][x] == 1) || (((tile_map[y][x] == 11)) && (!secret)))
                (*texture) = (*texture_image_sol_surface);

            else if((!(tile_map[y][x])) || (tile_map[y][x] == 2) || (tile_map[y][x] == 3) || (tile_map[y][x] == 5) || (tile_map[y][x] == 7) || (tile_map[y][x] == 8) ||
                    (((tile_map[y][x] == 11) || (tile_map[y][x] == 12)) && (secret)))
                (*texture) = (*texture_image_fond);

            else if((tile_map[y][x] == 10) || (tile_map[y][x] == 12))
                (*texture) = (*texture_image_sol_profondeur);

            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile;
            rectangle_tile->h = hauteur_tile;
            
            if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile) != 0)
                erreur("Copie de la texture");

            if(tile_map[y][x] == 3)
                if(SDL_RenderCopy((*renderer), (*texture_image_pique), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 7) && ((position_x != 29) || (position_y != 15)))
                if(SDL_RenderCopy((*renderer), (*texture_image_fin_premiers_niveaux), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if(tile_map[y][x] == 8)
                if(SDL_RenderCopy((*renderer), (*texture_image_monstre_terrestre), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if(tile_map[y][x] == 9)
                if(SDL_RenderCopy((*renderer), (*texture_image_monstre_volant), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 5) && (y == 8) && (avancee_niveaux[0].numero_collectible[0] == 0) )
                if(SDL_RenderCopy((*renderer), avancee_niveaux[0].texture_image_collectible, NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 5) && (y == 15) && (avancee_niveaux[0].numero_collectible[1] == 0))
                if(SDL_RenderCopy((*renderer), avancee_niveaux[0].texture_image_collectible, NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");
            
            if((tile_map[y][x] == 5) && (y == 3) && (avancee_niveaux[0].numero_collectible[2] == 0))
                if(SDL_RenderCopy((*renderer), avancee_niveaux[0].texture_image_collectible, NULL, rectangle_tile) != 0)
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

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le niveau 4 */
void niveau_1(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer,
              SDL_Texture **texture, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
              SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
              SDL_Texture **texture_image_sol_surface, SDL_Texture **texture_image_sol_profondeur, SDL_Texture **texture_image_fond,
              SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, int *mouvement_monstre,
              SDL_Surface **surface, int collectibles_intermediaires[3], time_t *timestamp,
              SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
              SDL_Keycode *touche_sauter_monter, int *decalage, int *secret_1, int *secret_2,
              int tile_map[18][32], int tile_map_niveau_1[18][110], SDL_Rect *rectangle_tile,
              itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Texture **texture_image_perso_pose,
              SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter,
              SDL_Color couleurNoire, SDL_Texture **texture_image_fin_premiers_niveaux,
              int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
              int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
              int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;
    
    int i, x, y;

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

                                for(i = 0; i < 3; i++)
                                    avancee_niveaux[0].numero_collectible[i] = collectibles_intermediaires[i];

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

    /* Déplacement du niveau en fonction du joueur */
    if((((*position_x) >= 16) && ((*decalage) < 65) && (!(*secret_1))) ||
       (((*position_x) <= 16) && ((*decalage) > 0) && (!(*secret_1)))) {

        (*decalage) += (*position_x) - 16;

        (*position_x) = 16;
    }

    if((!((time(NULL) - 1) % 4)))
        (*mouvement_monstre) = 1;

    if(((*timestamp) < time(NULL)) && (*mouvement_monstre)) {

        (*timestamp) = time(NULL);
        printf("%ld\n", (*timestamp));

        for (y = 0; y < 18; y++)
            for (x = 0; x < 110; x++)
                if(tile_map_niveau_1[y][x] == 8) {

                    if((!((*timestamp) % 4)) || (!(((*timestamp) - 1) % 4))) {

                        tile_map_niveau_1[y][x] = 0;
                        tile_map_niveau_1[y][x + 1] = 8;
                        x++;
                    }

                    else if(!((*timestamp) % 2) || (!(((*timestamp) + 1) % 4))) {

                        tile_map_niveau_1[y][x] = 0;
                        tile_map_niveau_1[y][x - 1] = 8;
                    }
                }

                else if(tile_map_niveau_1[y][x] == 9) {

                    if((!((*timestamp) % 4)) || (!(((*timestamp) - 1) % 4))) {

                        tile_map_niveau_1[y][x] = 0;
                        tile_map_niveau_1[y][x + 1] = 9;
                        x++;
                    }

                    else if(!((*timestamp) % 2) || (!(((*timestamp) + 1) % 4))) {

                        tile_map_niveau_1[y][x] = 0;
                        tile_map_niveau_1[y][x - 1] = 9;
                    }
                }
    }

    /* Cas où le joueur découvre le premier secret */

    else if(((*position_x) < 0) && (!(*secret_1))) {

        (*secret_1) = 1;

        (*position_x) = 12;
        (*position_y) = 15;
    }

    else if((*secret_1) && ((*position_x) > 12)) {

        (*secret_1) = 0;

        (*position_x) = 0;
    }

    /* Cas où le joueur découvre le deuxième secret */

    if((tile_map[(*position_y)][(*position_x)] == 11) || (tile_map[(*position_y)][(*position_x)] == 12) || ((tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 15))) {

        (*secret_2) = 1;

        tile_map_niveau_1[15][52] = 5; 
    }

    else {

        (*secret_2) = 0;

        tile_map_niveau_1[15][52] = 12; 
    }

    /* Cas où le joueur récupère un collectible */

    if((tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 8))
        avancee_niveaux[0].numero_collectible[0] = 1;

    if((tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 15))
        avancee_niveaux[0].numero_collectible[1] = 1;

    if((tile_map[(*position_y)][(*position_x)] == 5) && ((*position_y) == 3))
        avancee_niveaux[0].numero_collectible[2] = 1;

    if(!(*secret_1))
        for(y = 0; y < 18; y++)
            for(x = 0; x < 32; x++)
                tile_map[y][x] = tile_map_niveau_1[y][13 + (*decalage) + x];

    else
        for(y = 0; y < 18; y++)
            for(x = 0; x < 32; x++)
                tile_map[y][x] = tile_map_niveau_1[y][x];

    /* Cas où le personnage tue un monstre */
    if((tile_map[(*position_y) + 1][(*position_x)] == 8) || (tile_map[(*position_y) + 1][(*position_x)] == 9)) {

        tile_map_niveau_1[(*position_y) + 1][13 + (*position_x) + (*decalage)] = 0;

        (*tombe) = 0;
        (*saut) = 1;
    }

    /* Cas où le personnage meurt dans le vide, par des piques ou par des monstres */
    if(((*position_y) == 18) || (tile_map[(*position_y)][(*position_x)] == 3) || (tile_map[(*position_y)][(*position_x)] == 8) || (tile_map[(*position_y)][(*position_x)] == 9)) {

        chargement_niveau_1(position_x, position_y, position_x_initiale, position_y_initiale, tile_map_niveau_1);

        (*saut) = 0;
        (*tombe) = 0;

        (*decalage) = 0;
        (*secret_1) = 0;
        (*mouvement_monstre) = 0;
    }

    /* Cas où vous avez fini le niveau */
    else if (tile_map[(*position_y)][(*position_x)] == 7) {

        mise_a_jour_rendu_niveau_1(renderer, texture_image_sol_surface, texture_image_sol_profondeur, texture_image_fond,
                                   texture, rectangle_tile, rectangle_plein_ecran, texture_image_plein_ecran,
                                   texture_image_perso_pose, rectangle_personnage, texture_image_monstre_terrestre, texture_image_monstre_volant,
                                   texture_image_pique, avancee_niveaux, texture_image_fin_premiers_niveaux,
                                   (*position_x), (*position_y), tile_map, (*secret_2),
                                   (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));

        SDL_Delay(1000); 

        avancee_niveaux[0].niveau_fini = 1;

        (*page_active) = CARTE;
    }

    /* Mise à jour du rendu */
    mise_a_jour_rendu_niveau_1(renderer, texture_image_sol_surface, texture_image_sol_profondeur, texture_image_fond,
                               texture, rectangle_tile, rectangle_plein_ecran, texture_image_plein_ecran,
                               texture_image_personnage, rectangle_personnage, texture_image_monstre_terrestre, texture_image_monstre_volant,
                               texture_image_pique, avancee_niveaux, texture_image_fin_premiers_niveaux,
                               (*position_x), (*position_y), tile_map, (*secret_2),
                               (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile)); 
}