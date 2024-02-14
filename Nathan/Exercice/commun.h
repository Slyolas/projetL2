#ifndef _COMMUN_H_
#define _COMMUN_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>


/* Definition du type booleen */
typedef enum booleen_s { FAUX , VRAI } booleen_t ;

/* Definition du type erreur */
typedef int err_t ;

/* Definition du type operation sur les classes */
typedef enum operation_s { PARAMETRES , CREATION } operation_t ;

/* Constantes */

#define PARAM_TAILLE 1024


/* Erreurs */
#define OK 0

#define ERR_DEB_MEMOIRE -100 

#define ERR_LISTE_IND_ELEM  -200


/* Fonctions */

/*
 * Définitions des fonctions new et existe A FAIRE 
 */
booleen_t existe(void* const);

#endif

