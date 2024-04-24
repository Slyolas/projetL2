/**
 * \file fonctions_niveau_4.c
 * \brief Fichier contenant les fonctions servant à la gestion du niveau 4  
*/
#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_4.h>

/** 
 * \fn void initialisation_objets_niveau_4(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique, SDL_Texture **texture_image_fin_dernier_niveau)
 * \brief Fonction qui permet d'initialiser les différents objets du niveau 4 
* \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_fond Texture de l'image du fond.
 * \param texture_image_bordure Texture de l'image de la bordure.
 * \param texture_image_porte Texture de l'image de la porte.
 * \param texture_image_pique Texture de l'image du pique.
 * \param texture_image_fin_dernier_niveau Texture de l'image de fin du dernier niveau.
 * \see chargement_image
 */
void initialisation_objets_niveau_4(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                    SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique,
                                    SDL_Texture **texture_image_fin_dernier_niveau) {

    /* Chargement des images pour le niveau 4 */

    chargement_image(renderer, surface, texture_image_fond, "./images/niveau_4/fond_niveau_4.jpg");
    chargement_image(renderer, surface, texture_image_bordure, "./images/niveau_4/bordure_niveau_4.png");
    chargement_image(renderer, surface, texture_image_porte, "./images/niveau_4/porte.png");
    chargement_image(renderer, surface, texture_image_pique, "./images/pique.png");
    chargement_image(renderer, surface, texture_image_fin_dernier_niveau, "./images/niveau_4/fin_dernier_niveau.png");
}

/** 
 * \fn void etage_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) 
 * \brief Fonction qui permet de créer l'étage 1 
 * \param position_x Pointeur vers la position en abscisse du joueur.
 * \param position_y Pointeur vers la position en ordonnée du joueur.
 * \param position_x_initiale Pointeur vers la position initiale en abscisse du joueur.
 * \param position_y_initiale Pointeur vers la position initiale en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \see chargement_image
 */
void etage_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 2;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 1 */
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
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];

    /* Changement de mur pour l'étage 1 */
    chargement_image(renderer, surface, texture_image_mur, "./images/niveau_4/mur_etage_1.png");
}

/** 
 * \fn void etage_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) 
 * \brief Fonction qui permet de créer l'étage 2
 * \param position_x Pointeur vers la position en abscisse du joueur.
 * \param position_y Pointeur vers la position en ordonnée du joueur.
 * \param position_x_initiale Pointeur vers la position initiale en abscisse du joueur.
 * \param position_y_initiale Pointeur vers la position initiale en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \see chargement_image
 */
void etage_2(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 2 */
    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 2},
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
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++) 
            tile_map[y][x] = initialisation_tile_map[y][x];

    /* Changement de mur pour l'étage 2 */
    chargement_image(renderer, surface, texture_image_mur, "./images/niveau_4/mur_etage_2.png");
}

/** 
 * \fn void etage_3(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) 
 * \brief Fonction qui permet de créer l'étage 3
 * \param position_x Pointeur vers la position en abscisse du joueur.
 * \param position_y Pointeur vers la position en ordonnée du joueur.
 * \param position_x_initiale Pointeur vers la position initiale en abscisse du joueur.
 * \param position_y_initiale Pointeur vers la position initiale en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \see chargement_image
 */
void etage_3(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 3 */
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
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 4, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];

    /* Changement de mur pour l'étage 3 */
    chargement_image(renderer, surface, texture_image_mur, "./images/niveau_4/mur_etage_3.png");
}

/** 
 * \fn void etage_4(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) 
 * \brief Fonction qui permet de créer l'étage 4
 * \param position_x Pointeur vers la position en abscisse du joueur.
 * \param position_y Pointeur vers la position en ordonnée du joueur.
 * \param position_x_initiale Pointeur vers la position initiale en abscisse du joueur.
 * \param position_y_initiale Pointeur vers la position initiale en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \see chargement_image
 */
void etage_4(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 2;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 4 */
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
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];

    /* Changement de mur pour l'étage 4 */
    chargement_image(renderer, surface, texture_image_mur, "./images/niveau_4/mur_etage_4.png");
}

