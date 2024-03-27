typedef enum deplacement {HAUT = 1,BAS,GAUCHE,DROITE}deplacement_t;
typedef enum carte {MUR,VIDE,PERSO}carte_t;



#define TAILLE_BLOC 32


const int PERSO_DELAI_FRAME = 120; // délais entre deux frames (en ms)
 
const int PERSO_NB_ANIM = 3; // Nombre de frame d'animation

//Vitesse de marche du perso (en pixel par seconde)
const int PERSO_VITESSE = 120;