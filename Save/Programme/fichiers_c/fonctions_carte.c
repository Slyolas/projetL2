/**
 * \file fonctions_carte.c
 * \brief Fichier contenant toutes les fonctions gérant la carte principal
*/

#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_carte.h>

/**
 * \fn void initialisation_objets_carte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_carte, SDL_Texture **texture_image_perso_1_bas_1, SDL_Texture **texture_image_perso_1_bas_2, SDL_Texture **texture_image_perso_1_haut_1, SDL_Texture **texture_image_perso_1_haut_2, SDL_Texture **texture_image_perso_1_bas_gauche_1, SDL_Texture **texture_image_perso_1_bas_gauche_2, SDL_Texture **texture_image_perso_1_haut, SDL_Texture **texture_image_perso_1_droite, SDL_Texture **texture_image_perso_1_gauche, SDL_Texture **texture_image_perso_1_pose, SDL_Texture **texture_image_perso_2_bas_1, SDL_Texture **texture_image_perso_2_bas_2, SDL_Texture **texture_image_perso_2_haut_1, SDL_Texture **texture_image_perso_2_haut_2, SDL_Texture **texture_image_perso_2_bas_gauche_1, SDL_Texture **texture_image_perso_2_bas_gauche_2, SDL_Texture **texture_image_perso_2_haut, SDL_Texture **texture_image_perso_2_droite, SDL_Texture **texture_image_perso_2_gauche, SDL_Texture **texture_image_perso_2_pose, itemMenu *itemsNiveaux, SDL_Texture **texture_image_retour_menu)
 * \brief Fonction qui permet d'initialiser les différents objets de la carte.
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Surface SDL.
 * \param texture_image_carte Texture de l'image de la carte.
 * \param texture_image_perso_1_bas_1 Texture de l'image du personnage 1 en bas 1.
 * \param texture_image_perso_1_bas_2 Texture de l'image du personnage 1 en bas 2.
 * \param texture_image_perso_1_haut_1 Texture de l'image du personnage 1 en haut 1.
 * \param texture_image_perso_1_haut_2 Texture de l'image du personnage 1 en haut 2.
 * \param texture_image_perso_1_bas_gauche_1 Texture de l'image du personnage 1 en bas gauche 1.
 * \param texture_image_perso_1_bas_gauche_2 Texture de l'image du personnage 1 en bas gauche 2.
 * \param texture_image_perso_1_haut Texture de l'image du personnage 1 en haut.
 * \param texture_image_perso_1_droite Texture de l'image du personnage 1 à droite.
 * \param texture_image_perso_1_gauche Texture de l'image du personnage 1 à gauche.
 * \param texture_image_perso_1_pose Texture de l'image du personnage 1 en pose.
 * \param texture_image_perso_2_bas_1 Texture de l'image du personnage 2 en bas 1.
 * \param texture_image_perso_2_bas_2 Texture de l'image du personnage 2 en bas 2.
 * \param texture_image_perso_2_haut_1 Texture de l'image du personnage 2 en haut 1.
 * \param texture_image_perso_2_haut_2 Texture de l'image du personnage 2 en haut 2.
 * \param texture_image_perso_2_bas_gauche_1 Texture de l'image du personnage 2 en bas gauche 1.
 * \param texture_image_perso_2_bas_gauche_2 Texture de l'image du personnage 2 en bas gauche 2.
 * \param texture_image_perso_2_haut Texture de l'image du personnage 2 en haut.
 * \param texture_image_perso_2_droite Texture de l'image du personnage 2 à droite.
 * \param texture_image_perso_2_gauche Texture de l'image du personnage 2 à gauche.
 * \param texture_image_perso_2_pose Texture de l'image du personnage 2 en pose.
 * \param itemsNiveaux Tableau d'items pour les niveaux.
 * \param texture_image_retour_menu Texture de l'image du bouton retour au menu.
 * \see chargement_image
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
                                 itemMenu *itemsNiveaux, SDL_Texture **texture_image_retour_menu,
                                 itemMenu *itemsSucces, SDL_Texture **textures_images_succes) {

    /* Initialisation de l'image de fond de la carte */
    chargement_image(renderer, surface, texture_image_carte, "./images/carte.jpg");

    /* Initialisation des différentes images des personnages */
    
    chargement_image(renderer, surface, texture_image_perso_1_bas_1, "./images/personnages/personnage_masculin_bas_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_2, "./images/personnages/personnage_masculin_bas_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut_1, "./images/personnages/personnage_masculin_haut_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut_2, "./images/personnages/personnage_masculin_haut_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_gauche_1, "./images/personnages/personnage_masculin_bas_gauche_1.png");
    chargement_image(renderer, surface, texture_image_perso_1_bas_gauche_2, "./images/personnages/personnage_masculin_bas_gauche_2.png");
    chargement_image(renderer, surface, texture_image_perso_1_haut, "./images/personnages/personnage_masculin_haut.png");
    chargement_image(renderer, surface, texture_image_perso_1_droite, "./images/personnages/personnage_masculin_droite.png");
    chargement_image(renderer, surface, texture_image_perso_1_gauche, "./images/personnages/personnage_masculin_gauche.png");
    chargement_image(renderer, surface, texture_image_perso_1_pose, "./images/personnages/personnage_masculin_pose.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_1, "./images/personnages/personnage_feminin_bas_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_2, "./images/personnages/personnage_feminin_bas_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut_1, "./images/personnages/personnage_feminin_haut_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut_2, "./images/personnages/personnage_feminin_haut_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_gauche_1, "./images/personnages/personnage_feminin_bas_gauche_1.png");
    chargement_image(renderer, surface, texture_image_perso_2_bas_gauche_2, "./images/personnages/personnage_feminin_bas_gauche_2.png");
    chargement_image(renderer, surface, texture_image_perso_2_haut, "./images/personnages/personnage_feminin_haut.png");
    chargement_image(renderer, surface, texture_image_perso_2_droite, "./images/personnages/personnage_feminin_droite.png");
    chargement_image(renderer, surface, texture_image_perso_2_gauche, "./images/personnages/personnage_feminin_gauche.png");
    chargement_image(renderer, surface, texture_image_perso_2_pose, "./images/personnages/personnage_feminin_pose.png");

    /* Initialisation de l'image de retour au menu principal */
    chargement_image(renderer, surface, texture_image_retour_menu, "./images/menu.png");

    /* Initialisation des images des succès */
    chargement_image(renderer, surface, &(textures_images_succes[0]), "./images/succes/succes_non_accorde.png");
    chargement_image(renderer, surface, &(textures_images_succes[1]), "./images/succes/succes_1.png");
    chargement_image(renderer, surface, &(textures_images_succes[2]), "./images/succes/succes_2.png");
    chargement_image(renderer, surface, &(textures_images_succes[3]), "./images/succes/succes_3.png");
    chargement_image(renderer, surface, &(textures_images_succes[4]), "./images/succes/succes_4.png");
    chargement_image(renderer, surface, &(textures_images_succes[5]), "./images/succes/succes_5.png");
    chargement_image(renderer, surface, &(textures_images_succes[6]), "./images/succes/succes_6.png");
    chargement_image(renderer, surface, &(textures_images_succes[7]), "./images/succes/succes_7.png");
    chargement_image(renderer, surface, &(textures_images_succes[8]), "./images/succes/succes_8.png");
    chargement_image(renderer, surface, &(textures_images_succes[9]), "./images/succes/succes_9.png");
    chargement_image(renderer, surface, &(textures_images_succes[10]), "./images/succes/succes_10.png");

	/* Initialisation du texte dans les items de la carte */
    sprintf(itemsNiveaux[0].texte, " Le Commencement ");
    sprintf(itemsNiveaux[1].texte, " Bienvenue dans Linux ");
    sprintf(itemsNiveaux[2].texte, " Windows XP ");
    sprintf(itemsNiveaux[3].texte, " La Tour Infernale ");

    /* Initialisation du texte dans les items des succès */
    sprintf(itemsSucces[0].texte, " Succes ");
    sprintf(itemsSucces[1].texte, " C'est bien ! : Finir le jeu                                                             ");
    sprintf(itemsSucces[2].texte, " Collectionneur : Avoir tous les collectibles du jeu                                     ");
    sprintf(itemsSucces[3].texte, " T'as un train ? : Finir le jeu en moins de 10 minutes                                   ");
    sprintf(itemsSucces[4].texte, " La vie est dure : Finir le jeu en mode difficile                                        ");
    sprintf(itemsSucces[5].texte, " Pas de vermines ici ! : Tuer tous les monstres du jeu                                   ");
    sprintf(itemsSucces[6].texte, " Tu jouais ta vie ? : Finir le jeu sans mourir                                           ");
    sprintf(itemsSucces[7].texte, " Maitre du jeu : Finir le jeu en mode difficile et sans mourir                           ");
    sprintf(itemsSucces[8].texte, " Tricheur va ! : Activer le code de triche                                               ");
    sprintf(itemsSucces[9].texte, " Tu transpires ? : Finir le jeu en mode difficile, en moins de 10 minutes et sans mourir ");
    sprintf(itemsSucces[10].texte, " Dieu du jeu : Obtenir tous les succes (sans compter \"Tricheur va !\")                 ");
    sprintf(itemsSucces[11].texte, " Fermer ");
}

