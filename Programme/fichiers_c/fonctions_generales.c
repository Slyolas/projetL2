/**
 * \file fonctions_generales.c
 * \brief Fichier avec les fichiers utilisé régulièrement
*/
#include <../fichiers_h/fonctions_generales.h>

/**
 * \fn erreur(const char *message)
 * \brief Affiche l'erreur en cas de problème et ferme la SDL
 * \param message Un pointeur sur caractère en lecture représentant le message d'erreur
 * \return Arrêt du programme en Echec
 */
void erreur(const char *message) {

    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/**
 * \fn chargement_image(SDL_Renderer **renderer, SDL_Surface **surface,SDL_Texture **texture, char *chemin)
 * \brief Fonction qui permet de charger une image
 * \param renderer rendu sur lequel posé l'image
 * \param surface Surface à utiliser pour récupérer l'image
 * \param texture Texture à crée 
 * \param chemin Pointeur sur caractère représentant le chemin d'accès du fichier
 * \see erreur
  */
void chargement_image(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, char *chemin) {
    (*surface) = IMG_Load(chemin);
    if((*surface) == NULL)
        erreur("Chargement de l'image");
    
    (*texture) = SDL_CreateTextureFromSurface((*renderer), (*surface));
    if((*texture) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*surface));
}

/**
 * \fn affichage_texte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, itemMenu *item,TTF_Font **police, SDL_SDL_Color couleur)
 * \brief Affiche du texte sur la fenêtre
 * \param renderer Rendu de la fenêtre 
 * \param surface Surface ou appliquer la texture
 * \param texture Texture à afficher
 * \param item Texte à afficher
 * \param police police d'écriture
 * \param couleur couleur 
 */
void affichage_texte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, itemMenu *item, 
                     TTF_Font **police, SDL_Color couleur) {

    SDL_RenderFillRect((*renderer), &(item->rectangle));

    (*surface) = TTF_RenderText_Solid((*police), item->texte, couleur);
    (*texture) = SDL_CreateTextureFromSurface((*renderer), (*surface));

    SDL_RenderCopy((*renderer), (*texture), NULL, &(item->rectangle));

    SDL_FreeSurface((*surface));
    SDL_DestroyTexture((*texture));
}

