#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

// Constantes pour les onglets
#define ONGLET_SON 0
#define ONGLET_TOUCHES 1

/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[40];
} itemMenu;

/* Fonction qui affiche un message d'erreur quand une chose n'a pas pû être exécuté */
void erreur(const char *message) {

    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/* Fonction qui permet de créer une fenêtre et le rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) {

    /* Création de la fenêtre */
    (*window) = SDL_CreateWindow("Paramètres du jeu", SDL_WINDOWPOS_CENTERED,
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

/* Fonction qui permet d'initialiser les différents objets */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_hautParleurActif, SDL_Texture **texture_image_hautParleurActif,
                           SDL_Surface **image_hautParleurDesactive, SDL_Texture **texture_image_hautParleurDesactive,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, itemMenu *itemsTouches) {

    (*image_hautParleurActif) = IMG_Load("src/Ecran_Accueil.png");
    if((*image_hautParleurActif) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurActif) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurActif));
    if((*texture_image_hautParleurActif) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurActif));

    (*image_hautParleurDesactive) = IMG_Load("src/plein_ecran.png");
    if((*image_hautParleurDesactive) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurDesactive) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurDesactive));
    if((*texture_image_hautParleurDesactive) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurDesactive));

    if(((*police) = TTF_OpenFont("src/ChowFun.ttf", 20)) == NULL)
        erreur("Chargement de la police");

    /* Initialisation du titre du menu */
    sprintf(titre->texte, " Options ");

    /* Initialisation du texte dans les items du menu */
    sprintf(itemsMenu[0].texte, "           Son           ");
    sprintf(itemsMenu[1].texte, "         Touches         ");

    /* Initialisation du texte dans les items de touches */
    sprintf(itemsTouches[0].texte, " Touche pour aller vers la droite : ");
    sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName(SDLK_RIGHT));
    sprintf(itemsTouches[2].texte, " Touche pour aller vers la gauche : ");
    sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName(SDLK_LEFT));
    sprintf(itemsTouches[4].texte, "        Touche pour sauter :        ");
    sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName(SDLK_UP));
}