/** \fn void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, position_t positionActive, SDL_Color couleurNoire, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu, itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur, niveaux *avancee_niveaux)
 * \brief Fonction qui met à jour le rendu de la carte après redimension de la fenêtre
 * \param renderer Pointeur vers le renderer SDL.
 * \param texture_image_carte Texture de l'image de la carte.
 * \param rectangle_plein_ecran Rectangle plein écran SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param rectangle_options Rectangle des options SDL.
 * \param texture_image_options Texture de l'image des options.
 * \param rectangle_perso Rectangle du personnage SDL.
 * \param texture_image_perso Texture de l'image du personnage.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param positionActive Position active.
 * \param couleurNoire Couleur noire SDL.
 * \param rectangle_retour_menu Rectangle du bouton retour au menu SDL.
 * \param texture_image_retour_menu Texture de l'image du bouton retour au menu.
 * \param itemsNiveaux Tableau d'items pour les niveaux.
 * \param tailleNiveaux Taille du tableau d'items pour les niveaux.
 * \param largeur Largeur.
 * \param hauteur Hauteur.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \see erreur
 * \see affichage_texte
 */
void mise_a_jour_rendu_carte(SDL_Renderer **renderer, SDL_Texture **texture_image_carte,
                             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                             SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                             SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso,
                             SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Texture **texture_image_fin_dernier_niveau, SDL_Rect *rectangle_succes,
                             position_t positionActive, SDL_Color couleurNoire, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu,
                             itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur, niveaux *avancee_niveaux) {
    
    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de fond de la carte */
    if(SDL_RenderCopy((*renderer), (*texture_image_carte), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de retour au menu principal */

    rectangle_retour_menu->x = largeur / 53;
    rectangle_retour_menu->y = hauteur / 30;
    rectangle_retour_menu->w = largeur / 21;
    rectangle_retour_menu->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_retour_menu), NULL, rectangle_retour_menu) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */

    rectangle_plein_ecran->x = largeur - largeur / 21- largeur / 53;
    rectangle_plein_ecran->y = hauteur / 30;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image des options */

    rectangle_options->x = largeur - largeur / 21 - largeur / 53;
    rectangle_options->y = hauteur - hauteur / 12 - hauteur / 30;
    rectangle_options->w = largeur / 21;
    rectangle_options->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_options), NULL, rectangle_options) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image des succès */

    if(avancee_niveaux[3].niveau_fini) {

        rectangle_succes->x = largeur / 53;
        rectangle_succes->y = hauteur - hauteur / 12 - hauteur / 30;
        rectangle_succes->w = largeur / 21;
        rectangle_succes->h = hauteur / 12;

        if(SDL_RenderCopy((*renderer), (*texture_image_fin_dernier_niveau), NULL, rectangle_succes) != 0)
            erreur("Copie de la texture");
    }

    else {
        rectangle_succes->x = 0;
        rectangle_succes->y = 0;
        rectangle_succes->w = 0;
        rectangle_succes->h = 0;
    }

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 150);

    /* Dessine les éléments de la carte et dessine le personnage sur la carte */

    for (i = 0; i < tailleNiveaux; i++) {

        itemsNiveaux[i].rectangle.w = largeur / 7;
        itemsNiveaux[i].rectangle.h = hauteur / 17;
    }

    if(positionActive == NIVEAU1) {

        rectangle_perso->x = largeur / 4 + largeur / 75;
        rectangle_perso->y = hauteur / 2 + hauteur / 20 + hauteur / 17;
        rectangle_perso->w = largeur / 10;
        rectangle_perso->h = hauteur / 17;

        SDL_RenderFillRect((*renderer), rectangle_perso);

        rectangle_perso->w = largeur / 30;

        /* Compte le nombre de collectible recupéré */
        for(i = 0; i < 3; i++)
            if(avancee_niveaux[0].numero_collectible[i]) {

                rectangle_perso->x = largeur / 4 + largeur / 75 + i * (rectangle_perso->w);
                if(SDL_RenderCopy((*renderer), avancee_niveaux[0].texture_image_collectible, NULL, rectangle_perso) != 0)
                    erreur("Copie de la texture");
            }

        itemsNiveaux[0].rectangle.x = largeur / 4 + largeur / 75;
        itemsNiveaux[0].rectangle.y = hauteur / 2 + hauteur / 20;

        rectangle_perso->x = largeur / 3 - largeur / 70;
        rectangle_perso->y = hauteur / 3 * 2 + hauteur / 50;
    }

    else if(positionActive == NIVEAU2) {

        rectangle_perso->x = largeur / 2 - largeur / 18;
        rectangle_perso->y = hauteur / 3 * 2 - hauteur / 30 + hauteur / 17;
        rectangle_perso->w = largeur / 10;
        rectangle_perso->h = hauteur / 17;

        SDL_RenderFillRect((*renderer), rectangle_perso);

        rectangle_perso->w = largeur / 30;

        /* Compte le nombre de collectible recupéré */
        for(i = 0; i < 3; i++) 
            if(avancee_niveaux[1].numero_collectible[i]) {

                rectangle_perso->x = largeur / 2 - largeur / 18 + i * (rectangle_perso->w);
                if(SDL_RenderCopy((*renderer), avancee_niveaux[1].texture_image_collectible, NULL, rectangle_perso) != 0)
                    erreur("Copie de la texture");
            }

        itemsNiveaux[1].rectangle.x = largeur / 2 - largeur / 18;
        itemsNiveaux[1].rectangle.y = hauteur / 3 * 2 - hauteur / 30;

        rectangle_perso->x = largeur / 2 - largeur / 500;
        rectangle_perso->y = hauteur / 2 + hauteur / 50;
    }

    else if(positionActive == NIVEAU3) {

        rectangle_perso->x = largeur / 2 - largeur / 20;
        rectangle_perso->y = hauteur / 3 - hauteur / 27 + hauteur / 17;
        rectangle_perso->w = largeur / 10;
        rectangle_perso->h = hauteur / 17;

        SDL_RenderFillRect((*renderer), rectangle_perso);

        rectangle_perso->w = largeur / 30;

        /* Compte le nombre de collectible recupéré */
        for(i = 0; i < 3; i++)
            if(avancee_niveaux[2].numero_collectible[i]) {

                rectangle_perso->x = largeur / 2 - largeur / 20 + i * (rectangle_perso->w);

                if(SDL_RenderCopy((*renderer), avancee_niveaux[2].texture_image_collectible, NULL, rectangle_perso) != 0)
                    erreur("Copie de la texture");
            }
        
        itemsNiveaux[2].rectangle.x = largeur / 2 - largeur / 20;
        itemsNiveaux[2].rectangle.y = hauteur / 3 - hauteur / 27;

        rectangle_perso->x = largeur / 2 + largeur / 400;
        rectangle_perso->y = hauteur / 2 - hauteur / 14;
    }

    else if(positionActive == NIVEAU4){

        rectangle_perso->x = largeur / 3 * 2 - largeur / 9;
        rectangle_perso->y = hauteur / 4 - hauteur / 18 + hauteur / 17;
        rectangle_perso->w = largeur / 10;
        rectangle_perso->h = hauteur / 17;

        SDL_RenderFillRect((*renderer), rectangle_perso);

        rectangle_perso->w = largeur / 30;

        /* Compte le nombre de collectible recupéré */
        for(i = 0; i < 3; i++) 
            if(avancee_niveaux[3].numero_collectible[i]) {

                rectangle_perso->x = largeur / 3 * 2 - largeur / 9 + i * (rectangle_perso->w);
                if(SDL_RenderCopy((*renderer), avancee_niveaux[3].texture_image_collectible, NULL, rectangle_perso) != 0)
                    erreur("Copie de la texture");
            }
        

        itemsNiveaux[3].rectangle.x = largeur / 3 * 2 - largeur / 9;
        itemsNiveaux[3].rectangle.y = hauteur / 4 - hauteur / 18;

        rectangle_perso->x = largeur / 3 * 2 - largeur / 19;
        rectangle_perso->y = hauteur / 4 + hauteur / 13;
    }

    /* Le personnage est sur un niveau */
    if(positionActive != NIVEAU0)
        affichage_texte(renderer, surface, texture_texte, &(itemsNiveaux[positionActive - 1]), 
                        police, couleurNoire);

    rectangle_perso->w = largeur / 30;
    rectangle_perso->h = hauteur / 13;

    if(SDL_RenderCopy((*renderer), (*texture_image_perso), NULL, rectangle_perso) != 0)
        erreur("Copie de la texture");

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/**
 * \fn void deplacement_personnage_carte(SDL_Renderer **renderer, SDL_Window **window, SDL_Texture **texture_image_carte, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso_1, SDL_Texture **texture_image_perso_2,  SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, position_t *positionActive, SDL_Color couleurNoire, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu, itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur, int valeur_maximale, direction_t direction, niveaux *avancee_niveaux)
 * \brief Fonction qui permet de deplacer le personnage sur la carte
 * \param renderer Pointeur vers le renderer SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param texture_image_carte Texture de l'image de la carte.
 * \param rectangle_plein_ecran Rectangle plein écran SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param rectangle_options Rectangle des options SDL.
 * \param texture_image_options Texture de l'image des options.
 * \param rectangle_perso Rectangle du personnage SDL.
 * \param texture_image_perso_1 Texture de l'image du personnage 1.
 * \param texture_image_perso_2 Texture de l'image du personnage 2.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param positionActive Position active sur la carte.
 * \param couleurNoire Couleur noire SDL.
 * \param rectangle_retour_menu Rectangle du bouton retour au menu SDL.
 * \param texture_image_retour_menu Texture de l'image du bouton retour au menu.
 * \param itemsNiveaux Tableau d'items pour les niveaux.
 * \param tailleNiveaux Taille du tableau d'items pour les niveaux.
 * \param largeur Largeur de la carte.
 * \param hauteur Hauteur de la carte.
 * \param valeur_maximale Valeur maximale pour la direction.
 * \param direction Direction du déplacement.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \see mise_a_jour_rendu_carte
 */
