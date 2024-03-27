#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../fichiers_h/fonctions_generales.h"
#include "../fichiers_h/fonctions_menu_principal.h"
#include "../fichiers_h/fonctions_options.h"
#include "../fichiers_h/fonctions_nouvelle_partie.h"
#include "../fichiers_h/fonctions_introduction.h"
#include "../fichiers_h/fonctions_carte.h"

int main() {

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    int i;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Initialisation de la surface */
    SDL_Surface *surface = NULL;

    /* Création du pointeur sur la texture du texte */
    SDL_Texture *texture_texte = NULL;

    /* Création du pointeur sur la texture de l'image du plein écran et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_plein_ecran = NULL;
    SDL_Rect rectangle_plein_ecran;

    /* Création du pointeur sur la texture de l'image du retour en arrière et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_retour_en_arriere = NULL;
    SDL_Rect rectangle_retour_en_arriere;

    /* Création du pointeur sur la texture de l'image des options et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_options = NULL;
    SDL_Rect rectangle_options;

    /* Création du pointeur sur la texture de l'image du plein écran et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_passer = NULL;
    SDL_Rect rectangle_passer;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Création du pointeur sur la texture de l'image du menu */
    SDL_Texture *texture_image_menu = NULL;

    /* Création du pointeur sur la texture de l'image de la carte */
    SDL_Texture *texture_image_carte = NULL;

    /* Création du pointeur sur la texture de l'image haut parleur actif */
    SDL_Texture *texture_image_hautParleurActif = NULL;

    /* Création du pointeur sur la texture de l'image haut parleur désactivé */
    SDL_Texture *texture_image_hautParleurDesactive = NULL;

    /* Touches pour les déplacements du personnage */
    SDL_Keycode touche_aller_a_droite;
    SDL_Keycode touche_aller_a_gauche;
    SDL_Keycode touche_sauter_monter;
    SDL_Keycode touche_descendre;
    SDL_Keycode touche_interagir;

    /* Création d'un rectangle pour le pseudo */
    SDL_Rect rectangle_pseudo;

    /* Création du pointeur sur la texture de l'image du premier personnage et de son rectangle */
    SDL_Texture *texture_image_perso_1 = NULL;
    SDL_Rect rectangle_perso_1;

    /* Création du pointeur sur la texture de l'image du deuxième personnage et de son rectangle */
    SDL_Texture *texture_image_perso_2 = NULL;
    SDL_Rect rectangle_perso_2;

    /* Création des pointeurs sur la texture des différentes images pour le premier personnage */
    SDL_Texture *texture_image_perso_1_bas_1 = NULL;
    SDL_Texture *texture_image_perso_1_bas_2 = NULL;
    SDL_Texture *texture_image_perso_1_haut_1 = NULL;
    SDL_Texture *texture_image_perso_1_haut_2 = NULL;
    SDL_Texture *texture_image_perso_1_bas_gauche_1 = NULL;
    SDL_Texture *texture_image_perso_1_bas_gauche_2 = NULL;
    SDL_Texture *texture_image_perso_1_haut = NULL;
    SDL_Texture *texture_image_perso_1_droite = NULL;
    SDL_Texture *texture_image_perso_1_gauche = NULL;
    SDL_Texture *texture_image_perso_1_pose = NULL;

    /* Création des pointeurs sur la texture des différentes images pour le deuxième personnage */
    SDL_Texture *texture_image_perso_2_bas_1 = NULL;
    SDL_Texture *texture_image_perso_2_bas_2 = NULL;
    SDL_Texture *texture_image_perso_2_haut_1 = NULL;
    SDL_Texture *texture_image_perso_2_haut_2 = NULL;
    SDL_Texture *texture_image_perso_2_bas_gauche_1 = NULL;
    SDL_Texture *texture_image_perso_2_bas_gauche_2 = NULL;
    SDL_Texture *texture_image_perso_2_haut = NULL;
    SDL_Texture *texture_image_perso_2_droite = NULL;
    SDL_Texture *texture_image_perso_2_gauche = NULL;
    SDL_Texture *texture_image_perso_2_pose = NULL;

    /* Création du rectangle pour le texte de l'introduction */
    SDL_Rect rectangle_texte_introduction;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    /* Variable de la couleur du titre */
    SDL_Color couleurTitre = {200, 200, 200, 255};

    /* Variable de couleur blanche */
    SDL_Color couleurBlanche = {255, 255, 255, 255};

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    initialisation_objets(&renderer, &surface, &texture_image_plein_ecran,
                          &texture_image_retour_en_arriere, &texture_image_options,
                          &texture_image_passer, &police);

    /*-------------------------------------------------------------*/

    /* Objets du menu principal */

    itemMenu titre_menu_principal;

    int tailleMenuPrincipal;

    if(!verification_sauvegarde()) {
        tailleMenuPrincipal = 2;
    }
    else
        tailleMenuPrincipal = 3;

    /* Allocation dynamique de mémoire pour le tableau itemsMenuPrincipal en fonction de tailleMenuPrincipal */
    itemMenu *itemsMenuPrincipal = malloc(tailleMenuPrincipal * sizeof(itemMenu));
    if (itemsMenuPrincipal == NULL) {
        erreur("Allocation de la mémoire");
        exit(EXIT_FAILURE);
    }

    initialisation_objets_menu_principal(&renderer, &surface, &texture_image_menu,
                                         &titre_menu_principal, itemsMenuPrincipal, tailleMenuPrincipal);  

    /* Objets des options */

    itemMenu titre_options;

    int tailleBarres = 2;

    barreDeSon barre_de_son[tailleBarres];

    int tailleMenuOptions = 2;

    itemMenu itemsMenuOptions[tailleMenuOptions];
    
    int tailleTouches = 10;

    itemMenu itemsTouches[tailleTouches];

    itemMenu itemsBarres[tailleBarres];

    initialisation_objets_options(&renderer, &surface, &texture_image_hautParleurActif,
                                  &texture_image_hautParleurDesactive,
                                  &titre_options, itemsMenuOptions, itemsTouches, itemsBarres);

    /* Variable pour suivre l'onglet actif */
    option_t ongletActif = ONGLET_SON;                          

    /* Variable pour suivre l'état du son (activé/désactivé) */
    SDL_bool sonsActifs[tailleBarres];

    /* Rectangles des boutons de son */
    SDL_Rect rectangles_boutons_sons[tailleBarres]; 

    /* Variable pour suivre l'état de la sélection de touche (activé/désactivé) */
    int selection_touche = 0;

    /* Objets du menu nouvelle partie */

    itemMenu pseudo;
    pseudo.texte[0] = '\0';

    int tailleTitres = 3;

    itemMenu titres[tailleTitres];

    int tailleMenuNouvellePartie = 2;

    itemMenu itemsMenuNouvellePartie[tailleMenuNouvellePartie];

    itemMenu valider;

    initialisation_objets_nouvelle_partie(&renderer, &surface, &texture_image_perso_1,
                                          &texture_image_perso_2,
                                          titres, itemsMenuNouvellePartie, &valider);

    /* Variable pour suivre la saisie */
    int modeSaisie = 0;

    /* Variable pour suivre le personnage actif */
    personnage_t personnageActif = PERSONNAGE_1;

    /* Variable pour suivre le mode actif */
    modes_t modeActif = MODE_NORMAL; 

    /* Objets de la carte */

    int tailleNiveaux = 4;

    itemMenu itemsNiveaux[tailleNiveaux];

    position_t positionActive = NIVEAU1;

    initialisation_objets_carte(&renderer, &surface, &texture_image_carte,
                                &texture_image_perso_1_bas_1, &texture_image_perso_1_bas_2,
                                &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                                &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                                &texture_image_perso_1_haut, &texture_image_perso_1_droite,
                                &texture_image_perso_1_gauche, &texture_image_perso_1_pose,
                                &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2,
                                &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                                &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2,
                                &texture_image_perso_2_haut, &texture_image_perso_2_droite,
                                &texture_image_perso_2_gauche, &texture_image_perso_2_pose,
                                itemsNiveaux); 

    /* Chargement de la sauvegarde s'il y en a une */
    if(verification_sauvegarde()) {
        FILE *fichier_sauvegarde;

        /* Ouverture du fichier en mode lecture */
        fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "r");

        fscanf(fichier_sauvegarde, "%f\n", &(barre_de_son[0].volume));
        fscanf(fichier_sauvegarde, "%f\n", &(barre_de_son[1].volume));

        for(i = 1; i < tailleTouches; i+=2)
            fscanf(fichier_sauvegarde, "%s\n", itemsTouches[i].texte);
        touche_aller_a_droite = SDL_GetKeyFromName(itemsTouches[1].texte);
        touche_aller_a_gauche = SDL_GetKeyFromName(itemsTouches[3].texte);
        touche_sauter_monter = SDL_GetKeyFromName(itemsTouches[5].texte);
        touche_descendre = SDL_GetKeyFromName(itemsTouches[7].texte);
        touche_interagir = SDL_GetKeyFromName(itemsTouches[9].texte);
        sprintf(itemsTouches[1].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_droite));
        sprintf(itemsTouches[3].texte, "                 %s                 ", SDL_GetKeyName(touche_aller_a_gauche));
        sprintf(itemsTouches[5].texte, "                 %s                 ", SDL_GetKeyName(touche_sauter_monter));
        sprintf(itemsTouches[7].texte, "                 %s                 ", SDL_GetKeyName(touche_descendre));
        sprintf(itemsTouches[9].texte, "                 %s                 ", SDL_GetKeyName(touche_interagir));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&personnageActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&modeActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&positionActive));

        /* Fermeture du fichier */
        if (fclose(fichier_sauvegarde) != 0)
            erreur("Fermeture du fichier");
    }
    else {
        barre_de_son[0].volume = 0.5;
        barre_de_son[1].volume = 0.5;
    } 

    if(barre_de_son[0].volume)
        sonsActifs[0] = SDL_TRUE;
    else
        sonsActifs[0] = SDL_FALSE;
    
    if(barre_de_son[1].volume)
        sonsActifs[1] = SDL_TRUE;
    else
        sonsActifs[1] = SDL_FALSE; 
           
    /*-------------------------------------------------------------*/

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    page_t page_active = MENU_PRINCIPAL;

    page_t page_precedente = MENU_PRINCIPAL;

    SDL_Event event;

    while(programme_lance) {

        /* Page du menu principal */
        if(page_active == MENU_PRINCIPAL) {
            page_precedente = MENU_PRINCIPAL;
            menu_principal(&event, &window, &renderer, &programme_lance, &texture_image_menu,
                           &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                           &titre_menu_principal, &surface, &texture_texte, &police,
                           couleurTitre, couleurNoire,
                           itemsMenuPrincipal, tailleMenuPrincipal, &largeur, &hauteur, &page_active);
        }

        /* Page des options */
        else if(page_active == OPTIONS)
            options(&event, &window, &renderer, &programme_lance,
                    &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                    &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                    &texture_image_hautParleurActif,
                    &texture_image_hautParleurDesactive, sonsActifs,
                    rectangles_boutons_sons, &ongletActif,
                    &titre_options, &surface, &texture_texte, &police,
                    &selection_touche, &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                    &touche_descendre, &touche_interagir, couleurNoire,
                    itemsMenuOptions, tailleMenuOptions, itemsTouches, tailleTouches,
                    barre_de_son, tailleBarres, itemsBarres,
                    &largeur, &hauteur, &page_active, &page_precedente);

        /* Page de la nouvelle partie */
        else if(page_active == NOUVELLE_PARTIE) {
            page_precedente = NOUVELLE_PARTIE;
            nouvelle_partie(&event, &window, &renderer, &programme_lance,
                            &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran, 
                            &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                            &rectangle_options, &texture_image_options, &modeSaisie,
                            &modeActif, &texture_image_perso_1, &rectangle_perso_1,
                            &texture_image_perso_2, &rectangle_perso_2, &personnageActif,
                            &pseudo, &rectangle_pseudo, barre_de_son,
                            &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                            &touche_descendre, &touche_interagir, titres, tailleTitres, &surface, &texture_texte, 
                            &police, couleurNoire,
                            itemsMenuNouvellePartie, &valider, &largeur, &hauteur, &page_active);
        }

        /* Page de l'introduction */
        else if(page_active == INTRODUCTION) {
            introduction(&event, &renderer, &programme_lance,
                         &rectangle_passer, &texture_image_passer,
                         &rectangle_texte_introduction, &surface, &texture_texte, 
                         &personnageActif, couleurBlanche,
                         &largeur, &hauteur, &page_active);
            
            page_active = NIVEAU_1;
        }

        /* Page de la carte */
        else if(page_active == CARTE) {
            page_precedente = CARTE;

            if(personnageActif == PERSONNAGE_1)
                carte(&event, &window, &renderer, &programme_lance, &texture_image_carte,
                      &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                      &rectangle_options, &texture_image_options,
                      &texture_image_perso_1_bas_1, &texture_image_perso_1_bas_2,
                      &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                      &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                      &texture_image_perso_1_haut, &texture_image_perso_1_droite,
                      &texture_image_perso_1_gauche, &texture_image_perso_1_pose,
                      &texture_image_perso_1, &rectangle_perso_1,
                      &surface, &texture_texte, &police,
                      &positionActive, couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active);

            else
                carte(&event, &window, &renderer, &programme_lance, &texture_image_carte,
                      &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                      &rectangle_options, &texture_image_options,
                      &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2,
                      &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                      &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2,
                      &texture_image_perso_2_haut, &texture_image_perso_2_droite,
                      &texture_image_perso_2_gauche, &texture_image_perso_2_pose,
                      &texture_image_perso_2, &rectangle_perso_1,
                      &surface, &texture_texte, &police,
                      &positionActive, couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active);
        }

        /* Page du niveau 1 */
        else if(page_active == NIVEAU_1) {
            page_active = MENU_PRINCIPAL;
            page_precedente = MENU_PRINCIPAL;
            menu_principal(&event, &window, &renderer, &programme_lance, &texture_image_menu,
                           &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                           &titre_menu_principal, &surface, &texture_texte, &police,
                           couleurTitre, couleurNoire,
                           itemsMenuPrincipal, tailleMenuPrincipal, &largeur, &hauteur, &page_active);
        }

    }

    /*-------------------------------------------------------------*/

    /* Libération de la mémoire allouée dynamiquement */
    free(itemsMenuPrincipal);

    detruire_objets(&police, &texture_image_plein_ecran, &texture_image_retour_en_arriere,
                    &texture_image_options, &texture_image_passer, &texture_image_menu, &texture_image_carte,
                    &texture_image_hautParleurActif, &texture_image_hautParleurDesactive,
                    &texture_image_perso_1, &texture_image_perso_2, &texture_image_perso_1_bas_1,
                    &texture_image_perso_1_bas_2, &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                    &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                    &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2, 
                    &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                    &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}