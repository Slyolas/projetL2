#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "code.h"


SDL_Rect position,position_Joueur;

SDL_Surface *Perso[FRAME_PERSO] = {NULL};

SDL_Surcace *PersoActuel = NULL;


void jouer(SDL_Surface* ecran){
    SDL_Event event;
    int continuer = 1;
    int i,j;
    Perso[BAS] = IMG_Load("../Image_Perso/1gars_img");
    PersoActuel = Perso[BAS];
    int carte[11][26];
    positionJoueur.x = 3;
    positionJoueur.y = 3;
    SDL_EnableKeyRepeat(100,100);
    SDL_BlitSurface(PersoActuel,NULL,ecran, &position);
        while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                swtch(event.key.keysym.sym){
                    case SDLK_UP:
                        deplacerJoueur(carte,&position_Joueur, HAUT);
                        break;
                    case SDLK_DOWN:
                        deplacerJoueur(carte,&position_Joueur, BAS);
                        break;
                    case SDLK_RIGHT:
                        deplacerJoueur(carte,&position_Joueur, DROITE);
                        break;
                    case SDLK_LEFT:
                        deplacerJoueur(carte,&position_Joueur, GAUCHE);
                        break; 
                }
                break;
            
        }
        SDL_FillRect(ecran,NULL,MapRGB(ecran->format,255,255,255));
        position.x *= TAILLE_BLOC; 
        position.y *= TAILLE_BLOC; 
        
        SDL_Flip(ecran);
    }


    SDL_EnableKeyRepeat(0,0);

    for(i = 0; i < FRAME_PERSO;i++){
        SDL_FreeSurface(Perso[i]);
    }

}



void deplacerJoueur(int carte[][26],SDL_Rect *pos,position_t direction){
    switch(direction){
        case HAUT:
            pos->y--;
            break;
        case BAS:
            pos->y++;
            break;
        case GAUCHE:
            pos->x--;
            break;
        case DROITE:
            pos->x++;
            break;
        
    }


}