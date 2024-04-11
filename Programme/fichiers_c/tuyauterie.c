#include "../fichiers_h/tuyauterie.h"


void initSDL(SDL_Window ** window,SDL_Renderer ** renderer){
    // Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // Création de la fenêtre
    *window = SDL_CreateWindow("Tilemap Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!(*window)) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // Création du renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!(*renderer)) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }
}



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
int checkPath(int x, int y, int prevX, int prevY, position_pipe_t tilemap[TILE_MAP_X][TILE_MAP_Y], int arriveX, int arriveY) {

    // Vérifier si les coordonnées actuelles correspondent aux coordonnées de fin
    if (x == arriveX && y == arriveY) {
        return 1;
    }

    // Vérifier si le tuyau actuel est correctement aligné avec le précédent

    switch (tilemap[y][x]) {

        case VER: // Tuyau vertical
            /* On vient du dessus */
            if (prevY == y - 1){
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) ; /* On va en bas */
                }
            } 
            /* On vient d'en dessous */
            else {
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en haut */
                }
            }
            break;

        case HOR: // Tuyau horizontal
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            /* On vient de la droite */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            break;

        case HDR: // Tuyau HD
            /* On vient du dessus */
            if (prevY == y - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            /* On vient de la droite */
            else{
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en haut */
                }
            }
            break;

        case BDR: // Tuyau BD
            /* On vient de la droite */
            if (prevX == x + 1) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY); /* On va en bas */
                }
            }
            /* On vient du bas */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if(tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY); /* On va à droite */
                }
            }
            break;

        case BGR: // Tuyau BG
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir d'en haut*/
                if(tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY); /* On va en bas */
                }
            }
            /* On vient du bas */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            break;

        case HGR: // Tuyau HG
            /* On vient du haut */
            if (prevY == y - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la droite */
                if(tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR){
                    return checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY); /* On va à gauche */
                }
            }
            /* On vient de la gauche */
            else{
                /* On regarde que le tuyau suivant peut bien venir d'en bas*/
                if(tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR){
                    return checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va au haut */
                }
            }
            break;

        case CRX: // Tuyau croix
            /* On vient de la gauche */
            if (prevX == x - 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR) || (tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR) || (tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR)){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va à droite ou en bas ou en haut */
                }
            }
            /* On vient du bas */
            else if (prevY == y + 1) {
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR) || (tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR) || (tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR)){
                    return checkPath(x + 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va à droite ou à gauche ou en haut */
                }
            }
            /* On vient de la droite */
            else if(prevX == x + 1){
                if((tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR) || (tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR) || (tilemap[y-1][x] != HOR && tilemap[y-1][x] != HDR && tilemap[y-1][x] != HGR)){
                    return checkPath(x, y + 1, x, y, tilemap, arriveX, arriveY) || checkPath(x - 1, y, x, y, tilemap, arriveX, arriveY) || checkPath(x, y - 1, x, y, tilemap, arriveX, arriveY); /* On va en bas ou à gauche ou en haut */
                }
            }
            /* On vient du haut  */
            else{
                /* On regarde que le tuyau suivant peut bien venir de la gauche */
                if((tilemap[y][x+1] != VER && tilemap[y][x+1] != HDR && tilemap[y][x+1] != BDR) || (tilemap[y+1][x] != HOR && tilemap[y+1][x] != BDR && tilemap[y+1][x] != BGR) || (tilemap[y][x-1] != VER && tilemap[y][x-1] != BGR && tilemap[y][x-1] != HGR)){
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
int updateBorderTiles(SDL_Renderer* renderer, SDL_Texture* finish_Texture, position_pipe_t tilemap[TILE_MAP_X][TILE_MAP_Y], int tileX, int tileY, int finX, int finY) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[tileY][tileX] = 9;
    SDL_Rect dstRect = {tileX * TILE_SIZE_X, tileY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
    SDL_RenderCopy(renderer, finish_Texture, NULL, &dstRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à gauche de la courante */
    if(tilemap[tileY][tileX - 1] == MUR && tileX > finX && tileY == MUR) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX - 1, tileY, finX, finY);
    }
    else if((tilemap[tileY][tileX - 1] == ACT || tilemap[tileY][tileX - 1] == VER) && tileX > finX && tileY == MUR){
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX - 2, tileY, finX, finY);
    }
    /* Tuile à droite de la courante */
    else if(tilemap[tileY][tileX + 1] == MUR && tileX < finX && tileY == (TILE_MAP_X - 1)) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX + 1, tileY, finX, finY);
    }
    /* Tuile en bas de la courante */
    else if(tilemap[tileY + 1][tileX] == MUR && tileY < finY && tileX == MUR) {
        return updateBorderTiles(renderer, finish_Texture, tilemap, tileX, tileY + 1, finX, finY);
    }
    /* Tuile en haut de la courante */
    else if(tilemap[tileY - 1][tileX] == MUR && tileY > finY && tileX == (TILE_MAP_Y - 1)) {
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

    SDL_Event event;

    // Initialisation de la carte du labyrinthe
<<<<<<< HEAD
    position_pipe_t tilemap[TILE_MAP_X][TILE_MAP_Y] = {

        {MUR,     MUR, ACT, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR,    MUR,   MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, VER, MUR,      MUR},

        {MUR,     BDR, BDR, HGR, BGR, HOR, BDR, HDR, BGR, BDR, VER, HOR, BGR,     MUR,  BDR, HGR, HOR, HGR, HDR, BDR, HGR, BDR, HGR, HOR, BDR, MUR,      MUR},
        {MUR,     HOR, HDR, BDR, BGR, BDR, VER, BDR, BDR, HOR, MUR, BGR, BDR,     MUR,  VER, BGR, BDR, VER, HGR, BDR, HOR, HGR, HOR, VER, MUR, MUR,      MUR},
        {MUR,     VER, BDR, HOR, HGR, VER, BGR, BDR, CRX, HDR, HOR, HDR, HGR,     MUR,  BDR, BGR, MUR, HGR, CRX, BGR, VER, HDR, BDR, HGR, BGR, MUR,      MUR},
        {MUR,     CRX, HGR, HDR, BDR, BGR, MUR, MUR, HDR, VER, HDR, HGR, BGR,     MUR,  BGR, HGR, MUR, HGR, HOR, HDR, BGR, HOR, HDR, MUR, VER, BDR,      MUR},
        {MUR,     HDR, BGR, VER, BDR, BDR, BGR, MUR, HGR, HOR, MUR, MUR, VER,     MUR,  VER, BDR, CRX, HDR ,HGR, MUR, BGR, HDR, BDR, MUR, BDR, HGR,      MUR},
        {MUR,     BDR, HOR, HDR, VER, HGR, VER, HDR, BDR, HGR, HGR, VER, HGR,     MUR,  HGR, HOR, VER, BDR, BDR, VER, HDR, BDR, VER, MUR, MUR, VER,      MUR},
        {MUR,     MUR, HGR, HDR, BGR, BDR, BDR, HDR, HOR, HGR, HGR, HOR, HOR,     MUR,  BGR, HDR, HGR, HOR, HDR, BDR, HGR, BGR, CRX, HOR, BGR, BDR,      MUR},
        {MUR,     MUR, MUR, BGR, HOR, VER, HDR, VER, VER, BDR, MUR, HGR, HGR,     MUR,  BDR, HDR, MUR, MUR, BDR, HOR ,HDR, HGR, BDR, BGR, VER, HDR,      MUR},

        {MUR,     MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, VER, MUR,     MUR,  MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, VER, MUR, MUR,      MUR},

        {MUR,     BDR, HOR, VER, HDR, BDR, BGR, BDR, HDR, HDR, VER, CRX, HDR,     MUR,  BDR, HGR, HDR, HOR, HGR, BDR, BGR, HDR, MUR, BDR, HOR, BDR,      MUR},
        {MUR,     HGR, VER, MUR, BDR, VER, BGR, HDR, HOR, BDR, HGR, HOR, VER,     MUR,  HOR, BGR, MUR, HDR, HOR, HGR, BGR, BDR, MUR, BGR, VER, HDR,      MUR},
        {MUR,     BDR, BDR, MUR, HGR, CRX, HDR, BGR, HGR, HOR, HDR, HGR, HGR,     MUR,  BGR, VER, MUR, HGR, CRX, HDR, HOR, BDR, HDR, HGR, BGR, BDR,      MUR},
        {MUR,     HGR, BGR, HDR, VER, HOR, BDR, HDR, BDR, BGR, HGR, MUR, MUR,     MUR,  HDR, BDR, HGR, MUR, HOR, HDR, BDR, HDR, HOR, BDR, HOR, HGR,      MUR},
        {MUR,     BDR, CRX, HOR, MUR, MUR, VER, HGR, BDR, HDR, VER, BGR, BDR,     MUR,  BDR, HGR, VER, HGR, MUR, MUR, MUR, VER, CRX, HGR, MUR, HOR,      MUR},
        {MUR,     BGR, HGR, MUR, BGR, BDR, HDR, VER, HDR, HDR, HDR, MUR, BDR,     MUR,  BGR, BDR, HGR, CRX, VER, MUR, HDR, BDR, HOR, VER, MUR, VER,      MUR},
        {MUR,     BGR, BDR, VER, HOR, HGR, BGR, HGR, HOR, BDR, BGR, HOR, VER,     HOR,  BDR, HDR, VER, BDR, HDR, HGR, HOR, VER, BGR, BDR, HGR, BDR,      MUR},
        {MUR,     BGR, HDR, BGR, HOR, VER, HGR, VER, HDR, BGR, HGR, HDR, MUR,     MUR,  HGR, BGR, HDR, BGR, VER, HDR, BDR, HDR, BGR, BDR, VER, HDR,      MUR},

        {MUR,     MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR,     MUR,  MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR, MUR,      MUR}
=======
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
>>>>>>> 3bb03ab0a1cb23b83b290132f7030e8bd892d436
        
    };

    
    coordonnee_t cursor;

    cursor.x = 0;
    cursor.y = 0;   
    
    int quit = 1;
    int active_courant = 0;

    initSDL(&window,&renderer);

    // Chargement des textures des tuiles
    wallTexture = loadTexture(renderer, "./images/labyrinthe/mur.png");
    pipe_verti_Texture = loadTexture(renderer, "./images/pipe/pipe_vertical.png");
    pipe_hori_Texture = loadTexture(renderer, "./images/pipe/pipe_horizontal.png");
    pipe_HD_Texture = loadTexture(renderer, "./images/pipe/pipe_HD.png");
    pipe_BD_Texture = loadTexture(renderer, "./images/pipe/pipe_BD.png");
    pipe_BG_Texture = loadTexture(renderer, "./images/pipe/pipe_BG.png");
    pipe_HG_Texture = loadTexture(renderer, "./images/pipe/pipe_HG.png");
    pipe_croix_Texture = loadTexture(renderer, "./images/pipe/pipe_croix.png");
    pipe_courant_Texture = loadTexture(renderer, "./images/pipe/pipe_courant.png");
    finish_Texture = loadTexture(renderer, "./images/labyrinthe/emerald.png");
    

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
                            if(cursor.y > 0) cursor.y--;
                            break;
                        case SDLK_DOWN:
                            if(cursor.y < (TILE_MAP_X - 1)) cursor.y++;
                            break;
                        case SDLK_LEFT:
                            if(cursor.x > 0) cursor.x--;
                            break;
                        case SDLK_RIGHT:
                            if(cursor.x < (TILE_MAP_Y - 1)) cursor.x++;
                            break;
                        case SDLK_e:
                            if(tilemap[cursor.y][cursor.x] != MUR && tilemap[cursor.y][cursor.x] != CRX && tilemap[cursor.y][cursor.x] != ACT){
                                if(tilemap[cursor.y][cursor.x] == VER && cursor.y != START_CARRE_1_Y && cursor.y != END_Y){
                                    tilemap[cursor.y][cursor.x] = HOR;
                                }
                                else if(tilemap[cursor.y][cursor.x] == HOR){
                                    tilemap[cursor.y][cursor.x] = VER;
                                }
                                else if(tilemap[cursor.y][cursor.x] == HDR){
                                    tilemap[cursor.y][cursor.x] = BDR;
                                }
                                else if(tilemap[cursor.y][cursor.x] == BDR){
                                    tilemap[cursor.y][cursor.x] = BGR;
                                }
                                else if(tilemap[cursor.y][cursor.x] == BGR){
                                    tilemap[cursor.y][cursor.x] = HGR;
                                }
                                else if(tilemap[cursor.y][cursor.x] == HGR){
                                    tilemap[cursor.y][cursor.x] = HDR;
                                }
                            }
                            if(tilemap[cursor.y][cursor.x] == ACT && cursor.y == START_CARRE_1_Y && cursor.x == START_CARRE_1_X){
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
        for (int y = 0; y < TILE_MAP_X; ++y) {
            for (int x = 0; x < TILE_MAP_Y; ++x) {
                // Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe
                if (x >= 0 && x < TILE_MAP_Y && y >= 0 && y < TILE_MAP_X) { 
                    // Rendu de chaque tuile en fonction de son type
                    position_pipe_t tileType = tilemap[y][x];
                    SDL_Texture* texture = NULL;
                    switch(tileType){
                        case MUR: texture = wallTexture;
                            break;
                        case VER: texture = pipe_verti_Texture;
                            break;
                        case HOR: texture = pipe_hori_Texture;
                            break;
                        case HDR: texture = pipe_HD_Texture;
                            break;
                        case BDR: texture = pipe_BD_Texture;
                            break;
                        case BGR: texture = pipe_BG_Texture;
                            break;
                        case HGR: texture = pipe_HG_Texture;
                            break;
                        case CRX: texture = pipe_croix_Texture;
                            break;
                        case ACT: texture = pipe_courant_Texture;
                            break;
                        case FIN: texture = finish_Texture;
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
        SDL_Rect cursorRect = {cursor.x * TILE_SIZE_X, cursor.y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderDrawRect(renderer, &cursorRect);

        // Vérifier le chemin
        if(active_courant){
            int pathCorrect_carre1 = checkPath(START_CARRE_1_X, START_CARRE_1_Y + 1, START_CARRE_1_X, START_CARRE_1_Y, tilemap, START_CARRE_2_X, START_CARRE_2_Y);
            int pathCorrect_carre2 = checkPath(START_CARRE_2_X, START_CARRE_2_Y + 1, START_CARRE_2_X, START_CARRE_2_Y, tilemap, START_CARRE_3_X, START_CARRE_3_Y);
            int pathCorrect_carre3 = checkPath(START_CARRE_3_X, START_CARRE_3_Y, START_CARRE_3_X - 1, START_CARRE_3_Y, tilemap, START_CARRE_4_X, START_CARRE_4_Y);
            int pathCorrect_carre4 = checkPath(START_CARRE_4_X, START_CARRE_4_Y - 1, START_CARRE_4_X, START_CARRE_4_Y, tilemap, END_X, END_Y);

            // Vérifier si le joueur a gagné
            if (pathCorrect_carre1) {
                updateBorderTiles(renderer, finish_Texture, tilemap, 12, 0, 0, 9);
            }
            if (pathCorrect_carre1 && pathCorrect_carre2) {
                updateBorderTiles(renderer, finish_Texture, tilemap, 0, 10, 12, (TILE_MAP_X - 1));
            }
            if (pathCorrect_carre1 && pathCorrect_carre2 && pathCorrect_carre3) {
                updateBorderTiles(renderer, finish_Texture, tilemap, 13, (TILE_MAP_X - 1), (TILE_MAP_Y - 1), 9);
            }
            if(pathCorrect_carre1 && pathCorrect_carre2 && pathCorrect_carre3 && pathCorrect_carre4){
                updateBorderTiles(renderer, finish_Texture, tilemap, (TILE_MAP_Y - 1), 9, 13, 0);
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