#ifndef _PERSONNE_H_
#define _PERSONNE_H_

#include <individu.h>
#include <mystring.h>

/*
 * DEFINITION OBJET "PERSONNE"  
 */

typedef struct Personne personne_t;
struct Personne {
    individu_t identite;
    string_t adresse;
};

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets personne_t comme variable externe
 * pour compter les references sur ces objets 
 */

extern unsigned long int personne_cpt  ;

/* 
 * FONCTIONS
 */

/***********/
/* A FAIRE */
/***********/

#endif