/**
 * \fn void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) 
 * \brief Fonction qui permet de créer une fenêtre et le rendu
 * \param window fenêtre à créer
 * \param renderer Rendu de la fenêtre à créer 
 * \param largeur largeur de la fenêtre souhaité
 * \param hauteur hauteur de la fenêtre souhaité
 * \see erreur
 */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) {

    /* Création de la fenêtre */
    (*window) = SDL_CreateWindow("MétaTravers", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, 
                                 largeur, hauteur,
                                 SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if((*window) == NULL)
        erreur("Création fenêtre échouée");

    /* Création du rendu */
    (*renderer) = SDL_CreateRenderer((*window), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if((*renderer) == NULL)
        erreur("Création rendu échoué");
}

/**
 * \fn void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_plein_ecran, SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_options, SDL_Texture **texture_image_passer, itemMenu *itemsDemandeSauvegarde, itemMenu *itemsDemandeQuitter, SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant, SDL_Texture **texture_image_perso_1_gagnant, SDL_Texture **texture_image_perso_2_gagnant, niveaux *avancee_niveaux, TTF_Font **police)
 * \brief Fonctions qui permet d'initialiser les objets globaux
 * \param renderer Pointeur vers le renderer SDL.
 * \param surface Surface SDL.
 * \param texture_image_plein_ecran Texture de l'image en plein écran.
 * \param texture_image_retour_en_arriere Texture de l'image du bouton retour en arrière.
 * \param texture_image_options Texture de l'image du bouton options.
 * \param texture_image_passer Texture de l'image du bouton passer.
 * \param itemsDemandeSauvegarde Tableau d'items pour la demande de sauvegarde.
 * \param itemsDemandeQuitter Tableau d'items pour la demande de quitter.
 * \param texture_image_fin_premiers_niveaux Texture de l'image de fin des premiers niveaux.
 * \param texture_image_monstre_terrestre Texture de l'image du monstre terrestre.
 * \param texture_image_monstre_volant Texture de l'image du monstre volant.
 * \param texture_image_perso_1_gagnant Texture de l'image du personnage 1 gagnant.
 * \param texture_image_perso_2_gagnant Texture de l'image du personnage 2 gagnant.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \param police Police de caractères TTF.
 * \see chargement_image
 * \see erreur
 */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_plein_ecran,
                           SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_options,
                           SDL_Texture **texture_image_passer, itemMenu *itemsDemandeSauvegarde, itemMenu *itemsDemandeQuitter,
                           SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture_image_monstre_terrestre,
                           SDL_Texture **texture_image_monstre_volant, SDL_Texture **texture_image_perso_1_gagnant,
                           SDL_Texture **texture_image_perso_2_gagnant,
                           niveaux *avancee_niveaux, TTF_Font **police) {

    /* Initialisation de l'image du plein écran du menu */
    chargement_image(renderer, surface, texture_image_plein_ecran, "./images/plein_ecran_blanc.png");

    /* Initialisation de l'image du retour en arrière */
    chargement_image(renderer, surface, texture_image_retour_en_arriere, "./images/retour_en_arriere.png");

    /* Initialisation de l'image des options du menu */
    chargement_image(renderer, surface, texture_image_options, "./images/options_blanc.png");

    /* Initialisation de l'image du passer du menu */
    chargement_image(renderer, surface, texture_image_passer, "./images/passer.png");

    /* Initialisation de la police */
    if(((*police) = TTF_OpenFont("./polices/04B_11__.TTF", 20)) == NULL)
        erreur("Chargement de la police");

    /* Initialisation des images pour les collectibles */
    chargement_image(renderer, surface, &(avancee_niveaux[0].texture_image_collectible), "./images/niveau_1/collectible_niveau_1.png");
    chargement_image(renderer, surface, &(avancee_niveaux[1].texture_image_collectible), "./images/niveau_2/collectible_niveau_2.png");
    chargement_image(renderer, surface, &(avancee_niveaux[2].texture_image_collectible), "./images/niveau_3/collectible_niveau_3.png");
    chargement_image(renderer, surface, &(avancee_niveaux[3].texture_image_collectible), "./images/niveau_4/collectible_niveau_4.png");

    chargement_image(renderer, surface, texture_image_fin_premiers_niveaux, "./images/fin_premiers_niveaux.png");

    chargement_image(renderer, surface, texture_image_monstre_terrestre, "./images/monstre_terrestre.png");
    chargement_image(renderer, surface, texture_image_monstre_volant, "./images/monstre_volant.png");

    chargement_image(renderer, surface, texture_image_perso_1_gagnant, "./images/personnages/personnage_masculin_gagnant.png");
    chargement_image(renderer, surface, texture_image_perso_2_gagnant, "./images/personnages/personnage_feminin_gagnant.png");

    /* Initialisation du texte dans les items de la demande de sauvegarde */
    sprintf(itemsDemandeSauvegarde[0].texte, " Voulez-vous sauvegarder la partie avant de quitter ? ");
    sprintf(itemsDemandeSauvegarde[1].texte, " Oui ");
    sprintf(itemsDemandeSauvegarde[2].texte, " Non ");

    /* Initialisation du texte dans les items de la demande de quitter le niveau */
    sprintf(itemsDemandeQuitter[0].texte, " Voulez-vous quittez le niveau ? ");
    sprintf(itemsDemandeQuitter[1].texte, " Oui ");
    sprintf(itemsDemandeQuitter[2].texte, " Non ");
}

/**
 * \fn void demande_sauvegarde(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_sauvegarde, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur, itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde, int largeur, int hauteur)
 * \brief fenêtre se chargeant de demander à l'utilisateur si il souhaite sauvegarder
 * \param renderer Pointeur vers le renderer SDL.
 * \param rectangle_demande_sauvegarde Rectangle de la demande de sauvegarde SDL.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param couleur Couleur du texte.
 * \param itemsDemandeSauvegarde Tableau d'items pour la demande de sauvegarde.
 * \param tailleDemandeSauvegarde Taille du tableau d'items pour la demande de sauvegarde.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \see affichage_texte
 */
void demande_sauvegarde(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_sauvegarde,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur,
                        itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde, int largeur, int hauteur) {

    int i;

    /* Affichage du rectangle de la demande de sauvegarde */
    rectangle_demande_sauvegarde->x = largeur / 6;
    rectangle_demande_sauvegarde->y = hauteur / 6;
    rectangle_demande_sauvegarde->w = largeur / 3 * 2;
    rectangle_demande_sauvegarde->h = hauteur / 3 * 2;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    SDL_RenderFillRect((*renderer), rectangle_demande_sauvegarde);

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
    SDL_RenderDrawRect((*renderer), rectangle_demande_sauvegarde);

    /* Affichage du rectangle de la question de la demande de sauvegarde */
    itemsDemandeSauvegarde[0].rectangle.x = largeur / 6;
    itemsDemandeSauvegarde[0].rectangle.y = hauteur / 4 + hauteur / 20;
    itemsDemandeSauvegarde[0].rectangle.w = largeur / 3 * 2;
    itemsDemandeSauvegarde[0].rectangle.h = hauteur / 9;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    
    affichage_texte(renderer, surface, texture_texte, &(itemsDemandeSauvegarde[0]), 
                    police, couleur);

    /* Affichage des rectangles des réponses de la demande de sauvegarde */
    for(i = 1; i < tailleDemandeSauvegarde; i++) {
        itemsDemandeSauvegarde[i].rectangle.x = largeur / 3 + (i-1) * largeur / 3 - (i-1) * largeur / 10;
        itemsDemandeSauvegarde[i].rectangle.y = hauteur - hauteur / 4 - hauteur / 20 - hauteur / 10;
        itemsDemandeSauvegarde[i].rectangle.w = largeur / 10;
        itemsDemandeSauvegarde[i].rectangle.h = hauteur / 10;

        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

        affichage_texte(renderer, surface, texture_texte, &(itemsDemandeSauvegarde[i]), 
                        police, couleur);

        SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
        SDL_RenderDrawRect((*renderer), &(itemsDemandeSauvegarde[i].rectangle));
    }

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/** 
 * \fn void demande_quitter_niveau(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_quitter, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur, itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int largeur, int hauteur)
 * \brief Fonction qui permet de demander à l'utilisateur de quitter le niveau
 * \param renderer Pointeur vers le renderer SDL.
 * \param rectangle_demande_quitter Rectangle de la demande de quitter le niveau SDL.
 * \param surface Surface SDL.
 * \param texture_texte Texture du texte SDL.
 * \param police Police de caractères TTF.
 * \param couleur Couleur du texte.
 * \param itemsDemandeQuitter Tableau d'items pour la demande de quitter le niveau.
 * \param tailleDemandeQuitter Taille du tableau d'items pour la demande de quitter le niveau.
 * \param largeur Largeur de l'écran.
 * \param hauteur Hauteur de l'écran.
 * \see affichage_texte
 */
void demande_quitter_niveau(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_quitter,
                            SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur,
                            itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int largeur, int hauteur) {

    int i;

    /* Affichage du rectangle de la demande de quitter le niveau */
    rectangle_demande_quitter->x = largeur / 6;
    rectangle_demande_quitter->y = hauteur / 6;
    rectangle_demande_quitter->w = largeur / 3 * 2;
    rectangle_demande_quitter->h = hauteur / 3 * 2;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    SDL_RenderFillRect((*renderer), rectangle_demande_quitter);

    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
    SDL_RenderDrawRect((*renderer), rectangle_demande_quitter);

    /* Affichage du rectangle de la question de la demande de quitter le niveau */
    itemsDemandeQuitter[0].rectangle.x = largeur / 6;
    itemsDemandeQuitter[0].rectangle.y = hauteur / 4 + hauteur / 20;
    itemsDemandeQuitter[0].rectangle.w = largeur / 3 * 2;
    itemsDemandeQuitter[0].rectangle.h = hauteur / 9;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    
    affichage_texte(renderer, surface, texture_texte, &(itemsDemandeQuitter[0]), 
                    police, couleur);

    /* Affichage des rectangles des réponses de la demande de quitter le niveau */
    for(i = 1; i < tailleDemandeQuitter; i++) {
        itemsDemandeQuitter[i].rectangle.x = largeur / 3 + (i-1) * largeur / 3 - (i-1) * largeur / 10;
        itemsDemandeQuitter[i].rectangle.y = hauteur - hauteur / 4 - hauteur / 20 - hauteur / 10;
        itemsDemandeQuitter[i].rectangle.w = largeur / 10;
        itemsDemandeQuitter[i].rectangle.h = hauteur / 10;

        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

        affichage_texte(renderer, surface, texture_texte, &(itemsDemandeQuitter[i]), 
                        police, couleur);

        SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 255);
        SDL_RenderDrawRect((*renderer), &(itemsDemandeQuitter[i].rectangle));
    }

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/**
 * \fn void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur)
 * \brief Fonction qui permet de récupérer les nouvelles dimensions de la fenêtre pour redimensionner cette dernière et les différents objets
 * \param event Evenement SDL
 * \param largeur largeur de la fenêtre a redimensionné
 * \param hauteur hauteur de la fenêtre a redimensionné
 */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/**
 * \fn int verification_sauvegarde()
 * \brief Vérifie si une sauvegarde existe 
 * \return booléen représentant si il y a une sauvegarde ou non (1 si existant, sinon 0)
 * \see erreur
*/
int verification_sauvegarde() {
    
    FILE *fichier_sauvegarde;

    /* Ouverture du fichier en mode lecture */
    fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "r");

    /* Vérifie si le fichier existe */
    if (fichier_sauvegarde == NULL)
        return 0;

    /* Fermeture du fichier */
    if (fclose(fichier_sauvegarde) != 0)
        erreur("Fermeture du fichier");

    return 1;
}

/**
 * \fn void sauvegarder_partie(SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, barreDeSon *barre_de_son, itemMenu *pseudo, modes_t modeActif, personnage_t personnageActif, position_t positionActive, niveaux *avancee_niveaux, int tailleNiveaux) 
 * \brief Fonction qui permet de sauvegarder la partie dans un fichier
 * \param touche_aller_a_droite Touche pour aller à droite.
 * \param touche_aller_a_gauche Touche pour aller à gauche.
 * \param touche_sauter_monter Touche pour sauter/monter.
 * \param touche_descendre Touche pour descendre.
 * \param touche_interagir Touche pour interagir.
 * \param barre_de_son Réglages de la barre de son.
 * \param pseudo Pseudo du joueur.
 * \param modeActif Mode actif du jeu.
 * \param personnageActif Personnage actif.
 * \param positionActive Position active.
 * \param avancee_niveaux Structure de progression des niveaux.
 * \param tailleNiveaux Taille du tableau d'items pour les niveaux.
 * \see erreur
 */
void sauvegarder_partie(SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
                        SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, barreDeSon *barre_de_son, itemMenu *pseudo,
                        modes_t modeActif, personnage_t personnageActif, position_t positionActive,
                        niveaux *avancee_niveaux, int tailleNiveaux) {

    FILE *fichier_sauvegarde;

    int i;

    /* Ouverture du fichier en mode écriture */
    fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "w");

    fprintf(fichier_sauvegarde, "%f\n", barre_de_son[0].volume);
    fprintf(fichier_sauvegarde, "%f\n", barre_de_son[1].volume);
    fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_aller_a_droite)));
    fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_aller_a_gauche)));
    fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_sauter_monter)));
    fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_descendre)));
    fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_interagir)));
    fprintf(fichier_sauvegarde, "%s\n", pseudo->texte);

    fprintf(fichier_sauvegarde, "%d\n", personnageActif);

    fprintf(fichier_sauvegarde, "%d\n", modeActif);

    fprintf(fichier_sauvegarde, "%d\n", positionActive);

    for(i = 0; i < tailleNiveaux; i++) {
        fprintf(fichier_sauvegarde, "%d %d %d %d\n", avancee_niveaux[i].niveau_fini,
                                                     avancee_niveaux[i].numero_collectible[0],
                                                     avancee_niveaux[i].numero_collectible[1],
                                                     avancee_niveaux[i].numero_collectible[2]);
    }

    /* Fermeture du fichier */
    if (fclose(fichier_sauvegarde) != 0)
        erreur("Fermeture du fichier");
}

