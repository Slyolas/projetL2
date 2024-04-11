#include <../fichiers_h/fonctions_generales.h>

/* Fonction qui affiche un message d'erreur quand une chose n'a pas pû être exécuté */
void erreur(const char *message) {

    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/* Fonction qui permet de charger une image */
void chargement_image(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, char *chemin) {
    (*surface) = IMG_Load(chemin);
    if((*surface) == NULL)
        erreur("Chargement de l'image");
    
    (*texture) = SDL_CreateTextureFromSurface((*renderer), (*surface));
    if((*texture) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*surface));
}

/* Fonciton qui permet d'afficher le texte */
void affichage_texte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, itemMenu *item, 
                     TTF_Font **police, SDL_Color couleur) {

    SDL_RenderFillRect((*renderer), &(item->rectangle));

    (*surface) = TTF_RenderText_Solid((*police), item->texte, couleur);
    (*texture) = SDL_CreateTextureFromSurface((*renderer), (*surface));

    SDL_RenderCopy((*renderer), (*texture), NULL, &(item->rectangle));

    SDL_FreeSurface((*surface));
    SDL_DestroyTexture((*texture));
}

/* Fonction qui permet de créer une fenêtre et le rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) {

    /* Création de la fenêtre */
    (*window) = SDL_CreateWindow("MetaTravers", SDL_WINDOWPOS_CENTERED,
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

/* Fonctions qui permet d'initialiser les objets globaux */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_plein_ecran,
                           SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_options,
                           SDL_Texture **texture_image_passer, itemMenu *itemsDemandeSauvegarde, itemMenu *itemsDemandeQuitter,
                           SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture_image_monstre_terrestre,
                           SDL_Texture **texture_image_monstre_volant,
                           niveaux *avancee_niveaux, TTF_Font **police) {

    /* Initialisation de l'image du plein écran du menu */
    chargement_image(renderer, surface, texture_image_plein_ecran, "./images/plein_ecran.png");

    /* Initialisation de l'image du retour en arrière */
    chargement_image(renderer, surface, texture_image_retour_en_arriere, "./images/retour_en_arriere.png");

    /* Initialisation de l'image des options du menu */
    chargement_image(renderer, surface, texture_image_options, "./images/options/options.png");

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

    /* Initialisation du texte dans les items de la demande de sauvegarde */
    sprintf(itemsDemandeSauvegarde[0].texte, " Voulez-vous sauvegarder la partie avant de quitter ? ");
    sprintf(itemsDemandeSauvegarde[1].texte, " Oui ");
    sprintf(itemsDemandeSauvegarde[2].texte, " Non ");

    /* Initialisation du texte dans les items de la demande de quitter le niveau */
    sprintf(itemsDemandeQuitter[0].texte, " Voulez-vous quittez le niveau ? ");
    sprintf(itemsDemandeQuitter[1].texte, " Oui ");
    sprintf(itemsDemandeQuitter[2].texte, " Non ");
}

/* Fonction qui permet de demander à l'utilisateur de sauvegarder */
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

/* Fonction qui permet de demander à l'utilisateur de quitter le niveau */
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

/* Fonction qui permet de récupérer les nouvelles dimensions de la fenêtre pour redimensionner cette dernière et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Vérifie si une sauvegarde existe */
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

/* Fonction qui permet de sauvegarder la partie dans un fichier */
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

/* Fonction qui permet de renvoyer vrai quand on clique sur un rectangle, faux sinon */
int clic_case(SDL_Event event, SDL_Rect rectangle) {

        if((event.button.x >= rectangle.x) &&
           (event.button.x <= rectangle.x + rectangle.w) &&
           (event.button.y >= rectangle.y) &&
           (event.button.y <= rectangle.y + rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))
            return 1;
        
        return 0;
}

/* Fonction qui permet de mettre la fenêtre en plein écran quand on clique sur le bouton plein écran */
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

/* Fonction qui permet de déplacer le personnage dans les différents niveaux */
void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,
                            int sauter, int avancer, int reculer, int tile_map[18][32]) {

    /* Cas où la touche pour sauter est pressée */
    if((!(*saut)) && (!(*tombe)) && (sauter)) {

        (*position_avant_saut) = (*position_y);
        (*saut) = 1;
    }

    /* Cas où la touche pour aller à gauche est pressée */
    if(((!(tile_map[(*position_y)][(*position_x) - 1])) || 
        (tile_map[(*position_y)][(*position_x) - 1] == 3) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 4) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 5) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 7) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 8) ||
        (tile_map[(*position_y)][(*position_x) - 1] == 9) ||
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
        (tile_map[(*position_y)][(*position_x) + 1] == 3) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 4) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 5) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 7) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 8) ||
        (tile_map[(*position_y)][(*position_x) + 1] == 9) ||
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

        if ((tile_map[(*position_y) + 1][(*position_x)] == 1) || (tile_map[(*position_y) + 1][(*position_x)] == 10))
            (*tombe) = 0;

        else {

            (*position_y) += 1;
            SDL_Delay(75);
        }
    }
}

/* Fonction qui permet de gérer le nombre d'FPS à différents moments du jeu */
void SDL_LimitFPS(unsigned int limit) {

    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
}

/* Fonction qui permet de détruire les objets initialisés */
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
                     SDL_Texture **texture49) {

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
    SDL_DestroyTexture((*texture49));
    
    /* Destructions de la police */
    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}