#include <stdio.h>
#include "fonctionMain.h"

// Pour avoir le temps réel et non celui du CPU avec #include <time.h>
#include <sys/time.h>

// Fonction pour démarrer le chronomètre
void start_Chrono(settings_t *partie) {
    gettimeofday(&(partie->start_time), NULL);
}

// Fonction pour arrêter le chronomètre et afficher la durée écoulée
void stop_Chrono(settings_t *partie) {
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    double interval_time = (end_time.tv_sec - partie->start_time.tv_sec) +
                           (end_time.tv_usec - partie->start_time.tv_usec) / 1e6;

    //Si il y a déjà un chrono d'enregistrer dans la sauvegarde
    if(partie->chronometre != 0.00){
        interval_time += partie->chronometre;
    }

    printf("Durée total : %.2f secondes\n", interval_time);
    partie->chronometre = interval_time;
}