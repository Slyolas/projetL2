#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

// Fonction pour initialiser SDL et créer la fenêtre
int initSDL() {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Création de la fenêtre
    gWindow = SDL_CreateWindow("Entrez votre pseudo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Création du renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}


// Fonction pour initialiser SDL_ttf
int initSDLTTF() {
    // Initialisation de SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }
    return 1;
}

// Fonction pour charger la police
SDL_Texture* loadFont(const char* text, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    if (texture == NULL) {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);
    return texture;
}

int main() {
    // Initialisation de SDL
    if (!initSDL()) {
        printf("Failed to initialize!\n");
        return 1;
    }

    // Initialisation de SDL_ttf
    if (!initSDLTTF()) {
        printf("Failed to initialize SDL_ttf!\n");
        return 1;
    }

    // Ouverture de la police
    TTF_Font* font = TTF_OpenFont("../../Police/02587_ARIALMT.ttf", 28);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // Couleur du texte
    SDL_Color textColor = {255, 255, 255, 255};

    // Variables pour le pseudo
    char pseudo[12] = " ";
    int inputFinished = 0;

    // Boucle principale
    while (!inputFinished) {

        SDL_Event event;

        // Gestion des événements
        while (SDL_PollEvent(&event)) {

            switch(event.type){
                // Si l'utilisateur ferme la fenêtre
                case SDL_QUIT:
                    inputFinished = 1; // Sort de la boucle
                    break;
                
                // Si l'utilisateur tape quelque chose
                case SDL_TEXTINPUT:
                    // Concatène le texte saisi au pseudo
                    if (strlen(pseudo) + strlen(event.text.text) <= 10) {
                        strcat(pseudo, event.text.text);
                    }
                    break;

                case SDL_KEYDOWN:
                    // Si l'utilisateur appuie sur la touche de retour arrière
                    if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(pseudo) > 1) {
                        pseudo[strlen(pseudo) - 1] = '\0'; // Supprime le dernier caractère du pseudo
                    }
                    // Si l'utilisateur appuie sur la touche Entrée
                    else if (event.key.keysym.sym == SDLK_RETURN) {
                        inputFinished = 1; // Termine la saisie
                    }
                    break;
            }
        }

        // Efface l'écran
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);

        // Affiche le texte "Entrez votre pseudo"
        SDL_Texture* pseudoText = loadFont("Entrez votre pseudo : ", font, textColor);
        SDL_Rect pseudoRect = {20, 20, 0, 0};
        SDL_QueryTexture(pseudoText, NULL, NULL, &pseudoRect.w, &pseudoRect.h);
        SDL_RenderCopy(gRenderer, pseudoText, NULL, &pseudoRect);

        // Affiche le pseudo saisi jusqu'à présent
        SDL_Texture* pseudoInputText = loadFont(pseudo, font, textColor);
        SDL_Rect pseudoInputRect = {pseudoRect.x + pseudoRect.w, 20, 0, 0};
        SDL_QueryTexture(pseudoInputText, NULL, NULL, &pseudoInputRect.w, &pseudoInputRect.h);
        SDL_RenderCopy(gRenderer, pseudoInputText, NULL, &pseudoInputRect);

        // Met à jour l'écran
        SDL_RenderPresent(gRenderer);
    }

    // Affiche le pseudo final
    printf("Votre pseudo est : %s\n", pseudo);

    // Libère la mémoire et quitte SDL
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    TTF_CloseFont(font);
    font = NULL;

    SDL_Quit();
    return 0;
}
