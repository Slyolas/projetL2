#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../FichierH/fonctionIntro.h"

// Fonction pour initialiser SDL et les ressources
void initialisation(SDL_Window **window, SDL_Renderer **renderer, TTF_Font **font, int *largeur, int *hauteur) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        erreur("Erreur lors de l'initialisation de SDL");
    }

    // Initialisation de SDL_ttf
    if (TTF_Init() != 0) {
        SDL_Quit();
        erreur("Erreur lors de l'initialisation de SDL_ttf");
    }

    // Création de la fenêtre
    *window = SDL_CreateWindow("Introduction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, *largeur, *hauteur, SDL_WINDOW_SHOWN);
    if (!*window) {
        SDL_Quit();
        erreur("Erreur lors de la création de la fenêtre");
    }

    // Création du rendu
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!*renderer) {
        SDL_DestroyWindow(*window);
        SDL_Quit();
        erreur("Erreur lors de la création du rendu");
    }

    // Chargement de la police de caractères
    *font = TTF_OpenFont("../../Police/02587_ARIALMT.ttf", *hauteur / 30); 
    if (!*font) {
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        TTF_Quit();
        SDL_Quit();
        erreur("Erreur lors du chargement de la police");
    }

    // Configuration de la couleur de fond
    SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
    SDL_RenderClear(*renderer);
}

// Fonction pour libérer les ressources et quitter SDL
void fermeture(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font) {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    if (font) TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

// Fonction pour afficher le texte "Skip ->" en haut à droite de l'écran
void afficherSkip(SDL_Renderer *renderer, TTF_Font *font, int largeur) {

    SDL_Color couleurBlanche = {255, 255, 255, 255};
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dstRect;

    Uint32 ticks = SDL_GetTicks();
    Uint32 seconds = ticks / TEXT_BLINK_INTERVAL;

    // Texte à afficher
    const char *texte = "Skip ->";

    // Rendu du texte sur une surface
    surface = TTF_RenderUTF8_Blended(font, texte, couleurBlanche);
    if (!surface) {
        fprintf(stderr, "Erreur lors du rendu du texte \"%s\"\n", texte);
        return;
    }

    // Création d'une texture depuis la surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_FreeSurface(surface);
        fprintf(stderr, "Erreur lors de la création de la texture pour le texte \"%s\"\n", texte);
        return;
    }


    if (seconds % 2 == 0){
    
        // Obtention des dimensions de la texture
        int textureWidth, textureHeight;
        SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

        // Positionnement du texte en haut à droite de l'écran
        dstRect.x = largeur - textureWidth - 10; // 10 pixels de marge
        dstRect.y = 10;                           // 10 pixels de marge
        dstRect.w = textureWidth;
        dstRect.h = textureHeight;

        // Affichage de la texture
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    }

    // Libération de la texture et de la surface
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

// Fonction pour gérer l'événement de clic sur le texte "Skip ->"
int gererClicSkip(SDL_Event event, int largeur) {
    
    int flag = 0;
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            // Vérifiez si le clic a eu lieu sur le texte "Skip ->"
            if (event.button.x >= largeur - 10 - 100 && event.button.x <= largeur - 10 &&
                event.button.y >= 10 && event.button.y <= 10 + 50) {
                // Si oui, passez l'intro
                flag = 1;
                printf("Intro Passé\n");
            }
        }
    }
    return flag;
}

