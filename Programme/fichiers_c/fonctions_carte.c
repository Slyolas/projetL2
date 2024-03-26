#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_carte.h>

/* Fonction qui permet d'initialiser les différents objets de la carte */
void initialisation_objets_carte(SDL_Renderer **renderer, SDL_Surface **image_carte, SDL_Texture **texture_image_carte,
                                 itemMenu *itemsNiveaux) {

    /* Initialisation de l'image de fond de la carte */
    (*image_carte) = IMG_Load("./images/carte.jpg");
    if((*image_carte) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_carte) = SDL_CreateTextureFromSurface((*renderer), (*image_carte));
    if((*texture_image_carte) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_carte));

	/* Initialisation du texte dans les items de la carte */
    sprintf(itemsNiveaux[0].texte, " Niveau 1 ");
    sprintf(itemsNiveaux[1].texte, " Niveau 2 ");
    sprintf(itemsNiveaux[2].texte, " Niveau 3 ");
    sprintf(itemsNiveaux[3].texte, " Niveau 4 ");
}

/* Fonction qui met à jour le rendu de la carte après redimension de la fenêtre */
void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte,
                             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                             SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                             SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso,
                             SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                             position_t positionActive, SDL_Color couleurNoire,
                             itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur) {
    
    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de fond de la carte */
    if(SDL_RenderCopy((*renderer), (*texture_image_carte), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */
    rectangle_plein_ecran->x = largeur - largeur / 21;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image des options */
    rectangle_options->x = largeur - largeur / 21;
    rectangle_options->y = hauteur - hauteur / 12;
    rectangle_options->w = largeur / 21;
    rectangle_options->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_options), NULL, rectangle_options) != 0)
        erreur("Copie de la texture");

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 150);

    /* Dessine les éléments de la carte et dessine le personnage sur la carte */
    for (i = 0; i < tailleNiveaux; i++) {

        itemsNiveaux[i].rectangle.w = largeur / 7;
        itemsNiveaux[i].rectangle.h = hauteur / 17;
    }

    rectangle_perso->w = largeur / 30;
    rectangle_perso->h = hauteur / 13;

    if(positionActive == NIVEAU1) {

        itemsNiveaux[0].rectangle.x = largeur / 4 + largeur / 75;
        itemsNiveaux[0].rectangle.y = hauteur / 2 + hauteur / 17;

        rectangle_perso->x = largeur / 3 - largeur / 70;
        rectangle_perso->y = hauteur / 3 * 2 + hauteur / 50;
    }

    else if(positionActive == NIVEAU2) {

        itemsNiveaux[1].rectangle.x = largeur / 2 - largeur / 18;
        itemsNiveaux[1].rectangle.y = hauteur / 3 * 2 - hauteur / 50;

        rectangle_perso->x = largeur / 2 - largeur / 500;
        rectangle_perso->y = hauteur / 2 + hauteur / 50;
    }

    else if(positionActive == NIVEAU3) {

        itemsNiveaux[2].rectangle.x = largeur / 2 - largeur / 20;
        itemsNiveaux[2].rectangle.y = hauteur / 3 - hauteur / 46;

        rectangle_perso->x = largeur / 2 + largeur / 400;
        rectangle_perso->y = hauteur / 2 - hauteur / 14;
    }

    else if(positionActive == NIVEAU4){

        itemsNiveaux[3].rectangle.x = largeur / 3 * 2 - largeur / 9;
        itemsNiveaux[3].rectangle.y = hauteur / 4 - hauteur / 23;

        rectangle_perso->x = largeur / 3 * 2 - largeur / 19;
        rectangle_perso->y = hauteur / 4 + hauteur / 13;
    }

    if(positionActive != NIVEAU0) {

        SDL_RenderFillRect((*renderer), &(itemsNiveaux[positionActive - 1].rectangle));

        (*texte_menu) = TTF_RenderText_Solid((*police), itemsNiveaux[positionActive - 1].texte, couleurNoire);
        (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

        SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsNiveaux[positionActive - 1].rectangle));

        SDL_FreeSurface((*texte_menu));
        SDL_DestroyTexture((*texture_texte_menu));
    }

    if(SDL_RenderCopy((*renderer), (*texture_image_perso), NULL, rectangle_perso) != 0)
        erreur("Copie de la texture");

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent sur la carte */
void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte,
           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
           SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
           SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso, personnage_t *personnageActif,
           SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
           position_t *positionActive, SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir,
           itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active) {

    int i;

    /* Création d'un pointeur sur la surface de l'image du personnage */
    SDL_Surface *image_perso = NULL;

    /* Initialisation de l'image du personnage */
    if((*personnageActif) == PERSONNAGE_1)
        image_perso = IMG_Load("./images/personnage_masculin.png");
    else
        image_perso = IMG_Load("./images/personnage_feminin.png");

    if(image_perso == NULL)
        erreur("Chargement de l'image");
                            
    (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
    if((*texture_image_perso) == NULL)
        erreur("Création de la texture");

    SDL_FreeSurface(image_perso);

    while(SDL_PollEvent(event)) {

            switch(event->type) {
                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                /* Lecture de la touche pressée et de la position du personnage pour savoir où aller */
                case SDL_KEYDOWN :
                    /* Aller du niveau 1 au niveau 2 */
                    if((*positionActive == NIVEAU1) && 
                       ((event->key.keysym.sym == (*touche_aller_a_droite)) || (event->key.keysym.sym == (*touche_sauter_monter)))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y > (((*hauteur) / 2 + (*hauteur) / 50) + (*hauteur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->x += (*largeur) / 100;
                            rectangle_perso->y -= (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }

                        (*positionActive) = NIVEAU2;
                    }

                    /* Entrer dans le niveau 1 */
                    else if((*positionActive == NIVEAU1) && 
                            (event->key.keysym.sym == (*touche_interagir)))
                        printf("Vous entrez dans le niveau 1 !\n");

                    /* Aller du niveau 2 au niveau 3 */
                    else if((*positionActive == NIVEAU2) && 
                            (event->key.keysym.sym == (*touche_sauter_monter))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y > (((*hauteur) / 2 - (*hauteur) / 14) + (*hauteur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->y -= (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }
                        
                        (*positionActive) = NIVEAU3;
                    }

                    /* Aller du niveau 2 au niveau 1 */
                    else if((*positionActive == NIVEAU2) && 
                            ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y < (((*hauteur) / 3 * 2 + (*hauteur) / 50) - (*largeur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_gauche_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_gauche_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_gauche_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_gauche_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->x -= (*largeur) / 100;
                            rectangle_perso->y += (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }   
                        
                        (*positionActive) = NIVEAU1;
                    }

                    /* Entrer dans le niveau 2 */
                    else if((*positionActive == NIVEAU2) && 
                            (event->key.keysym.sym == (*touche_interagir)))
                        printf("Vous entrez dans le niveau 2 !\n");

                    /* Aller du niveau 3 au niveau 4 */
                    else if((*positionActive == NIVEAU3) && 
                            ((event->key.keysym.sym == (*touche_aller_a_droite)) || (event->key.keysym.sym == (*touche_sauter_monter)))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y > (((*hauteur) / 4 + (*hauteur) / 13) + (*hauteur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_haut_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_haut_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->x += (*largeur) / 100;
                            rectangle_perso->y -= (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }

                        (*positionActive) = NIVEAU4;
                    }

                    /* Aller du niveau 3 au niveau 2 */
                    else if((*positionActive == NIVEAU3) && 
                            (event->key.keysym.sym == (*touche_descendre))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y < (((*hauteur) / 2 + (*hauteur) / 50) - (*hauteur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->y += (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }

                        (*positionActive) = NIVEAU2;
                    }

                    /* Entrer dans le niveau 3 */
                    else if((*positionActive == NIVEAU3) && 
                            (event->key.keysym.sym == (*touche_interagir)))
                        printf("Vous entrez dans le niveau 3 !\n");

                    /* Aller du niveau 4 au niveau 3 */
                    if((*positionActive == NIVEAU4) && 
                       ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {
                        (*positionActive) = NIVEAU0;

                        for(i = 0; rectangle_perso->y < (((*hauteur) / 2 - (*hauteur) / 14) - (*largeur) / 75); i++) {
                            if(i % 2)
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_gauche_1.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_gauche_1.png");
                            else
                                if((*personnageActif) == PERSONNAGE_1)
                                    image_perso = IMG_Load("./images/personnage_masculin_bas_gauche_2.png");
                                else
                                    image_perso = IMG_Load("./images/personnage_feminin_bas_gauche_2.png");

                            if(image_perso == NULL)
                                erreur("Chargement de l'image");
                            
                            (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                            if((*texture_image_perso) == NULL)
                                erreur("Création de la texture");

                            SDL_FreeSurface(image_perso);

                            rectangle_perso->x -= (*largeur) / 100;
                            rectangle_perso->y += (*hauteur) / 100;
                            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                                    rectangle_options, texture_image_options,
                                                    rectangle_perso, texture_image_perso,
                                                    texte_menu, texture_texte_menu, police,
                                                    (*positionActive), couleurNoire,
                                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                            SDL_Delay(75);
                        }

                        (*positionActive) = NIVEAU3;
                    }

                    /* Entrer dans le niveau 4 */
                    else if((*positionActive == NIVEAU4) && 
                            (event->key.keysym.sym == (*touche_interagir)))
                        printf("Vous entrez dans le niveau 4 !\n");

                    /* Initialisation de l'image du personnage */
                    if((*personnageActif) == PERSONNAGE_1)
                        image_perso = IMG_Load("./images/personnage_masculin.png");
                    else
                        image_perso = IMG_Load("./images/personnage_feminin.png");

                    if(image_perso == NULL)
                        erreur("Chargement de l'image");
                            
                    (*texture_image_perso) = SDL_CreateTextureFromSurface((*renderer), image_perso);
                    if((*texture_image_perso) == NULL)
                        erreur("Création de la texture");

                    SDL_FreeSurface(image_perso);

                    break;

                /* Options plein écran et options */
                case SDL_MOUSEBUTTONDOWN:
                    
                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                    if(clic_case((*event), (*rectangle_options)))
                        (*page_active) = OPTIONS;

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
        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                rectangle_plein_ecran, texture_image_plein_ecran,
                                rectangle_options, texture_image_options,
                                rectangle_perso, texture_image_perso,
                                texte_menu, texture_texte_menu, police,
                                (*positionActive), couleurNoire,
                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
}