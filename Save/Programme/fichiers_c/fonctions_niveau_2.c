#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_niveau_2.h>

/* Fonction qui permet d'initialiser les différents objets du niveau 2 */
void initialisation_objets_niveau_2(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_fond_niveau_2, SDL_Texture **texture_image_dossier_niveau_2,
                                    SDL_Texture **texture_image_sol_niveau_2) {

    /* Chargement des images pour le niveau 2 */

    chargement_image(renderer, surface, texture_image_fond_niveau_2, "./images/niveau_2/fond_niveau_2.png");
    chargement_image(renderer, surface, texture_image_dossier_niveau_2, "./images/niveau_2/dossier_linux.png");
    chargement_image(renderer, surface, texture_image_sol_niveau_2, "./images/niveau_2/sol_niveau_2.png");
}