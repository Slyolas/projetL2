#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_menu_principal.h>

/* Fonction qui permet d'initialiser les différents objets du menu principal */
void initialisation_objets_menu_principal(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_menu,
                                          itemMenu *titre, itemMenu *itemsMenu, int tailleMenu) {

    /* Initialisation de l'image de fond du menu */
    chargement_image(renderer, surface, texture_image_menu, "./images/ecran_accueil.png");

    /* Initialisation du titre du menu */
    sprintf(titre->texte, " MetaTravers ");

	/* Initialisation du texte dans les items du menu */
    if(tailleMenu == 2) {
        for(int i = 0; i < tailleMenu; i++) {
        if(!i)
            sprintf(itemsMenu[i].texte, " Nouvelle Partie ");
        else
            sprintf(itemsMenu[i].texte, " Options ");
    }
    }
    else {
        for(int i = 0; i < tailleMenu; i++) {
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
                                      SDL_Color couleurTitre, SDL_Color couleurNoire,
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

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    /* Dessine les éléments du menu */
    if(tailleMenu == 2) {
        for (i = 0; i < tailleMenu; i++) {

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
                    SDL_Color couleurTitre, SDL_Color couleurNoire,
                    itemMenu *itemsMenu, int tailleMenu, int *largeur, int *hauteur, page_t *page_active) {

    while(SDL_PollEvent(event)) {

            switch(event->type) {
                
                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

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
                                         couleurTitre, couleurNoire,
                                         itemsMenu, tailleMenu, (*largeur), (*hauteur));
}