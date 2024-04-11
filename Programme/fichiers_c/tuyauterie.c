#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

// Dimensions de la fenêtre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Dimensions des tiles
#define TILE_SIZE_X SCREEN_WIDTH / 27
#define TILE_SIZE_Y SCREEN_HEIGHT / 19


// Coordonnées de début et de fin du chemin
#define START_CARRE_1_X 2
#define START_CARRE_1_Y 0

#define START_CARRE_2_X 11
#define START_CARRE_2_Y 9

#define START_CARRE_3_X 13
#define START_CARRE_3_Y 16

#define START_CARRE_4_X 23
#define START_CARRE_4_Y 9

#define END_X 24
#define END_Y 0

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

// Fonction de vérification du chemin
int checkPath(int x, int y, int prevX, int prevY, int tilemap[19][27], int arriveX, int arriveY) {

    // Vérifier si les coordonnées actuelles correspondent aux coordonnées de fin
    if (x == arriveX && y == arriveY) {
        return 1;
    }

    // Vérifier si le tuyau actuel est correctement aligné avec le précédent

    switch (tilemap[y][x]) {

        case 1: // Tuyau vertical
            /* On vient du dessus */
            if (prevY == y - 1){
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) ; /* On va en bas */
                }
            } 
            /* On vient d'en dessous */
            else {
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en haut */
                }
            }
            break;

        case 2: // Tuyau horizontal
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            /* On vient de la droite */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            break;

        case 3: // Tuyau HD
            /* On vient du dessus */
            if (prevY == y - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            /* On vient de la droite */
            else{
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en haut */
                }
            }
            break;

        case 4: // Tuyau BD
            /* On vient de la droite */
            if (prevX == x + 1) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY); /* On va en bas */
                }
            }
            /* On vient du bas */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            break;

        case 5: // Tuyau BG
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY); /* On va en bas */
                }
            }
            /* On vient du bas */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            break;

        case 6: // Tuyau HG
            /* On vient du haut */
            if (prevY == y - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            /* On vient de la gauche */
            else{
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va au haut */
                }
            }
            break;

        case 7: // Tuyau croix
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6)){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va à droite ou en bas ou en haut */
                }
            }
            /* On vient du bas */
            else if (prevY == y + 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6)){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va à droite ou à gauche ou en haut */
                }
            }
            /* On vient de la droite */
            else if(prevX == x + 1){
                if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6)){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) || checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en bas ou à gauche ou en haut */
                }
            }
            /* On vient du haut  */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6)){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) || checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va en bas ou à gauche ou à droite */
                }
            }
            break;
        
        default:
            return 0;
            break;
    }
    return 0;
}

// Fonction pour mettre à jour les tuiles de bordure lorsque le bloc atteint la fin du labyrinthe
int updateBorderTiles(SDL_Renderer* renderer, SDL_Texture* finish_Texture, int tilemap[19][27], int tileX, int tileY, int finX, int finY) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[tileY][tileX] = 9;
    SDL_Rect dstRect = {tileX * TILE_SIZE_X, tileY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
    SDL_RenderCopy(renderer, finish_Texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à gauche de la courante */
    if(tilemap[tileY][tileX - 1] == 0 && tileX > finX && tileY == 0) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX - 1, tileY, finX, finY);
    }
    else if((tilemap[tileY][tileX - 1] == 8 || tilemap[tileY][tileX - 1] == 1) && tileX > finX && tileY == 0){
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX - 2, tileY, finX, finY);
    }
    /* Tuile à droite de la courante */
    else if(tilemap[tileY][tileX + 1] == 0 && tileX < finX && tileY == 18) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX + 1, tileY, finX, finY);
    }
    /* Tuile en bas de la courante */
    else if(tilemap[tileY + 1][tileX] == 0 && tileY < finY && tileX == 0) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX, tileY + 1, finX, finY);
    }
    /* Tuile en haut de la courante */
    else if(tilemap[tileY - 1][tileX] == 0 && tileY > finY && tileX == 26) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX, tileY - 1, finX, finY);
    }
    
	return 0;
}

