#ifndef H_COMMUN
#define H_COMMUN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


/* Enumération de constantes pour la page */
typedef enum page_s {MENU_PRINCIPAL, OPTIONS, NOUVELLE_PARTIE, INTRODUCTION, CARTE, NIVEAU_1, NIVEAU_2, NIVEAU_3, NIVEAU_4} page_t;



/* Structure pour représenter les collectibles de chaque niveaux */
typedef struct {
    int niveau_fini;
    SDL_Texture *texture_image_collectible;
    int numero_collectible[3];
} niveaux;



/* Structure pour représenter une case avec un rectangle et du texte */
typedef struct {
    SDL_Rect rectangle;
    char texte[60];
} itemMenu;



/* Enumération de constantes pour l'onglet actif des options */
typedef enum option_s {ONGLET_SON, ONGLET_TOUCHES} option_t;

/* Structure pour représenter une barre de son */
typedef struct {
    SDL_Rect barre;
    SDL_Rect curseur;
    float volume;
    float volume_precedent;
} barreDeSon;






#endif 