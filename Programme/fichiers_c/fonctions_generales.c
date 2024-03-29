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
                           SDL_Texture **texture_image_passer, itemMenu *itemsDemandeSauvegarde, TTF_Font **police) {

    /* Initialisation de l'image du plein écran du menu */
    chargement_image(renderer, surface, texture_image_plein_ecran, "./images/plein_ecran.png");

    /* Initialisation de l'image du retour en arrière */
    chargement_image(renderer, surface, texture_image_retour_en_arriere, "./images/retour_en_arriere.png");

    /* Initialisation de l'image des options du menu */
    chargement_image(renderer, surface, texture_image_options, "./images/options.png");

    /* Initialisation de l'image du passer du menu */
    chargement_image(renderer, surface, texture_image_passer, "./images/passer.png");

    /* Initialisation de la police */
    if(((*police) = TTF_OpenFont("./polices/04B_11__.TTF", 20)) == NULL)
        erreur("Chargement de la police");

    /* Initialisation du texte dans les items de la demande de sauvegarde */
    sprintf(itemsDemandeSauvegarde[0].texte, " Voulez-vous sauvegarder la partie avant de quitter ? ");
    sprintf(itemsDemandeSauvegarde[1].texte, " Oui ");
    sprintf(itemsDemandeSauvegarde[2].texte, " Non ");
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

/* Fonction qui permet de sauvegarder la partie */
void sauvegarder_partie(SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
                        SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, barreDeSon *barre_de_son, itemMenu *pseudo,
                        modes_t modeActif, personnage_t personnageActif, position_t positionActive) {

    FILE *fichier_sauvegarde;

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
                    SDL_Texture **texture29, SDL_Texture **texture30) {

    /* Destructions des textures */
    SDL_DestroyTexture((*texture1)); SDL_DestroyTexture((*texture2)); 
    SDL_DestroyTexture((*texture3)); SDL_DestroyTexture((*texture4)); 
    SDL_DestroyTexture((*texture5)); SDL_DestroyTexture((*texture6)); 
    SDL_DestroyTexture((*texture7)); SDL_DestroyTexture((*texture8)); 
    SDL_DestroyTexture((*texture9)); SDL_DestroyTexture((*texture10)); 
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
    
    /* Destructions de la police */
    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}