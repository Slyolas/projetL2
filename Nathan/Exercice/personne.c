#include <stdlib.h>
#include <string.h>
#include <personne.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int personne_cpt = 0 ; 

/* 
 * FONCTIONS
 */



extern booleen_t personne_existe(personne_t * const p){
    if (p == NULL){
        return(FAUX);
    }else{
        return(VRAI);
    }
}













extern personne_t personne_creer(const char * nom, const char * prenom, const char * adresse){
    personne_t personne = NULL;

    if(( personne = malloc(sizeof(personne_t))) == NULL){
        fprintf(stderr, "personne_creer : Débordement mémoire lors de la création d'une personne\n");
        return((personne_t *)NULL);
    }
    







}
extern personne_detruire(personne_t ** p){
    (*p)->adresse->detruire((string_t**)&((*p)->adresse));
    (*p)->identite->detruire((individu_t**)&((*p)->identite));
    free(*p);
    *p = NULL;


    personne_cpt -= 1;
    return(OK);
}


