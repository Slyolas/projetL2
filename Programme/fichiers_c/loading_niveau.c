#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>

const int LARGEUR = 800;
const int HAUTEUR = 600;

void rendu_ecran_chargement(SDL_Renderer* renderer, SDL_Texture* sprites[], int sprite_count, int current_sprite_index) {
    /* Nettoyer le rendu */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Afficher le sprite actuel */
    SDL_Rect dest_rect = { (LARGEUR - 100) / 2, (HAUTEUR - 100) / 2, 100, 100 };
    SDL_RenderCopy(renderer, sprites[current_sprite_index], NULL, &dest_rect);

    /* Mise à jour de l'écran */
    SDL_RenderPresent(renderer);
}

/* Fonction qui permet de charger une image */
SDL_Texture* charger_texture(const char* fichier_image, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(fichier_image);
    if (!surface) {
        printf("Failed to load image: %s\n", fichier_image);
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

int main() {
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

    /* Charger les sprites */
    SDL_Texture* sprites[3];
    sprites[0] = charger_texture("../images/personnages/personnage_masculin_droit_NB.png", renderer);
    sprites[1] = charger_texture("../images/personnages/personnage_masculin_bas_droit_1_NB.png", renderer);
    sprites[2] = charger_texture("../images/personnages/personnage_masculin_bas_droit_2_NB.png", renderer);

    if (!sprites[0] || !sprites[1] || !sprites[2]) {
        printf("Erreur lors du chargement des sprites!\n");
        return 1;
    }

    int quit = 1;
    int current_sprite_index = 0;

    while (quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 0;
            }
        }

        /* Rendu */
        rendu_ecran_chargement(renderer, sprites, 3, current_sprite_index);

        /* Mise à jour de l'écran */
        SDL_RenderPresent(renderer);

        /* Ajout d'un délai pour simuler le chargement */
        SDL_Delay(500); // Temps d'affichage de chaque sprite en millisecondes

        /* Passer au sprite suivant */
        current_sprite_index++;
        if (current_sprite_index >= 3) {
            current_sprite_index = 0; // Revenir au premier sprite si tous les sprites ont été affichés
        }
    }

    /* Nettoyage et Quitter */
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    /* Libérer les textures des sprites */
    for (int i = 0; i < 3; i++) {
        SDL_DestroyTexture(sprites[i]);
    }

    return 0;
}
