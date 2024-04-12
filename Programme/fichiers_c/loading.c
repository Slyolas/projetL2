#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BAR_WIDTH = 400;
const int BAR_HEIGHT = 30;
const int SPIN_RADIUS = 20;

void drawLoadingScreen(SDL_Renderer* renderer, int percentage, TTF_Font* font) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the loading bar
    SDL_Rect loadingBarRect = { (SCREEN_WIDTH - BAR_WIDTH) / 2, SCREEN_HEIGHT / 2 - BAR_HEIGHT / 2, BAR_WIDTH, BAR_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &loadingBarRect);

    int fillWidth = BAR_WIDTH * percentage / 100;
    SDL_Rect fillRect = { (SCREEN_WIDTH - BAR_WIDTH) / 2, SCREEN_HEIGHT / 2 - BAR_HEIGHT / 2, fillWidth, BAR_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &fillRect);

    // Draw the percentage text
    SDL_Color textColor = { 255, 255, 255, 255 };
    char text[20];
    sprintf(text, "Loading... %d%%", percentage);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = { (SCREEN_WIDTH - textSurface->w) / 2, SCREEN_HEIGHT / 2 - textSurface->h - 20, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);

}

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Loading Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    // Load font
    font = TTF_OpenFont("../polices/02587_ARIALMT.ttf", 24);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    int quit = 1;
    int percentage = 0;

    while (quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 0;
            }
        }

        srand(time(NULL));

        // Simulate loading progress
        percentage += rand() % 3;
        if (percentage > 100) {
            percentage = 0;
        }

        // Render loading screen
        drawLoadingScreen(renderer, percentage, font);

        // Update screen
        SDL_RenderPresent(renderer);

        // Add delay to simulate loading
        SDL_Delay(50);
    }

    // Cleanup
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
