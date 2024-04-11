/**
 * @file fonctions_carte.c
 * @brief Génération de la carte des mondes
 * @version 1.0
 * 
 *
 */


#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_carte.h>

/**
 *  @brief Fonction qui permet d'initialiser les différents objets de la carte 
 *  @return void 
 */
void initialisation_objets_carte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_carte,
                                 SDL_Texture **texture_image_perso_1_bas_1, SDL_Texture **texture_image_perso_1_bas_2,
                                 SDL_Texture **texture_image_perso_1_haut_1, SDL_Texture **texture_image_perso_1_haut_2,
                                 SDL_Texture **texture_image_perso_1_bas_gauche_1, SDL_Texture **texture_image_perso_1_bas_gauche_2,
                                 SDL_Texture **texture_image_perso_1_haut, SDL_Texture **texture_image_perso_1_droite,
                                 SDL_Texture **texture_image_perso_1_gauche, SDL_Texture **texture_image_perso_1_pose,
                                 SDL_Texture **texture_image_perso_2_bas_1, SDL_Texture **texture_image_perso_2_bas_2,
                                 SDL_Texture **texture_image_perso_2_haut_1, SDL_Texture **texture_image_perso_2_haut_2,
                                 SDL_Texture **texture_image_perso_2_bas_gauche_1, SDL_Texture **texture_image_perso_2_bas_gauche_2,
                                 SDL_Texture **texture_image_perso_2_haut, SDL_Texture **texture_image_perso_2_droite,
                                 SDL_Texture **texture_image_perso_2_gauche, SDL_Texture **texture_image_perso_2_pose,
                                 itemMenu *itemsNiveaux) {

    /* Initialisation de l'image de fond de la carte */
    chargement_image(renderer, surface, texture_image_carte, "./images/carte.jpg");

    /* Initialisation des différentes images des personnages */
    
    chargement_image(renderer, surface, texture_image_perso_1_bas_1, "./images/personnage_masculin_bas_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_2, "./images/personnage_masculin_bas_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut_1, "./images/personnage_masculin_haut_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut_2, "./images/personnage_masculin_haut_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_gauche_1, "./images/personnage_masculin_bas_gauche_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_gauche_2, "./images/personnage_masculin_bas_gauche_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut, "./images/personnage_masculin_haut.png");
    chargement_image(renderer, surface, texture_image_perso_1_droite, "./images/personnage_masculin_droite.png");
    chargement_image(renderer, surface, texture_image_perso_1_gauche, "./images/personnage_masculin_gauche.png");
    chargement_image(renderer, surface, texture_image_perso_1_pose, "./images/personnage_masculin_pose.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_1, "./images/personnage_feminin_bas_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_2, "./images/personnage_feminin_bas_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut_1, "./images/personnage_feminin_haut_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut_2, "./images/personnage_feminin_haut_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_gauche_1, "./images/personnage_feminin_bas_gauche_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_gauche_2, "./images/personnage_feminin_bas_gauche_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut, "./images/personnage_feminin_haut.png");
    chargement_image(renderer, surface, texture_image_perso_2_droite, "./images/personnage_feminin_droite.png");
    chargement_image(renderer, surface, texture_image_perso_2_gauche, "./images/personnage_feminin_gauche.png");
    chargement_image(renderer, surface, texture_image_perso_2_pose, "./images/personnage_feminin_pose.png");

	/* Initialisation du texte dans les items de la carte */
    sprintf(itemsNiveaux[0].texte, " Niveau 1 ");
    sprintf(itemsNiveaux[1].texte, " Niveau 2 ");
    sprintf(itemsNiveaux[2].texte, " Niveau 3 ");
    sprintf(itemsNiveaux[3].texte, " La Tour Infernale ");
}

/* Fonction qui met à jour le rendu de la carte après redimension de la fenêtre */
void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte,
                             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                             SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                             SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso,
                             SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
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

    if(positionActive != NIVEAU0)
        affichage_texte(renderer, surface, texture_texte, &(itemsNiveaux[positionActive - 1]), 
                            police, couleurNoire);

    if(SDL_RenderCopy((*renderer), (*texture_image_perso), NULL, rectangle_perso) != 0)
        erreur("Copie de la texture");

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de deplacer le personnage sur la carte */
void deplacement_personnage_carte(SDL_Renderer **renderer, SDL_Window **window, SDL_Texture **texture_image_carte,
                                    SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                    SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                    SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso_1, SDL_Texture **texture_image_perso_2, 
                                    SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                                    position_t *positionActive, SDL_Color couleurNoire,
                                    itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur,
                                    int valeur_maximale, direction_t direction) {

    int i;

    SDL_SetWindowResizable((*window), SDL_FALSE);

    (*positionActive) = NIVEAU0;

    if((direction == HAUT) || (direction == HAUT_DROITE)) {
        for(i = 0; rectangle_perso->y > valeur_maximale; i++) {

            if((direction == HAUT) || (direction == HAUT_DROITE))
                rectangle_perso->y -= hauteur / 100;
            else if((direction == BAS) || (direction == BAS_GAUCHE))
                rectangle_perso->y += hauteur / 100;

            if(direction == HAUT_DROITE)
                rectangle_perso->x += largeur / 100;
            else if(direction == BAS_GAUCHE)
                rectangle_perso->x -= largeur / 100;
            

            if(i % 2)
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_1,
                                        surface, texture_texte, police,
                                        (*positionActive), couleurNoire,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur);
                                    
            else
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_2,
                                        surface, texture_texte, police,
                                        (*positionActive), couleurNoire,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur);

            SDL_Delay(75);
        }
    }

    else if((direction == BAS) || (direction == BAS_GAUCHE)) {
        for(i = 0; rectangle_perso->y < valeur_maximale; i++) {

            if((direction == HAUT) || (direction == HAUT_DROITE))
                rectangle_perso->y -= hauteur / 100;
            else if((direction == BAS) || (direction == BAS_GAUCHE))
                rectangle_perso->y += hauteur / 100;

            if(direction == HAUT_DROITE)
                rectangle_perso->x += largeur / 100;
            else if(direction == BAS_GAUCHE)
                rectangle_perso->x -= largeur / 100;
            

            if(i % 2)
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_1,
                                        surface, texture_texte, police,
                                        (*positionActive), couleurNoire,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur);
                                    
            else
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_2,
                                        surface, texture_texte, police,
                                        (*positionActive), couleurNoire,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur);

            SDL_Delay(75);
        }
    }

    SDL_SetWindowResizable((*window), SDL_TRUE);
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent sur la carte */
void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte,
           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
           SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
           SDL_Texture **texture_image_perso_bas_1, SDL_Texture **texture_image_perso_bas_2,
           SDL_Texture **texture_image_perso_haut_1, SDL_Texture **texture_image_perso_haut_2,
           SDL_Texture **texture_image_perso_bas_gauche_1, SDL_Texture **texture_image_perso_bas_gauche_2,
           SDL_Texture **texture_image_perso_haut, SDL_Texture **texture_image_perso_droite,
           SDL_Texture **texture_image_perso_gauche, SDL_Texture **texture_image_perso_pose,
           SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso,
           SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, direction_t *direction,
           SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde,
           position_t *positionActive, barreDeSon *barre_de_son, itemMenu *pseudo, modes_t *modeActif, personnage_t *personnageActif,
           SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir,
           itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

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

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 + (*hauteur) / 50) + (*hauteur) / 75), HAUT_DROITE);

                        (*positionActive) = NIVEAU2;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 1 */
                    else if((*positionActive == NIVEAU1) && 
                            (event->key.keysym.sym == (*touche_interagir))) {
                        
                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police,
                                                (*positionActive), couleurNoire,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));

                        SDL_Delay(1000);
                        
                        printf("Vous entrez dans le niveau 1 !\n");

                        (*direction) = BAS;
                    }

                    /* Aller du niveau 2 au niveau 3 */
                    else if((*positionActive == NIVEAU2) && 
                            (event->key.keysym.sym == (*touche_sauter_monter))) {
                        
                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 - (*hauteur) / 14) + (*hauteur) / 75), HAUT);

                        (*positionActive) = NIVEAU3;
                        (*direction) = BAS;
                    }

                    /* Aller du niveau 2 au niveau 1 */
                    else if((*positionActive == NIVEAU2) && 
                            ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_gauche_1, texture_image_perso_bas_gauche_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 3 * 2 + (*hauteur) / 50) - (*largeur) / 75), BAS_GAUCHE);
                        
                        (*positionActive) = NIVEAU1;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 2 */
                    else if((*positionActive == NIVEAU2) && 
                            (event->key.keysym.sym == (*touche_interagir))) {

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police,
                                                (*positionActive), couleurNoire,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));

                        SDL_Delay(1000);

                        printf("Vous entrez dans le niveau 2 !\n");

                        (*direction) = BAS;
                    }

                    /* Aller du niveau 3 au niveau 4 */
                    else if((*positionActive == NIVEAU3) && 
                            ((event->key.keysym.sym == (*touche_aller_a_droite)) || (event->key.keysym.sym == (*touche_sauter_monter)))) {

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 4 + (*hauteur) / 13) + (*hauteur) / 75), HAUT_DROITE);

                        (*positionActive) = NIVEAU4;
                        (*direction) = BAS;
                    }

                    /* Aller du niveau 3 au niveau 2 */
                    else if((*positionActive == NIVEAU3) && 
                            (event->key.keysym.sym == (*touche_descendre))) {

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_1, texture_image_perso_bas_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 + (*hauteur) / 50) - (*hauteur) / 75), BAS);

                        (*positionActive) = NIVEAU2;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 3 */
                    else if((*positionActive == NIVEAU3) && 
                            (event->key.keysym.sym == (*touche_interagir))) {

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police,
                                                (*positionActive), couleurNoire,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));

                        SDL_Delay(1000);

                        printf("Vous entrez dans le niveau 3 !\n");

                        (*direction) = BAS;
                    }

                    /* Aller du niveau 4 au niveau 3 */
                    else if((*positionActive == NIVEAU4) && 
                       ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_gauche_1, texture_image_perso_bas_gauche_2,
                                                     surface, texture_texte, police,
                                                     positionActive, couleurNoire,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 - (*hauteur) / 14) - (*largeur) / 75), BAS_GAUCHE);

                        (*positionActive) = NIVEAU3;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 4 */
                    else if((*positionActive == NIVEAU4) && 
                            (event->key.keysym.sym == (*touche_interagir))) {

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police,
                                                (*positionActive), couleurNoire,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));

                        SDL_Delay(1000);

                        (*page_active) = NIVEAU_4;
                    }

                    /* Pivoter vers le haut si on ne peut pas monter */
                    else if((*positionActive == NIVEAU4) && 
                            (event->key.keysym.sym == (*touche_sauter_monter)))

                        (*direction) = HAUT;

                    /* Pivoter vers le bas si on ne peut pas descendre */
                    else if((*positionActive == NIVEAU1) && 
                            (event->key.keysym.sym == (*touche_descendre)))

                        (*direction) = BAS;

                    /* Pivoter vers la droite si on ne peut pas aller vers la droite */
                    else if(((*positionActive == NIVEAU2) && 
                            (event->key.keysym.sym == (*touche_aller_a_droite))) ||
                            ((*positionActive == NIVEAU4) && 
                            (event->key.keysym.sym == (*touche_aller_a_droite))))

                        (*direction) = DROITE;

                    /* Pivoter vers la gauche si on ne peut pas aller vers la gauche */
                    else if(((*positionActive == NIVEAU1) && 
                            (event->key.keysym.sym == (*touche_aller_a_gauche))) ||
                            ((*positionActive == NIVEAU3) && 
                            (event->key.keysym.sym == (*touche_aller_a_gauche))))

                        (*direction) = GAUCHE;

                    break;

                /* Options plein écran et options */
                case SDL_MOUSEBUTTONDOWN:
                    
                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                    if(clic_case((*event), (*rectangle_options)))
                        (*page_active) = OPTIONS;

                    break;

                /* Quitter le programme en demandant s'il faut sauvarger la partie */
                case SDL_QUIT:

                    SDL_SetWindowResizable((*window), SDL_FALSE);

                    demande_sauvegarde(renderer, rectangle_demande_sauvegarde,
                                       surface, texture_texte, police, couleurNoire,
                                       itemsDemandeSauvegarde, tailleDemandeSauvegarde, (*largeur), (*hauteur));

                    while (!clic_effectue) {

                        while (SDL_PollEvent(&event_temporaire)) {

                            if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                if(clic_case(event_temporaire, itemsDemandeSauvegarde[1].rectangle)) {

                                    sauvegarder_partie(touche_aller_a_droite, touche_aller_a_gauche, touche_sauter_monter,
                                                       touche_descendre, touche_interagir, barre_de_son, pseudo,
                                                       (*modeActif), (*personnageActif), (*positionActive));

                                    (*programme_lance) = SDL_FALSE;
                                    clic_effectue = SDL_TRUE; 
                                }

                                else if(clic_case(event_temporaire, itemsDemandeSauvegarde[2].rectangle)) {
                                    (*programme_lance) = SDL_FALSE;
                                    clic_effectue = SDL_TRUE; 
                                }

                                else if(!clic_case(event_temporaire, (*rectangle_demande_sauvegarde)))
                                    clic_effectue = SDL_TRUE;    
                            }
                        }
                    }

                    SDL_SetWindowResizable((*window), SDL_TRUE);

                    break;

                default:
                    break;
            }
            /* Mise à jour du rendu */
            switch((*direction)) {
                case HAUT: 
                    mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                            rectangle_plein_ecran, texture_image_plein_ecran,
                                            rectangle_options, texture_image_options,
                                            rectangle_perso, texture_image_perso_haut,
                                            surface, texture_texte, police,
                                            (*positionActive), couleurNoire,
                                            itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                                    
                    break;

                case BAS:
                    mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                            rectangle_plein_ecran, texture_image_plein_ecran,
                                            rectangle_options, texture_image_options,
                                            rectangle_perso, texture_image_perso,
                                            surface, texture_texte, police,
                                            (*positionActive), couleurNoire,
                                            itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));

                    break;

                case DROITE:
                    mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                            rectangle_plein_ecran, texture_image_plein_ecran,
                                            rectangle_options, texture_image_options,
                                            rectangle_perso, texture_image_perso_droite,
                                            surface, texture_texte, police,
                                            (*positionActive), couleurNoire,
                                            itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
                                            
                    break;
            
                default:
                    mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                            rectangle_plein_ecran, texture_image_plein_ecran,
                                            rectangle_options, texture_image_options,
                                            rectangle_perso, texture_image_perso_gauche,
                                            surface, texture_texte, police,
                                            (*positionActive), couleurNoire,
                                            itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur));
            }
    }
}