/**
 * \fn int clic_case(SDL_Event event, SDL_Rect rectangle)
 * \brief Fonction qui permet de renvoyer vrai quand on clique sur un rectangle, faux sinon
 * \param event Evenement SDL
 * \param rectangle Rectangle qui a été cliqué ou non
 * \return booléen représentant si le clic s'est fait dans le rectangle (1 si c'est le cas sinon 0)
 * 
 */
int clic_case(SDL_Event event, SDL_Rect rectangle) {

        if((event.button.x >= rectangle.x) &&
           (event.button.x <= rectangle.x + rectangle.w) &&
           (event.button.y >= rectangle.y) &&
           (event.button.y <= rectangle.y + rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))
            return 1;
        
        return 0;
}

/**
 * \fn int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran,SDL_bool *plein_ecran, SDL_Window **window)
 * \brief Fonction qui permet de mettre la fenêtre en plein écran quand on clique sur le bouton plein écran
 * \param event Evenement SDL
 * \param rectangle_plein_ecran Rectangle ou se situe le bouton pour afficher le plein écran ou le retirer
 * \param plein_ecran booléen qui dit si il est en mode plein écran
 * \param window fenêtre à changer en pleine écran ou non
 * \return le changement d'état sous la forme d'un booléen 
 */
int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran, SDL_bool *plein_ecran, SDL_Window **window) {

    if ((event.button.x >= rectangle_plein_ecran->x) &&
        (event.button.x <= rectangle_plein_ecran->x + rectangle_plein_ecran->w) &&
        (event.button.y >= rectangle_plein_ecran->y) &&
        (event.button.y <= rectangle_plein_ecran->y + rectangle_plein_ecran->h) &&
        (event.button.button == SDL_BUTTON_LEFT)) {
            
        if ((*plein_ecran)) {   
            SDL_SetWindowFullscreen((*window), 0);
            (*plein_ecran) = SDL_FALSE;
        } else {
            SDL_SetWindowFullscreen((*window), SDL_WINDOW_FULLSCREEN_DESKTOP);
            (*plein_ecran) = SDL_TRUE;
        }
        return 1;
    }
    return 0;
}

