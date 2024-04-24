#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_menu_principal.h>

/* Fonction qui permet d'initialiser les différents objets du menu principal */
void initialisation_objets_menu_principal(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_menu,
                                          itemMenu *titre, itemMenu *itemsMenu, int tailleMenu) {

    int i;
    
    /* Initialisation de l'image de fond du menu */
    chargement_image(renderer, surface, texture_image_menu, "./images/ecran_accueil.png");

    /* Initialisation du titre du menu */
    sprintf(titre->texte, " MetaTravers ");

	/* Initialisation du texte dans les items du menu */

    if(tailleMenu == 2) {

        for(i = 0; i < tailleMenu; i++) {

            if(!i)
                sprintf(itemsMenu[i].texte, " Nouvelle Partie ");

            else
                sprintf(itemsMenu[i].texte, "     Options     ");
        }
    }

    else {

        for(i = 0; i < tailleMenu; i++) {

            if(!i)
                sprintf(itemsMenu[i].texte, "    Continuer    ");

            else if(i == 1)
                sprintf(itemsMenu[i].texte, " Nouvelle Partie ");

            else
                sprintf(itemsMenu[i].texte, "     Options     ");
        }
    }
}

/* Fonction qui met à jour le rendu du menu principal */
void mise_a_jour_rendu_menu_principal(SDL_Renderer **renderer, SDL_Texture **texture_image_menu,
                                      SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                      itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                                      SDL_Color couleurTitre, SDL_Color couleurNoire, int selection_menu,
                                      itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur) {
    
    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de fond du menu */
    if(SDL_RenderCopy((*renderer), (*texture_image_menu), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur - largeur / 21 - largeur / 53;
    rectangle_plein_ecran->y = hauteur / 30;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 175);

    /* Dessine le titre du menu */

    titre->rectangle.x = largeur / 2 - largeur / 3;
    titre->rectangle.y = hauteur / 20;
    titre->rectangle.w = largeur / 2 + largeur / 5;
    titre->rectangle.h = hauteur / 5;

    affichage_texte(renderer, surface, texture_texte, titre, 
                    police, couleurTitre);

    /* Dessine les éléments du menu */

    if(tailleMenu == 2) {

        for (i = 0; i < tailleMenu; i++) {

            if(selection_menu == (i + 1)) {

                itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6 - largeur / 200;
                itemsMenu[i].rectangle.y = hauteur / 3 + (i+1) * hauteur / 13 + i * hauteur / 11 - hauteur / 90;
                itemsMenu[i].rectangle.w = largeur / 3 + largeur / 100;
                itemsMenu[i].rectangle.h = hauteur / 10 + hauteur / 60 + hauteur / 250;

                SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
                SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));
            }

            SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

            itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6;
            itemsMenu[i].rectangle.y = hauteur / 3 + (i+1) * hauteur / 13 + i * hauteur / 11;
            itemsMenu[i].rectangle.w = largeur / 3;
            itemsMenu[i].rectangle.h = hauteur / 10;

            affichage_texte(renderer, surface, texture_texte, &(itemsMenu[i]), 
                            police, couleurNoire);
        }
    }

    else {

        for (i = 0; i < tailleMenu; i++) {

            if(selection_menu == (i + 1)) {

                itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6 - largeur / 200;
                itemsMenu[i].rectangle.y = hauteur / 3 + i * hauteur / 6 - hauteur / 90;
                itemsMenu[i].rectangle.w = largeur / 3 + largeur / 100;
                itemsMenu[i].rectangle.h = hauteur / 10 + hauteur / 60 + hauteur / 250;

                SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
                SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));
            }

            SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

            itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6;
            itemsMenu[i].rectangle.y = hauteur / 3 + i * hauteur / 6;
            itemsMenu[i].rectangle.w = largeur / 3;
            itemsMenu[i].rectangle.h = hauteur / 10;

            affichage_texte(renderer, surface, texture_texte, &(itemsMenu[i]), 
                            police, couleurNoire);
        }
    }

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le menu principal */
void menu_principal(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_menu,
                    SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
                    itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                    SDL_Color couleurTitre, SDL_Color couleurNoire, int code_de_triche[3], int *selection_menu,
                    itemMenu *itemsMenu, int tailleMenu, int *largeur, int *hauteur, page_t *page_active) {

    while(SDL_PollEvent(event)) {

            switch(event->type) {
                
                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                /* Gestion de l'événement de la position de la souris sur les différents items */
                case SDL_MOUSEMOTION:
                    
                    if((event->motion.x >= itemsMenu[0].rectangle.x) && (event->motion.x <= (itemsMenu[0].rectangle.x + itemsMenu[0].rectangle.w)) &&
                       (event->motion.y >= itemsMenu[0].rectangle.y) && (event->motion.y <= (itemsMenu[0].rectangle.y + itemsMenu[0].rectangle.h)))
                       (*selection_menu) = 1;

                    else if((event->motion.x >= itemsMenu[1].rectangle.x) && (event->motion.x <= (itemsMenu[1].rectangle.x + itemsMenu[1].rectangle.w)) &&
                            (event->motion.y >= itemsMenu[1].rectangle.y) && (event->motion.y <= (itemsMenu[1].rectangle.y + itemsMenu[1].rectangle.h)))
                       (*selection_menu) = 2;

                    else if((event->motion.x >= itemsMenu[2].rectangle.x) && (event->motion.x <= (itemsMenu[2].rectangle.x + itemsMenu[2].rectangle.w)) &&
                            (event->motion.y >= itemsMenu[2].rectangle.y) && (event->motion.y <= (itemsMenu[2].rectangle.y + itemsMenu[2].rectangle.h)))
                       (*selection_menu) = 3;

                    else
                        (*selection_menu) = 0; 

                    break;

                /* Gestion de l'événement du clic sur les différents items */
                case SDL_MOUSEBUTTONDOWN:

                    if(tailleMenu == 2) {

                        if(clic_case((*event), itemsMenu[0].rectangle))
                            (*page_active) = NOUVELLE_PARTIE;

                        else if(clic_case((*event), itemsMenu[1].rectangle))
                            (*page_active) = OPTIONS;
                    }

                    else {

                        if(clic_case((*event), itemsMenu[0].rectangle))
                            (*page_active) = CARTE;

                        else if(clic_case((*event), itemsMenu[1].rectangle))
                            (*page_active) = NOUVELLE_PARTIE;

                        else if(clic_case((*event), itemsMenu[2].rectangle))
                            (*page_active) = OPTIONS;
                    }

                    /* Option plein écran */
                    
                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                /* Gestion de l'événement du code de triche */
                case SDL_KEYDOWN:

                        if((event->key.keysym.sym == SDLK_g) && (code_de_triche[1]))
                            code_de_triche[0] = 1;

                        if(event->key.keysym.sym == SDLK_b)
                            code_de_triche[1] = 1;

                        if((event->key.keysym.sym == SDLK_n) && (code_de_triche[0]))
                            code_de_triche[2] = 1;

                        break;

                /* Quitter le programme */
                case SDL_QUIT:
                    (*programme_lance) = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        
        /* Mise à jour du rendu */
        mise_a_jour_rendu_menu_principal(renderer, texture_image_menu,
                                         rectangle_plein_ecran, texture_image_plein_ecran,
                                         titre, surface, texture_texte, police,
                                         couleurTitre, couleurNoire, (*selection_menu),
                                         itemsMenu, tailleMenu, (*largeur), (*hauteur));
}