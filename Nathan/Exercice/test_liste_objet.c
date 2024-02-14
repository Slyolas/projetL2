#include <stdio.h>
#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste_objet.h>

int
main() 
{
  err_t noerr = OK; 
  liste_t * liste = NULL ;

  /* 
   * Creation des objets a mettre dans la liste 
   * idem test_liste mais avec la fonction new 
   * A FAIRE 
   */
  individu_t * indiv_1 = individu_creer( "Roger" , "Waters" ) ; 
  individu_t * indiv_2 = individu_creer( "Minecraft" , "NathaN" ) ; 
  fraction_t * frac_1 = fraction_creer( 337 , 16 ) ;
  fraction_t * frac_2 = fraction_creer( 61 , 198413 ) ;
  string_t * str_1 = string_creer( "azertyuiop" ) ; 
  string_t * str_2 = string_creer( "qsdfghjklm" ) ;
  string_t * str_3 = string_creer( "wxcvbn" ) ; 

  printf( "Debut du programme des test sur les objets de type liste_t\n" ) ; 
  /*Obligé de créer la liste pour pouvoir utiliser les ptr sur ptr*/
  existe(liste) ? printf("Ok !\n") : printf("Ko !\n");
  
  printf( "Test creation liste_t\n" ) ;

  liste = liste_creer(8) ;  
  liste_elem_ecrire( liste , (objet_t *)indiv_1 , 2 ) ;
  liste_elem_ecrire( liste , (objet_t *)frac_1  , 6 ) ;
  liste_elem_ecrire( liste , (objet_t *)str_1   , 4 ) ;
  liste_elem_ecrire( liste , (objet_t *)indiv_2 , 1 ) ;
  liste_elem_ecrire( liste , (objet_t *)frac_2  , 3 ) ;
  liste_elem_ecrire( liste , (objet_t *)str_2   , 5 ) ;
  liste_elem_ecrire( liste , (objet_t *)str_3   , 7 ) ;

  printf( "Test affichage liste \n" ) ;
  liste->afficher( liste , '|' ) ; 
  printf( "\n");

  printf( "Test d'existance sur une liste_t existant\n" ) ;
  ( liste->existe(liste) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  if( ( noerr = liste->detruire( &liste) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "Fin du programme des test sur les objets de type liste_t\n" ) ; 
  
  return(0) ; 
}