/** 
 * \fn void etage_5(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) 
 * \brief Fonction qui permet de créer l'étage 5
 * \param position_x Pointeur vers la position en abscisse du joueur.
 * \param position_y Pointeur vers la position en ordonnée du joueur.
 * \param position_x_initiale Pointeur vers la position initiale en abscisse du joueur.
 * \param position_y_initiale Pointeur vers la position initiale en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \see chargement_image
 */
void etage_5(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map[18][32],
             SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_mur) {

    int x, y;

    /* Positionnement du personnage au début de l'étage */

    (*position_x) = 29;
    (*position_y) = 15;

    (*position_x_initiale) = (*position_x);
    (*position_y_initiale) = (*position_y);

    /* Création de l'étage 5 */
    int initialisation_tile_map[18][32] = { 
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
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
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}   
        
    };

    /* Copie du nouvel étage */
    for (y = 0; y < 18; y++)
        for (x = 0; x < 32; x++)
            tile_map[y][x] = initialisation_tile_map[y][x];

    /* Changement de mur pour l'étage 5 */
    chargement_image(renderer, surface, texture_image_mur, "./images/niveau_4/mur_etage_5.png");
}

/**
 * \fn void mise_a_jour_rendu_niveau_4(SDL_Renderer **renderer, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure, SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_porte, SDL_Texture **texture_image_fin_dernier_niveau, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, int numero_etage, int position_x, int position_y, int tile_map[18][32], int largeur, int hauteur, int largeur_tile, int hauteur_tile) 
 * \brief Fonction qui permet de mettre à jour le rendu du niveau 4 
 * \param renderer Pointeur vers le renderer SDL.
 * \param texture_image_mur Texture de l'image des murs.
 * \param texture_image_fond Texture de l'image du fond.
 * \param texture_image_bordure Texture de l'image de la bordure.
 * \param texture Texture générale.
 * \param rectangle_tile Rectangle de la tuile.
 * \param rectangle_plein_ecran Rectangle pour l'affichage en plein écran.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param texture_image_porte Texture de l'image de la porte.
 * \param texture_image_fin_dernier_niveau Texture de l'image de fin du dernier niveau.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle du personnage.
 * \param texture_image_pique Texture de l'image des pics.
 * \param avancee_niveaux Structure contenant l'avancement dans les niveaux.
 * \param numero_etage Numéro de l'étage.
 * \param position_x Position en abscisse du joueur.
 * \param position_y Position en ordonnée du joueur.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * \see erreur
 */
