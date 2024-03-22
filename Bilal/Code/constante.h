typedef enum deplacement {HAUT,BAS,GAUCHE,DROITE}deplacement_t;
typedef enum carte {MUR,VIDE,PERSO}carte_t;


typedef struct Perso {
    int offSet;
    Timer_t anim;
    int anim;
    int vitesse;
    int frame;
    deplacement_t status;
    void (*afficher)(void);
    void (*handle_events)(void);
}Perso_t ;


#define TAILLE_BLOC 32
#define FRAME 9
#define PERSO_HEIGHT 20
#define PERSO_WIDTH  20
#define PERSO_NBR_FRAME 9
#define PERSO_RIGHT 11
#define PERSO_LEFT 9
#define PERSO_DIRECTION 2

const int PERSO_DELAI_FRAME = 120; // délais entre deux frames (en ms)

const int PERSO_NB_ANIM = 3; // Nombre de frame d'animation

//Vitesse de marche du perso (en pixel par seconde)
const int PERSO_VITESSE = 120;