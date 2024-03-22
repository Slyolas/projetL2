#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Définir le nombre d'FPS (100 / nombre_FPS) */
#define FPS_LIMIT 16

/* Enumération de constantes pour l'onglet actif des options */
typedef enum option_s {ONGLET_SON, ONGLET_TOUCHES} option_t;

/* Enumération de constantes pour le mode séléctionné */
typedef enum modes_s {MODE_NORMAL, MODE_HARD} modes_t;

/* Enumération de constantes pour le personnage séléctionné */
typedef enum personnage_s {PERSONNAGE_1, PERSONNAGE_2} personnage_t;

/* Enumération de constantes pour la page */
typedef enum page_s {MENU_PRINCIPAL, OPTIONS, NOUVELLE_PARTIE, INTRODUCTION, NIVEAU_1} page_t;   

/* Structure pour représenter une case avec un rectangle et du texte */
typedef struct {
    SDL_Rect rectangle;
    char texte[40];
} itemMenu;

/* Structure pour représenter une barre de son */
typedef struct {
    SDL_Rect barre;
    SDL_Rect curseur;
    float volume;
    float volume_precedent;
} barreDeSon;

/* Squelette de la fonction erreur */
void erreur(const char *message);

/* Squelette de la fonction creer_fenetre_rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur);

/* Squelette de la fonction initialisation_objets */
void initialisation_objets(SDL_Renderer **renderer,
                          SDL_Surface **image_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                          SDL_Surface **image_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                          SDL_Surface **image_options, SDL_Texture **texture_image_options,
                          TTF_Font **police);

/* Squelette de la fonction redimensionnement_fenetre */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur);

/* Squelette de la fonction verification_sauvegarde */
int verification_sauvegarde();

/* Squelette de la fonction clic_case */
int clic_case(SDL_Event event, SDL_Rect rectangle);

/* Squelette de la fonction clic_plein_ecran */
int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran, SDL_bool *plein_ecran, SDL_Window **window);

/* Squelette de la fonction SDL_LimitFPS */
void SDL_LimitFPS(unsigned int limit);

/* Squelette de la fonction detruire_objets */
void detruire_objets(TTF_Font **police);

/* Squelette de la fonction detruire_fenetre_rendu */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window);