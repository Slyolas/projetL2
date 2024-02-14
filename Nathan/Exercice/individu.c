#include <stdlib.h>
#include <string.h>
#include <individu.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int individu_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t individu_existe( individu_t * const individu )
{
  if( individu == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

static 
err_t individu_detruire( individu_t ** individu ) /*Implémentation du contenu de la fonction individu_detruire*/
{
  free((*individu)->nom); (*individu)->nom = NULL; 
  free((*individu)->prenom); (*individu)->prenom = NULL; 
  (*individu)->detruire = NULL;
  (*individu)->afficher = NULL;
  free(*individu);
  *individu = NULL;
  individu_cpt -= 1;  /*Décrémentation du compteur d' individu car on vient d'en détruire un*/
  return(OK) ; 
}

static
void individu_afficher( individu_t * const individu ) 
{

  printf( "{" ) ; 
  if(  individu_existe(individu) ) 
    {
      printf( "%s %s" , individu->prenom , individu->nom ) ;
    }
  printf( "}" ) ; 
}

extern 
individu_t * individu_creer( char * const prenom , char * const nom ) 
{
  individu_t * individu = malloc(sizeof(individu_t)) ;
  individu->nom = malloc(strlen(nom)+1);
  strcpy(individu->nom,nom) ;
  individu->prenom = malloc(strlen(prenom)+1);
  strcpy(individu->prenom,prenom);
  individu->afficher = individu_afficher;
  individu->detruire = individu_detruire;  
  individu_cpt += 1;  /*Incrémentation du compteur d'individu car on vient d'en créer un */


  return( individu ) ;
}
