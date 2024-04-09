#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

// Dimensions de la fenêtre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Dimensions des tiles
#define TILE_SIZE_X SCREEN_WIDTH / 32
#define TILE_SIZE_Y SCREEN_HEIGHT / 24

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Fonction pour charger une image dans une texture
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

// Fonction pour traiter les commandes utilisateur
void traitementTouches(int* playerX, int* playerY, int* blockX, int* blockY, int tilemap[24][32], int direction) {

    // Vérification si le joueur est à côté du bloc
    if ((*playerX == *blockX - 1 && *playerY == *blockY) ||   // Le joueur est à gauche du bloc
        (*playerX == *blockX + 1 && *playerY == *blockY) ||   // Le joueur est à droite du bloc
        (*playerX == *blockX && *playerY == *blockY - 1) ||   // Le joueur est au dessus du bloc
        (*playerX == *blockX && *playerY == *blockY + 1)) {   // Le joueur est en dessous du bloc

        // Le personnage est au dessus du bloc
        if (*playerX == *blockX && *playerY == *blockY - 1) { 
            // On veut pousser le bloc
            if(direction == 1){
                // On regarde si on peut pousser le bloc sur la case suivante
                if (tilemap[*blockY + 1][*blockX] == 0 || tilemap[*blockY + 1][*blockX] == 3) {
                    (*blockY)++;
                    (*playerY)++;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 0){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY - 1][*playerX] == 0 || tilemap[*playerY - 1][*playerX] == 3) {
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
                if (tilemap[*blockY - 1][*blockX] == 0 || tilemap[*blockY - 1][*blockX] == 3) {
                    (*blockY)--;
                    (*playerY)--;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 1){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY + 1][*playerX] == 0 || tilemap[*playerY + 1][*playerX] == 3) {
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
                if (tilemap[*blockY][*blockX + 1] == 0 || tilemap[*blockY][*blockX + 1] == 3) {
                    (*blockX)++;
                    (*playerX)++;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 2){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY][*playerX - 1] == 0 || tilemap[*playerY][*playerX - 1] == 3) {
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
                if (tilemap[*blockY][*blockX - 1] == 0 || tilemap[*blockY][*blockX - 1] == 3) {
                    (*blockX)--;
                    (*playerX)--;
                    SDL_Delay(200);
                }
            }
            // On veut tirer le bloc
            if(direction == 3){
                // On regarde si le personnage peut être sur la case de derrière
                if (tilemap[*playerY][*playerX + 1] == 0 || tilemap[*playerY][*playerX + 1] == 3) {
                    (*playerX)++;
                    (*blockX)++;
                    SDL_Delay(200);
                }
            }
        }
    }
}

