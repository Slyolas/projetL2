typedef enum deplacement {HAUT = 1,BAS,GAUCHE,DROITE}deplacement_t;
typedef enum carte {MUR,VIDE,PERSO}carte_t;


/*Constante*/
#define TAILLE_SPRITE 32
#define NB_FRAME_PERSO 9
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 900
#define DEPLACEMENT_PIXEL_PERSO 5
 

//Vitesse de marche du perso (en pixel par seconde)
const int PERSO_VITESSE = 120;