void deplacement_personnage_carte(SDL_Renderer **renderer, SDL_Window **window, SDL_Texture **texture_image_carte,
                                  SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                  SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                  SDL_Rect *rectangle_perso, SDL_Texture **texture_image_perso_1, SDL_Texture **texture_image_perso_2, 
                                  SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Texture **texture_image_fin_dernier_niveau, SDL_Rect *rectangle_succes,
                                  position_t *positionActive, SDL_Color couleurNoire, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu,
                                  itemMenu *itemsNiveaux, int tailleNiveaux, int largeur, int hauteur,
                                  int valeur_maximale, direction_t direction, niveaux *avancee_niveaux) {

    int i;

    SDL_SetWindowResizable((*window), SDL_FALSE);

    (*positionActive) = NIVEAU0;

    /* Cas pour aller vers le haut ou vers le haut à gauche */
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
                                        surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                        (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur, avancee_niveaux);
                                    
            else
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_2,
                                        surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                        (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur, avancee_niveaux);

            SDL_Delay(75);
        }
    }

    /* Cas pour aller vers le bas ou vers le bas à gauche */
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
                                        surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                        (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur, avancee_niveaux);
                                    
            else
                mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                        rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_options, texture_image_options,
                                        rectangle_perso, texture_image_perso_2,
                                        surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                        (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                        itemsNiveaux, tailleNiveaux, largeur, hauteur, avancee_niveaux);

            SDL_Delay(75);
        }
    }

    SDL_SetWindowResizable((*window), SDL_TRUE);
}


