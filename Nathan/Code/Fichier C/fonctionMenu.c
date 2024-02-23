#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "fonctionMenu.h"
#include "fonctionMain.c"

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
}
*/

void new_game(settings_t *partie){

/*
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
*/
    partie->nom = malloc(sizeof(char)*LENGTH_NAME);
    char * nom1 ;
    //appelle de la fonction nom_perso
    nom_perso((&nom1));
    strcpy(partie->nom,nom1);
    //Une fois tout enregistrer appelle de la fonction sauvegarde
    sauvegarde(partie);

    //Libération de la mémoire
    free(nom1);
    nom1 = NULL;
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

void nom_perso(char **nom) {
    char confirmation[300];
    int choix_fait = 0;

    do{

        disable_echo();
        printf("\rVeuillez entrer le nom de votre personnage (max %d caractères) : ", LENGTH_NAME);

        (*nom) = (char *)malloc(LENGTH_NAME * sizeof(char) + 1);  // Alloue de la mémoire pour le nom
        int i = 0;
        int flag = 1;
        char c;


        while (flag) {
            c = getchar();

            if (c == '\n') {
                (*nom)[i] = '\0';
                flag = 0;
            } else if (c == 127 && i > 0) {
                // Touche Backspace (127 ASCII) pour supprimer le dernier caractère
                printf("\b \b");  // Efface le caractère précédent sur la console
                i--;
            } else if (i < LENGTH_NAME) {
                (*nom)[i] = c;
                putchar(c);
                i++;
            }
        }

        enable_echo();

        printf("\nEtes-vous sûr ? (oui/non)\n");
        scanf("%s", confirmation);
        clear_input_buffer();  // Vide le tampon d'entrée

        if (strcmp(confirmation, "oui") == 0) {
            choix_fait = 1;
        }else{
            free(*nom);
            *nom = NULL;
        }
    }while(choix_fait != 1);
}

//sauvegarde le nom/mode/genre de la partie
void sauvegarde(settings_t *partie) {
    
    FILE *file;

    // Ouvrir un fichier en mode écriture
    file = fopen("../Save/Sauvegarde.txt", "w");

    // Vérifier si l'ouverture du fichier a réussi
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Écrire les informations collectées
    fprintf(file, "%d\n%d\n%s\n%.2f\n", partie->difficulte, partie->perso, partie->nom, partie->chronometre);

    // Fermer le fichier
    if (fclose(file) != 0) {
        perror("Erreur lors de la fermeture du fichier");
        exit(EXIT_FAILURE);
    }

    printf("La partie a été sauvegardée avec succès!\n\n");
}


int charger_sauvegarde(settings_t *partie) {
    
    FILE *file;

    // Ouvrir le fichier en mode lecture
    file = fopen("../Save/Sauvegarde.txt", "r");

    // Vérifier si l'ouverture du fichier a réussi
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        return 0;
    }

    // Lire les informations de sauvegarde depuis le fichier
    fscanf(file, "%d\n%d\n", &(partie->difficulte), &(partie->perso));

    // Lire le nom
    char nom_buffer[LENGTH_NAME + 1];
    if (fscanf(file, "%10s\n", nom_buffer) == 1) {
        partie->nom = strdup(nom_buffer);
    } else {
        partie->nom = NULL;
        perror("Erreur lors de la lecture du nom depuis le fichier de sauvegarde");
    }

    fscanf(file, "%lf\n", &(partie->chronometre));

    // Fermer le fichier
    fclose(file);

    printf("Sauvegarde chargée avec succès!\n\n");
    return 1;
}


int parametre(){

}

// Fonction pour quitter le jeu en demandant de sauvegarder
void quitterJeu(settings_t *partie) {
    
    char reponse[10];

    // Demander à l'utilisateur s'il souhaite sauvegarder avant de quitter
    printf("Voulez-vous sauvegarder avant de quitter ? (oui/non): ");
    scanf("%s", reponse);

    if (strcmp(reponse, "oui") != 0) {
        return;
    }

    // Afficher un message de sortie et quitter le programme
    printf("Merci d'avoir joué. Au revoir !\n");

    // Arrêter le chronomètre  en cours
    stop_Chrono(partie);
    sauvegarde(partie);
    // Terminer le programme
    exit(0);
}


int main(){
    //lancement du jeu
    //appelle de la fonction menu

    // Initialiser la structure de sauvegarde
    settings_t *partie = malloc(sizeof(settings_t));

    printf("%d\n", partie->difficulte);

    partie->nom = NULL;
    start_Chrono(partie);

    // Appeler la fonction pour charger la sauvegarde
    if(charger_sauvegarde(partie)){
        // Utiliser les données de la sauvegarde
        printf("Difficulte: %d\n", partie->difficulte);
        printf("Perso: %d\n", partie->perso);
        printf("Nom: %s\n", partie->nom);
        printf("Chrono: %.2lf\n", partie->chronometre);
        printf("\n\n");
    }
    else{
        new_game(partie);
    }
       
    // Fin du jeu
    quitterJeu(partie);
    printf("\nTest fin\n");

    // Libérer la mémoire
    free(partie->nom);
    partie->nom = NULL;
    free(partie);
    partie = NULL;

    return 0;
}