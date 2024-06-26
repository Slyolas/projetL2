#ifndef H_GENERALE
#define H_GENERALE
#include "commun.h"
#include "fonctions_menu_principal.h"
/** Définir le nombre d'FPS (100 / nombre_FPS) */
#define FPS_LIMIT 16


/** Enumération de constantes pour le mode séléctionné */
typedef enum {
    MODE_NORMAL,               /** Indice de sélection de la difficulté normale*/
    MODE_HARD                  /** Indice de sélection de la difficulté difficile*/
} modes_t;

/** Enumération de constantes pour le personnage séléctionné */
typedef enum {
    PERSONNAGE_1,           /** Indice de sélection du personnage masculin*/
    PERSONNAGE_2            /** Indice de sélection du personnage féminin*/
} personnage_t;


/** Enumération de constantes pour la position sur la carte */
typedef enum {
    NIVEAU0,                    /** Indice du niveau 0*/
    NIVEAU1,                    /** Indice du niveau 1*/                     
    NIVEAU2,                    /** Indice du niveau 2*/ 
    NIVEAU3,                    /** Indice du niveau 3*/ 
    NIVEAU4                     /** Indice du niveau 4*/
} position_t; 

/** Enumération de constantes pour la direction du personnage sur la carte */
typedef enum {
    HAUT,                               /** Indice de la direction HAUT */
    BAS,                                /** Indice de la direction BAS */
    GAUCHE,                             /** Indice de la direction GAUCHE */
    DROITE,                             /** Indice de la direction DROITE */
    HAUT_DROITE,                        /** Indice de la direction HAUT_DROITE */
    BAS_GAUCHE                          /** Indice de la direction BAS_GAUCHE */
} direction_t; 



/** Squelette de la fonction erreur */
void erreur(const char *message);

/** Squelette de la fonction chargement_image */
void chargement_image(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, char *chemin);

/** Squelette de la fonction affichage_texte */
void affichage_texte(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture, itemMenu *item, 
                     TTF_Font **police, SDL_Color couleur);

/** Squelette de la fonction creer_fenetre_rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur);

/** Squelette de la fonction initialisation_objets */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **surface, SDL_Texture **texture_image_plein_ecran,
                           SDL_Texture **texture_image_retour_en_arriere, SDL_Texture **texture_image_options,
                           SDL_Texture **texture_image_passer, itemMenu *itemsDemandeSauvegarde, itemMenu *itemsDemandeQuitter,
                           SDL_Texture **texture_image_fin_premiers_niveaux, SDL_Texture **texture_image_monstre_terrestre,
                           SDL_Texture **texture_image_monstre_volant, SDL_Texture **texture_image_perso_1_gagnant,
                           SDL_Texture **texture_image_perso_2_gagnant,
                           niveaux *avancee_niveaux, TTF_Font **police);

/** Squelette de la fonction demande_sauvegarde */
void demande_sauvegarde(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_sauvegarde,
                        SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur,
                        itemMenu *itemsDemandeSauvegarde, int tailleDemandeSauvegarde, int largeur, int hauteur);

/** Squelette de la fonction demande_quitter_niveau */
void demande_quitter_niveau(SDL_Renderer **renderer, SDL_Rect *rectangle_demande_quitter,
                            SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police, SDL_Color couleur,
                            itemMenu *itemsDemandeQuitter, int tailleDemandeQuitter, int largeur, int hauteur);

/** Squelette de la fonction redimensionnement_fenetre */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur);

/** Squelette de la fonction verification_sauvegarde */
int verification_sauvegarde();

/** Squelette de la fonction sauvegarder_partie */
void sauvegarder_partie(SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter_monter,
                        SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, barreDeSon *barre_de_son, itemMenu *pseudo,
                        modes_t modeActif, personnage_t personnageActif, position_t positionActive,
                        niveaux *avancee_niveaux, int tailleNiveaux);

/** Squelette de la fonction clic_case */
int clic_case(SDL_Event event, SDL_Rect rectangle);

/** Squelette de la fonction deplacement_personnage */
void deplacement_personnage(int *saut, int *tombe, int *position_x, int *position_y, int *position_avant_saut,
                            int sauter, int avancer, int reculer, int tile_map[18][32]);

/** Squelette de la fonction clic_plein_ecran */
int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran, SDL_bool *plein_ecran, SDL_Window **window);

/** Squelette de la fonction SDL_LimitFPS */
void SDL_LimitFPS(unsigned int limit);

/** Squelette de la fonction detruire_objets */
void detruire_objets(TTF_Font **police, SDL_Texture **texture1, SDL_Texture **texture2,
                     SDL_Texture **texture3, SDL_Texture **texture4, SDL_Texture **texture5, SDL_Texture **texture6,
                     SDL_Texture **texture7, SDL_Texture **texture8,
                     SDL_Texture **texture9, SDL_Texture **texture10, SDL_Texture **texture11,
                     SDL_Texture **texture12, SDL_Texture **texture13, SDL_Texture **texture14,
                     SDL_Texture **texture15, SDL_Texture **texture16,
                     SDL_Texture **texture17, SDL_Texture **texture18, 
                     SDL_Texture **texture19, SDL_Texture **texture20,
                     SDL_Texture **texture21, SDL_Texture **texture22,
                     SDL_Texture **texture23, SDL_Texture **texture24,
                     SDL_Texture **texture25, SDL_Texture **texture26,
                     SDL_Texture **texture27, SDL_Texture **texture28,
                     SDL_Texture **texture29, SDL_Texture **texture30,
                     SDL_Texture **texture31, SDL_Texture **texture32,
                     SDL_Texture **texture33, SDL_Texture **texture34,
                     SDL_Texture **texture35, SDL_Texture **texture36, SDL_Texture **texture37,
                     SDL_Texture **texture38, SDL_Texture **texture39, SDL_Texture **texture40,
                     SDL_Texture **texture41, SDL_Texture **texture42,
                     SDL_Texture **texture43, SDL_Texture **texture44,
                     SDL_Texture **texture45, SDL_Texture **texture46,
                     SDL_Texture **texture47, SDL_Texture **texture48, 
                     SDL_Texture **texture49, SDL_Texture **texture50,
                     SDL_Texture **texture51, SDL_Texture **texture52,
                     SDL_Texture **texture53, SDL_Texture **texture54,
                     SDL_Texture **texture55, SDL_Texture **texture56, 
                     SDL_Texture **texture57, SDL_Texture **texture58,
                     SDL_Texture **texture59, SDL_Texture **texture60,
                     SDL_Texture **texture61, SDL_Texture **texture62,
                     SDL_Texture **texture63, SDL_Texture **texture64, 
                     SDL_Texture **texture65, SDL_Texture **texture66,
                     SDL_Texture **texture67, SDL_Texture **texture68, 
                     SDL_Texture **texture69, SDL_Texture **texture70, SDL_Texture **texture71);


/** Squelette de la fonction detruire_fenetre_rendu */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window);
#endif