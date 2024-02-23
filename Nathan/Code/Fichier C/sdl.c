#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "menu_principal.c"

/* Définir le nombre d'FPS (100 / nombre_FPS) */
#define FPS_LIMIT 16

/* Fonction qui permet de créer une fenêtre et le rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) {

    /* Création de la fenêtre */
    (*window) = SDL_CreateWindow("MetaTravers", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, 
                                 largeur, hauteur,
                                 SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if((*window) == NULL)
        erreur("Création fenêtre échouée");

    /* Création du rendu */
    (*renderer) = SDL_CreateRenderer((*window), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if((*renderer) == NULL)
        erreur("Création rendu échoué");
}

/* Fonction qui permet de gérer le nombre d'FPS à différents moments du jeu */
void SDL_LimitFPS(unsigned int limit) {

    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
}

/* Fonction qui permet de détruire les objets initialisés */
void detruire_objets(TTF_Font **police) {

    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}

int main(int argc, char **argv) {

    /* Initailisation de la largeur de la fenêtre */
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
    SDL_Color couleurNoire = {0, 0, 0};

    /* Variable de la couleur du titre */
    SDL_Color couleurTitre = {200, 200, 200};

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    /*-------------------------------------------------------------*/
    itemMenu titre;

    int tailleMenu = 3;
    itemMenu itemsMenu[tailleMenu];

    if(!verification_sauvegarde()) {
        tailleMenu--;
        itemsMenu[tailleMenu];
    }

    initialisation_objets(&renderer, &image_menu, &texture_image_menu,
                          &image_plein_ecran, &texture_image_plein_ecran,
                          &police, &titre, itemsMenu, tailleMenu);

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);
                    mise_a_jour_rendu(&renderer, &texture_image_menu,
                                      &rectangle_plein_ecran, &texture_image_plein_ecran,
                                      &titre, &texte_menu, &texture_texte_menu, &police,
                                      couleurTitre, couleurNoire,
                                      itemsMenu, tailleMenu, largeur, hauteur);
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    if(tailleMenu == 2) {
                        clic_case(event, itemsMenu, 0, tailleMenu);
                        clic_case(event, itemsMenu, 1, tailleMenu);
                    }
                    else {
                        clic_case(event, itemsMenu, 0, tailleMenu);
                        clic_case(event, itemsMenu, 1, tailleMenu);
                        clic_case(event, itemsMenu, 2, tailleMenu);
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(clic_plein_ecran(event, &rectangle_plein_ecran, &plein_ecran, &window)) {
                    redimensionnement_fenetre(event, &largeur, &hauteur);
                    mise_a_jour_rendu(&renderer, &texture_image_menu,
                                      &rectangle_plein_ecran, &texture_image_plein_ecran,
                                      &titre, &texte_menu, &texture_texte_menu, &police,
                                      couleurTitre, couleurNoire,
                                      itemsMenu, tailleMenu, largeur, hauteur);
                    }
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

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}