/**
 * \fn void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,int sauter, int avancer, int reculer, int tile_map[18][32]) 
 * \brief Fonction qui permet de déplacer le personnage dans les différents niveaux
 * \param saut Indicateur de saut.
 * \param tombe Indicateur de chute.
 * \param position_x Position en x du personnage.
 * \param position_y Position en y du personnage.
 * \param position_avant_saut Position avant le saut.
 * \param sauter Indicateur de tentative de saut.
 * \param avancer Indicateur d'avancement.
 * \param reculer Indicateur de recul.
 * \param tile_map Carte du niveau.
 */
void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,
                            int sauter, int avancer, int reculer, int tile_map[18][32]) {

    /* Cas où la touche pour sauter est pressée */
    if((!(*saut)) && (!(*tombe)) && (sauter)) {

        (*position_avant_saut) = (*position_y);
        (*saut) = 1;
    }

    /* Cas où la touche pour aller à gauche est pressée */
    if(((!(tile_map[(*position_y)][(*position_x) - 1])) || 
        ((tile_map[(*position_y)][(*position_x) - 1] >= 3) &&
        (tile_map[(*position_y)][(*position_x) - 1] <= 9)) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 11) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 12)) && (reculer)) {
                                    
        (*position_x)--;

        if((!(*saut)) && (!(*tombe))) {

            (*tombe) = 1;
            SDL_Delay(75);
        }
    }

    /* Cas où la touche pour aller à droite est pressée */
    if(((!(tile_map[(*position_y)][(*position_x) + 1])) || 
        ((tile_map[(*position_y)][(*position_x) + 1] >= 3) &&
        (tile_map[(*position_y)][(*position_x) + 1] <= 9)) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 11) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 12)) && (avancer)) {

        (*position_x)++;

        if((!(*saut)) && (!(*tombe))) {

            (*tombe) = 1;
            SDL_Delay(75);
        }
    }

    /* Cas où le personnage est entrain de sauter */
    if((*saut)) {

        if ((*position_y) < (*position_avant_saut)-2) {

            (*tombe) = 1;
            (*saut) = 0;
        }

        else if((tile_map[(*position_y) - 1][(*position_x)] == 0) || 
                (tile_map[(*position_y) - 1][(*position_x)] == 5) ||
                (tile_map[(*position_y) - 1][(*position_x)] == 6) ||
                (tile_map[(*position_y) - 1][(*position_x)] == 9)) {

            (*position_y) -= 1; 
            SDL_Delay(75);
        }

        else {

            (*tombe) = 1;
            (*saut) = 0; 
        }
    }

    /* Cas où le personnage est entrain de tomber */
    if((*tombe)) {

        if ((tile_map[(*position_y) + 1][(*position_x)] == 1) || (tile_map[(*position_y) + 1][(*position_x)] == 10) ||
            (tile_map[(*position_y) + 1][(*position_x)] == 13) || (tile_map[(*position_y) + 1][(*position_x)] == 14) ||
            (tile_map[(*position_y) + 1][(*position_x)] == 15) || (tile_map[(*position_y) + 1][(*position_x)] == 16)) {

            (*tombe) = 0;
        }

        else {

            (*position_y) += 1;
            SDL_Delay(75);
        }
    }
}

