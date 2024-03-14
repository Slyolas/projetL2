#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctions_generales.c"
#include "fonctions_nouvelle_partie.c"

int main(int argc, char **argv) {

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface de l'image du premier personnage et sur sa texture */
    SDL_Surface *image_perso_1 = NULL;
    SDL_Texture *texture_image_perso_1 = NULL;
    SDL_Rect rectangle_perso_1;

    /* Création des pointeurs sur la surface de l'image du deuxième personnage et sur sa texture */
    SDL_Surface *image_perso_2 = NULL;
    SDL_Texture *texture_image_perso_2 = NULL;
    SDL_Rect rectangle_perso_2;

    /* Création des pointeurs sur la surface de l'image du plein écran, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_plein_ecran = NULL;
    SDL_Texture *texture_image_plein_ecran = NULL;
    SDL_Rect rectangle_plein_ecran;

    /* Création des pointeurs sur la surface du texte et sur sa texture */
    SDL_Surface *texte = NULL;
    SDL_Texture *texture_texte = NULL;

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

    initialisation_objets(&renderer,
                          &image_plein_ecran, &texture_image_plein_ecran,
                          &police);

    /*-------------------------------------------------------------*/

    itemMenu pseudo;

    int tailleTitres = 3;

    itemMenu titres[tailleTitres];

    int tailleMenu = 2;

    itemMenu itemsMenu[tailleMenu];

    itemMenu valider;

    initialisation_objets_nouvelle_partie(&renderer,
                          &image_perso_1, &texture_image_perso_1,
                          &image_perso_2, &texture_image_perso_2,
                          titres, itemsMenu, &valider);

    /* Variable pour suivre la saisie */
    int modeSaisie = 0;

    /* Variable pour suivre le mode actif */
    int modeActif = MODE_NORMAL; 

    /* Variable pour suivre le personnage actif */
    int personnageActif = PERSONNAGE_1; 

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);
            
                    break;

                /* Si l'utilisateur tape quelque chose */
                case SDL_TEXTINPUT:
                    if(modeSaisie)
                        /* Concatène le texte saisi au pseudo */
                        if(strlen(pseudo.texte) + strlen(event.text.text) <= (10+1))
                            strcat(pseudo.texte, event.text.text);

                    break;

                case SDL_MOUSEBUTTONUP:
                    if(clic_case(event, pseudo.rectangle))
                        modeSaisie = 1;
                    else
                        modeSaisie = 0;

                    if(clic_case(event, itemsMenu[0].rectangle)) 
                        modeActif = MODE_NORMAL;
                    else if(clic_case(event, itemsMenu[1].rectangle))
                        modeActif = MODE_HARD;

                    if(clic_case(event, rectangle_perso_1)) 
                        personnageActif = PERSONNAGE_1;
                    else if(clic_case(event, rectangle_perso_2))
                        personnageActif = PERSONNAGE_2;

                    break; 

                case SDL_MOUSEBUTTONDOWN:
                    if(clic_plein_ecran(event, &rectangle_plein_ecran, &plein_ecran, &window))
                        redimensionnement_fenetre(event, &largeur, &hauteur);

                    if(clic_case(event, valider.rectangle))
                            printf("Vous avez fait clic gauche sur 'Commencer la partie !' !\n");

                    break;

                case SDL_KEYDOWN:
                    if(modeSaisie)
                        if(event.key.keysym.sym == SDLK_BACKSPACE && strlen(pseudo.texte) > 0)
                            pseudo.texte[strlen(pseudo.texte) - 1] = '\0'; /* Supprime le dernier caractère du pseudo */

                    break; 

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu_nouvelle_partie(&renderer, &rectangle_plein_ecran, &texture_image_plein_ecran, 
                                          modeActif, &texture_image_perso_1, &rectangle_perso_1,
                                          &texture_image_perso_2, &rectangle_perso_2, personnageActif,
                                          &pseudo,
                                          titres, tailleTitres, &texte, &texture_texte, 
                                          &police, couleurNoire,
                                          itemsMenu, &valider, largeur, hauteur);
    }

    /*-------------------------------------------------------------*/

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}