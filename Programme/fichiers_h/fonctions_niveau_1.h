#ifndef H_NIVEAU_1
#define H_NIVEAU_1


/* Fonction qui permet d'initialiser les différents objets du niveau 4 */
void initialisation_objets_niveau_1(SDL_Renderer **renderer, SDL_Surface **surface,
                                    SDL_Texture **texture_image_sol_surface_niveau_1, SDL_Texture **texture_image_sol_profondeur_niveau_1,
                                    SDL_Texture **texture_image_fond_niveau_1, SDL_Texture **texture_image_nuage_1, SDL_Texture **texture_image_nuage_2);

/* Fonction qui permet de créer l'étage 1 */
void chargement_niveau_1(int *position_x, int *position_y, int *position_x_initiale, int *position_y_initiale, int tile_map_niveau_1[18][110]);

/* Fonction qui permet de mettre à jour le rendu du niveau 4 */
void mise_a_jour_rendu_niveau_1(SDL_Renderer **renderer, SDL_Texture **texture_image_sol_surface, SDL_Texture **texture_image_sol_profondeur, SDL_Texture **texture_image_fond,
                                SDL_Texture **texture, SDL_Rect *rectangle_tile, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
                                SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, SDL_Texture **texture_image_fin_premiers_niveaux,
                                int position_x, int position_y, int tile_map[18][32], int secret, SDL_Texture **texture_image_nuage_1, SDL_Texture **texture_image_nuage_2,
                                int largeur, int hauteur, int largeur_tile, int hauteur_tile, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix);

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le niveau 4 */
void niveau_1(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance, SDL_Texture **texture_image_croix, SDL_Rect *rectangle_croix,
              SDL_Texture **texture, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran,
              SDL_Texture **texture_image_personnage, SDL_Rect *rectangle_personnage, SDL_Texture **texture_image_monstre_terrestre, SDL_Texture **texture_image_monstre_volant,
              SDL_Texture **texture_image_sol_surface, SDL_Texture **texture_image_sol_profondeur, SDL_Texture **texture_image_fond,
              SDL_Texture **texture_image_pique, niveaux *avancee_niveaux, int *mouvement_monstre,
              SDL_Surface **surface, int collectibles_intermediaires[3], time_t *timestamp,
              SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche,
              SDL_Keycode *touche_sauter_monter, int *decalage, int *secret_1, int *secret_2,
              int tile_map[18][32], int tile_map_niveau_1[18][110], SDL_Rect *rectangle_tile,
              itemMenu *itemsDemandeQuitter, int tailleDemande, SDL_Texture **texture_image_perso_gagnant,
              SDL_Texture **texture_texte, TTF_Font **police, SDL_Rect *rectangle_demande, SDL_Texture **texture_image_nuage_1, SDL_Texture **texture_image_nuage_2,
              SDL_Color couleurNoire, SDL_Texture **texture_image_fin_premiers_niveaux,
              int *avancer, int *reculer, int *sauter, int *position_avant_saut, int *saut, int *tombe,
              int *position_x_initiale, int *position_y_initiale, int *position_x, int *position_y,
              int *largeur, int *hauteur, int *largeur_tile, int *hauteur_tile, page_t *page_active,
              itemMenu *itemsDemandeSauvegarde, SDL_Keycode *touche_descendre, SDL_Keycode *touche_interagir, barreDeSon *barre_de_son, itemMenu *pseudo, 
              modes_t *modeActif, personnage_t *personnageActif, position_t *positionActive, int tailleNiveaux,
              time_t temps_debut_partie, int *compteur_mort, int *avancee_succes, int avancee_succes_intermediaires[10]);
#endif
