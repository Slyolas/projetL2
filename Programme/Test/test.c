#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Définir les dimensions de la zone cliquable
const int ZONE_X = 100;
const int ZONE_Y = 100;
const int ZONE_WIDTH = 200;
const int ZONE_HEIGHT = 150;

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur d'initialisation SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Créer une fenêtre
    window = SDL_CreateWindow("Clic sur la zone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480, SDL_WINDOW_SHOWN);

    if (!window) {
        fprintf(stderr, "Erreur de création de la fenêtre : %s\n", SDL_GetError());
        return 1;
    }

    // Créer un renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        fprintf(stderr, "Erreur de création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Vérifier si le clic est dans la zone désignée
                if (mouseX >= ZONE_X && mouseX <= ZONE_X + ZONE_WIDTH &&
                    mouseY >= ZONE_Y && mouseY <= ZONE_Y + ZONE_HEIGHT) {
                    printf("Clic dans la zone désignée!\n");
                }
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Dessiner la zone désignée
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_Rect zoneRect = {ZONE_X, ZONE_Y, ZONE_WIDTH, ZONE_HEIGHT};
        SDL_RenderFillRect(renderer, &zoneRect);

        // Mettre à jour l'écran
        SDL_RenderPresent(renderer);
    }

    // Libérer les ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