int main() {

    // Déclaration
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* wallTexture;
    SDL_Texture* pipe_verti_Texture;
    SDL_Texture* pipe_hori_Texture;
    SDL_Texture* pipe_HD_Texture;
    SDL_Texture* pipe_BD_Texture;
    SDL_Texture* pipe_BG_Texture;
    SDL_Texture* pipe_HG_Texture;
    SDL_Texture* pipe_croix_Texture;
    SDL_Texture* pipe_courant_Texture;
    SDL_Texture* finish_Texture;
    SDL_Texture* copper_Texture;

    SDL_Event event;

    // Initialisation de la carte du labyrinthe
    int tilemap[19][27] = {

        {0,     0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,      0},

        {0,     4, 4, 6, 5, 2, 4, 3, 5, 4, 1, 2, 5,    0,    4, 6, 2, 6, 3, 4, 6, 4, 6, 2, 4, 0,      0},
        {0,     2, 3, 4, 5, 4, 1, 4, 4, 2, 0, 5, 4,    0,    1, 5, 4, 1, 6, 4, 2, 6, 2, 1, 0, 0,      0},
        {0,     1, 4, 2, 6, 1, 5, 4, 7, 3, 2, 3, 6,    0,    4, 5, 0, 6, 7, 5, 1, 3, 4, 6, 5, 0,      0},
        {0,     7, 6, 3, 4, 5, 0, 0, 3, 1, 3, 6, 5,    0,    5, 6, 0, 6, 2, 3, 5, 2, 3, 0, 1, 4,      0},
        {0,     3, 5, 1, 4, 4, 5, 0, 6, 2, 0, 0, 1,    0,    1, 4, 7, 3 ,6, 0, 5, 3, 4, 0, 4, 6,      0},
        {0,     4, 2, 3, 1, 6, 1, 3, 4, 6, 6, 1, 6,    0,    6, 2, 1, 4, 4, 1, 3, 4, 1, 0, 0, 1,      0},
        {0,     0, 6, 3, 5, 4, 4, 3, 2, 6, 6, 2, 2,    0,    5, 3, 6, 2, 3, 4, 6, 5, 7, 2, 5, 4,      0},
        {0,     0, 0, 5, 2, 1, 3, 1, 1, 4, 0, 6, 6,    0,    4, 3, 0, 0, 4, 2 ,3, 6, 4, 5, 1, 3,      0},

        {0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,    0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,      0},

        {0,     4, 2, 1, 3, 4, 5, 4, 3, 3, 1, 7, 3,    0,    4, 6, 3, 2, 6, 4, 5, 3, 0, 4, 2, 4,      0},
        {0,     6, 1, 0, 4, 1, 5, 3, 2, 4, 6, 2, 1,    0,    2, 5, 0, 3, 2, 6, 5, 4, 0, 5, 1, 3,      0},
        {0,     4, 4, 0, 6, 7, 3, 5, 6, 2, 3, 6, 6,    0,    5, 1, 0, 6, 7, 3, 2, 4, 3, 6, 5, 4,      0},
        {0,     6, 5, 3, 1, 2, 4, 3, 4, 5, 6, 0, 0,    0,    3, 4, 6, 0, 2, 3, 4, 3, 2, 4, 2, 6,      0},
        {0,     4, 7, 2, 0, 0, 1, 6, 4, 3, 1, 5, 4,    0,    4, 6, 1, 6, 0, 0, 0, 1, 7, 6, 0, 2,      0},
        {0,     5, 6, 0, 5, 4, 3, 1, 3, 3, 3, 0, 4,    0,    5, 4, 6, 7, 1, 0, 3, 4, 2, 1, 0, 1,      0},
        {0,     5, 4, 1, 2, 6, 5, 6, 2, 4, 5, 2, 1,    2,    4, 3, 1, 4, 3, 6, 2, 1, 5, 4, 6, 4,      0},
        {0,     5, 3, 5, 2, 1, 6, 1, 3, 5, 6, 3, 0,    0,    6, 5, 3, 5, 1, 3, 4, 3, 5, 4, 1, 3,      0},

        {0,     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0}
        
    };

    int cursorX = 0;
    int cursorY = 0;
    int quit = 1;
    int active_courant = 0;

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
    pipe_verti_Texture = loadTexture(renderer, "../images/pipe/pipe_vertical.png");
    pipe_hori_Texture = loadTexture(renderer, "../images/pipe/pipe_horizontal.png");
    pipe_HD_Texture = loadTexture(renderer, "../images/pipe/pipe_HD.png");
    pipe_BD_Texture = loadTexture(renderer, "../images/pipe/pipe_BD.png");
    pipe_BG_Texture = loadTexture(renderer, "../images/pipe/pipe_BG.png");
    pipe_HG_Texture = loadTexture(renderer, "../images/pipe/pipe_HG.png");
    pipe_croix_Texture = loadTexture(renderer, "../images/pipe/pipe_croix.png");
    pipe_courant_Texture = loadTexture(renderer, "../images/pipe/pipe_courant.png");
    finish_Texture = loadTexture(renderer, "../images/labyrinthe/emerald.png");


    if (!wallTexture || !pipe_verti_Texture || !pipe_hori_Texture || !pipe_HD_Texture || !pipe_BD_Texture || !pipe_BG_Texture || !pipe_HG_Texture || !pipe_croix_Texture || !pipe_courant_Texture || !finish_Texture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // Boucle principale
    while (quit) {
        // Gestion des événements
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT:
                    quit = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            if(cursorY > 0) cursorY--;
                            break;
                        case SDLK_DOWN:
                            if(cursorY < 18) cursorY++;
                            break;
                        case SDLK_LEFT:
                            if(cursorX > 0) cursorX--;
                            break;
                        case SDLK_RIGHT:
                            if(cursorX < 26) cursorX++;
                            break;
                        case SDLK_e:
                            if(tilemap[cursorY][cursorX] != 0 && tilemap[cursorY][cursorX] != 7 && tilemap[cursorY][cursorX] != 8){
                                if(tilemap[cursorY][cursorX] == 1 && cursorY != START_CARRE_1_Y && cursorY != END_Y){
                                    tilemap[cursorY][cursorX] = 2;
                                }
                                else if(tilemap[cursorY][cursorX] == 2){
                                    tilemap[cursorY][cursorX] = 1;
                                }
                                else if(tilemap[cursorY][cursorX] == 3){
                                    tilemap[cursorY][cursorX] = 4;
                                }
                                else if(tilemap[cursorY][cursorX] == 4){
                                    tilemap[cursorY][cursorX] = 5;
                                }
                                else if(tilemap[cursorY][cursorX] == 5){
                                    tilemap[cursorY][cursorX] = 6;
                                }
                                else if(tilemap[cursorY][cursorX] == 6){
                                    tilemap[cursorY][cursorX] = 3;
                                }
                            }
                            if(tilemap[cursorY][cursorX] == 8 && cursorY == START_CARRE_1_Y && cursorX == START_CARRE_1_X){
                                active_courant = 1;
                            }
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }


        // Nettoyer le renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Rendu tilemap
        for (int y = 0; y < 19; ++y) {
            for (int x = 0; x < 27; ++x) {
                // Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe
                if (x >= 0 && x < 27 && y >= 0 && y < 19) { 
                    // Rendu de chaque tuile en fonction de son type
                    int tileType = tilemap[y][x];
                    SDL_Texture* texture = NULL;
                    switch(tileType){
                        case 0: texture = wallTexture;
                            break;
                        case 1: texture = pipe_verti_Texture;
                            break;
                        case 2: texture = pipe_hori_Texture;
                            break;
                        case 3: texture = pipe_HD_Texture;
                            break;
                        case 4: texture = pipe_BD_Texture;
                            break;
                        case 5: texture = pipe_BG_Texture;
                            break;
                        case 6: texture = pipe_HG_Texture;
                            break;
                        case 7: texture = pipe_croix_Texture;
                            break;
                        case 8: texture = pipe_courant_Texture;
                            break;
                        case 9: texture = finish_Texture;
                            break;
                        default:
                            break;
                    }
                    if(texture){
                        SDL_Rect dstRect = {x * TILE_SIZE_X, y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
                        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                    }
                }
            }
        }
        // Rendu du curseur en rouge
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect cursorRect = {cursorX * TILE_SIZE_X, cursorY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderDrawRect(renderer, &cursorRect);

        // Vérifier le chemin
        if(active_courant){
            int pathCorrect_carre1 = checkPath(START_CARRE_1_X, START_CARRE_1_Y + 1, START_CARRE_1_X, START_CARRE_1_Y, tilemap, START_CARRE_2_X, START_CARRE_2_Y);
            int pathCorrect_carre2 = checkPath(START_CARRE_2_X, START_CARRE_2_Y + 1, START_CARRE_2_X, START_CARRE_2_Y, tilemap, START_CARRE_3_X, START_CARRE_3_Y);
            int pathCorrect_carre3 = checkPath(START_CARRE_3_X, START_CARRE_3_Y, START_CARRE_3_X - 1, START_CARRE_3_Y, tilemap, START_CARRE_4_X, START_CARRE_4_Y);
            int pathCorrect_carre4 = checkPath(START_CARRE_4_X, START_CARRE_4_Y - 1, START_CARRE_4_X, START_CARRE_4_Y, tilemap, END_X, END_Y);

            printf("1: %d\n2: %d\n3: %d\n4: %d\n", pathCorrect_carre1, pathCorrect_carre2, pathCorrect_carre3, pathCorrect_carre4);

            // Vérifier si le joueur a gagné
            if (pathCorrect_carre1) {
                printf("Carré 1 fini\n");
                updateBorderTiles(renderer, finish_Texture, tilemap, 12, 0, 0, 9);
            }
            if (pathCorrect_carre1 && pathCorrect_carre2) {
                printf("Carré 2 fini\n");
                updateBorderTiles(renderer, finish_Texture, tilemap, 0, 10, 12, 18);
            }
            if (pathCorrect_carre1 && pathCorrect_carre2 && pathCorrect_carre3) {
                printf("Carré 3 fini\n");
                updateBorderTiles(renderer, finish_Texture, tilemap, 13, 18, 26, 9);
            }
            if(pathCorrect_carre1 && pathCorrect_carre2 && pathCorrect_carre3 && pathCorrect_carre4){
                printf("Carré 4 fini\n");
                updateBorderTiles(renderer, finish_Texture, tilemap, 26, 9, 13, 0);
                quit = 0;
            }
            active_courant = 0;
        }

        // Actualiser le renderer
        SDL_RenderPresent(renderer);
    }

    // Nettoyer et quitter
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(pipe_verti_Texture);
    SDL_DestroyTexture(pipe_hori_Texture);
    SDL_DestroyTexture(pipe_HD_Texture);
    SDL_DestroyTexture(pipe_BD_Texture);
    SDL_DestroyTexture(pipe_BG_Texture);
    SDL_DestroyTexture(pipe_HG_Texture);
    SDL_DestroyTexture(pipe_croix_Texture);
    SDL_DestroyTexture(pipe_courant_Texture);
    SDL_DestroyTexture(finish_Texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();

    return 0;
}