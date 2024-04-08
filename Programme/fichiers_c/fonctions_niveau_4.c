#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_4.h>

/* Fonction qui permet d'initialiser les différents objets du menu principal */
void initialisation_objets_niveau_4(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                    SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique) {

    /* Chargement des images pour le niveau 4 */

    chargement_image(renderer, surface, texture_image_fond, "./images/fond.jpg");
    chargement_image(renderer, surface, texture_image_bordure, "./images/bordure.png");
    chargement_image(renderer, surface, texture_image_porte, "./images/porte.png");
    chargement_image(renderer, surface, texture_image_pique, "./images/pique.png");
}

/* Fonction qui permet de créer l'étage 1 */
void etage_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */
    (*position_x) = 2;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2},
        {2, 0, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 32; x++) {
            tile_map[y][x] = initialisation_tile_map[y][x];
        }
    }

    /* Changement de mur pour l'étage 1 */
    chargement_image(renderer, surface, texture_image_mur, "./images/mur_etage_1.png");
}

/* Fonction qui permet de créer l'étage 2 */
void etage_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */
    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 2},
        {2, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 4, 0, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 32; x++) {
            tile_map[y][x] = initialisation_tile_map[y][x];
        }
    }

    /* Changement de mur pour l'étage 2 */
    chargement_image(renderer, surface, texture_image_mur, "./images/mur_etage_2.png");
}

/* Fonction qui permet de créer l'étage 3 */
void etage_3(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */
    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2},
        {2, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
        {2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 32; x++) {
            tile_map[y][x] = initialisation_tile_map[y][x];
        }
    }

    /* Changement de mur pour l'étage 3 */
    chargement_image(renderer, surface, texture_image_mur, "./images/mur_etage_3.png");
}

/* Fonction qui permet de créer l'étage 4 */
void etage_4(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */
    (*position_x) = 2;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 1, 1, 3, 1, 1, 1, 3, 3, 1, 1, 3, 1, 1, 1, 3, 3, 1, 1, 3, 1, 1, 1, 3, 3, 0, 0, 4, 0, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 2},
        {2, 3, 3, 1, 3, 3, 1, 1, 1, 3, 1, 1, 3, 3, 1, 1, 1, 3, 1, 1, 3, 3, 1, 1, 1, 3, 1, 1, 0, 0, 0, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 2},
        {2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 4, 0, 0, 0, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 32; x++) {
            tile_map[y][x] = initialisation_tile_map[y][x];
        }
    }

    /* Changement de mur pour l'étage 4 */
    chargement_image(renderer, surface, texture_image_mur, "./images/mur_etage_4.png");
}

/* Fonction qui permet de créer l'étage 4 */
void etage_5(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */
    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 3, 3, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 0, 0, 0, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2},
        {2, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 32; x++) {
            tile_map[y][x] = initialisation_tile_map[y][x];
        }
    }

    /* Changement de mur pour l'étage 5 */
    chargement_image(renderer, surface, texture_image_mur, "./images/mur_etage_5.png");
}

void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,
                            int position_x_initiale, int position_y_initiale, int sauter, int avancer, int reculer, int tile_map[18][32]) {

    /* Cas où la touche pour sauter est pressée */
    if((!(*saut)) && (!(*tombe)) && (sauter)) {

        (*position_avant_saut) = (*position_y);
        (*saut) = 1;
    }

    /* Cas où la touche pour aller à gauche est pressée */
    if(((!(tile_map[(*position_y)][(*position_x) - 1])) || 
        (tile_map[(*position_y)][(*position_x) - 1] == 4) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 3)) && (reculer)) {
                                    
        (*position_x)--;

        if((!(*saut)) && (!(*tombe))) {

            (*tombe) = 1;
            SDL_Delay(75);
        }
    }

    /* Cas où la touche pour aller à droite est pressée */
    if(((!(tile_map[(*position_y)][(*position_x) + 1])) || 
        (tile_map[(*position_y)][(*position_x) + 1] == 4) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 3)) && (avancer)) {

        (*position_x)++;

        if((!(*saut)) && (!(*tombe))) {

            (*tombe) = 1;
            SDL_Delay(75);
        }
    }

    /* Cas où le personnage est entrain de sauter */
    if((*saut)) {

        if ((*position_y) < (*position_avant_saut)-2) {

            (*tombe) = 1;
            (*saut) = 0;
        }

        else if(tile_map[(*position_y) - 1][(*position_x)] == 0) {

            (*position_y) -= 1; 
            SDL_Delay(75);
        }

        else {

            (*tombe) = 1;
            (*saut) = 0; 
        }
    }

    /* Cas où le personnage est entrain de tomber */
    if((*tombe)) {

        if (tile_map[(*position_y) + 1][(*position_x)] == 1)
            (*tombe) = 0;

        else {

            (*position_y) += 1;
            SDL_Delay(75);
        }
    }

    /* Cas où le personnage meurt dans le vide ou par des piques */
    if((tile_map[(*position_y)][(*position_x)] == 2) || (tile_map[(*position_y)][(*position_x)] == 3)) {

        (*position_x) = position_x_initiale;
        (*position_y) = position_y_initiale;
    }
}

