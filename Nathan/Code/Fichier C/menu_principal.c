#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[20];
} itemMenu;

/* Fonction qui affiche un message d'erreur quand une chose n'a pas pû être exécuté */
void erreur(const char *message) {

    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/* Vérifie si une sauvegarde existe */
int verification_sauvegarde() {
    
    FILE *fichier_sauvegarde;

    /* Ouverture du fichier en mode lecture */
    fichier_sauvegarde = fopen("src/sauvegarde.txt", "r");

    /* Vérifie si le fichier existe */
    if (fichier_sauvegarde == NULL)
        return 0;

    /* Fermeture du fichier */
    if (fclose(fichier_sauvegarde) != 0)
        erreur("Fermeture du fichier");

    return 1;
}

/* Fonction qui permet d'initialiser les différents objets */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_menu, SDL_Texture **texture_image_menu,
                           SDL_Surface **image_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, int tailleMenu) {

    /* Initialisation de l'image de fond du menu */
    (*image_menu) = IMG_Load("src/Ecran_Accueil.png");
    if((*image_menu) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_menu) = SDL_CreateTextureFromSurface((*renderer), (*image_menu));
    if((*texture_image_menu) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_menu));

    /* Initialisation de l'image du plein écran du menu */
    (*image_plein_ecran) = IMG_Load("src/plein_ecran.png");
    if((*image_plein_ecran) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_plein_ecran) = SDL_CreateTextureFromSurface((*renderer), (*image_plein_ecran));
    if((*texture_image_plein_ecran) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_plein_ecran));

    /* Initialisation de la police */
    if(((*police) = TTF_OpenFont("src/04B_11__.TTF", 20)) == NULL)
        erreur("Chargement de la police");

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
            sprintf(itemsMenu[i].texte, " Continuer ");
        else if(i == 1)
            sprintf(itemsMenu[i].texte, " Nouvelle Partie ");
        else
            sprintf(itemsMenu[i].texte, " Options ");
        }
    }
}

/* Fonction qui permet de redimensionner la fenêtre et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Fonction qui met à jour le rendu après redimension de la fenêtre */
void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_menu,
                       SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                       itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                       SDL_Color couleurTitre, SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur) {
    
    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de fond du menu */
    if(SDL_RenderCopy((*renderer), (*texture_image_menu), NULL, NULL) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */
    rectangle_plein_ecran->x = largeur - largeur / 21;
    rectangle_plein_ecran->y = 0;
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

    SDL_RenderFillRect((*renderer), &(titre->rectangle));

    (*texte_menu) = TTF_RenderText_Solid((*police), titre->texte, couleurTitre);
    (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

    SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(titre->rectangle));

    SDL_FreeSurface((*texte_menu));
    SDL_DestroyTexture((*texture_texte_menu));

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    /* Dessine les éléments du menu */
    if(tailleMenu == 2) {
        for (int i = 0; i < tailleMenu; i++) {

            itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6;
            itemsMenu[i].rectangle.y = hauteur / 3 + (i+1) * hauteur / 13 + i * hauteur / 11;
            itemsMenu[i].rectangle.w = largeur / 3;
            itemsMenu[i].rectangle.h = hauteur / 10;

            SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsMenu[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsMenu[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }
    }
    else {
        for (int i = 0; i < tailleMenu; i++) {

            itemsMenu[i].rectangle.x = largeur / 2 - largeur / 6;
            itemsMenu[i].rectangle.y = hauteur / 3 + i * hauteur / 6;
            itemsMenu[i].rectangle.w = largeur / 3;
            itemsMenu[i].rectangle.h = hauteur / 10;

            SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsMenu[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsMenu[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }
    }

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de ... quand on clique sur une case du menu */
void clic_case(SDL_Event event, itemMenu *itemsMenu, int numero_case, int tailleMenu) {

    if(tailleMenu == 2) {

        if((event.button.x >= itemsMenu[numero_case].rectangle.x) &&
           (event.button.x <= itemsMenu[numero_case].rectangle.x + itemsMenu[numero_case].rectangle.w) &&
           (event.button.y >= itemsMenu[numero_case].rectangle.y) &&
           (event.button.y <= itemsMenu[numero_case].rectangle.y + itemsMenu[numero_case].rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))

        if(!numero_case)
            printf("Vous avez fait clic gauche sur 'Nouvelle Partie' !\n");
        else
            printf("Vous avez fait clic gauche sur 'Options' !\n");
    }
    else {

        if((event.button.x >= itemsMenu[numero_case].rectangle.x) &&
           (event.button.x <= itemsMenu[numero_case].rectangle.x + itemsMenu[numero_case].rectangle.w) &&
           (event.button.y >= itemsMenu[numero_case].rectangle.y) &&
           (event.button.y <= itemsMenu[numero_case].rectangle.y + itemsMenu[numero_case].rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))

        if(!numero_case)
            printf("Vous avez fait clic gauche sur 'Continuer' !\n");
        else if(numero_case == 1)
            printf("Vous avez fait clic gauche sur 'Nouvelle Partie' !\n");
        else
            printf("Vous avez fait clic gauche sur 'Options' !\n");
    }
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