#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_options.h>

/* Fonction qui permet d'initialiser les différents objets des options */
void initialisation_objets_options(SDL_Renderer **renderer,
                                   SDL_Surface **image_hautParleurActif, SDL_Texture **texture_image_hautParleurActif,
                                   SDL_Surface **image_hautParleurDesactive, SDL_Texture **texture_image_hautParleurDesactive,
                                   itemMenu *titre, itemMenu *itemsMenu, itemMenu *itemsTouches, itemMenu *itemsBarres) {

    /* Initialisation de l'image du haut parleur actif */
    (*image_hautParleurActif) = IMG_Load("./images/haut_parleur_actif.png");
    if((*image_hautParleurActif) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurActif) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurActif));
    if((*texture_image_hautParleurActif) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurActif));

    /* Initialisation de l'image du haut parleur desactif */
    (*image_hautParleurDesactive) = IMG_Load("./images/haut_parleur_desactive.png");
    if((*image_hautParleurDesactive) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurDesactive) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurDesactive));
    if((*texture_image_hautParleurDesactive) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurDesactive));

    /* Initialisation du titre des options */
    sprintf(titre->texte, " Options ");

    /* Initialisation du texte des onglets */
    sprintf(itemsMenu[0].texte, "           Son           ");
    sprintf(itemsMenu[1].texte, "         Touches         ");

    /* Initialisation du texte dans les items */
    sprintf(itemsTouches[0].texte, " Touche pour aller vers la droite : ");
    sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName(SDLK_RIGHT));
    sprintf(itemsTouches[2].texte, " Touche pour aller vers la gauche : ");
    sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName(SDLK_LEFT));
    sprintf(itemsTouches[4].texte, "    Touche pour sauter / monter :   ");
    sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName(SDLK_UP));
    sprintf(itemsTouches[6].texte, "       Touche pour descendre :      ");
    sprintf(itemsTouches[7].texte, "                 %s                 ", SDL_GetKeyName(SDLK_DOWN));
    sprintf(itemsTouches[8].texte, "       Touche pour interagir :      ");
    sprintf(itemsTouches[9].texte, "                 %s                 ", SDL_GetKeyName(SDLK_SPACE));
    sprintf(itemsBarres[0].texte, "              Musique :             ");
    sprintf(itemsBarres[1].texte, "           Effets sonores :         ");
}