/**
 * \fn void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu, SDL_Texture **texture_image_perso_bas_1, SDL_Texture **texture_image_perso_bas_2, SDL_Texture **texture_image_perso_haut_1, SDL_Texture **texture_image_perso_haut_2, SDL_Texture **texture_image_perso_bas_gauche_1, SDL_Texture **texture_image_perso_bas_gauche_2, SDL_Texture **texture_image_perso_haut, SDL_Texture **texture_image_perso_droite, SDL_Texture **texture_image_perso_gauche, SDL_Texture **texture_image_perso_pose, SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso, niveaux *avancee_niveaux, int niveau_fini[4], int collectibles[12], position_t *position_intermediaire, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, direction_t *direction, int *touche_pressee, SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde, position_t *positionActive, barreDeSon *barre_de_son, itemMenu *pseudo, modes_t *modeActif, personnage_t *personnageActif, SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active)
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent sur la carte

 * \param event Pointeur vers l'événement SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param programme_lance Booléen indiquant si le programme est en cours d'exécution.
 * \param texture_image_carte Texture de l'image de la carte.
 * \param rectangle_plein_ecran Rectangle plein écran SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param plein_ecran Booléen pour le plein écran.
 * \param rectangle_options Rectangle des options SDL.
 * \param texture_image_options Texture de l'image des options.
 * \param rectangle_retour_menu Rectangle du bouton retour au menu SDL.
 * \param texture_image_retour_menu Texture de l'image du bouton retour au menu.
 * \param texture_image_perso_bas_1 Texture de l'image du personnage en bas 1.
 * \param texture_image_perso_bas_2 Texture de l'image du personnage en bas 2.
 * \param texture_image_perso_haut_1 Texture de l'image du personnage en haut 1.
 * \param texture_image_perso_haut_2 Texture de l'image du personnage en haut 2.
 * \param texture_image_perso_bas_gauche_1 Texture de l'image du personnage en bas gauche 1.
 * \param texture_image_perso_bas_gauche_2 Texture de l'image du personnage en bas gauche 2.
 * \param texture_image_perso_haut Texture de l'image du personnage en haut.
 * \param texture_image_perso_droite Texture de l'image du personnage à droite.
 * \param texture_image_perso_gauche Texture de l'image du personnage à gauche.
 * \param texture_image_perso_pose Texture de l'image du personnage en pose.
 * \param texture_image_perso Texture de l'image du personnage.
 * \param rectangle_perso Rectangle du personnage SDL.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \param niveau_fini Tableau indiquant si chaque niveau est terminé.
 * \param collectibles Tableau des collectibles.
 * \param position_intermediaire Position intermédiaire du personnage.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param direction Direction du personnage.
 * \param touche_pressee Indicateur de touche pressée.
 * \param rectangle_demande_sauvegarde Rectangle de la demande de sauvegarde SDL.
 * \param itemsDemandeSauvegarde Tableau d'items pour la demande de sauvegarde.
 * \param tailleDemandeSauvegarde Taille du tableau d'items pour la demande de sauvegarde.
 * \param positionActive Position active.
 * \param barre_de_son Barre de son SDL.
 * \param pseudo Pseudo du joueur SDL.
 * \param modeActif Mode actif du jeu.
 * \param personnageActif Personnage actif.
 * \param couleurNoire Couleur noire SDL.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_sauter_monter Touche pour sauter/monter.
 * \param touche_descendre Touche pour descendre.
 * \param touche_interagir Touche pour interagir.
 * \param itemsNiveaux Tableau d'items pour les niveaux.
 * \param tailleNiveaux Taille du tableau d'items pour les niveaux.
 * \param largeur Largeur de la carte.
 * \param hauteur Hauteur de la carte.
 * \param page_active Page active.
 * \see mise_a_jour_rendu_carte
 * \see redimensionnement_fenetre
 * \see deplacement_personnage_carte
 * \see erreur
 * \see demande_sauvegarde
 * \see sauvegarder_partie
 * \see clic_case
 */
