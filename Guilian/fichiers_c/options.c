#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "fonctions_generales.c"
#include "fonctions_options.c"

int main(int argc, char **argv) {

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface du de l'image haut parleur actif et sur sa texture */
    SDL_Surface *image_hautParleurActif = NULL;
    SDL_Texture *texture_image_hautParleurActif = NULL;

    /* Création des pointeurs sur la surface du de l'image haut parleur désactivé et sur sa texture */
    SDL_Surface *image_hautParleurDesactive = NULL;
    SDL_Texture *texture_image_hautParleurDesactive = NULL;

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

    /* Touches pour les déplacements du personnage */
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

    initialisation_objets(&renderer,
                          &image_plein_ecran, &texture_image_plein_ecran,
                          &police);

    /*-------------------------------------------------------------*/

    itemMenu titre;

    int tailleBarres = 2;

    barreDeSon barre_de_son[tailleBarres];
    barre_de_son[0].volume = 0.5;
    barre_de_son[1].volume = 0.5;

    int tailleMenu = 2;

    itemMenu itemsMenu[tailleMenu];
    
    int tailleTouches = 6;

    itemMenu itemsTouches[tailleTouches];

    itemMenu itemsBarres[tailleBarres];

    initialisation_objets_options(&renderer,
                                  &image_hautParleurActif, &texture_image_hautParleurActif,
                                  &image_hautParleurDesactive, &texture_image_hautParleurDesactive,
                                  &titre, itemsMenu, itemsTouches, itemsBarres);

    /* Variable pour suivre l'onglet actif */
    int ongletActif = ONGLET_SON;                          

    /* Variable pour suivre l'état du son (activé/désactivé) */
    SDL_bool sonsActifs[tailleBarres];
    sonsActifs[0] = SDL_TRUE;
    sonsActifs[1] = SDL_TRUE;

    /* Rectangles des boutons de son */
    SDL_Rect rectangles_boutons_sons[tailleBarres]; 

    /* Variable pour suivre l'état de la sélection de touche (activé/désactivé) */
    int selection_touche = 0;

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
                        if(clic_case(event, itemsMenu[0].rectangle))
                            ongletActif = ONGLET_SON;
                        if(clic_case(event, itemsMenu[1].rectangle))
                            ongletActif = ONGLET_TOUCHES;
                        
                        if((clic_case(event, rectangles_boutons_sons[0])) && (sonsActifs[0] == SDL_TRUE)) {
                            sonsActifs[0] = SDL_FALSE;
                            barre_de_son[0].volume_precedent = barre_de_son[0].volume;
                            barre_de_son[0].volume = 0;
                        }
                        else if((clic_case(event, rectangles_boutons_sons[0])) && (barre_de_son[0].volume_precedent != 0)) {
                            sonsActifs[0] = SDL_TRUE;
                            barre_de_son[0].volume = barre_de_son[0].volume_precedent;
                        }

                        if((clic_case(event, rectangles_boutons_sons[1])) && (sonsActifs[1] == SDL_TRUE)) {
                            sonsActifs[1] = SDL_FALSE;
                            barre_de_son[1].volume_precedent = barre_de_son[1].volume;
                            barre_de_son[1].volume = 0;
                        }
                        else if(clic_case(event, rectangles_boutons_sons[1]) && (barre_de_son[1].volume_precedent != 0)) {
                            sonsActifs[1] = SDL_TRUE;
                            barre_de_son[1].volume = barre_de_son[1].volume_precedent;
                        }

                        if(clic_case(event, itemsTouches[1].rectangle))
                            selection_touche = 1;
                        else if(clic_case(event, itemsTouches[3].rectangle))
                            selection_touche = 3;
                        else if(clic_case(event, itemsTouches[5].rectangle))
                            selection_touche = 5;
                        else    
                            selection_touche = 0;

                        if(clic_plein_ecran(event, &rectangle_plein_ecran, &plein_ecran, &window))
                            redimensionnement_fenetre(event, &largeur, &hauteur);

                        break;

                case SDL_MOUSEBUTTONUP :
                    if(clic_case(event, barre_de_son[0].barre)) {
                        barre_de_son[0].volume_precedent = barre_de_son[0].volume;
                        barre_de_son[0].volume = (event.motion.x - barre_de_son[0].barre.x) * 1.0 / barre_de_son[0].barre.w;
                        if((sonsActifs[0] == SDL_FALSE) && (barre_de_son[0].volume != 0))
                            sonsActifs[0] = SDL_TRUE;
                        if(barre_de_son[0].volume == 0)
                            sonsActifs[0] = SDL_FALSE;
                    }
                    else if(clic_case(event, barre_de_son[1].barre)) {
                        barre_de_son[1].volume_precedent = barre_de_son[1].volume;
                        barre_de_son[1].volume = (event.motion.x - barre_de_son[1].barre.x) * 1.0 / barre_de_son[1].barre.w;
                        if((sonsActifs[1] == SDL_FALSE) && (barre_de_son[1].volume != 0))
                            sonsActifs[1] = SDL_TRUE;
                        if(barre_de_son[1].volume == 0)
                            sonsActifs[1] = SDL_FALSE;
                    }

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
        mise_a_jour_rendu_options(&renderer, &rectangle_plein_ecran, &texture_image_plein_ecran,
                                  &texture_image_hautParleurActif,
                                  &texture_image_hautParleurDesactive, sonsActifs,
                                  rectangles_boutons_sons, ongletActif,
                                  &titre, &texte_menu, &texture_texte_menu, &police,
                                  couleurNoire,
                                  itemsMenu, tailleMenu, itemsTouches, tailleTouches,
                                  barre_de_son, tailleBarres, itemsBarres,
                                  largeur, hauteur);
    }

    /*-------------------------------------------------------------*/

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}