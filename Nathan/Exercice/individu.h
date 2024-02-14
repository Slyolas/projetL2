#ifndef _INDIVIDU_H_
#define _INDIVIDU_H_

#include <objet.h>


/*
 * DEFINITION OBJET "INDIVIDU"  
 */

typedef struct individu_s individu_t;
 struct individu_s 
{
  err_t (*detruire)(individu_t **);              /*Ajout du pointeur sur fonction permettant la destruction de la structure*/
  void (*afficher)(individu_t * const);              /*Ajout du pointeur sur fonction permettant à l'affichage de la structure*/
  char * nom ;
  char * prenom ;
};

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets individu_t comme variable externe
 * pour compter les references sur ces objets 
 */

extern unsigned long int individu_cpt  ;

/* 
 * FONCTIONS
 */

extern individu_t * individu_creer(char * const prenom , char * const nom ) ;
extern booleen_t individu_existe( individu_t * const individu ) ;

#endif
