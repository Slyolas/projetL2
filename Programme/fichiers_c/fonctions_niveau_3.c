#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_3.h>

/* Fonction qui permet d'initialiser les différents objets du niveau 2 */
void initialisation_objets_niveau_3(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_3, SDL_Texture **texture_image_dossier_niveau_3,
                                    SDL_Texture **texture_image_sol_niveau_3, SDL_Texture **barre_windows_1, SDL_Texture **barre_windows_2, 
                                    SDL_Texture **barre_windows_3, SDL_Texture **barre_windows_4) {

    /* Chargement des images pour le niveau 3 */

    chargement_image(renderer, surface, texture_image_fond_niveau_3, "./images/niveau_3/fond_niveau_3.jpg");
    chargement_image(renderer, surface, texture_image_dossier_niveau_3, "./images/niveau_3/dossier_windows_xp.png");
    chargement_image(renderer, surface, texture_image_sol_niveau_3, "./images/niveau_3/sol_niveau_3.jpg");
    chargement_image(renderer, surface, barre_windows_1, "./images/niveau_3/windows_1.png");
    chargement_image(renderer, surface, barre_windows_2, "./images/niveau_3/windows_2.png");
    chargement_image(renderer, surface, barre_windows_3, "./images/niveau_3/windows_3.png");
    chargement_image(renderer, surface, barre_windows_4, "./images/niveau_3/windows_4.png");
}