void mise_a_jour_rendu_niveau_4(SDL_Renderer **renderer, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                SDL_Texture **texture_image_porte, SDL_Texture **texture_image_fin_dernier_niveau,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
                                SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, int numero_etage,
                                int position_x, int position_y, int tile_map[18][32], SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
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

            else if((!(tile_map[y][x])) || (tile_map[y][x] == 3) || (tile_map[y][x] == 4) || (tile_map[y][x] == 5) || (tile_map[y][x] == 7)) 
                (*texture) = (*texture_image_fond);

            else if(tile_map[y][x] == 2) 
                (*texture) = (*texture_image_bordure);

            rectangle_tile->x = x * largeur_tile;
            rectangle_tile->y = y * hauteur_tile;
            rectangle_tile->w = largeur_tile;
            rectangle_tile->h = hauteur_tile;

            if(SDL_RenderCopy((*renderer), (*texture), NULL, rectangle_tile) != 0)
                erreur("Copie de la texture");

            if(tile_map[y][x] == 3)
                if(SDL_RenderCopy((*renderer), (*texture_image_pique), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if(tile_map[y][x] == 4)
                if(SDL_RenderCopy((*renderer), (*texture_image_porte), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if(tile_map[y][x] == 7)
                if(SDL_RenderCopy((*renderer), (*texture_image_fin_dernier_niveau), NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 5) && (numero_etage == 2) && (avancee_niveaux[3].numero_collectible[0] == 0))
                if(SDL_RenderCopy((*renderer), avancee_niveaux[3].texture_image_collectible, NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 5) && (numero_etage == 3) && (avancee_niveaux[3].numero_collectible[1] == 0))
                if(SDL_RenderCopy((*renderer), avancee_niveaux[3].texture_image_collectible, NULL, rectangle_tile) != 0)
                    erreur("Copie de la texture");

            if((tile_map[y][x] == 5) && (numero_etage == 5) && (avancee_niveaux[3].numero_collectible[2] == 0))
                if(SDL_RenderCopy((*renderer), avancee_niveaux[3].texture_image_collectible, NULL, rectangle_tile) != 0)
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
 *\fn void niveau_4(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_Texture **texture, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond, SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte, SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, SDL_Surface **surface, modes_t *modeActif, int collectibles_intermediaires[3], SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_interagir, int tile_map[18][32], SDL_Rect *rectangle_tile, SDL_Texture **texture_image_perso_gagnant, itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande_quitter, SDL_Color couleurNoire, SDL_Texture **texture_image_fin_dernier_niveau, int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *numero_etage, int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y, int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active)
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le niveau 4 
 * \param event Pointeur vers la structure d'événements SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param texture Texture générale.
 * \param rectangle_plein_ecran Rectangle pour l'affichage en plein écran.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param plein_ecran Pointeur vers un booléen indiquant si le jeu est en mode plein écran.
 * \param texture_image_personnage Texture de l'image du personnage.
 * \param rectangle_personnage Rectangle du personnage.
 * \param texture_image_mur Texture de l'image des murs.
 * \param texture_image_fond Texture de l'image du fond.
 * \param texture_image_bordure Texture de l'image de la bordure.
 * \param texture_image_porte Texture de l'image de la porte.
 * \param texture_image_pique Texture de l'image des pics.
 * \param avancee_niveaux Structure contenant l'avancement dans les niveaux.
 * \param surface Surface SDL pour le texte.
 * \param modeActif Pointeur vers le mode de jeu actif.
 * \param collectibles_intermediaires Tableau des collectibles intermédiaires.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_sauter_monter Touche pour sauter ou monter.
 * \param touche_interagir Touche pour interagir.
 * \param tile_map Tableau représentant la carte du niveau.
 * \param rectangle_tile Rectangle de la tuile.
 * \param texture_image_perso_gagnant Texture de l'image du personnage gagnant.
 * \param itemsDemandeQuitter Tableau des items pour demander à quitter.
 * \param tailleDemandeQuitter Taille du tableau des items pour demander à quitter.
 * \param texture_texte Texture pour le texte.
 * \param police Police de caractères pour le texte.
 * \param rectangle_demande_quitter Rectangle pour la demande de quitter.
 * \param couleurNoire Couleur noire pour le texte.
 * \param texture_image_fin_dernier_niveau Texture de l'image de fin du dernier niveau.
 * \param avancer Pointeur vers la commande d'avancer.
 * \param reculer Pointeur vers la commande de reculer.
 * \param sauter Pointeur vers la commande de sauter.
 * \param position_avant_saut Position avant le saut.
 * \param tombe Pointeur vers la commande de tomber.
 * \param numero_etage Numéro de l'étage.
 * \param position_x_initiale Position initiale en abscisse.
 * \param position_y_initiale Position initiale en ordonnée.
 * \param position_x Position en abscisse du joueur.
 * \param position_y Position en ordonnée du joueur.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param largeur_tile Largeur d'une tuile.
 * \param hauteur_tile Hauteur d'une tuile.
 * \param page_active Pointeur vers la page active.
 * \param itemsDemandeSauvegarde Éléments pour la demande de sauvegarde.
 * \param touche_descendre Touche pour descendre.
 * \param barre_de_son Barre de son.
 * \param pseudo Pseudo.
 * \param personnageActif Personnage actif.
 * \param positionActive Position active.
 * \param tailleNiveaux Taille des niveaux.
 * \param temps_debut_partie Temps de début de partie.
 * \param compteur_mort Compteur de mort.
 * \param avancee_succes Avancée des succès.
 * \param avancee_succes_intermediaires Avancée des succès intermédiaires.
 * \see redimensionnement_fenetre
 * \see erreur
 * \see etage_1
 * \see etage_2
 * \see etage_3
 * \see etage_4
 * \see etage_5
 * \see clic_plein_ecran
 * \see clic_case
 * \see demande_quitter_niveau
 * \see deplacement_personnage
 * \see mise_a_jour_rendu_niveau_4
 */
void niveau_4(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
              SDL_Texture **texture, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
              SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage,
              SDL_Texture **texture_image_mur, SDL_Texture **texture_image_fond,
              SDL_Texture **texture_image_bordure, SDL_Texture **texture_image_porte,
              SDL_Texture **texture_image_pique, niveaux *avancee_niveaux,
              SDL_Surface **surface, modes_t *modeActif, int collectibles_intermediaires[3],
              SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
              SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_interagir,
              int tile_map[18][32], SDL_Rect *rectangle_tile, SDL_Texture **texture_image_perso_gagnant,
              itemMenu *itemsDemandeQuitter, int tailleDemande, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
              SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande,
              SDL_Color couleurNoire, SDL_Texture **texture_image_fin_dernier_niveau,
              int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe, int *numero_etage,
              int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
              int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active,
              itemMenu *itemsDemandeSauvegarde, SDL_Keycode *touche_descendre, barreDeSon *barre_de_son, itemMenu *pseudo, 
              personnage_t *personnageActif, position_t *positionActive, int tailleNiveaux,
              time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    Mix_Chunk *effet_sonore = NULL;
    
    int i;

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
                    if (((*numero_etage) == 1) && ((*position_x) == 2) && ((*position_y) == 15)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*page_active) = CARTE;
                    }
                        

                    /* Cas où vous montez à l'étage 2 */
                    else if (((*numero_etage) == 1) && ((*position_x) == 29) && ((*position_y) == 2)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*numero_etage) = 2;
                    }

                    /* Cas où vous descendez à l'étage 1 */
                    else if (((*numero_etage) == 2) && ((*position_x) == 29) && ((*position_y) == 15)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_1(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*position_x) = 29;
                        (*position_y) = 2;
                        (*numero_etage) = 1;
                    }

                    /* Cas où vous montez à l'étage 3 */
                    else if (((*numero_etage) == 2) && ((*position_x) == 29) && ((*position_y) == 2)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_3(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*numero_etage) = 3;
                    }

                    /* Cas où vous descendez à l'étage 2 */
                    else if (((*numero_etage) == 3) && ((*position_x) == 29) && ((*position_y) == 15)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_2(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*position_x) = 29;
                        (*position_y) = 2;
                        (*numero_etage) = 2;
                    }

                    /* Cas où vous montez à l'étage 4 */
                    else if (((*numero_etage) == 3) && ((*position_x) == 2) && ((*position_y) == 2)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_4(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*numero_etage) = 4;
                    }

                    /* Cas où vous descendez à l'étage 3 */
                    else if (((*numero_etage) == 4) && ((*position_x) == 2) && ((*position_y) == 15)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_3(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*position_x) = 2;
                        (*position_y) = 2;
                        (*numero_etage) = 3;
                    }

                    /* Cas où vous montez à l'étage 5 */
                    else if (((*numero_etage) == 4) && ((*position_x) == 29) && ((*position_y) == 2)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_5(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*numero_etage) = 5;
                    }

                    /* Cas où vous descendez à l'étage 4 */
                    else if (((*numero_etage) == 5) && ((*position_x) == 29) && ((*position_y) == 15)) {

                        /* Effet sonore quand on passe dans une porte */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/porte.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        etage_4(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                                renderer, surface, texture_image_mur);

                        (*position_x) = 29;
                        (*position_y) = 2;
                        (*numero_etage) = 4;
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
                                        avancee_niveaux[3].numero_collectible[i] = collectibles_intermediaires[i];

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
                                    avancee_niveaux[3].numero_collectible[i] = collectibles_intermediaires[i];

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

            default:
                break;
        }
    }
    
    /* Déplacement du personnage */
    deplacement_personnage(saut, tombe, position_x, position_y, position_avant_saut,
                           (*sauter), (*avancer), (*reculer), tile_map, (*personnageActif));

    /* Cas où le personnage meurt dans le vide ou par des piques */

    if(((tile_map[(*position_y)][(*position_x)] == 2) || (tile_map[(*position_y)][(*position_x)] == 3)) && ((*modeActif) == MODE_NORMAL)) {

        (*compteur_mort)++;

        if((*personnageActif) == PERSONNAGE_1) {

            /* Effet sonore quand le premier personnage meurt */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_masculin.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
        }

        else if((*personnageActif) == PERSONNAGE_2) {

            /* Effet sonore quand le premier personnage meurt */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_feminin.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
        }
            
        Mix_PlayChannel(1, effet_sonore, 0);

        (*position_x) = (*position_x_initiale);
        (*position_y) = (*position_y_initiale);
    }

    else if(((tile_map[(*position_y)][(*position_x)] == 2) || (tile_map[(*position_y)][(*position_x)] == 3)) && ((*modeActif) == MODE_HARD)) {

        if((*personnageActif) == PERSONNAGE_1) {

            /* Effet sonore quand le premier personnage meurt */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_masculin.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
        }

        else if((*personnageActif) == PERSONNAGE_2) {

            /* Effet sonore quand le premier personnage meurt */
            if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/mort_feminin.wav")) == NULL)
                erreur("Chargement de l'effet sonore");
        }
            
        Mix_PlayChannel(1, effet_sonore, 0);

        (*numero_etage) = 1;

        etage_1(position_x, position_y, position_x_initiale, position_y_initiale, tile_map,
                renderer, surface, texture_image_mur);
    }

    /* Cas où le joueur récupère un collectible */

    if(((*numero_etage) == 2) && (tile_map[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[3].numero_collectible[0])) {

        /* Effet sonore quand on ramasse un collectible */
        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
            
        Mix_PlayChannel(1, effet_sonore, 0);

        avancee_niveaux[3].numero_collectible[0] = 1;
    } 

    if(((*numero_etage) == 3) && (tile_map[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[3].numero_collectible[1])) {

        /* Effet sonore quand on ramasse un collectible */
        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
            
        Mix_PlayChannel(1, effet_sonore, 0);

        avancee_niveaux[3].numero_collectible[1] = 1;
    }

    if(((*numero_etage) == 5) && (tile_map[(*position_y)][(*position_x)] == 5) && (!avancee_niveaux[3].numero_collectible[2])) {

        /* Effet sonore quand on ramasse un collectible */
        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collectibles.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
            
        Mix_PlayChannel(1, effet_sonore, 0);

        avancee_niveaux[3].numero_collectible[2] = 1;
    }

    /* Cas où vous avez fini le niveau */
    if (tile_map[(*position_y)][(*position_x)] == 7) {

        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/fin_niveaux.wav")) == NULL)
            erreur("Chargement de l'effet sonore");
        
        Mix_PlayChannel(1, effet_sonore, 0);
        
        /* Mise à jour du rendu */
        mise_a_jour_rendu_niveau_4(renderer, texture_image_mur, texture_image_fond, texture_image_bordure,
                                   texture, rectangle_tile, rectangle_plein_ecran, texture_image_plein_ecran,
                                   texture_image_porte, texture_image_fin_dernier_niveau,
                                   texture_image_perso_gagnant, rectangle_personnage,
                                   texture_image_pique, avancee_niveaux, (*numero_etage),
                                   (*position_x), (*position_y), tile_map, texture_image_croix, rectangle_croix,
                                   (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));  

        SDL_Delay(1000);

        avancee_niveaux[3].niveau_fini = 1; 

        avancee_succes[0] = 1;

        if((time(NULL) - temps_debut_partie) < 600)
            avancee_succes[2] = 1;

        if((*modeActif) == MODE_HARD)
            avancee_succes[3] = 1;

        if(!(*compteur_mort))
            avancee_succes[5] = 1;

        if(((*modeActif) == MODE_HARD) && ((time(NULL) - temps_debut_partie) < 600))
            avancee_succes[6] = 1;

        if(((*modeActif) == MODE_HARD) && ((time(NULL) - temps_debut_partie) < 600) && (!(*compteur_mort)))
            avancee_succes[8] = 1;

        (*numero_etage) = 1;

        (*page_active) = CARTE;
    }
    /* Mise à jour du rendu */
    mise_a_jour_rendu_niveau_4(renderer, texture_image_mur, texture_image_fond, texture_image_bordure,
                               texture, rectangle_tile, rectangle_plein_ecran, texture_image_plein_ecran,
                               texture_image_porte, texture_image_fin_dernier_niveau,
                               texture_image_personnage, rectangle_personnage,
                               texture_image_pique, avancee_niveaux, (*numero_etage),
                               (*position_x), (*position_y), tile_map, texture_image_croix, rectangle_croix,
                               (*largeur), (*hauteur), (*largeur_tile), (*hauteur_tile));  
}