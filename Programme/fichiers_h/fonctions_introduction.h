#ifndef H_INTRODUCTION
#define H_INTRODUCTION
/* Squelette de la fonction mise_a_jour_rendu_introduction */
void mise_a_jour_rendu_introduction(SDL_Renderer **renderer, int indice, char *ligne,
                                    SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                                    SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, 
                                    TTF_Font **police, SDL_Color couleurBlanche,
                                    int largeur, int hauteur);
/* Squelette de la fonction introduction */
void introduction(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                  SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                  SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                  personnage_t *personnageActif, SDL_Color couleurBlanche,
                  int *largeur, int *hauteur, page_t *page_active);
#endif