// Fonction pour mettre à jour les tuiles de bordure lorsque le bloc atteint la fin du labyrinthe
int updateBorderTiles(SDL_Renderer* renderer, SDL_Texture* finishTexture, int tilemap[24][32], int tileX, int tileY) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[tileY][tileX] = 3;
    SDL_Rect dstRect = {tileX * TILE_SIZE_X, tileY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
    SDL_RenderCopy(renderer, finishTexture, NULL, &dstRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à droite de la courante */
    if(tilemap[tileY][tileX + 1] == 2 && tileX < 31) {
        return updateBorderTiles(renderer, finishTexture, tilemap, tileX + 1, tileY);
    }
    /* Tuile à gauche de la courante */
    else if(tilemap[tileY][tileX - 1] == 2 && tileX > 0){
        return updateBorderTiles(renderer, finishTexture, tilemap, tileX - 1, tileY);
    }
    /* Tuile en dessous de la courante */
    else if(tilemap[tileY + 1][tileX] == 2 && tileY < 31){
        return updateBorderTiles(renderer, finishTexture, tilemap, tileX, tileY + 1);
    }
    /* Tuile au dessus de la courante */
    else if(tilemap[tileY - 1][tileX] == 2 && tileY > 0){
        return updateBorderTiles(renderer, finishTexture, tilemap, tileX, tileY - 1);
    }
    
	return 0;
}

int main() {

    // Déclaration
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* wallTexture;
    SDL_Texture* floorTexture;
    SDL_Texture* borderTexture;
    SDL_Texture* playerTexture;
    SDL_Texture* blockTexture;
    SDL_Texture* finishTexture;

    SDL_Event event;

    // Initialisation de la carte du labyrinthe
    // 0 : sol, 1 : mur, 2 : bordure, 3 : tuile de fin
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
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 4, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2},
        {2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 2},
        {2, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 2},
        {2, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2},
        {2, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 2},
        {2, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2},
        {2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 2},
        {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 2},
        {2, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 3, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}        
        
    };

    // Position initiale du joueur en coordonnées de tuile
    int playerX = 1;
    int playerY = 1;
    // Position initiale du block à deplacer en coordonnées de tuile
    int blockX = 2;
    int blockY = 1;
    // Position du block d'arriver en coordonnées de tuile
    int finishX = 30;
    int finishY = 22;

    int up = 0, down = 0, left = 0, right = 0, e = 0;

    int quit = 0;

    // Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("Tilemap Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Chargement des textures des tuiles
    wallTexture = loadTexture(renderer, "../images/labyrinthe/mur.png");
    floorTexture = loadTexture(renderer, "../images/labyrinthe/sol.png");
    borderTexture = loadTexture(renderer, "../images/labyrinthe/obsi.png");
    playerTexture = loadTexture(renderer, "../images/labyrinthe/steve.png");
    blockTexture = loadTexture(renderer, "../images/labyrinthe/diamand.png");
    finishTexture = loadTexture(renderer, "../images/labyrinthe/emerald.png");
    if (!wallTexture || !floorTexture || !borderTexture || !playerTexture || !blockTexture || !finishTexture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Boucle principale
    while (!quit) {
        // Gestion des événements
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT:
                    quit = 1;
                    break;
                
                /* 
                    On peut pas traiter l'appui de 2 touches en même temps donc 
                    On stocke une valeur pour permettre l'appuie de 2 touches en même 
                    Et ainsi pouvoir traiter cette information 
                */
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
        /* Traitement de l'appuie des touches */
        if(up){
            if(e){
                traitementTouches(&playerX, &playerY, &blockX, &blockY, tilemap, UP);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if ((tilemap[playerY - 1][playerX] == 0 || tilemap[playerY - 1][playerX] == 3 || tilemap[playerY - 1][playerX] == 4) && !(playerX == blockX && playerY == blockY + 1)) {
                playerY--;
                SDL_Delay(200);
            }
        }
        if(down){
            if(e){
                traitementTouches(&playerX, &playerY, &blockX, &blockY, tilemap, DOWN);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if ((tilemap[playerY + 1][playerX] == 0 || tilemap[playerY + 1][playerX] == 3 || tilemap[playerY + 1][playerX] == 4) && !(playerX == blockX && playerY == blockY - 1)) {
                playerY++;
                SDL_Delay(200);
            }
        }
        if(left){
            if(e){
                traitementTouches(&playerX, &playerY, &blockX, &blockY, tilemap, LEFT);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if ((tilemap[playerY][playerX - 1] == 0 || tilemap[playerY][playerX - 1] == 3 || tilemap[playerY][playerX - 1] == 4) && !(playerX == blockX + 1 && playerY == blockY)) {
                playerX--;
                SDL_Delay(200);
            }
        }
        if(right){
            if(e){
                traitementTouches(&playerX, &playerY, &blockX, &blockY, tilemap, RIGHT);
            }
            // On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc
            else if ((tilemap[playerY][playerX + 1] == 0 || tilemap[playerY][playerX + 1] == 3 || tilemap[playerY][playerX + 1] == 4) && !(playerX == blockX - 1 && playerY == blockY)) {
                playerX++;
                SDL_Delay(200);
            }
        }

        // Nettoyer le renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Rendu tilemap
        // Mode Normal
        if(modeActif == MODE_NORMAL){
            for (int y = 0; y < 24; ++y) {
                for (int x = 0; x < 32; ++x) {
                    // Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe
                    if (x >= 0 && x < 32 && y >= 0 && y < 24) { 
                        // Rendu de chaque tuile en fonction de son type
                        int tileType = tilemap[y][x];
                        SDL_Texture* texture = NULL;
                        if(tileType == 0){
                            texture = floorTexture;
                        }
                        else if(tileType == 1){
                            texture = wallTexture;
                        }
                        else if(tileType == 2){
                            texture = borderTexture;
                        }
                        else if(tileType == 3){
                            texture = finishTexture;
                        }
                        else if(tileType == 4){
                            texture = wallTexture;
                        }
                        if(texture){
                            SDL_Rect dstRect = {x * TILE_SIZE_X, y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
                            SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                        }
                    }
                }
            }
        }
        // Mode Difficile
        if(modeActif == MODE_HARD){
            for (int y = playerY - 2; y <= playerY + 2; ++y) {
                for (int x = playerX - 2; x <= playerX + 2; ++x) {
                    // Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe
                    if (x >= 0 && x < 32 && y >= 0 && y < 24) { 
                        // Rendu de chaque tuile en fonction de son type
                        int tileType = tilemap[y][x];
                        SDL_Texture* texture = NULL;
                        if(tileType == 0){
                            texture = floorTexture;
                        }
                        else if(tileType == 1){
                            texture = wallTexture;
                        }
                        else if(tileType == 2){
                            texture = borderTexture;
                        }
                        else if(tileType == 3){
                            texture = finishTexture;
                        }
                        else if(tileType == 4){
                            texture = wallTexture;
                        }
                        if(texture){
                            SDL_Rect dstRect = {x * TILE_SIZE_X, y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
                            SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                        }
                    }
                }
            }
        }

        /* Passage secret vers un collectible */
        if(playerX == 12 && playerY == 11 && tilemap[playerY][playerX] == 4){
            SDL_Texture* texture = NULL;

            tilemap[11][12] = 0;
            texture = floorTexture;
            SDL_Rect dstRect1 = {12 * TILE_SIZE_X, 11 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect1);

            tilemap[12][12] = 0;
            SDL_Rect dstRect2 = {12 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect2);

            tilemap[12][13] = 0;
            SDL_Rect dstRect3 = {13 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect3);
        }

        /* Remise à l'état initial */
        if(playerX == 12 && playerY == 10 && tilemap[11][12] == 0){
            SDL_Texture* texture = NULL;

            tilemap[11][12] = 4;
            texture = floorTexture;
            SDL_Rect dstRect1 = {12 * TILE_SIZE_X, 11 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect1);

            tilemap[12][12] = 4;
            SDL_Rect dstRect2 = {12 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect2);

            tilemap[12][13] = 4;
            SDL_Rect dstRect3 = {13 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect3);
            
        }

        // Rendu du bloc à deplacer
        SDL_Rect blockRect = {blockX * TILE_SIZE_X, blockY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, blockTexture, NULL, &blockRect);

        // Rendu du bloc d'arriver
        SDL_Rect finishRect = {finishX * TILE_SIZE_X, finishY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, finishTexture, NULL, &finishRect);

        // Rendu du joueur
        SDL_Rect playerRect = {playerX * TILE_SIZE_X, playerY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);


        // Vérifier si le bloc atteint la fin du labyrinthe et mettre à jour les tuiles de bordure si nécessaire
        if(blockX == 30 && blockY == 22){
            updateBorderTiles(renderer, finishTexture, tilemap, 31, 23);
            printf("Oui\n");
            quit = 1;
        }

        // Actualiser le renderer
        SDL_RenderPresent(renderer);
    }

    // Nettoyer et quitter
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(floorTexture);
    SDL_DestroyTexture(borderTexture);
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(blockTexture);
    SDL_DestroyTexture(finishTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