// Fonction pour afficher du texte lettre par lettre
void afficherTexte(SDL_Renderer *renderer, TTF_Font *font, const char *texte, int positionX, int positionY) {
    
    SDL_Color couleurBlanche = {255, 255, 255, 255};
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dstRect;

    positionX /= 2;
    positionY /= 2;
    int len = strlen(texte);
    int taillePolice = positionY / 25;

    SDL_Event event;

    font = TTF_OpenFont("../../Police/02587_ARIALMT.ttf", taillePolice); 

    // Effacement du rendu précédent
    SDL_RenderClear(renderer);

    // Boucle pour afficher le texte lettre par lettre
    for (int indice = 0; indice < len; indice++) {

        // Effacement du rendu précédent
        SDL_RenderClear(renderer);

        // Affichage du texte "Skip ->"
        afficherSkip(renderer, font, positionX);

        // Gestion de l'événement de redimensionnement de la fenêtre
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        redimensionnement_fenetre(event, &positionX, &positionY);
                        positionX /= 2;
                        positionY /= 2;
                        taillePolice = positionY / 25;
                        font = TTF_OpenFont("../../Police/02587_ARIALMT.ttf", taillePolice); 
                    }
                    break;
                
                case SDL_MOUSEBUTTONDOWN:
                    // Appui sur le clic gauche de la souris 
                    if(event.button.button == SDL_BUTTON_LEFT){
                        // Fin de la ligne
                        indice = len;
                        // Si clic sur le bouton "Skip" fin de l'intro
                        if(gererClicSkip(event, positionX)) {
                            exit(0);
                        }
                    }
                    break;
            }
        }

        // Création d'une sous-chaîne du texte jusqu'à la lettre actuelle
        char buffer[indice + 2];
        strncpy(buffer, texte, indice);
        buffer[indice] = texte[indice]; // Ajout de la lettre actuelle
        buffer[indice + 1] = '\0'; // Ajout d'un caractère nul pour terminer la chaîne

        // Rendu du texte actuel sur une surface
        surface = TTF_RenderUTF8_Blended(font, buffer, couleurBlanche);
        if (!surface) {
            // Gestion de l'erreur en cas d'échec du rendu
            fprintf(stderr, "Erreur lors du rendu du texte pour la sous-chaîne \"%s\"\n", buffer);
            break; // Sortie de la boucle en cas d'erreur
        }

        // Création d'une texture depuis la surface
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            // Gestion de l'erreur en cas d'échec de création de la texture
            SDL_FreeSurface(surface);
            fprintf(stderr, "Erreur lors de la création de la texture pour la sous-chaîne \"%s\"\n", buffer);
            break; // Sortie de la boucle en cas d'erreur
        }

        // Obtention des dimensions de la texture
        int textureWidth, textureHeight;
        SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

        // Positionnement du texte au centre
        dstRect.x = positionX - textureWidth / 2;
        dstRect.y = positionY - textureHeight / 2;
        dstRect.w = textureWidth;
        dstRect.h = textureHeight;

        // Affichage de la texture
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        // Libération de la texture et de la surface
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);

        // Rafraîchissement de l'affichage
        SDL_RenderPresent(renderer);

        // Délai entre chaque lettre
        SDL_Delay(100);
    }
}

// Fonction pour afficher l'introduction
void afficherIntro(SDL_Renderer *renderer, TTF_Font *font, int largeur, int hauteur) {
    
    // Ouverture du fichier contenant l'introduction
    FILE *fichier = fopen("../../Texte/intro.txt", "r");
    if (!fichier) {
        erreur("Erreur lors de l'ouverture du fichier intro.txt");
    }
    
    int indice;
    char *ligne = NULL;
    size_t longueur = 0;
    ssize_t lecture;

    // Lecture de chaque ligne du fichier
    for (indice = 0; ((lecture = getline(&ligne, &longueur, fichier)) != -1); indice++) {
        
        // Effacement du rendu précédent
        SDL_RenderClear(renderer);

        // Affichage du texte centré
        afficherTexte(renderer, font, ligne, largeur, hauteur);

        // Rafraîchissement de l'affichage
        SDL_RenderPresent(renderer);

        // Délai d'attente avant de passer à la ligne suivante
        SDL_Delay(2000);
    }

    // Libération de la mémoire allouée pour la ligne et fermeture du fichier
    free(ligne);
    fclose(fichier);
}