void carte(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_carte,
           SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
           SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, SDL_Rect *rectangle_retour_menu, SDL_Texture **texture_image_retour_menu,
           SDL_Texture **texture_image_perso_bas_1, SDL_Texture **texture_image_perso_bas_2,
           SDL_Texture **texture_image_perso_haut_1, SDL_Texture **texture_image_perso_haut_2,
           SDL_Texture **texture_image_perso_bas_gauche_1, SDL_Texture **texture_image_perso_bas_gauche_2,
           SDL_Texture **texture_image_perso_haut, SDL_Texture **texture_image_perso_droite,
           SDL_Texture **texture_image_perso_gauche, SDL_Texture **texture_image_perso_pose,
           SDL_Texture **texture_image_perso, SDL_Rect *rectangle_perso, niveaux *avancee_niveaux,
           int niveau_fini[4], int collectibles[12], position_t *position_intermediaire, SDL_Texture **texture_image_fin_dernier_niveau, SDL_Rect *rectangle_succes,
           SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, direction_t *direction, int *touche_pressee,
           SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde,
           position_t *positionActive, barreDeSon *barre_de_son, itemMenu *pseudo, modes_t *modeActif, personnage_t *personnageActif,
           SDL_Color couleurNoire, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
           SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir,
           itemMenu *itemsNiveaux, int tailleNiveaux, int *largeur, int *hauteur, page_t *page_active,
           itemMenu *itemsSucces, SDL_Texture **textures_images_succes,
           time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    Mix_Chunk *effet_sonore = NULL;

    int i, j;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 3; j++)
    
            if(avancee_niveaux[i].numero_collectible[j]) {

                avancee_succes[1] = 1;
            }

            else {

                avancee_succes[1] = 0;
                j = 3;
                i = 4;
            } 
    
    if((avancee_succes[0]) && (avancee_succes[1]) && 
       (avancee_succes[2]) && (avancee_succes[3]) && 
       (avancee_succes[4]) && (avancee_succes[5]) && 
       (avancee_succes[6]) && (avancee_succes[8]))
       avancee_succes[9] = 1;

    /* Mise à jour du rendu */
    switch((*direction)) {

        case HAUT: 
            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                    rectangle_options, texture_image_options,
                                    rectangle_perso, texture_image_perso_haut,
                                    surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                    (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);
                            
            break;

        case BAS:
            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                    rectangle_options, texture_image_options,
                                    rectangle_perso, texture_image_perso,
                                    surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                    (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);

            break;

        case DROITE:
            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                    rectangle_options, texture_image_options,
                                    rectangle_perso, texture_image_perso_droite,
                                    surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                    (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);
                                    
            break;
    
        default:
            mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                    rectangle_plein_ecran, texture_image_plein_ecran,
                                    rectangle_options, texture_image_options,
                                    rectangle_perso, texture_image_perso_gauche,
                                    surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                    (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                    itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);
    }

    while(SDL_PollEvent(event)) {

            switch(event->type) {

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                /* Lecture de la touche pressée et de la position du personnage pour savoir où aller */
                case SDL_KEYDOWN :

                    /* Aller du niveau 1 au niveau 2 */
                    if((*positionActive == NIVEAU1) && (!(*touche_pressee)) && (avancee_niveaux[0].niveau_fini) &&
                       ((event->key.keysym.sym == (*touche_aller_a_droite)) || (event->key.keysym.sym == (*touche_sauter_monter)))) {

                        (*touche_pressee) = 1;

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 + (*hauteur) / 50) + (*hauteur) / 75), HAUT_DROITE, avancee_niveaux);

                        (*positionActive) = NIVEAU2;
                        (*direction) = BAS;

                    }

                    /* Entrer dans le niveau 1 */
                    else if((*positionActive == NIVEAU1) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_interagir))) {

                        /* Effet sonore quand on rentre dans un niveau */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/rentree_niveaux.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;
                        
                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);

                        SDL_Delay(1000);
                        
                        (*page_active) = NIVEAU_1;
                    }

                    /* Aller du niveau 2 au niveau 3 */
                    else if((*positionActive == NIVEAU2) && (!(*touche_pressee)) && (avancee_niveaux[1].niveau_fini) &&
                            (event->key.keysym.sym == (*touche_sauter_monter))) {

                        (*touche_pressee) = 1;
                        
                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 - (*hauteur) / 14) + (*hauteur) / 75), HAUT, avancee_niveaux);

                        (*positionActive) = NIVEAU3;
                        (*direction) = BAS;
                    }

                    /* Aller du niveau 2 au niveau 1 */
                    else if((*positionActive == NIVEAU2) && (!(*touche_pressee)) &&
                            ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {

                        (*touche_pressee) = 1;

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_gauche_1, texture_image_perso_bas_gauche_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 3 * 2 + (*hauteur) / 50) - (*largeur) / 75), BAS_GAUCHE, avancee_niveaux);
                        
                        (*positionActive) = NIVEAU1;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 2 */
                    else if((*positionActive == NIVEAU2) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_interagir))) {

                        /* Effet sonore quand on rentre dans un niveau */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/rentree_niveaux.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);
                                                
                        SDL_Delay(1000);

                        (*page_active) = NIVEAU_2;
                    }

                    /* Aller du niveau 3 au niveau 4 */
                    else if((*positionActive == NIVEAU3) && (!(*touche_pressee)) && (avancee_niveaux[2].niveau_fini) &&
                            ((event->key.keysym.sym == (*touche_aller_a_droite)) || (event->key.keysym.sym == (*touche_sauter_monter)))) {

                        (*touche_pressee) = 1;

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_haut_1, texture_image_perso_haut_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 4 + (*hauteur) / 13) + (*hauteur) / 75), HAUT_DROITE, avancee_niveaux);

                        (*positionActive) = NIVEAU4;
                        (*direction) = BAS;
                    }

                    /* Aller du niveau 3 au niveau 2 */
                    else if((*positionActive == NIVEAU3) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_descendre))) {

                        (*touche_pressee) = 1;

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_1, texture_image_perso_bas_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 + (*hauteur) / 50) - (*hauteur) / 75), BAS, avancee_niveaux);

                        (*positionActive) = NIVEAU2;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 3 */
                    else if((*positionActive == NIVEAU3) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_interagir))) {

                        /* Effet sonore quand on rentre dans un niveau */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/rentree_niveaux.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);

                        SDL_Delay(1000);

                        (*page_active) = NIVEAU_3;
                    }

                    /* Aller du niveau 4 au niveau 3 */
                    else if((*positionActive == NIVEAU4) && (!(*touche_pressee)) &&
                       ((event->key.keysym.sym == (*touche_aller_a_gauche)) || (event->key.keysym.sym == (*touche_descendre)))) {

                        (*touche_pressee) = 1;

                        deplacement_personnage_carte(renderer, window, texture_image_carte,
                                                     rectangle_plein_ecran, texture_image_plein_ecran,
                                                     rectangle_options, texture_image_options,
                                                     rectangle_perso, texture_image_perso_bas_gauche_1, texture_image_perso_bas_gauche_2,
                                                     surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                     positionActive, couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                     itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur),
                                                     (((*hauteur) / 2 - (*hauteur) / 14) - (*largeur) / 75), BAS_GAUCHE, avancee_niveaux);

                        (*positionActive) = NIVEAU3;
                        (*direction) = BAS;
                    }

                    /* Entrer dans le niveau 4 */
                    else if((*positionActive == NIVEAU4) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_interagir))) {

                        /* Effet sonore quand on rentre dans un niveau */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/rentree_niveau_4.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        mise_a_jour_rendu_carte(renderer, texture_image_carte,
                                                rectangle_plein_ecran, texture_image_plein_ecran,
                                                rectangle_options, texture_image_options,
                                                rectangle_perso, texture_image_perso_pose,
                                                surface, texture_texte, police, texture_image_fin_dernier_niveau, rectangle_succes,
                                                (*positionActive), couleurNoire, rectangle_retour_menu, texture_image_retour_menu,
                                                itemsNiveaux, tailleNiveaux, (*largeur), (*hauteur), avancee_niveaux);

                        SDL_Delay(1000);

                        (*page_active) = NIVEAU_4;
                    }

                    /* Pivoter vers le haut si on ne peut pas monter */
                    else if(((((*positionActive) == NIVEAU1) && (!avancee_niveaux[0].niveau_fini)) ||
                             (((*positionActive) == NIVEAU2) && (!avancee_niveaux[1].niveau_fini)) ||
                             (((*positionActive) == NIVEAU3) && (!avancee_niveaux[2].niveau_fini)) ||
                             ((*positionActive) == NIVEAU4)) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_sauter_monter))) {

                        /* Effet sonore quand on ne peut pas aller dans une direction */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collision_mur.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        (*direction) = HAUT;
                    }

                    /* Pivoter vers le bas si on ne peut pas descendre */
                    else if(((*positionActive) == NIVEAU1) && (!(*touche_pressee)) &&
                            (event->key.keysym.sym == (*touche_descendre))) {

                        /* Effet sonore quand on ne peut pas aller dans une direction */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collision_mur.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        (*direction) = BAS;
                    }

                    /* Pivoter vers la droite si on ne peut pas aller vers la droite */
                    else if(((((*positionActive) == NIVEAU2) || ((*positionActive) == NIVEAU4)) || 
                             (((*positionActive) == NIVEAU1) && (!avancee_niveaux[0].niveau_fini)) ||
                             (((*positionActive) == NIVEAU3) && (!avancee_niveaux[2].niveau_fini))) && 
                            (!(*touche_pressee)) && (event->key.keysym.sym == (*touche_aller_a_droite))) {

                        /* Effet sonore quand on ne peut pas aller dans une direction */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collision_mur.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        (*direction) = DROITE;
                    }

                    /* Pivoter vers la gauche si on ne peut pas aller vers la gauche */
                    else if((((*positionActive) == NIVEAU1) || (((*positionActive) == NIVEAU3))) && 
                            (!(*touche_pressee)) && (event->key.keysym.sym == (*touche_aller_a_gauche))) {

                        /* Effet sonore quand on ne peut pas aller dans une direction */
                        if((effet_sonore = Mix_LoadWAV("./sons/effets_sonores/collision_mur.wav")) == NULL)
                            erreur("Chargement de l'effet sonore");
                            
                        Mix_PlayChannel(1, effet_sonore, 0);

                        (*touche_pressee) = 1;

                        (*direction) = GAUCHE;
                    }

                    break;

                /* Options plein écran, options, retour au menu principal et succès */
                case SDL_MOUSEBUTTONDOWN:
                    
                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                    if(clic_case((*event), (*rectangle_options)))
                        (*page_active) = OPTIONS;

                    if(clic_case((*event), (*rectangle_retour_menu))) {

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
                                                        (*modeActif), (*personnageActif), (*positionActive),
                                                        avancee_niveaux, tailleNiveaux, temps_debut_partie, (*compteur_mort), avancee_succes);

                                        (*page_active) = MENU_PRINCIPAL;
                                        clic_effectue = SDL_TRUE; 
                                    }

                                    else if(clic_case(event_temporaire, itemsDemandeSauvegarde[2].rectangle)) {

                                        for(i = 0; i < 4; i++) {

                                            avancee_niveaux[i].niveau_fini = niveau_fini[i];

                                            for(j = 0; j < 3; j++)
                                                avancee_niveaux[i].numero_collectible[j] = collectibles[i + j];

                                            (*positionActive) = (*position_intermediaire);
                                        }

                                        for(i = 0; i < 10; i++)
                                            avancee_succes[i] = avancee_succes_intermediaires[i];
                                        
                                        (*page_active) = MENU_PRINCIPAL;
                                        clic_effectue = SDL_TRUE; 
                                    }

                                    else if(!clic_case(event_temporaire, (*rectangle_demande_sauvegarde)))
                                        clic_effectue = SDL_TRUE;    
                                }
                            }
                        }

                        SDL_SetWindowResizable((*window), SDL_TRUE);
                    }

                    /* Page des succès */
                    if(clic_case((*event), (*rectangle_succes))) {

                        SDL_SetWindowResizable((*window), SDL_FALSE);

                        while (!clic_effectue) {

                            SDL_Event event_temporaire_bis;
                            SDL_bool clic_effectue_bis = SDL_FALSE;

                            SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 255);

                            /* Efface le rendu */
                            if(SDL_RenderClear((*renderer)) != 0)
                                erreur("Effacement rendu échoué");

                            /* Initialise le rectangle pour les images des succès */

                            rectangle_succes->x = (*largeur) / 50;
                            rectangle_succes->w = (*largeur) / 25;
                            rectangle_succes->h = (*hauteur) / 14;

                            /* Affichage des différentes images */
                            for(i = 0; i < 10; i++) {

                                rectangle_succes->y = (*hauteur) / 14 + i * ((*hauteur) / 70 + (*hauteur) / 14);

                                if(avancee_succes[i]) {

                                    if(SDL_RenderCopy((*renderer), textures_images_succes[i + 1], NULL, rectangle_succes) != 0)
                                        erreur("Copie de la texture");
                                }

                                else {

                                    if(SDL_RenderCopy((*renderer), textures_images_succes[0], NULL, rectangle_succes) != 0)
                                        erreur("Copie de la texture");
                                }
                            }

                            /* Affiche le titre de la page */

                            itemsSucces[0].rectangle.x = (*largeur) / 8 * 3;
                            itemsSucces[0].rectangle.y = (*hauteur) / 11 - (*hauteur) / 12;
                            itemsSucces[0].rectangle.w = (*largeur) / 4;
                            itemsSucces[0].rectangle.h = (*hauteur) / 15;

                            affichage_texte(renderer, surface, texture_texte, &(itemsSucces[0]), 
                                                police, couleurNoire);

                            /* Affichage les différentes phrases pour chaque succès */
                            for(i = 0; i < 10; i++) {

                                itemsSucces[i + 1].rectangle.x = rectangle_succes->x * 2 + rectangle_succes->w;
                                itemsSucces[i + 1].rectangle.y = (*hauteur) / 14 + i * ((*hauteur) / 70 + (*hauteur) / 14);
                                itemsSucces[i + 1].rectangle.w = (*largeur) - itemsSucces[i + 1].rectangle.x - rectangle_succes->x;
                                itemsSucces[i + 1].rectangle.h = (*hauteur) / 14;

                                affichage_texte(renderer, surface, texture_texte, &(itemsSucces[i + 1]), 
                                                police, couleurNoire);
                            }

                            /* Initialise le rectangle pour le bouton de sorti de la page des succès */

                            itemsSucces[11].rectangle.x = (*largeur) / 3 * 2;
                            itemsSucces[11].rectangle.y = (*hauteur) - (*hauteur) / 11;
                            itemsSucces[11].rectangle.w = (*largeur) / 7;
                            itemsSucces[11].rectangle.h = (*hauteur) / 12;

                            SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
                            SDL_RenderDrawRect((*renderer), &(itemsSucces[11].rectangle));

                            SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 0);

                            affichage_texte(renderer, surface, texture_texte, &(itemsSucces[11]), 
                                                police, couleurNoire);

                            /* Affiche le rendu */
                            SDL_RenderPresent((*renderer));

                            while (SDL_PollEvent(&event_temporaire)) 

                                /* Cas où on quitte la page des succès */
                                if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                    if(clic_case(event_temporaire, itemsSucces[11].rectangle)) 
                                        clic_effectue = SDL_TRUE; 
                                }

                                /* Quitter le programme en demandant s'il faut sauvarger la partie */
                                else if(event_temporaire.type == SDL_QUIT) {

                                    demande_sauvegarde(renderer, rectangle_demande_sauvegarde,
                                                        surface, texture_texte, police, couleurNoire,
                                                        itemsDemandeSauvegarde, tailleDemandeSauvegarde, (*largeur), (*hauteur));

                                    while (!clic_effectue_bis) {

                                        while (SDL_PollEvent(&event_temporaire_bis)) {

                                            if(event_temporaire_bis.type == SDL_MOUSEBUTTONDOWN) {

                                                if(clic_case(event_temporaire_bis, itemsDemandeSauvegarde[1].rectangle)) {

                                                    sauvegarder_partie(touche_aller_a_droite, touche_aller_a_gauche, touche_sauter_monter,
                                                                    touche_descendre, touche_interagir, barre_de_son, pseudo,
                                                                    (*modeActif), (*personnageActif), (*positionActive),
                                                                    avancee_niveaux, tailleNiveaux, temps_debut_partie, (*compteur_mort), avancee_succes);

                                                    (*programme_lance) = SDL_FALSE;
                                                    clic_effectue_bis = SDL_TRUE; 
                                                    clic_effectue = SDL_TRUE;
                                                }

                                                else if(clic_case(event_temporaire_bis, itemsDemandeSauvegarde[2].rectangle)) {
                                                    (*programme_lance) = SDL_FALSE;
                                                    clic_effectue_bis = SDL_TRUE; 
                                                    clic_effectue = SDL_TRUE;
                                                }

                                                else if(!clic_case(event_temporaire_bis, (*rectangle_demande_sauvegarde)))
                                                    clic_effectue_bis = SDL_TRUE;    
                                            }
                                        }
                                    }
                                }
                        }

                        SDL_SetWindowResizable((*window), SDL_TRUE);
                    }

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
                                                       (*modeActif), (*personnageActif), (*positionActive),
                                                       avancee_niveaux, tailleNiveaux, temps_debut_partie, (*compteur_mort), avancee_succes);

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
    }

    Mix_FreeChunk((*effet_sonore));
}