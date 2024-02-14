#ifndef _LISTE_SDD_H_
#define _LISTE_SDD_H_

#include <commun.h>
#include <objet.h>


#define LISTE_NULL NULL
#define LISTE_ID_NULL -1


typedef struct liste_s liste_t;

struct liste_s{
  int nb ;		/* Nombre d'objets dans la liste  */
  objet_t ** liste ;	/* liste  des objets */
  err_t (*detruire)( liste_t **);
  void (*afficher)(liste_t * const, const char);
  int (*nb_lire)(liste_t * const);
  objet_t * (*elem_lire)( liste_t * const , const int );
  booleen_t (*existe)( liste_t * const) ; 
  booleen_t (*vide)( liste_t * const) ; 
  err_t (*elem_ecrire)( liste_t *, objet_t * const ,const int ) ;
  
};

#endif