/* Fonction qui met à jour le rendu des options après redimension de la fenêtre */
void mise_a_jour_rendu_options(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                               SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                               SDL_Texture **texture_image_hautParleurActif, 
                               SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
                               SDL_Rect *rectangles_boutons_sons, option_t ongletActif,
                               itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                               SDL_Color couleurNoire,
                               itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, 
                               barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres,
                               int largeur, int hauteur) {

    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de plein écran */
    rectangle_plein_ecran->x = largeur - largeur / 21;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image du retour en arrière */
    rectangle_retour_en_arriere->x = 0;
    rectangle_retour_en_arriere->y = 0;
    rectangle_retour_en_arriere->w = largeur / 21;
    rectangle_retour_en_arriere->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_retour_en_arriere), NULL, rectangle_retour_en_arriere) != 0)
        erreur("Copie de la texture");

    /* Dessine le titre des options */
    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 255);

    titre->rectangle.x = largeur / 3;
    titre->rectangle.y = hauteur / 15;
    titre->rectangle.w = largeur / 3;
    titre->rectangle.h = hauteur / 10;

    SDL_RenderFillRect((*renderer), &(titre->rectangle));

    (*texte_menu) = TTF_RenderText_Solid((*police), titre->texte, couleurNoire);
    (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

    SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(titre->rectangle));

    SDL_FreeSurface((*texte_menu));
    SDL_DestroyTexture((*texture_texte_menu));

    /* Décide de la couleur en fonction de l'onglet actif */
    if(ongletActif == ONGLET_SON)
        SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
    else
        SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

    /* Dessine les éléments des onglets */
    for (i = 0; i < tailleMenu; i++) {

        if((i) && (ongletActif == ONGLET_TOUCHES))
            SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
        else if(i)
            SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

        itemsMenu[i].rectangle.x = i * largeur / 2;
        itemsMenu[i].rectangle.y = hauteur / 15 * 3;
        itemsMenu[i].rectangle.w = largeur / 2;
        itemsMenu[i].rectangle.h = hauteur / 10;

        SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));

        (*texte_menu) = TTF_RenderText_Solid((*police), itemsMenu[i].texte, couleurNoire);
        (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

        SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsMenu[i].rectangle));

        SDL_FreeSurface((*texte_menu));
        SDL_DestroyTexture((*texture_texte_menu));
    }

    if(ongletActif == ONGLET_SON) {

        /* Dessine les items pour les deux barres de sons */
        SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

        for (i = 0; i < tailleBarres; i++) {

            itemsBarres[i].rectangle.x = largeur / 8;
            itemsBarres[i].rectangle.y = hauteur / 2 + hauteur / 50 + i * hauteur / 5 - hauteur / 100;
            itemsBarres[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsBarres[i].rectangle.h = hauteur / 15;

            SDL_RenderFillRect((*renderer), &(itemsBarres[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsBarres[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsBarres[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }

        /* Dessine les boutons sons actifs ou desactifs des deux barres de sons */
        for (i = 0; i < tailleBarres; i++) {

            rectangles_boutons_sons[i].x = largeur - largeur / 9;
            rectangles_boutons_sons[i].y = hauteur / 2 + hauteur / 50 + i * hauteur / 5;
            rectangles_boutons_sons[i].w = largeur / 35;
            rectangles_boutons_sons[i].h = hauteur / 20;

            if(sonsActifs[i]) {
                if(SDL_RenderCopy((*renderer), (*texture_image_hautParleurActif), NULL, &(rectangles_boutons_sons[i])) != 0)
                    erreur("Copie de la texture");
            }
            else
                if(SDL_RenderCopy((*renderer), (*texture_image_hautParleurDesactive), NULL, &(rectangles_boutons_sons[i])) != 0)
                    erreur("Copie de la texture");
        }

        /* Dessine les rectangles et les curseurs des deux barres de sons */
        for (i = 0; i < tailleBarres; i++) {

            barre_de_son[i].barre.x = largeur - largeur / 8 - (largeur / 2 - largeur / 7);
            barre_de_son[i].barre.y = hauteur / 2 + hauteur / 50 + i * hauteur / 5;
            barre_de_son[i].barre.w = largeur / 2 - largeur / 7;
            barre_de_son[i].barre.h = hauteur / 20;

            barre_de_son[i].curseur.x = barre_de_son[i].barre.x + (largeur / 2 - largeur / 7) * barre_de_son[i].volume - largeur / 45 / 2;
            barre_de_son[i].curseur.y = hauteur / 2 + i * hauteur / 5;
            barre_de_son[i].curseur.w = largeur / 45;
            barre_de_son[i].curseur.h = hauteur / 12;

            SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
            SDL_RenderFillRect((*renderer), &(barre_de_son[i].barre));

            SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
            SDL_RenderFillRect((*renderer), &(barre_de_son[i].curseur));
        }

        for (i = 0; i < tailleTouches; i++) {

            itemsTouches[i].rectangle.x = 0;
            itemsTouches[i].rectangle.y = 0;
            itemsTouches[i].rectangle.w = 0;
            itemsTouches[i].rectangle.h = 0;
        }
    }
    else {

        for (i = 0; i < tailleBarres; i++) {

            rectangles_boutons_sons[i].x = 0;
            rectangles_boutons_sons[i].y = 0;
            rectangles_boutons_sons[i].w = 0;
            rectangles_boutons_sons[i].h = 0;

            barre_de_son[i].barre.x = 0;
            barre_de_son[i].barre.y = 0;
            barre_de_son[i].barre.w = 0;
            barre_de_son[i].barre.h = 0;

            barre_de_son[i].curseur.x = 0;
            barre_de_son[i].curseur.y = 0;
            barre_de_son[i].curseur.w = 0;
            barre_de_son[i].curseur.h = 0;

            itemsBarres[i].rectangle.x = 0;
            itemsBarres[i].rectangle.y = 0;
            itemsBarres[i].rectangle.w = 0;
            itemsBarres[i].rectangle.h = 0;
        }

        /* Dessine les items pour les trois touches différentes */
        SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

        for (i = 0; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 7;
            itemsTouches[i].rectangle.y = hauteur / 2 - hauteur / 7 + i * hauteur / 15;
            itemsTouches[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsTouches[i].rectangle.h = hauteur / 15;

            SDL_RenderFillRect((*renderer), &(itemsTouches[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsTouches[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsTouches[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }

        /* Dessine les rectangles pour les trois touches différentes */
        SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

        for (i = 1; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 2;
            itemsTouches[i].rectangle.y = hauteur / 2 - hauteur / 7 + (i-1) * hauteur / 15;
            itemsTouches[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsTouches[i].rectangle.h = hauteur / 15;

            SDL_RenderFillRect((*renderer), &(itemsTouches[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsTouches[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsTouches[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }
    }     

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans les options */
void options(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
             SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
             SDL_Texture **texture_image_hautParleurActif, 
             SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
             SDL_Rect *rectangles_boutons_sons, option_t *ongletActif,
             itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
             int *selection_touche, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
             SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, SDL_Color couleurNoire,
             itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, 
             barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres,
             int *largeur, int *hauteur, page_t *page_active, page_t *page_precedente) {

    while(SDL_PollEvent(event)) {

            switch(event->type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                case SDL_MOUSEBUTTONDOWN:
                        if(clic_case((*event), itemsMenu[0].rectangle))
                            (*ongletActif) = ONGLET_SON;
                        if(clic_case((*event), itemsMenu[1].rectangle))
                            (*ongletActif) = ONGLET_TOUCHES;
                        
                        if((clic_case((*event), rectangles_boutons_sons[0])) && (sonsActifs[0] == SDL_TRUE)) {
                            sonsActifs[0] = SDL_FALSE;
                            barre_de_son[0].volume_precedent = barre_de_son[0].volume;
                            barre_de_son[0].volume = 0;
                        }
                        else if((clic_case((*event), rectangles_boutons_sons[0])) && (barre_de_son[0].volume_precedent != 0)) {
                            sonsActifs[0] = SDL_TRUE;
                            barre_de_son[0].volume = barre_de_son[0].volume_precedent;
                        }

                        if((clic_case((*event), rectangles_boutons_sons[1])) && (sonsActifs[1] == SDL_TRUE)) {
                            sonsActifs[1] = SDL_FALSE;
                            barre_de_son[1].volume_precedent = barre_de_son[1].volume;
                            barre_de_son[1].volume = 0;
                        }
                        else if(clic_case((*event), rectangles_boutons_sons[1]) && (barre_de_son[1].volume_precedent != 0)) {
                            sonsActifs[1] = SDL_TRUE;
                            barre_de_son[1].volume = barre_de_son[1].volume_precedent;
                        }

                        if(clic_case((*event), itemsTouches[1].rectangle))
                            (*selection_touche) = 1;
                        else if(clic_case((*event), itemsTouches[3].rectangle))
                            (*selection_touche) = 3;
                        else if(clic_case((*event), itemsTouches[5].rectangle))
                            (*selection_touche) = 5;
                        else if(clic_case((*event), itemsTouches[7].rectangle))
                            (*selection_touche) = 7;
                        else if(clic_case((*event), itemsTouches[9].rectangle))
                            (*selection_touche) = 9;
                        else    
                            (*selection_touche) = 0;

                        if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                        if(clic_case((*event), (*rectangle_retour_en_arriere)))
                            (*page_active) = (*page_precedente);

                        break;

                case SDL_MOUSEBUTTONUP :
                    if(clic_case((*event), barre_de_son[0].barre)) {
                        barre_de_son[0].volume_precedent = barre_de_son[0].volume;
                        barre_de_son[0].volume = (event->motion.x - barre_de_son[0].barre.x) * 1.0 / barre_de_son[0].barre.w;
                        if((sonsActifs[0] == SDL_FALSE) && (barre_de_son[0].volume != 0))
                            sonsActifs[0] = SDL_TRUE;
                        if(barre_de_son[0].volume == 0)
                            sonsActifs[0] = SDL_FALSE;
                    }
                    else if(clic_case((*event), barre_de_son[1].barre)) {
                        barre_de_son[1].volume_precedent = barre_de_son[1].volume;
                        barre_de_son[1].volume = (event->motion.x - barre_de_son[1].barre.x) * 1.0 / barre_de_son[1].barre.w;
                        if((sonsActifs[1] == SDL_FALSE) && (barre_de_son[1].volume != 0))
                            sonsActifs[1] = SDL_TRUE;
                        if(barre_de_son[1].volume == 0)
                            sonsActifs[1] = SDL_FALSE;
                    }

                    break;

                case SDL_KEYDOWN :
                    if((event->key.keysym.sym == SDLK_ESCAPE) && (*selection_touche)) {
                        (*touche_aller_a_droite) = SDLK_RIGHT;
                        (*touche_aller_a_gauche) = SDLK_LEFT;
                        (*touche_sauter_monter) = SDLK_UP;
                        (*touche_descendre) = SDLK_DOWN;
                        (*touche_interagir) = SDLK_SPACE;
                        sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName((*touche_aller_a_droite)));
                        sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName((*touche_aller_a_gauche)));
                        sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName((*touche_sauter_monter)));
                        sprintf(itemsTouches[7].texte, "                 %s                 ", SDL_GetKeyName((*touche_descendre)));
                        sprintf(itemsTouches[9].texte, "                 %s                 ", SDL_GetKeyName((*touche_interagir)));
                        (*selection_touche) = 0;
                    }
                    else if(((*selection_touche) == 1) && 
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_descendre)) &&
                            (event->key.keysym.sym != (*touche_interagir))) {
                               (*touche_aller_a_droite) = event->key.keysym.sym; 
                        sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche_aller_a_droite)));
                        (*selection_touche) = 0;
                    }
                    else if(((*selection_touche) == 3) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_descendre)) &&
                            (event->key.keysym.sym != (*touche_interagir))) {
                               (*touche_aller_a_gauche) = event->key.keysym.sym; 
                        sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche_aller_a_gauche)));
                        (*selection_touche) = 0;
                    }
                    else if(((*selection_touche) == 5) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_descendre)) &&
                            (event->key.keysym.sym != (*touche_interagir))) {
                               (*touche_sauter_monter) = event->key.keysym.sym; 
                        sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche_sauter_monter)));
                        (*selection_touche) = 0;
                    }
                    else if(((*selection_touche) == 7) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_interagir))) {
                               (*touche_descendre) = event->key.keysym.sym; 
                        sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche_descendre)));
                        (*selection_touche) = 0;
                    }
                    else if(((*selection_touche) == 9) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_descendre))) {
                               (*touche_interagir) = event->key.keysym.sym; 
                        sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche_interagir)));
                        (*selection_touche) = 0;
                    }
                    break;

                case SDL_QUIT:
                    (*programme_lance) = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu_options(renderer, rectangle_plein_ecran, texture_image_plein_ecran,
                                  rectangle_retour_en_arriere, texture_image_retour_en_arriere,
                                  texture_image_hautParleurActif,
                                  texture_image_hautParleurDesactive, sonsActifs,
                                  rectangles_boutons_sons, (*ongletActif),
                                  titre, texte_menu, texture_texte_menu, police,
                                  couleurNoire,
                                  itemsMenu, tailleMenu, itemsTouches, tailleTouches,
                                  barre_de_son, tailleBarres, itemsBarres,
                                  (*largeur), (*hauteur));
}