/* Fonction qui permet de redimensionner la fenêtre et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Fonction qui met à jour le rendu après redimension de la fenêtre */
void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_hautParleurActif, 
                       SDL_Texture **texture_image_hautParleurDesactive, SDL_bool sonActif,
                       SDL_Rect *rectangle_bouton_son, int ongletActif,
                       itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                       SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int tailleMenu, itemMenu *itemsTouches, int tailleTouches, int largeur, int hauteur) {

    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    if(ongletActif == ONGLET_SON) {
        /* Copie la texture de l'image de plein écran */
        rectangle_bouton_son->x = largeur / 12;
        rectangle_bouton_son->y = hauteur / 2;
        rectangle_bouton_son->w = largeur / 21;
        rectangle_bouton_son->h = hauteur / 12;

        /* Copie la texture de l'image de fond du menu */
        if(sonActif) {
            if(SDL_RenderCopy((*renderer), (*texture_image_hautParleurActif), NULL, rectangle_bouton_son) != 0)
                erreur("Copie de la texture");
        }
        else
            if(SDL_RenderCopy((*renderer), (*texture_image_hautParleurDesactive), NULL, rectangle_bouton_son) != 0)
                erreur("Copie de la texture");
    }
    else {
        rectangle_bouton_son->x = 0;
        rectangle_bouton_son->y = 0;
        rectangle_bouton_son->w = 0;
        rectangle_bouton_son->h = 0;
    }

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    /* Dessine le titre du menu */
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

    if(ongletActif == ONGLET_SON)
        SDL_SetRenderDrawColor((*renderer), 255, 0, 0, 255);
    else
        SDL_SetRenderDrawColor((*renderer), 200, 200, 200, 255);

    /* Dessine les éléments du menu */
    for (i = 0; i < tailleMenu; i++) {

        if((i) && (ongletActif == ONGLET_TOUCHES))
            SDL_SetRenderDrawColor((*renderer), 255, 0, 0, 255);
        else if(i)
            SDL_SetRenderDrawColor((*renderer), 200, 200, 200, 255);

        itemsMenu[i].rectangle.x = i * largeur / 2;
        itemsMenu[i].rectangle.y = hauteur / 10 * 2 + hauteur / 15;
        itemsMenu[i].rectangle.w = largeur / 2;
        itemsMenu[i].rectangle.h = hauteur / 10;

        SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));

        (*texte_menu) = TTF_RenderText_Solid((*police), itemsMenu[i].texte, couleurNoire);
        (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

        SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsMenu[i].rectangle));

        SDL_FreeSurface((*texte_menu));
        SDL_DestroyTexture((*texture_texte_menu));
    }

    if(ongletActif == ONGLET_TOUCHES) {
        /* Dessine les éléments des touches */

        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

        for (i = 0; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 7;
            itemsTouches[i].rectangle.y = hauteur / 2 + i * hauteur / 15;
            itemsTouches[i].rectangle.w = largeur / 2 - largeur / 7;
            itemsTouches[i].rectangle.h = hauteur / 15;

            SDL_RenderFillRect((*renderer), &(itemsTouches[i].rectangle));

            (*texte_menu) = TTF_RenderText_Solid((*police), itemsTouches[i].texte, couleurNoire);
            (*texture_texte_menu) = SDL_CreateTextureFromSurface((*renderer), (*texte_menu));

            SDL_RenderCopy((*renderer), (*texture_texte_menu), NULL, &(itemsTouches[i].rectangle));

            SDL_FreeSurface((*texte_menu));
            SDL_DestroyTexture((*texture_texte_menu));
        }

        SDL_SetRenderDrawColor((*renderer), 200, 200, 200, 255);

        for (i = 1; i < tailleTouches; i+=2) {

            itemsTouches[i].rectangle.x = largeur / 2;
            itemsTouches[i].rectangle.y = hauteur / 2 + (i-1) * hauteur / 15;
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
    else
        for (i = 0; i < tailleTouches; i++) {

            itemsTouches[i].rectangle.x = 0;
            itemsTouches[i].rectangle.y = 0;
            itemsTouches[i].rectangle.w = 0;
            itemsTouches[i].rectangle.h = 0;
        }            

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de ... quand on clique sur une case du menu */
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

/* Fonction qui permet de détruire les objets initialisés */
void detruire_objets(TTF_Font **police) {

    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}

int main(int argc, char **argv) {

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Surface *image_hautParleurActif = NULL;
    SDL_Texture *texture_image_hautParleurActif = NULL;

    SDL_Surface *image_hautParleurDesactive = NULL;
    SDL_Texture *texture_image_hautParleurDesactive = NULL;

    // Rectangle du bouton de son
    SDL_Rect rectangle_bouton_son; 

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_menu = NULL;
    SDL_Texture *texture_texte_menu = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0};

    SDL_Keycode touche_aller_a_droite = SDLK_RIGHT;
    SDL_Keycode touche_aller_a_gauche = SDLK_LEFT;
    SDL_Keycode touche_sauter = SDLK_UP;

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    /*-------------------------------------------------------------*/

    itemMenu titre;

    int tailleMenu = 2;
    itemMenu itemsMenu[tailleMenu];
    
    int tailleTouches = 6;
    itemMenu itemsTouches[tailleTouches];

    initialisation_objets(&renderer, &image_hautParleurActif, &texture_image_hautParleurActif,
                          &image_hautParleurDesactive, &texture_image_hautParleurDesactive,
                          &police, &titre, itemsMenu, itemsTouches);

    // Variable pour suivre l'onglet actif
    int ongletActif = ONGLET_SON;                          

    // Variable pour suivre l'état du son (activé/désactivé)
    SDL_bool sonActif = SDL_TRUE;

    int selection_touche = 0;

    SDL_bool programme_lance = SDL_TRUE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);

                    break;

                case SDL_MOUSEBUTTONUP:
                        if(clic_case(event, itemsMenu[0].rectangle))
                            ongletActif = ONGLET_SON;
                        if(clic_case(event, itemsMenu[1].rectangle))
                            ongletActif = ONGLET_TOUCHES;
                        
                        if((clic_case(event, rectangle_bouton_son)) && (sonActif == SDL_TRUE))
                            sonActif = SDL_FALSE;
                        else if(clic_case(event, rectangle_bouton_son))
                            sonActif = SDL_TRUE;

                        if(clic_case(event, itemsTouches[1].rectangle))
                            selection_touche = 1;
                        else if(clic_case(event, itemsTouches[3].rectangle))
                            selection_touche = 3;
                        else if(clic_case(event, itemsTouches[5].rectangle))
                            selection_touche = 5;
                        else    
                            selection_touche = 0;

                        break;

                case SDL_MOUSEBUTTONDOWN:
                    if(clic_case(event, itemsTouches[1].rectangle))
                        selection_touche = 1;
                    else if(clic_case(event, itemsTouches[3].rectangle))
                        selection_touche = 3;
                    else if(clic_case(event, itemsTouches[5].rectangle))
                        selection_touche = 5;
                    else    
                        selection_touche = 0;
                    break;

                case SDL_KEYDOWN :
                    if((event.key.keysym.sym == SDLK_ESCAPE) && (selection_touche)) {
                        touche_aller_a_droite = SDLK_RIGHT;
                        touche_aller_a_gauche = SDLK_LEFT;
                        touche_sauter = SDLK_UP;
                        sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_droite));
                        sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_gauche));
                        sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName(touche_sauter));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 1) && 
                            (event.key.keysym.sym != touche_aller_a_gauche) &&
                            (event.key.keysym.sym != touche_sauter)) {
                               touche_aller_a_droite = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_droite));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 3) && 
                            (event.key.keysym.sym != touche_aller_a_droite) &&
                            (event.key.keysym.sym != touche_sauter)) {
                               touche_aller_a_gauche = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_gauche));
                        selection_touche = 0;
                    }
                    else if((selection_touche == 5) && 
                            (event.key.keysym.sym != touche_aller_a_droite) &&
                            (event.key.keysym.sym != touche_aller_a_gauche)) {
                               touche_sauter = event.key.keysym.sym; 
                        sprintf(itemsTouches[selection_touche].texte, "                 %s                 ", SDL_GetKeyName(touche_sauter));
                        selection_touche = 0;
                    }

                    break;

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu(&renderer, &texture_image_hautParleurActif,
                                          &texture_image_hautParleurDesactive, sonActif,
                                          &rectangle_bouton_son, ongletActif,
                                          &titre, &texte_menu, &texture_texte_menu, &police,
                                          couleurNoire,
                                          itemsMenu, tailleMenu, itemsTouches, tailleTouches, largeur, hauteur);
    }

    /*-------------------------------------------------------------*/

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}