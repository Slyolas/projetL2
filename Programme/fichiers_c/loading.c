#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

const int LARGEUR = 800;
const int HAUTEUR = 600;
const int LARGEUR_BARRE = 400;
const int HAUTEUR_BARRE = 30;

void rendu_ecran_chargement(SDL_Renderer* renderer, int pourcentage, TTF_Font* font) {

    /* Nettoyer le rendu */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Barre de chargement */
    SDL_Rect rectangle_barre_chargement = { (LARGEUR - LARGEUR_BARRE) / 2, HAUTEUR / 2 - HAUTEUR_BARRE / 2, LARGEUR_BARRE, HAUTEUR_BARRE };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Renderrectangle_remplissage(renderer, &rectangle_barre_chargement);

    int remplissage_largeur = LARGEUR_BARRE * pourcentage / 100;
    SDL_Rect rectangle_remplissage = { (LARGEUR - LARGEUR_BARRE) / 2, HAUTEUR / 2 - HAUTEUR_BARRE / 2, remplissage_largeur, HAUTEUR_BARRE };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Renderrectangle_remplissage(renderer, &rectangle_remplissage);

    /* Texte du pourcentage */
    SDL_Color couleur_police = { 255, 255, 255, 255 };
    char text[20];
    sprintf(text, "Loading... %d%%", pourcentage);
    SDL_Surface* surface_texte = TTF_RenderText_Solid(font, text, couleur_police);
    SDL_Texture* texture_texte = SDL_CreateTextureFromSurface(renderer, surface_texte);
    SDL_Rect rectangle_texte = { (LARGEUR - surface_texte->w) / 2, HAUTEUR / 2 - surface_texte->h - 20, surface_texte->w, surface_texte->h };
    SDL_RenderCopy(renderer, texture_texte, NULL, &rectangle_texte);
    SDL_FreeSurface(surface_texte);
    SDL_DestroyTexture(texture_texte);

}

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    
    /* Initialisation de SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    /* Initialisation de la fenetre */
    window = SDL_CreateWindow("Loading Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR, HAUTEUR, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    /* Initialisation du rendu */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    /* Initialisation de la bibliothèque SDL_ttf */
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    /* Chargement de la police */
    font = TTF_OpenFont("../polices/02587_ARIALMT.ttf", 24);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }

    int quit = 1;
    int pourcentage = 0;

    while (quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 0;
            }
        }

        srand(time(NULL));

        /* Simulation de la progression du chargement */
        pourcentage += rand() % 3;
        if (pourcentage > 100) {
            pourcentage = 0;
        }

        /* Rendu */
        rendu_ecran_chargement(renderer, pourcentage, font);

        /* Mise à jour de l'écran */
        SDL_RenderPresent(renderer);

        /* Ajout d'un delai pour simuler le chargement */
        SDL_Delay(50);
    }

    /* Nettoyage et Quitter */
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
