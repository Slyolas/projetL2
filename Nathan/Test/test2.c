#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Fonction pour afficher la fenêtre des paramètres de commande
void afficherParametresCommandes(SDL_Renderer *renderer) {
    // ... Ajoutez ici le code pour afficher les options de commande (avancer, reculer, sauter)
    // Vous pouvez utiliser SDL_Rect et SDL_RenderFillRect pour créer des boutons ou des cases à cocher
}

// Fonction pour afficher la fenêtre des paramètres de volume
void afficherParametresVolume(SDL_Renderer *renderer) {
    // ... Ajoutez ici le code pour afficher les options de volume
    // Vous pouvez utiliser SDL_Rect et SDL_RenderFillRect pour créer des sliders ou des boutons +/- pour ajuster le volume
}

// Fonction principale des paramètres
void parametre() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur d'initialisation SDL : %s\n", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("Paramètres", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480, SDL_WINDOW_SHOWN);

    if (!window) {
        fprintf(stderr, "Erreur de création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        fprintf(stderr, "Erreur de création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                // Quitter la boucle si la touche Échap est enfoncée
                quit = 1;
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Afficher la fenêtre des paramètres de commande
        afficherParametresCommandes(renderer);

        // Afficher la fenêtre des paramètres de volume
        afficherParametresVolume(renderer);

        // Mettre à jour l'écran
        SDL_RenderPresent(renderer);
    }

    // Libérer les ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    parametre();
    return 0;
}