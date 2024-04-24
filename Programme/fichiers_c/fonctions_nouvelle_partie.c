/**
 * \file fonctions_nouvelle_partie.c
 * \brief Fichier contenant les fonctions servant à la fenêtre d'une nouvelle partie 
*/
#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_nouvelle_partie.h>

/** 
 * \fn void initialisation_objets_nouvelle_partie(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_perso_1, SDL_Texture **texture_image_perso_2, itemMenu *titres, itemMenu *itemsMenu, itemMenu *valider)
 * \brief Fonction qui permet d'initialiser les différents objets de la nouvelle partie
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_image_perso_1 Texture pour le premier personnage.
 * \param texture_image_perso_2 Texture pour le deuxième personnage.
 * \param titres Tableau des titres des sections.
 * \param itemsMenu Tableau des éléments de menu.
 * \param valider Élément de menu pour valider.
 * \see chargement_image
 */
void initialisation_objets_nouvelle_partie(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_perso_1,
                                           SDL_Texture **texture_image_perso_2,
                                           itemMenu *titres, itemMenu *itemsMenu, itemMenu *valider) {

    /* Initialisation de l'image du premier personnage */
    chargement_image(renderer, surface, texture_image_perso_1, "./images/personnages/personnage_masculin.png");

    /* Initialisation de l'image du deuxième personnage */
    chargement_image(renderer, surface, texture_image_perso_2, "./images/personnages/personnage_feminin.png");

    /* Initialisation des titres du menu nouvelle partie */
    sprintf(titres[0].texte, "    Pseudo :    ");
    sprintf(titres[1].texte, "  Personnage :  ");
    sprintf(titres[2].texte, " Mode de jeu : ");

	/* Initialisation du texte dans les items de la difficulté */
    sprintf(itemsMenu[0].texte, "  Normal  ");
    sprintf(itemsMenu[1].texte, " Difficile ");

    /* Initialisation du texte dans l'item pour commencer la partie */
    sprintf(valider->texte, " Commencer la partie ");
}

/** 
 * \fn void mise_a_jour_rendu_nouvelle_partie(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, modes_t modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1, SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t personnageActif, itemMenu *pseudo, SDL_Rect *rectangle_pseudo, itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte,  TTF_Font **police, SDL_Color couleurNoire, itemMenu *itemsMenu, itemMenu *valider, int largeur, int hauteur)
 * \brief Fonction qui met à jour le rendu du menu nouvelle partie 
 * \param renderer Pointeur vers le renderer SDL.
 * \param rectangle_plein_ecran Rectangle représentant l'écran entier.
 * \param texture_image_plein_ecran Texture pour l'écran entier.
 * \param rectangle_retour_en_arriere Rectangle pour le bouton retour.
 * \param texture_image_retour_en_arriere Texture pour le bouton retour.
 * \param rectangle_options Rectangle pour les options.
 * \param texture_image_options Texture pour les options.
 * \param modeActif Mode de jeu actif.
 * \param texture_image_perso_1 Texture pour le premier personnage.
 * \param rectangle_perso_1 Rectangle pour le premier personnage.
 * \param texture_image_perso_2 Texture pour le deuxième personnage.
 * \param rectangle_perso_2 Rectangle pour le deuxième personnage.
 * \param personnageActif Personnage actif.
 * \param pseudo Pseudo du joueur.
 * \param rectangle_pseudo Rectangle pour le pseudo.
 * \param titres Tableau des titres des sections.
 * \param tailleTitres Taille du tableau des titres.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_texte Texture pour le texte.
 * \param police Police de caractères.
 * \param couleurNoire Couleur noire.
 * \param itemsMenu Tableau des éléments de menu.
 * \param valider Élément de menu pour valider.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \see erreur
 * \see affichage_texte
 */
