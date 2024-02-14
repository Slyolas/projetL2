#include <stdlib.h>
#include <string.h>
#include <mystring.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int string_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t string_existe( string_t * const string )
{
  if( string == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

static 
err_t string_detruire( string_t ** string ) 
{
  free((*string)->string);
  (*string)->afficher = NULL;
  (*string)->detruire = NULL;
  (*string)->string = NULL;
  free(*string);
  *string = NULL;
  
  string_cpt -= 1; /*Décrémente le compteur de l'objet après le déférencement complet de ce dernier*/
  return(OK) ; 
}

static
void string_afficher( string_t * const string ) 
{

  printf( "{" ) ; 
  if(  string_existe(string) ) 
    {
      printf( "%s" , string->string) ;
    }
  printf( "}" ) ; 
}

extern 
string_t * string_creer( char * const chaine ) 
{
  string_t * string = malloc(sizeof(string_t)) ; 
  string->string = malloc(strlen(chaine)+1);
  strcpy(string->string,chaine);
  string->detruire = string_detruire;
  string->afficher = string_afficher;
  string_cpt += 1; /*Incrémentation du compteur après la création de l'objet*/
  return( string ) ;
}
