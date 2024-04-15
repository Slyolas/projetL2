#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

typedef enum {MUR,VER,HOR,HDR,BDR,BGR,HGR,CRX,ACT,FIN}position_pipe_t;
/**
 * Bordure -> MUR 
 * pipe verticale -> VER
 * pipe horizontal -> HOR
 * pipe Haut droit -> HDR
 * pipe Bas droit -> BDR
 * pipe Haut Gauche -> HGR
 * pipe Bas Gauche -> BGR
 * pipe croix -> CRX
 * pipe actuelle -> ACT 
 * lieu d'arrivé -> FIN
*/







typedef struct coordonne_s{
    int x;
    int y;
}coordonnee_t;



// Dimensions de la fenêtre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Dimensions des tiles
#define TILE_MAP_X 19
#define TILE_MAP_Y 27

#define TILE_SIZE_X SCREEN_WIDTH / TILE_MAP_Y

#define TILE_SIZE_Y SCREEN_HEIGHT / TILE_MAP_X


// Coordonnées de début et de fin du chemin
#define START_CARRE_1_X 2
#define START_CARRE_1_Y 0

#define START_CARRE_2_X 11
#define START_CARRE_2_Y 9

#define START_CARRE_3_X 13
#define START_CARRE_3_Y 16

#define START_CARRE_4_X 23
#define START_CARRE_4_Y 9

#define END_X 24
#define END_Y 0
