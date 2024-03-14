#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS_LIMIT 16

void erreur(const char *message) {
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_LimitFPS(unsigned int limit) {
    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
}

int main(int argc, char **argv) {

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    // Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        erreur("Impossible de créer la fenêtre et le rendu");

    /*-------------------------------------------------------------*/

    /*-------------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS; //return 0;
}

/*
    SDL_RENDERER_SOFTWARE
    SDL_RENDERER_ACCELERATED
    SDL_RENDERER_PRESENTVSYNC
    SDL_RENDERER_TARGETTEXTURE
*/

/*  
    if(SDL_RenderClear(renderer) != 0)
        erreur("Effacement rendu échoué"); 
*/

/*  
    // Création fenêtre
    window = SDL_CreateWindow("Première fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if(window == NULL)
        erreur("Création fenêtre échouée");

    // Création du rendu
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if(renderer == NULL)
        erreur("Création rendu échoué");
*/

/*
    if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
        erreur("Impossible de changer la couleur pour le rendu");

    if(SDL_RenderDrawPoint(renderer, 100, 450) != 0)
        erreur("Impossible de dessiner un point");

    if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        erreur("Impossible de dessiner une ligne");

    SDL_Rect rectangle;
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 120;

    if(SDL_RenderFillRect(renderer, &rectangle) != 0)
        erreur("Impossible de dessiner un rectangle");

    if(SDL_SetRenderDrawColor(renderer, 255, 15, 15, SDL_ALPHA_OPAQUE) != 0)
        erreur("Impossible de changer la couleur pour le rendu");

    if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        erreur("Impossible de dessiner une ligne");

    SDL_RenderPresent(renderer);
    SDL_Delay(6000);
*/

/*
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

    image = SDL_LoadBMP("dossier/image.bmp");

    if(image == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        erreur("Impossible de charger l'image");
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    if(texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        erreur("Impossible de créer la texture");
    }

    SDL_Rect rectangle;

    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        erreur("Impossible de charger la texture");
    }

    // Centrer l'image
    rectangle.x = (WINDOW_WIDTH - rectangle.w) / 2;
    rectangle.y = (WINDOW_HEIGHT - rectangle.h) / 2;

    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        erreur("Impossible d'afficher la texture");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(6000);
*/

/*
    // Fonction bloquante
        while(SDL_WaitEvent(&event) == 1) {
            switch(event.type) {
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
*/

/*
    SDL_bool program_launched = SDL_TRUE;

    while(program_launched) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_b:
                            printf("Vous avez appuyé sur B\n");
                            continue;

                        default:
                            continue;
                    }

                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                        case SDLK_b:
                            printf("Vous avez relaché sur B\n");
                            continue;

                        default:
                            continue;
                    }

                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
*/

/*
    SDL_bool program_launched = SDL_TRUE;

    while(program_launched) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                *//*
                    SDL_BUTTON_LEFT
                    SDL_BUTTON_MIDDLE
                    SDL_BUTTON_RIGHT
                *//*
                case SDL_MOUSEMOTION:
                    printf("%d / %d\n", event.motion.x, event.motion.y);
                    break;
                
                case SDL_MOUSEBUTTONDOWN:
                    printf("Clic en %dx / %dy\n", event.button.x, event.button.y);
                    if(event.button.clicks >= 2)
                        printf("Double-clic !\n");
                    if(event.button.button == SDL_BUTTON_LEFT)
                        printf("Clic gauche !\n");
                    if(event.button.button == SDL_BUTTON_RIGHT)
                        printf("Clic gauche !\n");
                    break;
                
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
*/

/*
    SDL_bool program_launched = SDL_TRUE;

    while(program_launched) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                //event.window.event
                // Voir documentation pour d'autres commandes
                //event.windows.data1
                //event.windows.data2
                // Déplacemant de la fenêtre
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_LEAVE)
                        printf("La souris est sortie de la fenêtre.\n");
                    if(event.window.event == SDL_WINDOWEVENT_ENTER)
                        printf("La souris est sur de la fenêtre.\n");
                    break;
                
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
*/

/*
    SDL_bool program_launched = SDL_TRUE;

    unsigned int frame_limit = 0;
    
    frame_limit = SDL_GetTicks() + FPS_LIMIT;
    SDL_LimitFPS(frame_limit);
    frame_limit = SDL_GetTicks() + FPS_LIMIT;

    while(program_launched) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
*/