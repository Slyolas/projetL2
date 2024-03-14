#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../FichierH/fonctionParametres.h"


int main() {

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Surface *image_hautParleurActif = NULL;
    SDL_Texture *texture_image_hautParleurActif = NULL;

    SDL_Surface *image_hautParleurDesactive = NULL;
    SDL_Texture *texture_image_hautParleurDesactive = NULL;

    // Rectangle du bouton de son
    SDL_Rect rectangle_bouton_son; 

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_menu = NULL;
    SDL_Texture *texture_texte_menu = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    SDL_Keycode touche_aller_a_droite = SDLK_RIGHT;
    SDL_Keycode touche_aller_a_gauche = SDLK_LEFT;
    SDL_Keycode touche_sauter = SDLK_UP;

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
    
    int tailleTouches = 6;
    // Allocation dynamique de mémoire pour le tableau itemsTouches en fonction de tailleMenu
    itemMenu *itemsTouches = malloc(tailleMenu * sizeof(itemMenu));
    if (itemsTouches == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    initialisation_objets(&renderer, &image_hautParleurActif, &texture_image_hautParleurActif,
                          &image_hautParleurDesactive, &texture_image_hautParleurDesactive,
                          &police, &titre, itemsMenu, itemsTouches);

    // Variable pour suivre l'onglet actif
    int ongletActif = ONGLET_SON;                          

    // Variable pour suivre l'état du son (activé/désactivé)
    SDL_bool sonActif = SDL_TRUE;

    int selection_touche = 0;

    SDL_bool programme_lance = SDL_TRUE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);

                    break;

                case SDL_MOUSEBUTTONUP:
                        if(clic_case(event, itemsMenu[0].rectangle))
                            ongletActif = ONGLET_SON;
                        if(clic_case(event, itemsMenu[1].rectangle))
                            ongletActif = ONGLET_TOUCHES;
                        
                        if((clic_case(event, rectangle_bouton_son)) && (sonActif == SDL_TRUE))
                            sonActif = SDL_FALSE;
                        else if(clic_case(event, rectangle_bouton_son))
                            sonActif = SDL_TRUE;

                        if(clic_case(event, itemsTouches[1].rectangle))
                            selection_touche = 1;
                        else if(clic_case(event, itemsTouches[3].rectangle))
                            selection_touche = 3;
                        else if(clic_case(event, itemsTouches[5].rectangle))
                            selection_touche = 5;
                        else    
                            selection_touche = 0;

                        break;

                case SDL_MOUSEBUTTONDOWN:
                    if(clic_case(event, itemsTouches[1].rectangle))
                        selection_touche = 1;
                    else if(clic_case(event, itemsTouches[3].rectangle))
                        selection_touche = 3;
                    else if(clic_case(event, itemsTouches[5].rectangle))
                        selection_touche = 5;
                    else    
                        selection_touche = 0;
                    break;

                case SDL_KEYDOWN :
                    if((event.key.keysym.sym == SDLK_ESCAPE) && (selection_touche)) {
                        touche_aller_a_droite = SDLK_RIGHT;
                        touche_aller_a_gauche = SDLK_LEFT;
                        touche_sauter = SDLK_UP;
                        sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_droite));
                        sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_gauche));
                        sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName(touche_sauter));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 1) && 
                            (event.key.keysym.sym != touche_aller_a_gauche) &&
                            (event.key.keysym.sym != touche_sauter)) {
                               touche_aller_a_droite = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_droite));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 3) && 
                            (event.key.keysym.sym != touche_aller_a_droite) &&
                            (event.key.keysym.sym != touche_sauter)) {
                               touche_aller_a_gauche = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_gauche));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 5) && 
                            (event.key.keysym.sym != touche_aller_a_droite) &&
                            (event.key.keysym.sym != touche_aller_a_gauche)) {
                               touche_sauter = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_sauter));
                        selection_touche = 0;
                    }

                    break;

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu(&renderer, &texture_image_hautParleurActif,
                                          &texture_image_hautParleurDesactive, sonActif,
                                          &rectangle_bouton_son, ongletActif,
                                          &titre, &texte_menu, &texture_texte_menu, &police,
                                          couleurNoire,
                                          itemsMenu, tailleMenu, itemsTouches, tailleTouches, largeur, hauteur);
    }

    /*-------------------------------------------------------------*/

    // Libération de la mémoire allouée dynamiquement
    free(itemsMenu);
    free(itemsTouches);
    
    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}