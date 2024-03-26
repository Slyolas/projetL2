void jouer(SDL_Surface *ecran);
void deplacerJoueur(int carte[][26],SDL_Rect *pos,position_t direction);



typedef enum {HAUT,BAS,GAUCHE,DROITE}position_t;

typedef enum {VIDE,MUR,PERSO}map_t;

//Constante

#define TAILLE_BLOC 


#define FRAME_PERSO 16
