#ifndef H_COMMUN
#define H_COMMUN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


/** Enumération de constantes pour la page */
typedef enum {
    MENU_PRINCIPAL,         /** Indice page du menu principal*/
    OPTIONS,                /** Indice page d'options*/
    NOUVELLE_PARTIE,        /** Indice page d'une Nouvelle partie*/
    INTRODUCTION,           /** Indice page d'introduction*/
    CARTE,                  /** Indice page de la carte*/
    NIVEAU_1,               /** Indice page du niveau 1*/
    NIVEAU_2,               /** Indice page du niveau 2*/
    NIVEAU_3,               /** Indice page du niveau 3*/
    NIVEAU_4                /** Indice page du niveau 4*/
} page_t;



/** Structure pour représenter les collectibles de chaque niveaux */
typedef struct {
    int niveau_fini;                            /** Booléen état du niveau*/
    SDL_Texture *texture_image_collectible;     /** Texture du collectible du niveau*/
    int numero_collectible[3];                  /** Tableau représentant le nombre de collectible*/    
} niveaux;



/** Structure pour représenter une case avec un rectangle et du texte */
typedef struct {
    SDL_Rect rectangle;             /** Rectangle ou se trouvera le texte*/
    char texte[100];                 /** Texte à afficher */
} itemMenu;



/** Enumération de constantes pour l'onglet actif des options */
typedef enum {
    ONGLET_SON,         /** Indice de l'onglet son de la page paramètre*/
     ONGLET_TOUCHES     /** Indice de l'onglet touche de la page paramètre*/
} option_t;

/** Structure pour représenter une barre de son */
typedef struct {
    SDL_Rect barre;		/** Barre de chargement du son*/
    SDL_Rect curseur;		/** Curseur de position du son*/
    float volume;		/** Volume actuelle du son*/
    float volume_precedent;	/** Volume précédent (avant le mute)*/
} barreDeSon;






#endif 
