#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../FichierH/fonctionDifficulte.h"

int main() {

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface de l'image du menu et sur sa texture */
    SDL_Surface *image_normal_mode = NULL;
    SDL_Texture *texture_image_normal_mode = NULL;
    SDL_Rect rectangle_normal_mode;

    /* Création des pointeurs sur la surface de l'image du plein écran, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_hard_mode = NULL;
    SDL_Texture *texture_image_hard_mode = NULL;
    SDL_Rect rectangle_hard_mode;

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_difficultee = NULL;
    SDL_Texture *texture_texte_difficultee = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    /*-------------------------------------------------------------*/
    itemMenu titre;

    int tailleMenu = 2;
    // Allocation dynamique de mémoire pour le tableau itemsMenu en fonction de tailleMenu
    itemMenu *itemsMenu = malloc(tailleMenu * sizeof(itemMenu));
    if (itemsMenu == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    initialisation_objets(&renderer, &image_normal_mode, &texture_image_normal_mode,
                          &image_hard_mode, &texture_image_hard_mode,
                          &police, &titre, itemsMenu, tailleMenu);

    SDL_bool programme_lance = SDL_TRUE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);
                    mise_a_jour_rendu(&renderer, &texture_image_normal_mode,
                                      &rectangle_normal_mode, &texture_image_hard_mode, &rectangle_hard_mode,
                                      &titre, &texte_difficultee, &texture_texte_difficultee, 
                                      &police, couleurNoire,
                                      itemsMenu, largeur, hauteur);
                    break;

                case SDL_MOUSEBUTTONUP:
                    clic_case(event, itemsMenu, 0, tailleMenu, &rectangle_normal_mode, 0);
                    clic_case(event, itemsMenu, 1, tailleMenu, &rectangle_hard_mode, 1);
                    break;     

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }

    /*-------------------------------------------------------------*/

    // Libération de la mémoire allouée dynamiquement
    free(itemsMenu);
    
    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}