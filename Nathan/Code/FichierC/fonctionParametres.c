#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../FichierH/fonctionParametres.h"

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

    (*image_hautParleurActif) = IMG_Load("../../Images/Ecran_Accueil.png");
    if((*image_hautParleurActif) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurActif) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurActif));
    if((*texture_image_hautParleurActif) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurActif));

    (*image_hautParleurDesactive) = IMG_Load("../../Images/plein_ecran.png");
    if((*image_hautParleurDesactive) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hautParleurDesactive) = SDL_CreateTextureFromSurface((*renderer), (*image_hautParleurDesactive));
    if((*texture_image_hautParleurDesactive) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hautParleurDesactive));

    if(((*police) = TTF_OpenFont("../../Police/ChowFun.ttf", 20)) == NULL)
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

        for (i = 0; i < tailleTouches; i += 2) {

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

        for (i = 1; i < tailleTouches; i += 2) {

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

/* Fonction qui permet de détruire les objets initialisés */
void detruire_objets(TTF_Font **police) {

    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}