void mise_a_jour_rendu_nouvelle_partie(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                       SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                                       SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                       modes_t modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                                       SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t personnageActif,
                                       itemMenu *pseudo, SDL_Rect *rectangle_pseudo,
                                       itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte, 
                                       TTF_Font **police, SDL_Color couleurNoire, int modeSaisie,
                                       itemMenu *itemsMenu, itemMenu *valider, int largeur, int hauteur) {

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

    /* Copie la texture de l'image des options */

    rectangle_options->x = largeur - largeur / 21 - largeur / 53;
    rectangle_options->y = hauteur - hauteur / 12 - hauteur / 30;
    rectangle_options->w = largeur / 21;
    rectangle_options->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_options), NULL, rectangle_options) != 0)
        erreur("Copie de la texture");

    /* Dessine les items du menu nouvelle partie */

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    for(i = 0; i < tailleTitres; i++) {

        titres[i].rectangle.x = largeur / 3;
        titres[i].rectangle.y = hauteur / 20 + i * hauteur / 4;
        titres[i].rectangle.w = largeur / 3;
        titres[i].rectangle.h = hauteur / 14;

        affichage_texte(renderer, surface, texture_texte, &(titres[i]), 
                        police, couleurNoire);
    }

    /* Dessine le rectangle pour le pseudo */

    rectangle_pseudo->x = largeur / 3;
    rectangle_pseudo->y = hauteur / 8;
    rectangle_pseudo->w = largeur / 3;
    rectangle_pseudo->h = hauteur / 8;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    SDL_RenderFillRect((*renderer), rectangle_pseudo);

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
    SDL_RenderDrawRect((*renderer), rectangle_pseudo);

    /* Rendu du texte actuel sur la surface texte */

    (*surface) = TTF_RenderUTF8_Blended((*police), pseudo->texte, couleurNoire);
    (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*surface));

    /* Récupération des dimensions du texte */

    int largeur_texte = 0;
    int hauteur_texte = 0;
    SDL_QueryTexture((*texture_texte), NULL, NULL, &largeur_texte, &hauteur_texte);

    /* Positionnement du texte au centre */

    pseudo->rectangle.x = largeur / 3 + largeur / 100;
    pseudo->rectangle.y = hauteur / 8;
    pseudo->rectangle.w = largeur_texte;
    pseudo->rectangle.h = hauteur / 8;

    /* Affichage de la texture texture_texte */

    SDL_RenderCopy((*renderer), (*texture_texte), NULL, &(pseudo->rectangle));

    SDL_FreeSurface((*surface));
    SDL_DestroyTexture((*texture_texte));

    pseudo->rectangle.y = hauteur / 7;
    pseudo->rectangle.w = largeur / 200;
    pseudo->rectangle.h = hauteur / 11;

    /* Clignotement d'une barre quand le joueur peut écrire son pseudo */
    if (modeSaisie) {

        static int conteur = 0;

        if (conteur < 30) {

            SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
        
            pseudo->rectangle.x = largeur / 3 + largeur / 100 + largeur_texte;

            SDL_RenderFillRect((*renderer), &(pseudo->rectangle));
        }
        
        conteur = (conteur + 1) % 60;
    }

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

    if(personnageActif == PERSONNAGE_1)
        SDL_RenderFillRect((*renderer), rectangle_perso_1);

    else 
        SDL_RenderFillRect((*renderer), rectangle_perso_2);

    /* Copie la texture de l'image du premier personnage */

    rectangle_perso_1->x = largeur / 4 + largeur / 100;
    rectangle_perso_1->y = hauteur / 3 + hauteur / 20;
    rectangle_perso_1->w = largeur / 16;
    rectangle_perso_1->h = hauteur / 7;

    if(SDL_RenderCopy((*renderer), (*texture_image_perso_1), NULL, rectangle_perso_1) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image du deuxième personnage */

    rectangle_perso_2->x = largeur - largeur / 4 - largeur / 16 - largeur / 100;
    rectangle_perso_2->y = hauteur / 3 + hauteur / 20;
    rectangle_perso_2->w = largeur / 16;
    rectangle_perso_2->h = hauteur / 7;

    if(SDL_RenderCopy((*renderer), (*texture_image_perso_2), NULL, rectangle_perso_2) != 0)
        erreur("Copie de la texture");

    /* Dessine les éléments du menu pour la difficulté */

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

    if(modeActif == MODE_NORMAL) {
        
        SDL_RenderFillRect((*renderer), &(itemsMenu[0].rectangle));
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
        SDL_RenderFillRect((*renderer), &(itemsMenu[1].rectangle));
    }

    else {

        SDL_RenderFillRect((*renderer), &(itemsMenu[1].rectangle));
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
        SDL_RenderFillRect((*renderer), &(itemsMenu[0].rectangle));
    }

    /* Décide de la couleur en fonction de l'onglet actif */

    if(modeActif == MODE_NORMAL)
        SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

    else
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    itemsMenu[0].rectangle.x = largeur / 6;
    itemsMenu[1].rectangle.x = largeur - largeur / 6 - largeur / 4;

    for(i = 0; i < 2; i++) {

        if((i) && (modeActif == MODE_HARD))
            SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
        else if(i)
            SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

        itemsMenu[i].rectangle.y = hauteur / 2 + hauteur / 6;
        itemsMenu[i].rectangle.w = largeur / 4;
        itemsMenu[i].rectangle.h = hauteur / 12;

        affichage_texte(renderer, surface, texture_texte, &(itemsMenu[i]), 
                        police, couleurNoire);
    }

    /* Dessine les éléments du menu pour le bouton "Commencer la partie" */

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    valider->rectangle.x = largeur / 3;
    valider->rectangle.y = hauteur / 2 + hauteur / 3;
    valider->rectangle.w = largeur / 3;
    valider->rectangle.h = hauteur / 8;

    affichage_texte(renderer, surface, texture_texte, valider, 
                    police, couleurNoire);

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/** 
 * \fn void nouvelle_partie(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,  SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,  SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, int *modeSaisie, modes_t *modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1, SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t *personnageActif, itemMenu *pseudo, SDL_Rect *rectangle_pseudo, barreDeSon *barre_de_son, int *pseudo_valide, SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte,  TTF_Font **police, SDL_Color couleurNoire, position_t *positionActive, niveaux *avancee_niveaux, int tailleNiveaux, itemMenu *itemsMenu, itemMenu *valider, int *largeur, int *hauteur, page_t *page_active)
 * \brief Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le menu nouvelle partie
 * \param event Événement SDL.
 * \param window Pointeur vers la fenêtre SDL.
 * \param renderer Pointeur vers le renderer SDL.
 * \param programme_lance Booléen pour vérifier si le programme est en cours d'exécution.
 * \param rectangle_plein_ecran Rectangle représentant l'écran entier.
 * \param texture_image_plein_ecran Texture pour l'écran entier.
 * \param plein_ecran Booléen pour vérifier si le jeu est en mode plein écran.
 * \param rectangle_retour_en_arriere Rectangle pour le bouton retour.
 * \param texture_image_retour_en_arriere Texture pour le bouton retour.
 * \param rectangle_options Rectangle pour les options.
 * \param texture_image_options Texture pour les options.
 * \param modeSaisie Mode de saisie pour le pseudo.
 * \param modeActif Mode de jeu actif.
 * \param texture_image_perso_1 Texture pour le premier personnage.
 * \param rectangle_perso_1 Rectangle pour le premier personnage.
 * \param texture_image_perso_2 Texture pour le deuxième personnage.
 * \param rectangle_perso_2 Rectangle pour le deuxième personnage.
 * \param personnageActif Personnage actif.
 * \param pseudo Pseudo du joueur.
 * \param rectangle_pseudo Rectangle pour le pseudo.
 * \param barre_de_son Barre de son.
 * \param pseudo_valide Booléen pour vérifier si le pseudo est valide.
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_sauter_monter Touche pour sauter ou monter.
 * \param touche_descendre Touche pour descendre.
 * \param touche_interagir Touche pour interagir.
 * \param titres Tableau des titres des sections.
 * \param tailleTitres Taille du tableau des titres.
 * \param surface Pointeur vers la surface SDL.
 * \param texture_texte Texture pour le texte.
 * \param police Police de caractères.
 * \param couleurNoire Couleur noire.
 * \param positionActive Position active.
 * \param avancee_niveaux Tableau de l'avancée des niveaux.
 * \param tailleNiveaux Taille du tableau de l'avancée des niveaux.
 * \param itemsMenu Tableau des éléments de menu.
 * \param valider Élément de menu pour valider.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \param page_active Page active.
 * \param temps_debut_partie Temps de début de partie.
 * \param compteur_mort Compteur de mort.
 * \param avancee_succes Avancée des succès.
 * \see redimensionnement_fenetre 
 * \see clic_case 
 * \see clic_plein_ecran 
 * \see sauvegarder_partie 
 * \see mise_a_jour_rendu_nouvelle_partie
*/
void nouvelle_partie(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, 
                     SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, 
                     SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, int *modeSaisie,
                     modes_t *modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                     SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t *personnageActif,
                     itemMenu *pseudo, SDL_Rect *rectangle_pseudo, barreDeSon *barre_de_son, int *pseudo_valide,
                     SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
                     SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte, 
                     TTF_Font **police, SDL_Color couleurNoire, position_t *positionActive, niveaux *avancee_niveaux, int tailleNiveaux,
                     itemMenu *itemsMenu, itemMenu *valider, int *largeur, int *hauteur, page_t *page_active,
                     time_t *temps_debut_partie, int *compteur_mort, int *avancee_succes) {

    int i;

    while(SDL_PollEvent(event)) {

        switch(event->type) {

            /* Gestion de l'événement de redimensionnement de la fenêtre */
            case SDL_WINDOWEVENT:
                redimensionnement_fenetre((*event), largeur, hauteur);

                /* Actualisation de la taille de la police */
                (*police) = TTF_OpenFont("./polices/04B_11__.TTF", (*largeur) / 35);
        
                break;

            /* Si l'utilisateur tape quelque chose */
            case SDL_TEXTINPUT:
                if((*modeSaisie))
                    /* Concatène le texte saisi au pseudo */
                    if(strlen(pseudo->texte) + strlen(event->text.text) <= 10)
                        strcat(pseudo->texte, event->text.text);

                break;

            /* Si l'utilisateur clic quelque part */
            case SDL_MOUSEBUTTONDOWN:
                if(clic_case((*event), (*rectangle_pseudo)))
                    (*modeSaisie) = 1;
                else
                    (*modeSaisie) = 0;

                if(clic_case((*event), itemsMenu[0].rectangle)) 
                    (*modeActif) = MODE_NORMAL;
                else if(clic_case((*event), itemsMenu[1].rectangle))
                    (*modeActif) = MODE_HARD;

                if(clic_case((*event), (*rectangle_perso_1))) 
                    (*personnageActif) = PERSONNAGE_1;
                else if(clic_case((*event), (*rectangle_perso_2)))
                    (*personnageActif) = PERSONNAGE_2;

                /* Options plein écran, options et retour en arrière */

                if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                    redimensionnement_fenetre((*event), largeur, hauteur);

                if(clic_case((*event), (*rectangle_retour_en_arriere)))
                    (*page_active) = MENU_PRINCIPAL;

                if(clic_case((*event), (*rectangle_options)))
                    (*page_active) = OPTIONS;

                /* Options valider */
                if((clic_case((*event), valider->rectangle)) && (strcmp(pseudo->texte, "\0"))) {

                    for(i = 0; pseudo->texte[i] != '\0'; i++)
                        if(pseudo->texte[i] != ' ')
                            (*pseudo_valide) = 1;

                    if((*pseudo_valide)) {

                        (*positionActive) = NIVEAU1;

                        for(i = 0; i < tailleNiveaux; i++) {

                            avancee_niveaux[i].niveau_fini = 0;
                            avancee_niveaux[i].numero_collectible[0] = 0;
                            avancee_niveaux[i].numero_collectible[1] = 0;
                            avancee_niveaux[i].numero_collectible[2] = 0;
                        }

                        (*temps_debut_partie) = time(NULL);
                        (*compteur_mort) = 0;

                        for(i = 0; i < 10; i++)
                            avancee_succes[i] = 0;

                        sauvegarder_partie(touche_aller_a_droite, touche_aller_a_gauche, touche_sauter_monter,
                                            touche_descendre, touche_interagir, barre_de_son, pseudo,
                                            (*modeActif), (*personnageActif), (*positionActive),
                                            avancee_niveaux, tailleNiveaux, (*temps_debut_partie), (*compteur_mort), avancee_succes);

                        (*page_active) = INTRODUCTION; 
                    }
                }

                break;

            /* Mode saisie du pseudo */
            case SDL_KEYDOWN:

                if((*modeSaisie))

                    if(event->key.keysym.sym == SDLK_BACKSPACE && strlen(pseudo->texte) > 0)
                        pseudo->texte[strlen(pseudo->texte) - 1] = '\0'; /* Supprime le dernier caractère du pseudo */

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
    mise_a_jour_rendu_nouvelle_partie(renderer, rectangle_plein_ecran, texture_image_plein_ecran,
                                        rectangle_retour_en_arriere, texture_image_retour_en_arriere,
                                        rectangle_options, texture_image_options,
                                        (*modeActif), texture_image_perso_1, rectangle_perso_1,
                                        texture_image_perso_2, rectangle_perso_2, (*personnageActif),
                                        pseudo, rectangle_pseudo,
                                        titres, tailleTitres, surface, texture_texte, 
                                        police, couleurNoire, (*modeSaisie),
                                        itemsMenu, valider, (*largeur), (*hauteur));
}