/**
 * \fn void SDL_LimitFPS(unsigned int limit)
 * \brief Fonction qui permet de gérer le nombre d'FPS à différents moments du jeu 
 * \param limit la limite désiré en FPS 
 */
void SDL_LimitFPS(unsigned int limit) {

    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
}

/**
 * \fn
 * \brief Fonction qui permet de détruire les objets initialisés
 * \param police Police d'écriture qui sera désallouer
 * \param texture_1_to_71 les 71 textures à désallouer
 */
void detruire_objets(TTF_Font **police, SDL_Texture **texture1, SDL_Texture **texture2,
                     SDL_Texture **texture3, SDL_Texture **texture4, SDL_Texture **texture5, SDL_Texture **texture6,
                     SDL_Texture **texture7, SDL_Texture **texture8,
                     SDL_Texture **texture9, SDL_Texture **texture10, SDL_Texture **texture11,
                     SDL_Texture **texture12, SDL_Texture **texture13, SDL_Texture **texture14,
                     SDL_Texture **texture15, SDL_Texture **texture16,
                     SDL_Texture **texture17, SDL_Texture **texture18, 
                     SDL_Texture **texture19, SDL_Texture **texture20,
                     SDL_Texture **texture21, SDL_Texture **texture22,
                     SDL_Texture **texture23, SDL_Texture **texture24,
                     SDL_Texture **texture25, SDL_Texture **texture26,
                     SDL_Texture **texture27, SDL_Texture **texture28,
                     SDL_Texture **texture29, SDL_Texture **texture30,
                     SDL_Texture **texture31, SDL_Texture **texture32,
                     SDL_Texture **texture33, SDL_Texture **texture34,
                     SDL_Texture **texture35, SDL_Texture **texture36, SDL_Texture **texture37,
                     SDL_Texture **texture38, SDL_Texture **texture39, SDL_Texture **texture40,
                     SDL_Texture **texture41, SDL_Texture **texture42,
                     SDL_Texture **texture43, SDL_Texture **texture44,
                     SDL_Texture **texture45, SDL_Texture **texture46,
                     SDL_Texture **texture47, SDL_Texture **texture48, 
                     SDL_Texture **texture49, SDL_Texture **texture50,
                     SDL_Texture **texture51, SDL_Texture **texture52,
                     SDL_Texture **texture53, SDL_Texture **texture54,
                     SDL_Texture **texture55, SDL_Texture **texture56, 
                     SDL_Texture **texture57, SDL_Texture **texture58,
                     SDL_Texture **texture59, SDL_Texture **texture60,
                     SDL_Texture **texture61, SDL_Texture **texture62,
                     SDL_Texture **texture63, SDL_Texture **texture64, 
                     SDL_Texture **texture65, SDL_Texture **texture66,
                     SDL_Texture **texture67, SDL_Texture **texture68, 
                     SDL_Texture **texture69, SDL_Texture **texture70, SDL_Texture **texture71) {

    /* Destructions des textures */
    SDL_DestroyTexture((*texture1));  SDL_DestroyTexture((*texture2)); 
    SDL_DestroyTexture((*texture3));  SDL_DestroyTexture((*texture4)); 
    SDL_DestroyTexture((*texture5));  SDL_DestroyTexture((*texture6)); 
    SDL_DestroyTexture((*texture7));  SDL_DestroyTexture((*texture8)); 
    SDL_DestroyTexture((*texture9));  SDL_DestroyTexture((*texture10)); 
    SDL_DestroyTexture((*texture11)); SDL_DestroyTexture((*texture12)); 
    SDL_DestroyTexture((*texture13)); SDL_DestroyTexture((*texture14)); 
    SDL_DestroyTexture((*texture15)); SDL_DestroyTexture((*texture16)); 
    SDL_DestroyTexture((*texture17)); SDL_DestroyTexture((*texture18)); 
    SDL_DestroyTexture((*texture19)); SDL_DestroyTexture((*texture20)); 
    SDL_DestroyTexture((*texture21)); SDL_DestroyTexture((*texture22));
    SDL_DestroyTexture((*texture23)); SDL_DestroyTexture((*texture24)); 
    SDL_DestroyTexture((*texture25)); SDL_DestroyTexture((*texture26)); 
    SDL_DestroyTexture((*texture27)); SDL_DestroyTexture((*texture28)); 
    SDL_DestroyTexture((*texture29)); SDL_DestroyTexture((*texture30));
    SDL_DestroyTexture((*texture31)); SDL_DestroyTexture((*texture32)); 
    SDL_DestroyTexture((*texture33)); SDL_DestroyTexture((*texture34));
    SDL_DestroyTexture((*texture35)); SDL_DestroyTexture((*texture36)); 
    SDL_DestroyTexture((*texture37)); SDL_DestroyTexture((*texture38));
    SDL_DestroyTexture((*texture39)); SDL_DestroyTexture((*texture40)); 
    SDL_DestroyTexture((*texture41)); SDL_DestroyTexture((*texture42));
    SDL_DestroyTexture((*texture43)); SDL_DestroyTexture((*texture44));
    SDL_DestroyTexture((*texture45)); SDL_DestroyTexture((*texture46));
    SDL_DestroyTexture((*texture47)); SDL_DestroyTexture((*texture48));
    SDL_DestroyTexture((*texture49)); SDL_DestroyTexture((*texture50));
    SDL_DestroyTexture((*texture51)); SDL_DestroyTexture((*texture52));
    SDL_DestroyTexture((*texture53)); SDL_DestroyTexture((*texture54)); 
    SDL_DestroyTexture((*texture55)); SDL_DestroyTexture((*texture56));
    SDL_DestroyTexture((*texture57)); SDL_DestroyTexture((*texture58)); 
    SDL_DestroyTexture((*texture59)); SDL_DestroyTexture((*texture60));
    SDL_DestroyTexture((*texture61)); SDL_DestroyTexture((*texture62));
    SDL_DestroyTexture((*texture63)); SDL_DestroyTexture((*texture64));
    SDL_DestroyTexture((*texture65)); SDL_DestroyTexture((*texture66));
    SDL_DestroyTexture((*texture67)); SDL_DestroyTexture((*texture68));
    SDL_DestroyTexture((*texture69)); SDL_DestroyTexture((*texture70)); SDL_DestroyTexture((*texture71));
    
    /* Destructions de la police */
    TTF_CloseFont((*police));
}

/**
 * \fn void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window)
 * \brief Fonction qui permet de détruire le rendu et la fenêtre
 * \param renderer Rendu à détruire
 * \param widnow fenêtre à détruire
 */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}