#ifndef H_NOUVELLE_PARTIE
#define H_NOUVELLE_PARTIE
#include "commun.h"
/* Squelette de la fonction initialisation_objets_nouvelle_partie */
void initialisation_objets_nouvelle_partie(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_perso_1,
                                           SDL_Texture **texture_image_perso_2,
                                           itemMenu *titres, itemMenu *itemsMenu, itemMenu *valider);

/* Squelette de la fonction mise_a_jour_rendu_nouvelle_partie */
void mise_a_jour_rendu_nouvelle_partie(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                       SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                                       SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                       modes_t modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                                       SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t personnageActif,
                                       itemMenu *pseudo, SDL_Rect *rectangle_pseudo,
                                       itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte, 
                                       TTF_Font **police, SDL_Color couleurNoire,
                                       itemMenu *itemsMenu, itemMenu *valider, int largeur, int hauteur);

/* Squelette de la fonction nouvelle_partie */
void nouvelle_partie(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, 
                     SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, 
                     SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, int *modeSaisie,
                     modes_t *modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                     SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, personnage_t *personnageActif,
                     itemMenu *pseudo, SDL_Rect *rectangle_pseudo, barreDeSon *barre_de_son, int *pseudo_valide,
                     SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
                     SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, itemMenu *titres, int tailleTitres, SDL_Surface **surface, SDL_Texture **texture_texte, 
                     TTF_Font **police, SDL_Color couleurNoire, position_t *positionActive, niveaux *avancee_niveaux, int tailleNiveaux,
                     itemMenu *itemsMenu, itemMenu *valider, int *largeur, int *hauteur, page_t *page_active);
#endif