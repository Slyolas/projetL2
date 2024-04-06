#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

// Define window dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Define tile dimensions
#define TILE_SIZE_X SCREEN_WIDTH / 32
#define TILE_SIZE_Y SCREEN_HEIGHT / 24

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Function to load an image into a texture
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        printf("Failed to load image: %s\n", filePath);
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Function to process user commands
void processCommand(int* playerX, int* playerY, int* blockX, int* blockY, int tilemap[24][32], int direction) {

    // Check if the player is next to the block
    if ((*playerX == *blockX - 1 && *playerY == *blockY) ||   // Player is to the left of the block
        (*playerX == *blockX + 1 && *playerY == *blockY) ||   // Player is to the right of the block
        (*playerX == *blockX && *playerY == *blockY - 1) ||   // Player is above the block
        (*playerX == *blockX && *playerY == *blockY + 1)) {   // Player is below the block

        // Le personnage est au dessus du bloc
        if (*playerX == *blockX && *playerY == *blockY - 1) { 
            // On veut pousser le bloc
            if(direction == 1){
                // On regarde si on peut pousser le bloc sur la case suivante
                if (tilemap[*blockY + 1][*blockX] == 0) {
                    (*blockY)++;
                    (*playerY)++;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 0){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY - 1][*playerX] == 0) {
                    (*playerY)--;
                    (*blockY)--;
                    SDL_Delay(200);
                }
            }
        
        // Le personnage est en dessous du bloc
        } else if (*playerX == *blockX && *playerY == *blockY + 1) {
            // On veut pousser le bloc
            if(direction == 0){
                // On regarde si on peut pousser le bloc sur la case suivante
                if (tilemap[*blockY - 1][*blockX] == 0) {
                    (*blockY)--;
                    (*playerY)--;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 1){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY + 1][*playerX] == 0) {
                    (*playerY)++;
                    (*blockY)++;
                    SDL_Delay(200);
                }
            }

        // Le personnage est à gauche du bloc
        } else if (*playerX == *blockX - 1 && *playerY == *blockY) {  
            // On veut pousser le bloc
            if(direction == 3){
                // On regarde si on peut pousser le bloc sur la case suivante
                if (tilemap[*blockY][*blockX + 1] == 0) {
                    (*blockX)++;
                    (*playerX)++;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 2){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY][*playerX - 1] == 0) {
                    (*playerX)--;
                    (*blockX)--;
                    SDL_Delay(200);
                }
            }

        // Le personnage est à droite du bloc
        } else if (*playerX == *blockX + 1 && *playerY == *blockY) {
            // On veut pousser le bloc
            if(direction == 2){
                // On regarde si on peut pousser le bloc sur la case suivante
                if (tilemap[*blockY][*blockX - 1] == 0) {
                    (*blockX)--;
                    (*playerX)--;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 3){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY][*playerX + 1] == 0) {
                    (*playerX)++;
                    (*blockX)++;
                    SDL_Delay(200);
                }
            }
        }
    }
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* wallTexture;
    SDL_Texture* floorTexture;
    SDL_Texture* borderTexture;
    SDL_Texture* playerTexture;
    SDL_Texture* blockTexture;

    SDL_Event event;
    int tilemap[24][32] = { /* 24*32 max avec ces dimensions */
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 2},
        {2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2},
        {2, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},
        {2, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 2},
        {2, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 2},
        {2, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 2},
        {2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 2},
        {2, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2},
        {2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 2},
        {2, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2},
        {2, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 2},
        {2, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 2},
        {2, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}        
        
    };

    // Position initiale du joueur en coordonnées de tuile
    int playerX = 1;
    int playerY = 1;
    // Position initiale du block en coordonnées de tuile
    int blockX = 2;
    int blockY = 1;

    int up = 0, down = 0, left = 0, right = 0, e = 0;

    int quit = 0;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Tilemap Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load tile textures
    wallTexture = loadTexture(renderer, "../images/mur.png");
    floorTexture = loadTexture(renderer, "../images/sol.png");
    borderTexture = loadTexture(renderer, "../images/obsi.png");
    playerTexture = loadTexture(renderer, "../images/steve.png");
    blockTexture = loadTexture(renderer, "../images/diamand.png");
    if (!wallTexture || !floorTexture || !borderTexture || !playerTexture || !blockTexture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop
    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_UP){
                        up = 1;
                    }
                    if(event.key.keysym.sym == SDLK_DOWN){
                        down = 1;
                    }
                    if(event.key.keysym.sym == SDLK_LEFT){
                        left = 1;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        right = 1;
                    }
                    if(event.key.keysym.sym == SDLK_e){
                        e = 1;
                    }

                    break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_UP){
                        up = 0;
                    }
                    if(event.key.keysym.sym == SDLK_DOWN){
                        down = 0;
                    }
                    if(event.key.keysym.sym == SDLK_LEFT){
                        left = 0;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        right = 0;
                    }
                    if(event.key.keysym.sym == SDLK_e){
                        e = 0;
                    }
                    
                    break;
                default:
                    break;
            }
        }
        if(up){
            if(e){
                processCommand(&playerX, &playerY, &blockX, &blockY, tilemap, UP);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if (tilemap[playerY - 1][playerX] == 0 && !(playerX == blockX && playerY == blockY + 1)) {
                playerY--;
                SDL_Delay(200);
            }
        }
        if(down){
            if(e){
                processCommand(&playerX, &playerY, &blockX, &blockY, tilemap, DOWN);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if (tilemap[playerY + 1][playerX] == 0 && !(playerX == blockX && playerY == blockY - 1)) {
                playerY++;
                SDL_Delay(200);
            }
        }
        if(left){
            if(e){
                processCommand(&playerX, &playerY, &blockX, &blockY, tilemap, LEFT);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if (tilemap[playerY][playerX - 1] == 0 && !(playerX == blockX + 1 && playerY == blockY)) {
                playerX--;
                SDL_Delay(200);
            }
        }
        if(right){
            if(e){
                processCommand(&playerX, &playerY, &blockX, &blockY, tilemap, RIGHT);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if (tilemap[playerY][playerX + 1] == 0 && !(playerX == blockX - 1 && playerY == blockY)) {
                playerX++;
                SDL_Delay(200);
            }
        }

        // Clear renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render tilemap
        for (int y = 0; y < 24; ++y) {
            for (int x = 0; x < 32; ++x) {
                int tileType = tilemap[y][x];
                SDL_Texture* texture = NULL;
                if(tileType == 1){
                    texture = wallTexture;
                }
                else if(tileType == 0){
                    texture = floorTexture;
                }
                else if(tileType == 2){
                    texture = borderTexture;
                }
                if(texture){
                    SDL_Rect dstRect = {x * TILE_SIZE_X, y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
                    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                }
            }
        }

        // Render block
        SDL_Rect blockRect = {blockX * TILE_SIZE_X, blockY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, blockTexture, NULL, &blockRect);

        // Render player
        SDL_Rect playerRect = {playerX * TILE_SIZE_X, playerY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

        // Render to screen
        SDL_RenderPresent(renderer);


        if(blockX == 30 && blockY == 22){
            printf("Oui\n");
            quit = 1;
        }
    }

    // Clean up
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(floorTexture);
    SDL_DestroyTexture(borderTexture);
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(blockTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
