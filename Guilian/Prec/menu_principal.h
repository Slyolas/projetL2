#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Fonction qui affiche un message d'erreur quand une chose n'a pas pû être exécuté */
void erreur(const char *message);

/* Vérifie si une sauvegarde existe */
int verification_sauvegarde();

/* Fonction qui permet d'initialiser les différents objets */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_menu, SDL_Texture **texture_image_menu,
                           SDL_Surface **image_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, int tailleMenu);

/* Fonction qui permet de redimensionner la fenêtre et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur);

/* Fonction qui met à jour le rendu après redimension de la fenêtre */
void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_menu,
                       SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                       itemMenu *titre, SDL_Surface **texte_menu, SDL_Texture **texture_texte_menu, TTF_Font **police,
                       SDL_Color couleurTitre, SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur);

/* Fonction qui permet de ... quand on clique sur une case du menu */
void clic_case(SDL_Event event, itemMenu *itemsMenu, int numero_case, int tailleMenu);

/* Fonction qui permet de mettre la fenêtre en plein écran quand on clique sur le bouton plein écran */
int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran, SDL_bool *plein_ecran, SDL_Window **window);