/* Fonction qui permet de mettre à jour le rendu du niveau 4 */
void mise_a_jour_rendu_niveau_4(SDL_Renderer **renderer, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile,
                                SDL_Texture **texture_image_porte,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                SDL_Texture **texture_image_pique,
                                int position_x, int position_y, int tile_map[18][32],
                                int largeur, int hauteur, int largeur_tile, int hauteur_tile) {
                                
    int x, y;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Affiche tout l'étage en fonction des valeurs */
    for (y = 0; y < hauteur / hauteur_tile; y++) {

        for (x = 0; x < largeur / largeur_tile; x++) {

            if(tile_map[y][x] == 1)
                (*texture) = (*texture_image_mur);

            else if((!(tile_map[y][x])) || (tile_map[y][x] == 3) || (tile_map[y][x] == 4))
                (*texture) = (*texture_image_fond);

            else if(tile_map[y][x] == 2) 
                (*texture) = (*texture_image_bordure);

            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile;
            rectangle_tile->h = hauteur_tile;
            SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile);

            if(tile_map[y][x] == 3)
                SDL_RenderCopy((*renderer), (*texture_image_pique), NULL, rectangle_tile);

            if(tile_map[y][x] == 4)
                SDL_RenderCopy((*renderer), (*texture_image_porte), NULL, rectangle_tile);
        }
    }

    /* Affiche le personnage */
            
    rectangle_personnage->x = position_x * largeur_tile;
    rectangle_personnage->y = position_y * hauteur_tile;
    rectangle_personnage->w = largeur_tile;
    rectangle_personnage->h = hauteur_tile;
    SDL_RenderCopy((*renderer), (*texture_image_personnage), NULL, rectangle_personnage);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}


void niveau_4(SDL_Event *event, SDL_Renderer **renderer, SDL_bool *programme_lance,
        SDL_Texture **texture,
         SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
         SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond,
         SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte,
         SDL_Texture **texture_image_pique,
           SDL_Surface **surface,
           SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_interagir,
           int tile_map[18][32], SDL_Rect *rectangle_tile, direction_t *direction,
           int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *numero_etage,
           int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
           int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active) {

        while(SDL_PollEvent(event)) {

            switch(event->type) {

                case SDL_KEYDOWN:

                    if(event->key.keysym.sym == (*touche_sauter_monter))
                        (*sauter) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_droite))
                        (*avancer) = 1;

                    if(event->key.keysym.sym == (*touche_aller_a_gauche))
                        (*reculer) = 1;

                    if(event->key.keysym.sym == (*touche_interagir)) {

                        /* Cas où vous retournez sur la carte */
                        if (((*numero_etage) == 1) && ((*position_x) == 2) && ((*position_y) == 15)) {

                            (*direction) = BAS;
                            (*page_active) = CARTE;
                        }
                            

                        /* Cas où vous montez à l'étage 2 */
                        else if (((*numero_etage) == 1) && ((*position_x) == 29) && ((*position_y) == 2)) {

                            etage_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*numero_etage) = 2;
                        }

                        /* Cas où vous descendez à l'étage 1 */
                        else if (((*numero_etage) == 2) && ((*position_x) == 29) && ((*position_y) == 15)) {

                            etage_1(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*position_x) = 29;
                            (*position_y) = 2;
                            (*numero_etage) = 1;
                        }

                        /* Cas où vous montez à l'étage 3 */
                        else if (((*numero_etage) == 2) && ((*position_x) == 29) && ((*position_y) == 2)) {

                            etage_3(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*numero_etage) = 3;
                        }

                        /* Cas où vous descendez à l'étage 2 */
                        else if (((*numero_etage) == 3) && ((*position_x) == 29) && ((*position_y) == 15)) {

                            etage_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*position_x) = 29;
                            (*position_y) = 2;
                            (*numero_etage) = 2;
                        }

                        /* Cas où vous montez à l'étage 4 */
                        else if (((*numero_etage) == 3) && ((*position_x) == 2) && ((*position_y) == 2)) {

                            etage_4(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*numero_etage) = 4;
                        }

                        /* Cas où vous descendez à l'étage 3 */
                        else if (((*numero_etage) == 4) && ((*position_x) == 2) && ((*position_y) == 15)) {

                            etage_3(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*position_x) = 2;
                            (*position_y) = 2;
                            (*numero_etage) = 3;
                        }

                        /* Cas où vous montez à l'étage 5 */
                        else if (((*numero_etage) == 4) && ((*position_x) == 29) && ((*position_y) == 2)) {

                            etage_5(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*numero_etage) = 5;
                        }

                        /* Cas où vous descendez à l'étage 4 */
                        else if (((*numero_etage) == 5) && ((*position_x) == 29) && ((*position_y) == 15)) {

                            etage_4(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*position_x) = 29;
                            (*position_y) = 2;
                            (*numero_etage) = 4;
                        }

                        /* Cas où vous avez fini le niveau */
                        if (((*numero_etage) == 5) && ((*position_x) == 16) && ((*position_y) == 2)) {
                            (*numero_etage) = 1;

                            etage_1(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                    renderer, surface, texture_image_mur);

                            (*page_active) = CARTE;
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

                /* Quitter le programme */
                case SDL_QUIT:
                    (*programme_lance) = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        
        deplacement_personnage(saut, tombe, position_x, position_y, position_avant_saut,
                               (*position_x_initiale), (*position_y_initiale), (*sauter), (*avancer), (*reculer), tile_map);

        mise_a_jour_rendu_niveau_4(renderer, texture_image_mur, texture_image_fond, texture_image_bordure,
                                   texture, rectangle_tile,
                                   texture_image_porte,
                                   texture_image_personnage, rectangle_personnage,
                                   texture_image_pique,
                                   (*position_x), (*position_y), tile_map,
                                   (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));  
}