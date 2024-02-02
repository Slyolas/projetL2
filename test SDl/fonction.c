#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"

/*
menu(){
    //regarde dans les fichiers si une sauvegarde existe
    if(sauvegarde){
        //charger partie
        if(charger){
            //lancement du jeu depuis la sauvegarde
            //appelle de la fonction ouverture_fichier
        }
        //nouvelle partie
        if(new game){
            //pop-up "etes vous sur"
            if(oui){
                //appel d'une fonction new game
            }
        }
        else{
            //retour menu
        }
    }
    else{
        //nouvelle partie
        //appel d'une fonction new game
    }
    //paramètre
}*/


void new_game(){

    settings_t * partie = malloc(sizeof(settings_t));

    //appelle de la fonction difficulté
    switch(difficulte()){
        case 1: partie->difficulte = NORMAL;
                break;
        case 2: partie->difficulte = HARD;
    }   

    //appelle de la fonction perso
    switch(perso()){
        case 1: partie->perso = MEN;
                break;
        case 2: partie->perso = WOMEN;
    }

    partie->nom = malloc(sizeof(char)*10);
    char * nom = malloc(sizeof(char)*10);

    //appelle de la fonction nom_perso
    nom_perso(nom);
    strcpy(partie->nom,nom);
    
    //Une fois tout enregistrer appelle de la fonction sauvegarde
    sauvegarde(partie);

    //Libération de la mémoire
    free(nom);
    nom = NULL;
    free(partie->nom);
    partie->nom = NULL;
}

int difficulte(){
    //choix difficulté

    /*Affichage des choix*/

    //return choix == NORMAL ? NORMAL : HARD;

}

int perso(){
    //choix du perso

    /*Affichage des perso*/

    //return choix == MEN ? MEN : WOMEN;

}

void nom_perso(char * nom){
    //choix du nom
    char confirmation[300];
    int choix_fait = 0;
    /*Affichage avec :*/
    do{
        printf("Veuillez entrez le nom de votre personnage : ");
        scanf("%s", nom);
        //Une fois la touche "entrer" selectionner
        printf("Etes vous sur ?");
        //choix entre oui||entrer et non
        scanf("%s", confirmation);
        if(strcmp(confirmation,"oui") == 0) 
            choix_fait = 1; 
    }while(choix_fait == 0);
}

//sauvegarde le nom/mode/genre de la partie
void sauvegarde(settings_t * partie) {

    FILE *file;

    //Ouverture d'un fichier en mode écriture
    file = fopen("../Save/Sauvegarde.txt", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    //Ecrire les information collecter
    fprintf(file, "%d\n%d\n%s\n", partie->difficulte, partie->perso, partie->nom);
    //Fermer le fichier
    fclose(file);

    printf("Game saved successfully!\n");
}

void charger_sauvegarde(){
    
}

int parametre(){

}





int main(){
    //lancement du jeu
    //appelle de la fonction menu
    new_game();
}