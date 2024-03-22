#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "constante.h"




void handle_events(){
    /*Si la touche du bas est pressé*/
    if(event.type == SDL_KEYDOWN){
        /*Mise à jour de la vitesse*/
        switch(event.key.keysym.sym){
            case SDLK_RIGHT:
                vitesse += (PERSO_VITESSE / FRAMES_PER_SECOND);
                break;
            case SDLK_LEFT:
                vitesse += (PERSO_VITESSE / FRAMES_PER_SECOND);
                break;
            default:
                break;
        }
    }
    else if(event.type == SDL_KEYUP){
        switch(event.key.keysym.sym){
            case SDLK_RIGHT:
                vitesse -= (PERSO_VITESSE / FRAMES_PER_SECOND);
                break;
            case SDLK_LEFT:
                vitesse += (PERSO_VITESSE / FRAMES_PER_SECOND);
                break;
            default:
                break;
        }
    }
}

void perso_afficher(){
    /*Mouvement du personnage*/
    offSet += vitesse;
    /*Si le personnage fini sur une bordure de l'écran, annule la vitesse*/
    if((offSet < 0) || ((offSet + PERSO_WIDTH) > PERSO_WIDTH)){
        offSet -= vitesse;
    }
    if(vitesse < 0){
        /*Le profil du perso sera mis sur la gauche*/
        status = GAUCHE;
    }else if(vitesse > 0){
        /*Le profil du perso sera mis sur la droite*/
        status = DROITE;
        /*On bouge à la prochaine frame (image) du personnage*/
        frame++;
    }else{
        /*Remet le sprite à l'état initial*/
        frame = 1;
    }

    if(frame >= FRAME){
        frame = 0;
    }

    if(status == DROITE){
        apply_surface( offset, SCREEN_HEIGH - PERSO_HEIGHT, perso,screen,&clipsRight[frame]);
    }else if(status == GAUCHE){
        apply_surface(offSet,SCREEN_HEIGH - PERSO_HEIGHT, perso,screen,&clipsLeft[frame])
    }

}


void set_clips()
{
    //On coupe la feuille de sprite
    clipsRight[ i ].x = PERSO_WIDTH * i;
    clipsRight[ i ].y = 0;
    clipsRight[ i ].w = PERSO_WIDTH;
    clipsRight[ i ].h = PERSO_HEIGHT;


    clipsLeft[ i ].x = PERSO_WIDTH * i;
    clipsLeft[ i ].y = PERSO_HEIGHT;
    clipsLeft[ i ].w = PERSO_WIDTH;
    clipsLeft[ i ].h = PERSO_HEIGHT;
}

SDL_Rect position, positionJoueur;

void joueur(SDL_Surface* ecran){

    SDL_Surface *perso[FRAME] = {NULL};
    SDL_Surface *persoActuel = NULL;


    SDL_Event event;

    int continuer = 1;
    int i = 0, j = 0;


    perso[BAS] = IMG_Load("../Image_Perso/1gars_img");

    persoActuel = perso[BAS];


    positionJoueur = (SDL_Rect){
        .x = 3,
        .y = 3
    };

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            
        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        
        position.x = positionJoueur.x * TAILLE_BLOC;
        position.y = positionJoueur.y * TAILLE_BLOC;
        
        SDL_Flip(ecran);
        
    }
    for(i = 0; i < FRAME; ++i){
        SDL_FreeSurface(perso[i]);
    }






}




int main(){

}
