#include <stdio.h>
#include <SDL/SDL.h>
#include "commun.h"

void Demarrage_Timer(){
    started = VRAI;     /*Démarrage du timer*/

    paused = FAUX;      /*La mise en pause enlevée*/

    startTicks = SDL_GETTicks();    /*Récupèration du temps courant*/
}



void Arret_Timer(){
    started = FAUX;         /*Le timer est arrêté*/

    paused = FAUX;          /*On enlève le pause*/
}


int get_ticks(){
    if(started == VRAI){
        if(paused == VRAI){     /*On retourne le nombre de ticks quand le timer a été mis en pause */
            return pausedTicks;
        }else{                  /*Sinon, on retourne le temps courant moins le temps obtenu depuis le démarrage du timer*/
            return SDL_GetTicks() - startTicks;
        }
    }
    return 0;           /*Cas ou le timer n'est pas en marche*/
}




void Pause_Timer(){
    if( (started == VRAI) && (paused == FAUX)){     /*Mise en pause du timer si il était lancer et pas mis en pause*/
        /*Mise en pause du timer*/
        paused = true;
        /*On calcule le temps de pause*/
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}


void UnPause_Timer(){
    if(paused == VRAI){
        /*On retire le pause si il était en pause*/
        paused = FAUX;

        /*On remet à zero le startTicks*/
        startTicks = SDL_GetTicks() - pausedTicks;
        /*Remise à zéro du pausedTicks*/
        pausedTicks = 0;
    }
}


bool_t is_started_Timer(){
    return started;             /*Envoie la variable started pour savoir si le timer est lancé*/
}


bool_t is_paused_Timer(){
    return paused;              /*Envoie la variable paused pour savoir si le timer est en pause*/
}