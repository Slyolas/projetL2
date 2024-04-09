#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

// Dimensions de la fenêtre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Dimensions des tiles
#define TILE_SIZE_X SCREEN_WIDTH / 24
#define TILE_SIZE_Y SCREEN_HEIGHT / 16


// Coordonnées de début et de fin du chemin
#define START_X 2
#define START_Y 0
#define END_X 22
#define END_Y 15

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
int checkPath(int x, int y, int prevX, int prevY, int tilemap[16][24]) {
    // Vérifier si les coordonnées sont en dehors des limites du labyrinthe
    if (x < 0 || x >= 24 || y < 0 || y >= 16) {
        return 0;
    }
    // Vérifier si les coordonnées actuelles correspondent aux coordonnées de fin
    if (x == END_X && y == END_Y) {
        return 1;
    }
    // Vérifier si le tuyau actuel est correctement aligné avec le précédent
    if ((x != prevX || y != prevY) && tilemap[y][x] != 0) {
        switch (tilemap[y][x]) {
            case 1: // Tuyau vertical
                /* On vient du dessus */
                if (prevY == y - 1){
                    /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                    if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9){
                        return checkPath(x, y + 1, x, y, tilemap) ; /* On va en bas */
                    }
                } 
                /* On vient d'en dessous */
                else {
                    /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                    if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7){
                        return checkPath(x, y - 1, x, y, tilemap); /* On va en haut */
                    }
                }
                break;

            case 2: // Tuyau horizontal
                /* On vient de la gauche */
                if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8){
                        return checkPath(x + 1, y, x, y, tilemap); /* On va à droite */
                    }
                }
                /* On vient de la droite */
                else{
                    /* On regarde que le tuyau suivant peut bien venir de la droite */
                    if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10){
                        return checkPath(x - 1, y, x, y, tilemap); /* On va à gauche */
                    }
                }
                break;

            case 3: // Tuyau HD
                /* On vient du dessus */
                if (prevY == y - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8){
                        return checkPath(x + 1, y, x, y, tilemap); /* On va à droite */
                    }
                }
                /* On vient de la droite */
                else{
                    /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                    if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7){
                        return checkPath(x, y - 1, x, y, tilemap); /* On va en haut */
                    }
                }
                break;

            case 4: // Tuyau BD
                /* On vient de la droite */
                if (prevX == x + 1) {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                    if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9){
                        return checkPath(x, y + 1, x, y, tilemap); /* On va en bas */
                    }
                }
                /* On vient du bas */
                else{
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if(tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8){
                        return checkPath(x + 1, y, x, y, tilemap); /* On va à droite */
                    }
                }
                break;

            case 5: // Tuyau BG
                /* On vient de la gauche */
                if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                    if(tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9){
                        return checkPath(x, y + 1, x, y, tilemap); /* On va en bas */
                    }
                }
                /* On vient du bas */
                else{
                    /* On regarde que le tuyau suivant peut bien venir de la droite */
                    if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10){
                        return checkPath(x - 1, y, x, y, tilemap); /* On va à gauche */
                    }
                }
                break;

            case 6: // Tuyau HG
                /* On vient du haut */
                if (prevY == y - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la droite */
                    if(tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10){
                        return checkPath(x - 1, y, x, y, tilemap); /* On va à gauche */
                    }
                }
                /* On vient de la gauche */
                else{
                    /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                    if(tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7){
                        return checkPath(x, y - 1, x, y, tilemap); /* On va au haut */
                    }
                }
                break;

            case 7: // Tuyau 3 haut
                /* On vient du haut */
                if (prevY == y - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la droite ou de la gauche */
                    if((tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8)){
                        return checkPath(x - 1, y, x, y, tilemap) || checkPath(x + 1, y, x, y, tilemap); /* On va à gauche ou à droite */
                    }
                }
                /* On vient de la gauche */
                else if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir d'en bas ou de la gauche */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à droite ou en haut */
                    }
                }
                /* On vient de la droite */
                else {
                    /* On regarde que le tuyau suivant peut bien venir de la droite ou du bas */
                    if((tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x - 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à gauche ou en haut */
                    }
                }
                break;

            case 8: // Tuyau 3 droite
                /* On vient du haut */
                if (prevY == y - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche  ou du haut */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x, y + 1, x, y, tilemap); /* On va à droite ou en bas */
                    }
                }
                /* On vient du bas */
                else if (prevY == y + 1) {
                    /* On regarde que le tuyau suivant peut bien venir d'en bas ou de la gauche */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à droite ou en haut */
                    }
                }
                /* On vient de la droite */
                else {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut ou d'en bas */
                    if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x, y + 1, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va en bas ou en haut */
                    }
                }
                break;

            case 9: // Tuyau 3 bas
                /* On vient de la gauche */
                if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche  ou du haut */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x, y + 1, x, y, tilemap); /* On va à droite ou en bas */
                    }
                }
                /* On vient du bas */
                else if (prevY == y + 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la droite ou de la gauche */
                    if((tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap); /* On va à droite ou à gauche */
                    }
                }
                /* On vient de la droite */
                else {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut ou de la droite */
                    if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10)){
                        return checkPath(x, y + 1, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap); /* On va en bas ou à gauche */
                    }
                }
                break;

            case 10: // Tuyau 3 gauche
                /* On vient de la gauche */
                if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut ou d'en bas */
                    if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x, y - 1, x, y, tilemap) || checkPath(x, y + 1, x, y, tilemap); /* On va en haut ou en bas */
                    }
                }
                /* On vient du bas */
                else if (prevY == y + 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la droite ou du bas */
                    if((tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x - 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à gauche ou en haut */
                    }
                }
                /* On vient du haut */
                else {
                    /* On regarde que le tuyau suivant peut bien venir d'en haut ou de la droite */
                    if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10)){
                        return checkPath(x, y + 1, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap); /* On va en bas ou à gauche */
                    }
                }
                break;

            case 11: // Tuyau croix
                /* On vient de la gauche */
                if (prevX == x - 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x, y + 1, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à droite ou en bas ou en haut */
                    }
                }
                /* On vient du bas */
                else if (prevY == y + 1) {
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x + 1, y, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va à droite ou à gauche ou en haut */
                    }
                }
                /* On vient de la droite */
                else if(prevX == x + 1){
                    if((tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10) || (tilemap[y-1][x] != 2 && tilemap[y-1][x] != 3 && tilemap[y-1][x] != 6 && tilemap[y-1][x] != 7)){
                        return checkPath(x, y + 1, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap) || checkPath(x, y - 1, x, y, tilemap); /* On va en bas ou à gauche ou en haut */
                    }
                }
                /* On vient du haut  */
                else{
                    /* On regarde que le tuyau suivant peut bien venir de la gauche */
                    if((tilemap[y][x+1] != 1 && tilemap[y][x+1] != 3 && tilemap[y][x+1] != 4 && tilemap[y][x+1] != 8) || (tilemap[y+1][x] != 2 && tilemap[y+1][x] != 4 && tilemap[y+1][x] != 5 && tilemap[y+1][x] != 9) || (tilemap[y][x-1] != 1 && tilemap[y][x-1] != 5 && tilemap[y][x-1] != 6 && tilemap[y][x-1] != 10)){
                        return checkPath(x, y + 1, x, y, tilemap) || checkPath(x - 1, y, x, y, tilemap) || checkPath(x + 1, y, x, y, tilemap); /* On va en bas ou à gauche ou à droite */
                    }
                }
                break;
        }
        return 0;
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
    SDL_Texture* pipe_3_haut_Texture;
    SDL_Texture* pipe_3_droit_Texture;
    SDL_Texture* pipe_3_bas_Texture;
    SDL_Texture* pipe_3_gauche_Texture;
    SDL_Texture* pipe_croix_Texture;
    SDL_Texture* pipe_courant_Texture;

    SDL_Event event;

    // Initialisation de la carte du labyrinthe
    int tilemap[16][24] = { /* 16*24 max avec ces dimensions */
        {0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 4, 5, 8, 3, 9, 3, 0, 7, 0, 8, 6, 0, 3, 8, 7, 3, 9, 6, 8, 4, 5, 0},
        {0, 7, 3, 3, 6, 7, 8, 5, 4, 2, 7, 9, 5, 0, 9, 10, 9, 2, 5, 11, 3, 0, 9, 0},
        {0, 1, 2, 8, 0, 5, 3, 1, 9, 0, 8, 5, 2, 7, 4, 0, 6, 10, 4, 3, 5, 1, 5, 0},
        {0, 11, 6, 8, 3, 2, 0, 6, 8, 0, 11, 0, 6, 5, 0, 4, 8, 7, 3, 7, 0, 0, 8, 0},
        {0, 3, 7, 0, 2, 0, 0, 4, 0, 0, 0, 4, 0, 9, 3, 3, 5, 0, 3, 3, 2, 9, 6, 0},
        {0, 8, 4, 5, 9, 4, 3, 5, 9, 2, 1, 2, 1, 0, 8, 6, 9, 6, 11, 3, 8, 4, 0, 0},
        {0, 0, 3, 1, 2, 3, 10, 1, 8, 5, 8, 11, 9, 5, 6, 6, 0, 4, 0, 7, 0, 10, 5, 0},
        {0, 9, 6, 0, 8, 1, 11, 2, 3, 6, 0, 5, 3, 8, 6, 2, 3, 6, 10, 0, 8, 6, 0, 0},
        {0, 5, 11, 10, 0, 3, 3, 9, 4, 0, 3, 4, 0, 6, 5, 0, 0, 10, 0, 0, 4, 0, 9, 0},
        {0, 7, 4, 8, 3, 5, 9, 6, 3, 0, 8, 7, 6, 0, 0, 7, 4, 6, 7, 7, 3, 2, 8, 0},
        {0, 6, 0, 3, 4, 3, 3, 9, 8, 1, 3, 3, 6, 2, 0, 5, 3, 3, 6, 3, 10, 0, 5, 0},
        {0, 9, 4, 8, 2, 10, 6, 8, 3, 6, 4, 3, 11, 3, 5, 9, 4, 4, 0, 1, 9, 7, 0, 0},
        {0, 3, 9, 8, 0, 0, 8, 5, 2, 5, 10, 8, 6, 5, 4, 7, 3, 7, 6, 0, 8, 6, 8, 0},
        {0, 5, 8, 7, 6, 10, 5, 0, 8, 6, 7, 6, 3, 10, 0, 3, 8, 9, 2, 0, 7, 5, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
        
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
    pipe_3_haut_Texture = loadTexture(renderer, "../images/pipe/pipe_3_haut.png");
    pipe_3_droit_Texture = loadTexture(renderer, "../images/pipe/pipe_3_droite.png");
    pipe_3_bas_Texture = loadTexture(renderer, "../images/pipe/pipe_3_bas.png");
    pipe_3_gauche_Texture = loadTexture(renderer, "../images/pipe/pipe_3_gauche.png");
    pipe_croix_Texture = loadTexture(renderer, "../images/pipe/pipe_croix.png");
    pipe_courant_Texture = loadTexture(renderer, "../images/pipe/pipe_courant.png");


    if (!wallTexture || !pipe_verti_Texture || !pipe_hori_Texture || !pipe_HD_Texture || !pipe_BD_Texture || !pipe_BG_Texture || !pipe_HG_Texture || !pipe_3_haut_Texture || !pipe_3_droit_Texture || !pipe_3_bas_Texture || !pipe_3_gauche_Texture || !pipe_croix_Texture || !pipe_courant_Texture) {
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
                            if(cursorY < 15) cursorY++;
                            break;
                        case SDLK_LEFT:
                            if(cursorX > 0) cursorX--;
                            break;
                        case SDLK_RIGHT:
                            if(cursorX < 23) cursorX++;
                            break;
                        case SDLK_e:
                            if(tilemap[cursorY][cursorX] != 0 && tilemap[cursorY][cursorX] != 11 && tilemap[cursorY][cursorX] != 12){
                                if(tilemap[cursorY][cursorX] == 1 && cursorY != START_Y && cursorY != END_Y){
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
                                else if(tilemap[cursorY][cursorX] == 7){
                                    tilemap[cursorY][cursorX] = 8;
                                }
                                else if(tilemap[cursorY][cursorX] == 8){
                                    tilemap[cursorY][cursorX] = 9;
                                }
                                else if(tilemap[cursorY][cursorX] == 9){
                                    tilemap[cursorY][cursorX] = 10;
                                }
                                else if(tilemap[cursorY][cursorX] == 10){
                                    tilemap[cursorY][cursorX] = 7;
                                }
                                if(tilemap[cursorY][cursorX] == 12 && cursorY == START_Y && cursorX == START_X){
                                    active_courant = 1;
                                }
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
        for (int y = 0; y < 16; ++y) {
            for (int x = 0; x < 24; ++x) {
                // Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe
                if (x >= 0 && x < 24 && y >= 0 && y < 16) { 
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
                        case 7: texture = pipe_3_haut_Texture;
                            break;
                        case 8: texture = pipe_3_droit_Texture;
                            break;
                        case 9: texture = pipe_3_bas_Texture;
                            break;
                        case 10: texture = pipe_3_gauche_Texture;
                            break;
                        case 11: texture = pipe_croix_Texture;
                            break;
                        case 12: texture = pipe_courant_Texture;
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
            int pathCorrect = checkPath(START_X, START_Y + 1, START_X, START_Y, tilemap);
            // Vérifier si le joueur a gagné
            if (pathCorrect) {
                printf("Félicitations, vous avez gagné !\n");
                quit = 0;
            }
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
    SDL_DestroyTexture(pipe_3_haut_Texture);
    SDL_DestroyTexture(pipe_3_droit_Texture);
    SDL_DestroyTexture(pipe_3_bas_Texture);
    SDL_DestroyTexture(pipe_3_gauche_Texture);
    SDL_DestroyTexture(pipe_croix_Texture);
    SDL_DestroyTexture(pipe_courant_Texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
