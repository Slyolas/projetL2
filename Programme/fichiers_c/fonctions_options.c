/**
 * \file fonctions_options.c
 * \brief Fichier qui réunit les fonctions s'occupant de la fenêtre des options du jeu
*/
#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_options.h>

/** \brief Fonction qui permet d'initialiser les différents objets des options
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_hautParleurActif Texture pour l'icône de haut-parleur actif.
 * \param texture_image_hautParleurDesactive Texture pour l'icône de haut-parleur désactivé.
 * \param titre Pointeur vers l'item du titre du menu.
 * \param itemsMenu Tableau des items du menu.
 * \param itemsTouches Tableau des items pour les touches du clavier.
 * \param itemsBarres Tableau des items pour les barres de volume.
 * \see chargement_image
 */
void initialisation_objets_options(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_hautParleurActif,
                                   SDL_Texture **texture_image_hautParleurDesactive,
                                   itemMenu *titre, itemMenu *itemsMenu, itemMenu *itemsTouches, itemMenu *itemsBarres) {

    /* Initialisation de l'image du haut parleur actif */
    chargement_image(renderer, surface, texture_image_hautParleurActif, "./images/options/haut_parleur_actif.png");

    /* Initialisation de l'image du haut parleur desactif */
    chargement_image(renderer, surface, texture_image_hautParleurDesactive, "./images/options/haut_parleur_desactive.png");
    
    /* Initialisation du titre des options */
    sprintf(titre->texte, " Options ");

    /* Initialisation du texte des onglets */
    sprintf(itemsMenu[0].texte, "           Son           ");
    sprintf(itemsMenu[1].texte, "         Touches         ");

    /* Initialisation du texte dans les items */
    sprintf(itemsTouches[0].texte, " Aller vers la droite : ");
    sprintf(itemsTouches[1].texte, "           %s           ", SDL_GetKeyName(SDLK_RIGHT));
    sprintf(itemsTouches[2].texte, " Aller vers la gauche : ");
    sprintf(itemsTouches[3].texte, "           %s           ", SDL_GetKeyName(SDLK_LEFT));
    sprintf(itemsTouches[4].texte, "   Sauter / monter :     ");
    sprintf(itemsTouches[5].texte, "           %s           ", SDL_GetKeyName(SDLK_UP));
    sprintf(itemsTouches[6].texte, "       Descendre :      ");
    sprintf(itemsTouches[7].texte, "           %s           ", SDL_GetKeyName(SDLK_DOWN));
    sprintf(itemsTouches[8].texte, "       Interagir :      ");
    sprintf(itemsTouches[9].texte, "           %s           ", SDL_GetKeyName(SDLK_SPACE));
    sprintf(itemsBarres[0].texte, "        Musique :        ");
    sprintf(itemsBarres[1].texte, "     Effets sonores :     ");
}


/** 
 * \fn void mise_a_jour_rendu_options(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_hautParleurActif,  SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs, SDL_Rect *rectangles_boutons_sons, option_t ongletActif, itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleurNoire, int selection_touche, itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches,  barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres, int largeur, int hauteur) {
 * \brief Fonction qui met à jour le rendu des options 
 * \param renderer Pointeur vers le renderer SDL.
 * \param rectangle_plein_ecran Rectangle pour le plein écran.
 * \param texture_image_plein_ecran Texture pour l'image du plein écran.
 * \param rectangle_retour_en_arriere Rectangle pour le bouton de retour en arrière.
 * \param texture_image_retour_en_arriere Texture pour l'image du bouton de retour en arrière.
 * \param texture_image_hautParleurActif Texture pour l'icône de haut-parleur actif.
 * \param texture_image_hautParleurDesactive Texture pour l'icône de haut-parleur désactivé.
 * \param sonsActifs Pointeur booléen pour l'état des sons.
 * \param rectangles_boutons_sons Tableau des rectangles pour les boutons de sons.
 * \param ongletActif Onglet actif dans le menu des options.
 * \param titre Pointeur vers l'item du titre du menu.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_texte Texture pour le texte.
 * \param police Pointeur vers la police TTF.
 * \param couleurNoire Couleur noire.
 * \param selection_touche Sélection de la touche du clavier.
 * \param itemsMenu Tableau des items du menu.
 * \param tailleMenu Taille du tableau des items du menu.
 * \param itemsTouches Tableau des items pour les touches du clavier.
 * \param tailleTouches Taille du tableau des items pour les touches du clavier.
 * \param barre_de_son Tableau des barres de son.
 * \param tailleBarres Taille du tableau des barres de son.
 * \param itemsBarres Tableau des items pour les barres de volume.
 * \param largeur Largeur de la fenêtre.
 * \param hauteur Hauteur de la fenêtre.
 * \see erreur
 * \see affichage_texte
 */
