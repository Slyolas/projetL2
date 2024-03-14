#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctions_generales.c"
#include "fonctions_menu_principal.c"

int main(int argc, char **argv) {

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface de l'image du menu et sur sa texture */
    SDL_Surface *image_menu = NULL;
    SDL_Texture *texture_image_menu = NULL;

    /* Création des pointeurs sur la surface de l'image du plein écran, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_plein_ecran = NULL;
    SDL_Texture *texture_image_plein_ecran = NULL;
    SDL_Rect rectangle_plein_ecran;

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_menu = NULL;
    SDL_Texture *texture_texte_menu = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    /* Variable de la couleur du titre */
    SDL_Color couleurTitre = {200, 200, 200, 255};

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    initialisation_objets(&renderer,
                          &image_plein_ecran, &texture_image_plein_ecran,
                          &police);

    /*-------------------------------------------------------------*/
    itemMenu titre;

    int tailleMenu;

    if(!verification_sauvegarde()) {
        tailleMenu = 2;
    }
    else{
        tailleMenu = 3;
    }

    /* Allocation dynamique de mémoire pour le tableau itemsMenu en fonction de tailleMenu */
    itemMenu *itemsMenu = malloc(tailleMenu * sizeof(itemMenu));
    if (itemsMenu == NULL) {
        erreur("Allocation de la mémoire");
        exit(EXIT_FAILURE);
    }

    initialisation_objets_menu_principal(&renderer, &image_menu, &texture_image_menu,
                                         &titre, itemsMenu, tailleMenu);

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);

                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(tailleMenu == 2)
                        if(clic_case(event, itemsMenu[0].rectangle))
                            printf("Vous avez fait clic gauche sur 'Nouvelle Partie' !\n");
                        else if(clic_case(event, itemsMenu[1].rectangle))
                            printf("Vous avez fait clic gauche sur 'Options' !\n");
                    else if(tailleMenu == 3)
                        if(clic_case(event, itemsMenu[0].rectangle))
                            printf("Vous avez fait clic gauche sur 'Continuer' !\n");
                        else if(clic_case(event, itemsMenu[1].rectangle))
                            printf("Vous avez fait clic gauche sur 'Nouvelle Partie' !\n");
                        else if(clic_case(event, itemsMenu[2].rectangle))
                            printf("Vous avez fait clic gauche sur 'Options' !\n");
                    
                    if(clic_plein_ecran(event, &rectangle_plein_ecran, &plein_ecran, &window))
                        redimensionnement_fenetre(event, &largeur, &hauteur);

                    break;

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu_menu_principal(&renderer, &texture_image_menu,
                                         &rectangle_plein_ecran, &texture_image_plein_ecran,
                                         &titre, &texte_menu, &texture_texte_menu, &police,
                                         couleurTitre, couleurNoire,
                                         itemsMenu, tailleMenu, largeur, hauteur);
    }

    /*-------------------------------------------------------------*/

    /* Libération de la mémoire allouée dynamiquement */
    free(itemsMenu); 

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}