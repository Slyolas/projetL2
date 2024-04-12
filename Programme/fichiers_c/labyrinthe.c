#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

/* Dimensions de la fenêtre */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* Dimensions des tiles */
#define TILE_SIZE_X SCREEN_WIDTH / 32
#define TILE_SIZE_Y SCREEN_HEIGHT / 24

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

/* Fonction pour charger une image dans une texture */
SDL_Texture* chargement_texture(SDL_Renderer* renderer, const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        printf("Failed to load image: %s\n", filePath);
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

/* Fonction pour traiter les commandes utilisateur */
void traitementTouches(int* joueur_X, int* joueur_Y, int* bloc_X, int* bloc_Y, int tilemap[24][32], int direction) {

    /* Vérification si le joueur est à côté du bloc */
    if ((*joueur_X == *bloc_X - 1 && *joueur_Y == *bloc_Y) ||   /* Le joueur est à gauche du bloc */
        (*joueur_X == *bloc_X + 1 && *joueur_Y == *bloc_Y) ||   /* Le joueur est à droite du bloc */
        (*joueur_X == *bloc_X && *joueur_Y == *bloc_Y - 1) ||   /* Le joueur est au dessus du bloc */
        (*joueur_X == *bloc_X && *joueur_Y == *bloc_Y + 1)) {   /* Le joueur est en dessous du bloc */

        /* Le personnage est au dessus du bloc */
        if (*joueur_X == *bloc_X && *joueur_Y == *bloc_Y - 1) { 
            /* On veut pousser le bloc */
            if(direction == 1){
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if (tilemap[*bloc_Y + 1][*bloc_X] == 0 || tilemap[*bloc_Y + 1][*bloc_X] == 3) {
                    (*bloc_Y)++;
                    (*joueur_Y)++;
                    SDL_Delay(200);
                }
            }
            /* On veut tirer le bloc */
            if(direction == 0){
                /* On regarde si le personnage peut être sur la case de derrière */
                if (tilemap[*joueur_Y - 1][*joueur_X] == 0 || tilemap[*joueur_Y - 1][*joueur_X] == 3) {
                    (*joueur_Y)--;
                    (*bloc_Y)--;
                    SDL_Delay(200);
                }
            }
        
        /* Le personnage est en dessous du bloc */
        } else if (*joueur_X == *bloc_X && *joueur_Y == *bloc_Y + 1) {
            /* On veut pousser le bloc */
            if(direction == 0){
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if (tilemap[*bloc_Y - 1][*bloc_X] == 0 || tilemap[*bloc_Y - 1][*bloc_X] == 3) {
                    (*bloc_Y)--;
                    (*joueur_Y)--;
                    SDL_Delay(200);
                }
            }
            /* On veut tirer le bloc */
            if(direction == 1){
                /* On regarde si le personnage peut être sur la case de derrière */
                if (tilemap[*joueur_Y + 1][*joueur_X] == 0 || tilemap[*joueur_Y + 1][*joueur_X] == 3) {
                    (*joueur_Y)++;
                    (*bloc_Y)++;
                    SDL_Delay(200);
                }
            }

        /* Le personnage est à gauche du bloc */
        } else if (*joueur_X == *bloc_X - 1 && *joueur_Y == *bloc_Y) {  
            /* On veut pousser le bloc */
            if(direction == 3){
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if (tilemap[*bloc_Y][*bloc_X + 1] == 0 || tilemap[*bloc_Y][*bloc_X + 1] == 3) {
                    (*bloc_X)++;
                    (*joueur_X)++;
                    SDL_Delay(200);
                }
            }
            /* On veut tirer le bloc */
            if(direction == 2){
                /* On regarde si le personnage peut être sur la case de derrière */
                if (tilemap[*joueur_Y][*joueur_X - 1] == 0 || tilemap[*joueur_Y][*joueur_X - 1] == 3) {
                    (*joueur_X)--;
                    (*bloc_X)--;
                    SDL_Delay(200);
                }
            }

        /* Le personnage est à droite du bloc */
        } else if (*joueur_X == *bloc_X + 1 && *joueur_Y == *bloc_Y) {
            /* On veut pousser le bloc */
            if(direction == 2){
                /* On regarde si on peut pousser le bloc sur la case suivante */
                if (tilemap[*bloc_Y][*bloc_X - 1] == 0 || tilemap[*bloc_Y][*bloc_X - 1] == 3) {
                    (*bloc_X)--;
                    (*joueur_X)--;
                    SDL_Delay(200);
                }
            }
            /* On veut tirer le bloc */
            if(direction == 3){
                /* On regarde si le personnage peut être sur la case de derrière */
                if (tilemap[*joueur_Y][*joueur_X + 1] == 0 || tilemap[*joueur_Y][*joueur_X + 1] == 3) {
                    (*joueur_X)++;
                    (*bloc_X)++;
                    SDL_Delay(200);
                }
            }
        }
    }
}

/* Fonction pour mettre à jour les tuiles de bordure lorsque le bloc atteint la fin du labyrinthe */
int updateBorderTiles(SDL_Renderer* renderer, SDL_Texture* texture_image_arrivee, int tilemap[24][32], int tileX, int tileY) {

    /* Mise à jour du rendu de la tuile courante */
    tilemap[tileY][tileX] = 3;
    SDL_Rect dstRect = {tileX * TILE_SIZE_X, tileY * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
    SDL_RenderCopy(renderer, texture_image_arrivee, NULL, &dstRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);

	/* Vérification des tuiles adjacentes pour permettre un appel récursif et ainsi changé toute les tuiles de la bordure */
    
    /* Tuile à droite de la courante */
    if(tilemap[tileY][tileX + 1] == 2 && tileX < 31) {
        return updateBorderTiles(renderer, texture_image_arrivee, tilemap, tileX + 1, tileY);
    }
    /* Tuile à gauche de la courante */
    else if(tilemap[tileY][tileX - 1] == 2 && tileX > 0){
        return updateBorderTiles(renderer, texture_image_arrivee, tilemap, tileX - 1, tileY);
    }
    /* Tuile en dessous de la courante */
    else if(tilemap[tileY + 1][tileX] == 2 && tileY < 31){
        return updateBorderTiles(renderer, texture_image_arrivee, tilemap, tileX, tileY + 1);
    }
    /* Tuile au dessus de la courante */
    else if(tilemap[tileY - 1][tileX] == 2 && tileY > 0){
        return updateBorderTiles(renderer, texture_image_arrivee, tilemap, tileX, tileY - 1);
    }
    
	return 0;
}

int main() {

    /* Déclaration */
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* texture_image_mur;
    SDL_Texture* texture_image_sol;
    SDL_Texture* texture_image_bordure;
    SDL_Texture* texture_image_joueur;
    SDL_Texture* texture_image_bloc;
    SDL_Texture* texture_image_arrivee;

    SDL_Event event;

    /* Initialisation de la carte du labyrinthe */
    /* 0 : sol, 1 : mur, 2 : bordure, 3 : tuile de fin */
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

    /* Position initiale du joueur en coordonnées de tuile */
    int joueur_X = 1;
    int joueur_Y = 1;
    /* Position initiale du block à deplacer en coordonnées de tuile */
    int bloc_X = 2;
    int bloc_Y = 1;
    /* Position du block d'arriver en coordonnées de tuile */
    int arrivee_X = 30;
    int arrivee_Y = 22;

    int haut = 0, bas = 0, gauche = 0, droite = 0, appuie_touche_interaction = 0;

    int quit = 0;

    /* Initialisation SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    /* Création de la fenêtre */
    window = SDL_CreateWindow("Tilemap Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* Création du renderer */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    /* Chargement des textures des tuiles */
    texture_image_mur = chargement_texture(renderer, "../images/labyrinthe/mur.png");
    texture_image_sol = chargement_texture(renderer, "../images/labyrinthe/sol.png");
    texture_image_bordure = chargement_texture(renderer, "../images/labyrinthe/obsi.png");
    texture_image_joueur = chargement_texture(renderer, "../images/labyrinthe/steve.png");
    texture_image_bloc = chargement_texture(renderer, "../images/labyrinthe/diamand.png");
    texture_image_arrivee = chargement_texture(renderer, "../images/labyrinthe/emerald.png");
    if (!texture_image_mur || !texture_image_sol || !texture_image_bordure || !texture_image_joueur || !texture_image_bloc || !texture_image_arrivee) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    /* Boucle principale */
    while (!quit) {
        /* Gestion des événements */
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
                        haut = 1;
                    }
                    if(event.key.keysym.sym == SDLK_DOWN){
                        bas = 1;
                    }
                    if(event.key.keysym.sym == SDLK_LEFT){
                        gauche = 1;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        droite = 1;
                    }
                    if(event.key.keysym.sym == SDLK_e){
                        appuie_touche_interaction = 1;
                    }

                    break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_UP){
                        haut = 0;
                    }
                    if(event.key.keysym.sym == SDLK_DOWN){
                        bas = 0;
                    }
                    if(event.key.keysym.sym == SDLK_LEFT){
                        gauche = 0;
                    }
                    if(event.key.keysym.sym == SDLK_RIGHT){
                        droite = 0;
                    }
                    if(event.key.keysym.sym == SDLK_e){
                        appuie_touche_interaction = 0;
                    }
                    
                    break;
                default:
                    break;
            }
        }
        /* Traitement de l'appuie des touches */
        if(haut){
            if(appuie_touche_interaction){
                traitementTouches(&joueur_X, &joueur_Y, &bloc_X, &bloc_Y, tilemap, UP);
            }
            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if ((tilemap[joueur_Y - 1][joueur_X] == 0 || tilemap[joueur_Y - 1][joueur_X] == 3 || tilemap[joueur_Y - 1][joueur_X] == 4) && !(joueur_X == bloc_X && joueur_Y == bloc_Y + 1)) {
                joueur_Y--;
                SDL_Delay(200);
            }
        }
        if(bas){
            if(appuie_touche_interaction){
                traitementTouches(&joueur_X, &joueur_Y, &bloc_X, &bloc_Y, tilemap, DOWN);
            }
            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if ((tilemap[joueur_Y + 1][joueur_X] == 0 || tilemap[joueur_Y + 1][joueur_X] == 3 || tilemap[joueur_Y + 1][joueur_X] == 4) && !(joueur_X == bloc_X && joueur_Y == bloc_Y - 1)) {
                joueur_Y++;
                SDL_Delay(200);
            }
        }
        if(gauche){
            if(appuie_touche_interaction){
                traitementTouches(&joueur_X, &joueur_Y, &bloc_X, &bloc_Y, tilemap, LEFT);
            }
            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if ((tilemap[joueur_Y][joueur_X - 1] == 0 || tilemap[joueur_Y][joueur_X - 1] == 3 || tilemap[joueur_Y][joueur_X - 1] == 4) && !(joueur_X == bloc_X + 1 && joueur_Y == bloc_Y)) {
                joueur_X--;
                SDL_Delay(200);
            }
        }
        if(droite){
            if(appuie_touche_interaction){
                traitementTouches(&joueur_X, &joueur_Y, &bloc_X, &bloc_Y, tilemap, RIGHT);
            }
            /* On vérifie que c'est bien un chemin et qu'il n'y a pas le bloc */
            else if ((tilemap[joueur_Y][joueur_X + 1] == 0 || tilemap[joueur_Y][joueur_X + 1] == 3 || tilemap[joueur_Y][joueur_X + 1] == 4) && !(joueur_X == bloc_X - 1 && joueur_Y == bloc_Y)) {
                joueur_X++;
                SDL_Delay(200);
            }
        }

        /* Nettoyer le renderer */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        /* Rendu tilemap */
        /* Mode Normal */
        if(modeActif == MODE_NORMAL){
            for (int y = 0; y < 24; ++y) {
                for (int x = 0; x < 32; ++x) {
                    /* Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe */
                    if (x >= 0 && x < 32 && y >= 0 && y < 24) { 
                        /* Rendu de chaque tuile en fonction de son type */
                        int tileType = tilemap[y][x];
                        SDL_Texture* texture = NULL;
                        if(tileType == 0){
                            texture = texture_image_sol;
                        }
                        else if(tileType == 1){
                            texture = texture_image_mur;
                        }
                        else if(tileType == 2){
                            texture = texture_image_bordure;
                        }
                        else if(tileType == 3){
                            texture = texture_image_arrivee;
                        }
                        else if(tileType == 4){
                            texture = texture_image_mur;
                        }
                        if(texture){
                            SDL_Rect dstRect = {x * TILE_SIZE_X, y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
                            SDL_RenderCopy(renderer, texture, NULL, &dstRect);
                        }
                    }
                }
            }
        }
        /* Mode Difficile */
        if(modeActif == MODE_HARD){
            for (int y = joueur_Y - 2; y <= joueur_Y + 2; ++y) {
                for (int x = joueur_X - 2; x <= joueur_X + 2; ++x) {
                    /* Vérifiez que les coordonnées sont à l'intérieur des limites du labyrinthe */
                    if (x >= 0 && x < 32 && y >= 0 && y < 24) { 
                        /* Rendu de chaque tuile en fonction de son type */
                        int tileType = tilemap[y][x];
                        SDL_Texture* texture = NULL;
                        if(tileType == 0){
                            texture = texture_image_sol;
                        }
                        else if(tileType == 1){
                            texture = texture_image_mur;
                        }
                        else if(tileType == 2){
                            texture = texture_image_bordure;
                        }
                        else if(tileType == 3){
                            texture = texture_image_arrivee;
                        }
                        else if(tileType == 4){
                            texture = texture_image_mur;
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
        if(joueur_X == 12 && joueur_Y == 11 && tilemap[joueur_Y][joueur_X] == 4){
            SDL_Texture* texture = NULL;

            tilemap[11][12] = 0;
            texture = texture_image_sol;
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
        if(joueur_X == 12 && joueur_Y == 10 && tilemap[11][12] == 0){
            SDL_Texture* texture = NULL;

            tilemap[11][12] = 4;
            texture = texture_image_sol;
            SDL_Rect dstRect1 = {12 * TILE_SIZE_X, 11 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect1);

            tilemap[12][12] = 4;
            SDL_Rect dstRect2 = {12 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect2);

            tilemap[12][13] = 4;
            SDL_Rect dstRect3 = {13 * TILE_SIZE_X, 12 * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
            SDL_RenderCopy(renderer, texture, NULL, &dstRect3);
            
        }

        /* Rendu du bloc à deplacer */
        SDL_Rect rectangle_bloc = {bloc_X * TILE_SIZE_X, bloc_Y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, texture_image_bloc, NULL, &rectangle_bloc);

        /* Rendu du bloc d'arriver */
        SDL_Rect rectangle_arrivee = {arrivee_X * TILE_SIZE_X, arrivee_Y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, texture_image_arrivee, NULL, &rectangle_arrivee);

        /* Rendu du joueur */
        SDL_Rect rectangle_joueur = {joueur_X * TILE_SIZE_X, joueur_Y * TILE_SIZE_Y, TILE_SIZE_X, TILE_SIZE_Y};
        SDL_RenderCopy(renderer, texture_image_joueur, NULL, &rectangle_joueur);


        /* Vérifier si le bloc atteint la fin du labyrinthe et mettre à jour les tuiles de bordure si nécessaire */
        if(bloc_X == 30 && bloc_Y == 22){
            updateBorderTiles(renderer, texture_image_arrivee, tilemap, 31, 23);
            printf("Oui\n");
            quit = 1;
        }

        /* Actualiser le renderer */
        SDL_RenderPresent(renderer);
    }

    /* Nettoyer et quitter */
    SDL_DestroyTexture(texture_image_mur);
    SDL_DestroyTexture(texture_image_sol);
    SDL_DestroyTexture(texture_image_bordure);
    SDL_DestroyTexture(texture_image_joueur);
    SDL_DestroyTexture(texture_image_bloc);
    SDL_DestroyTexture(texture_image_arrivee);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