void mise_a_jour_rendu_options(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                               SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                               SDL_Texture **texture_image_hautParleurActif, 
                               SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
                               SDL_Rect *rectangles_boutons_sons, option_t ongletActif,
                               itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                               SDL_Color couleurNoire, int selection_touche,
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

    rectangle_plein_ecran->x = largeur - largeur / 21 - largeur / 53;
    rectangle_plein_ecran->y = hauteur / 30;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image du retour en arrière */

    rectangle_retour_en_arriere->x = largeur / 53;
    rectangle_retour_en_arriere->y = hauteur / 30;
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

    affichage_texte(renderer, surface, texture_texte, titre, 
                    police, couleurNoire);

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

        affichage_texte(renderer, surface, texture_texte, &(itemsMenu[i]), 
                        police, couleurNoire);
    }

    if(ongletActif == ONGLET_SON) {

        /* Dessine les items pour les deux barres de sons */
        SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

        for (i = 0; i < tailleBarres; i++) {

            itemsBarres[i].rectangle.x = largeur / 8;
            itemsBarres[i].rectangle.y = hauteur / 2 + hauteur / 50 + i * hauteur / 5 - hauteur / 100;
            itemsBarres[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsBarres[i].rectangle.h = hauteur / 15;

            affichage_texte(renderer, surface, texture_texte, &(itemsBarres[i]), 
                            police, couleurNoire);
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

    else if(ongletActif == ONGLET_TOUCHES) {

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

        /* Dessine les items pour les cinq touches différentes */

        SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

        for (i = 0; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 7;
            itemsTouches[i].rectangle.y = hauteur / 2 - hauteur / 7 + i * hauteur / 15;
            itemsTouches[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsTouches[i].rectangle.h = hauteur / 15;

            affichage_texte(renderer, surface, texture_texte, &(itemsTouches[i]), 
                            police, couleurNoire);
        }

        /* Dessine les rectangles pour les cinq touches différentes */

        for (i = 1; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 2;
            itemsTouches[i].rectangle.y = hauteur / 2 - hauteur / 7 + (i-1) * hauteur / 15;
            itemsTouches[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsTouches[i].rectangle.h = hauteur / 15;

            if(selection_touche == i) {
                SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
                SDL_RenderFillRect((*renderer), &(itemsTouches[i].rectangle));

                itemsTouches[i].rectangle.y = hauteur / 2 - hauteur / 7 + (i-1) * hauteur / 15;
                itemsTouches[i].rectangle.w = largeur / 2 - largeur / 8;
                itemsTouches[i].rectangle.h = hauteur / 16;
            }

            SDL_SetRenderDrawColor((*renderer), 180, 180, 180, 255);

            affichage_texte(renderer, surface, texture_texte, &(itemsTouches[i]), 
                            police, couleurNoire);
        }
    }     

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/** 
 * \fn void mise_a_jour_barre_de_son(SDL_Event *event, barreDeSon *barre_de_son, SDL_bool *sonsActifs)
 * \brief Fonction qui permet de mettre à jour les barres de sons 
 * \param event Pointeur vers l'événement SDL.
 * \param barre_de_son Pointeur vers la barre de son.
 * \param sonsActifs Pointeur booléen pour l'état des sons.
 */
void mise_a_jour_barre_de_son(SDL_Event *event, barreDeSon *barre_de_son, SDL_bool *sonsActifs) {

    barre_de_son->volume_precedent = barre_de_son->volume;
    barre_de_son->volume = (event->motion.x - barre_de_son->barre.x) * 1.0 / barre_de_son->barre.w;
    if(((*sonsActifs) == SDL_FALSE) && (barre_de_son->volume != 0))
        (*sonsActifs) = SDL_TRUE;
    if(barre_de_son->volume == 0)
        (*sonsActifs) = SDL_FALSE;
}

/** 
 * \fn void mise_a_jour_touches(SDL_Event *event, SDL_Keycode *touche, int *selection_touche, itemMenu *itemsTouches)
 * \brief Fonction qui permet de mettre à jour les touches 
 * \param event Pointeur vers l'événement SDL.
 * \param touche Pointeur vers la touche sélectionnée.
 * \param selection_touche Pointeur vers l'indice de la touche sélectionnée.
 * \param itemsTouches Tableau des éléments de menu des touches.
 */
void mise_a_jour_touches(SDL_Event *event, SDL_Keycode *touche, int *selection_touche, itemMenu *itemsTouches) {

    (*touche) = event->key.keysym.sym; 
    sprintf(itemsTouches[(*selection_touche)].texte, "                 %s                 ", SDL_GetKeyName((*touche)));
    (*selection_touche) = 0;
}


/** 
 * \fn void options(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_hautParleurActif, SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde, SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs, SDL_Rect *rectangles_boutons_sons, option_t *ongletActif, itemMenu *pseudo, modes_t *modeActif, personnage_t *personnageActif, position_t *positionActive, niveaux *avancee_niveaux, int tailleNiveaux, itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, int *selection_touche, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, SDL_Color couleurNoire, itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches,  barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres, int *largeur, int *hauteur, page_t *page_active, page_t *page_precedente, int *maintient_clic) 
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans les options 
 * \param event Pointeur vers l'événement SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param programme_lance Pointeur vers le booléen indiquant si le programme est en cours d'exécution.
 * \param rectangle_plein_ecran Rectangle pour le mode plein écran.
 * \param texture_image_plein_ecran Texture pour le bouton du mode plein écran.
 * \param plein_ecran Pointeur vers le booléen indiquant si le jeu est en mode plein écran.
 * \param rectangle_retour_en_arriere Rectangle pour le bouton de retour en arrière.
 * \param texture_image_retour_en_arriere Texture pour le bouton de retour en arrière.
 * \param texture_image_hautParleurActif Texture pour l'icône du haut-parleur actif.
 * \param rectangle_demande_sauvegarde Rectangle pour le bouton de demande de sauvegarde.
 * \param itemsDemandeSauvegarde Tableau des éléments de menu pour la demande de sauvegarde.
 * \param tailleDemandeSauvegarde Taille du tableau des éléments de menu de demande de sauvegarde.
 * \param texture_image_hautParleurDesactive Texture pour l'icône du haut-parleur désactivé.
 * \param sonsActifs Pointeur vers le booléen indiquant si les sons sont actifs.
 * \param rectangles_boutons_sons Tableau des rectangles pour les boutons des sons.
 * \param ongletActif Pointeur vers l'onglet actif dans les options.
 * \param pseudo Pseudo du joueur.
 * \param modeActif Mode de jeu actif.
 * \param personnageActif Personnage actif.
 * \param positionActive Position active du joueur.
 * \param avancee_niveaux Tableau de progression des niveaux.
 * \param tailleNiveaux Taille du tableau de progression des niveaux.
 * \param titre Élément de menu pour le titre.
 * \param surface Surface SDL pour le rendu de texte.
 * \param texture_texte Texture SDL pour le rendu de texte.
 * \param police Police TTF pour le rendu de texte.
 * \param selection_touche Indice de la touche sélectionnée.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_sauter_monter Touche pour sauter/monter.
 * \param touche_descendre Touche pour descendre.
 * \param touche_interagir Touche pour interagir.
 * \param couleurNoire Couleur noire pour le texte.
 * \param itemsMenu Tableau des éléments de menu.
 * \param tailleMenu Taille du tableau des éléments de menu.
 * \param itemsTouches Tableau des éléments de menu pour les touches.
 * \param tailleTouches Taille du tableau des éléments de menu pour les touches.
 * \param barre_de_son Tableau des barres de son.
 * \param tailleBarres Taille du tableau des barres de son.
 * \param itemsBarres Tableau des éléments de menu pour les barres de son.
 * \param largeur Largeur de la fenêtre.
 * \param hauteur Hauteur de la fenêtre.
 * \param page_active Page active.
 * \param page_precedente Page précédente.
 * \param maintient_clic Booléen indiquant si le clic est maintenu.
 * \param temps_debut_partie Temps de début de partie.
 * \param compteur_mort Compteur de mort.
 * \param avancee_succes Avancée des succès.
 * \see redimensionnement_fenetre
 * \see clic_case
 * \see clic_plein_ecran
 * \see mise_a_jour_barre_de_son
 * \see mise_a_jour_touches
 * \see mise_a_jour_rendu_options
 * \see demande_sauvegarde
 * \see sauvegarder_partie
 */
void options(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
             SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
             SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
             SDL_Texture **texture_image_hautParleurActif, SDL_Rect *rectangle_demande_sauvegarde, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde,
             SDL_Texture **texture_image_hautParleurDesactive, SDL_bool *sonsActifs,
             SDL_Rect *rectangles_boutons_sons, option_t *ongletActif, itemMenu *pseudo,
             modes_t *modeActif, personnage_t *personnageActif, position_t *positionActive,
             niveaux *avancee_niveaux, int tailleNiveaux,
             itemMenu *titre, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
             int *selection_touche, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
             SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, SDL_Color couleurNoire,
             itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, 
             barreDeSon *barre_de_son, int tailleBarres, itemMenu *itemsBarres,
             int *largeur, int *hauteur, page_t *page_active, page_t *page_precedente, int *maintient_clic,
             time_t temps_debut_partie, int *compteur_mort, int *avancee_succes) {

    SDL_Event event_temporaire;
    SDL_bool clic_effectue = SDL_FALSE;

    while(SDL_PollEvent(event)) {

            switch(event->type) {

                /* Gestion de l'événement de redimensionnement de la fenêtre */
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);

                    break;

                /* Changement du volume des barres de sons */
                case SDL_MOUSEBUTTONDOWN:

                        (*maintient_clic) = 1;

                        /* Clic sur les rectangles de changement d'onglet */
                        if(clic_case((*event), itemsMenu[0].rectangle))
                            (*ongletActif) = ONGLET_SON;
                        if(clic_case((*event), itemsMenu[1].rectangle))
                            (*ongletActif) = ONGLET_TOUCHES;
                        
                        /* Onglet Son */
                        /* Désactivation du musqiue */
                        if((clic_case((*event), rectangles_boutons_sons[0])) && (sonsActifs[0] == SDL_TRUE)) {
                            sonsActifs[0] = SDL_FALSE;
                            barre_de_son[0].volume_precedent = barre_de_son[0].volume;
                            barre_de_son[0].volume = 0;
                        }
                        /* Réactivation du musqiue */
                        else if((clic_case((*event), rectangles_boutons_sons[0])) && (barre_de_son[0].volume_precedent != 0)) {
                            sonsActifs[0] = SDL_TRUE;
                            barre_de_son[0].volume = barre_de_son[0].volume_precedent;
                        }
                        /* Désactivation du effet sonore */
                        if((clic_case((*event), rectangles_boutons_sons[1])) && (sonsActifs[1] == SDL_TRUE)) {
                            sonsActifs[1] = SDL_FALSE;
                            barre_de_son[1].volume_precedent = barre_de_son[1].volume;
                            barre_de_son[1].volume = 0;
                        }
                        /* Réactivation du effet sonore */
                        else if(clic_case((*event), rectangles_boutons_sons[1]) && (barre_de_son[1].volume_precedent != 0)) {
                            sonsActifs[1] = SDL_TRUE;
                            barre_de_son[1].volume = barre_de_son[1].volume_precedent;
                        }

                        /* Onglet Touches */
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

                        /* Options plein écran et retour en arrière */

                        if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                        if(clic_case((*event), (*rectangle_retour_en_arriere)))
                            (*page_active) = (*page_precedente);

                        break;

                /* Changement du volume */
                case SDL_MOUSEBUTTONUP :

                    (*maintient_clic) = 0;

                    if(clic_case((*event), barre_de_son[0].barre)){
                        mise_a_jour_barre_de_son(event, &(barre_de_son[0]), &(sonsActifs[0]));
                    }

                    else if(clic_case((*event), barre_de_son[1].barre)){
                        mise_a_jour_barre_de_son(event, &(barre_de_son[1]), &(sonsActifs[1]));
                    }

                    break;

                /* Changement des touches */
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
                            (event->key.keysym.sym != (*touche_interagir)))
                        mise_a_jour_touches(event, touche_aller_a_droite, selection_touche, itemsTouches);

                    else if(((*selection_touche) == 3) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_descendre)) &&
                            (event->key.keysym.sym != (*touche_interagir)))
                        mise_a_jour_touches(event, touche_aller_a_gauche, selection_touche, itemsTouches);

                    else if(((*selection_touche) == 5) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_descendre)) &&
                            (event->key.keysym.sym != (*touche_interagir)))
                        mise_a_jour_touches(event, touche_sauter_monter, selection_touche, itemsTouches);

                    else if(((*selection_touche) == 7) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_interagir)))
                        mise_a_jour_touches(event, touche_descendre, selection_touche, itemsTouches);
                        
                    else if(((*selection_touche) == 9) && 
                            (event->key.keysym.sym != (*touche_aller_a_droite)) &&
                            (event->key.keysym.sym != (*touche_aller_a_gauche)) &&
                            (event->key.keysym.sym != (*touche_sauter_monter)) &&
                            (event->key.keysym.sym != (*touche_descendre)))
                        mise_a_jour_touches(event, touche_interagir, selection_touche, itemsTouches);

                    break;

                case SDL_MOUSEMOTION :

                    if ((*maintient_clic)) {

                        /* Si le mouvement de la souris est dans la zone de la barre de son, ajuste le volume en fonction de la position du curseur */
                        if ((event->motion.y >= barre_de_son[0].barre.y - barre_de_son[0].barre.h / 2) &&
                            (event->motion.y <= barre_de_son[0].barre.y + barre_de_son[0].barre.h) &&
                            (event->motion.x >= barre_de_son[0].barre.x - barre_de_son[0].barre.w / 2) &&
                            (event->motion.x <= barre_de_son[0].barre.x + barre_de_son[0].barre.w)) {

                            barre_de_son[0].volume = (event->motion.x - ((*largeur) / 2 - barre_de_son[0].barre.w / 2)) * 100 / barre_de_son[0].barre.w;
                            mise_a_jour_barre_de_son(event, &(barre_de_son[0]), &(sonsActifs[0]));
                        }

                        if ((event->motion.y >= barre_de_son[1].barre.y - barre_de_son[1].barre.h / 2) &&
                            (event->motion.y <= barre_de_son[1].barre.y + barre_de_son[1].barre.h) &&
                            (event->motion.x >= barre_de_son[1].barre.x - barre_de_son[1].barre.w / 2) &&
                            (event->motion.x <= barre_de_son[1].barre.x + barre_de_son[1].barre.w)) {

                            barre_de_son[1].volume = (event->motion.x - ((*largeur) / 2 - barre_de_son[1].barre.w / 2)) * 100 / barre_de_son[1].barre.w;
                            mise_a_jour_barre_de_son(event, &(barre_de_son[1]), &(sonsActifs[1]));
                        }
                    }

                    break;

                /* Quitter le programme */
                case SDL_QUIT :

                    if((*page_precedente) == CARTE) {

                        SDL_SetWindowResizable((*window), SDL_FALSE);

                        demande_sauvegarde(renderer, rectangle_demande_sauvegarde,
                                           surface, texture_texte, police, couleurNoire,
                                           itemsDemandeSauvegarde, tailleDemandeSauvegarde, (*largeur), (*hauteur));

                        while (!clic_effectue) {

                            while (SDL_PollEvent(&event_temporaire)) {

                                if(event_temporaire.type == SDL_MOUSEBUTTONDOWN) {

                                    /* Cas où la personne veut sauvegarder */
                                    if(clic_case(event_temporaire, itemsDemandeSauvegarde[1].rectangle)) {

                                        sauvegarder_partie(touche_aller_a_droite, touche_aller_a_gauche, touche_sauter_monter,
                                                           touche_descendre, touche_interagir, barre_de_son, pseudo,
                                                           (*modeActif), (*personnageActif), (*positionActive),
                                                           avancee_niveaux, tailleNiveaux, temps_debut_partie, (*compteur_mort), avancee_succes);

                                        (*programme_lance) = SDL_FALSE;
                                        clic_effectue = SDL_TRUE; 
                                    }

                                    /* Cas où la personne ne veut pas sauvegarder */
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
                    }
                    
                    else
                        (*programme_lance) = SDL_FALSE;

                    break;

                default:
                    break;
            }
        }
        
        /* Mise à jour du rendu */
        mise_a_jour_rendu_options(renderer, rectangle_plein_ecran, texture_image_plein_ecran,
                                  rectangle_retour_en_arriere, texture_image_retour_en_arriere,
                                  texture_image_hautParleurActif,
                                  texture_image_hautParleurDesactive, sonsActifs,
                                  rectangles_boutons_sons, (*ongletActif),
                                  titre, surface, texture_texte, police,
                                  couleurNoire, (*selection_touche),
                                  itemsMenu, tailleMenu, itemsTouches, tailleTouches,
                                  barre_de_son, tailleBarres, itemsBarres,
                                  (*largeur), (*hauteur));
}