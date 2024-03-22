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

int main() {

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface de l'image du plein écran, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_plein_ecran = NULL;
    SDL_Texture *texture_image_plein_ecran = NULL;
    SDL_Rect rectangle_plein_ecran;

    /* Création des pointeurs sur la surface de l'image du retour en arrière, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_retour_en_arriere = NULL;
    SDL_Texture *texture_image_retour_en_arriere = NULL;
    SDL_Rect rectangle_retour_en_arriere;

    /* Création des pointeurs sur la surface de l'image des options, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_options = NULL;
    SDL_Texture *texture_image_options = NULL;
    SDL_Rect rectangle_options;

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_menu = NULL;
    SDL_Texture *texture_texte_menu = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    /* Variable de la couleur du titre */
    SDL_Color couleurTitre = {200, 200, 200, 255};

    /* Création des pointeurs sur la surface de l'image du menu et sur sa texture */
    SDL_Surface *image_menu = NULL;
    SDL_Texture *texture_image_menu = NULL;

    /* Création des pointeurs sur la surface du de l'image haut parleur actif et sur sa texture */
    SDL_Surface *image_hautParleurActif = NULL;
    SDL_Texture *texture_image_hautParleurActif = NULL;

    /* Création des pointeurs sur la surface du de l'image haut parleur désactivé et sur sa texture */
    SDL_Surface *image_hautParleurDesactive = NULL;
    SDL_Texture *texture_image_hautParleurDesactive = NULL;

    /* Touches pour les déplacements du personnage */
    SDL_Keycode touche_aller_a_droite;
    SDL_Keycode touche_aller_a_gauche;
    SDL_Keycode touche_sauter_monter;
    SDL_Keycode touche_descendre;
    SDL_Keycode touche_interagir;

    /* Création d'un rectangle pour le pseudo */
    SDL_Rect rectangle_pseudo;

    /* Création des pointeurs sur la surface de l'image du premier personnage et sur sa texture */
    SDL_Surface *image_perso_1 = NULL;
    SDL_Texture *texture_image_perso_1 = NULL;
    SDL_Rect rectangle_perso_1;

    /* Création des pointeurs sur la surface de l'image du deuxième personnage et sur sa texture */
    SDL_Surface *image_perso_2 = NULL;
    SDL_Texture *texture_image_perso_2 = NULL;
    SDL_Rect rectangle_perso_2;

    /* Variable de couleur blanche */
    SDL_Color couleurBlanche = {255, 255, 255, 255};

    /* Création du rectangle pour le texte de l'introduction */
    SDL_Rect rectangle_texte_introduction;

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    initialisation_objets(&renderer,
                          &image_plein_ecran, &texture_image_plein_ecran,
                          &image_retour_en_arriere, &texture_image_retour_en_arriere,
                          &image_options, &texture_image_options,
                          &police);

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

    initialisation_objets_menu_principal(&renderer, &image_menu, &texture_image_menu,
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

    initialisation_objets_options(&renderer,
                                  &image_hautParleurActif, &texture_image_hautParleurActif,
                                  &image_hautParleurDesactive, &texture_image_hautParleurDesactive,
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

    initialisation_objets_nouvelle_partie(&renderer,
                                          &image_perso_1, &texture_image_perso_1,
                                          &image_perso_2, &texture_image_perso_2,
                                          titres, itemsMenuNouvellePartie, &valider);

    /* Variable pour suivre la saisie */
    int modeSaisie = 0;

    /* Variable pour suivre le mode actif */
    modes_t modeActif = MODE_NORMAL; 

    /* Variable pour suivre le personnage actif */
    personnage_t personnageActif = PERSONNAGE_1;

    /* Chargement de la sauvegarde s'il y en a une */
    if(verification_sauvegarde()) {
        FILE *fichier_sauvegarde;

        /* Ouverture du fichier en mode lecture */
        fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "r");

        fscanf(fichier_sauvegarde, "%f\n", &(barre_de_son[0].volume));
        fscanf(fichier_sauvegarde, "%f\n", &(barre_de_son[1].volume));
        fscanf(fichier_sauvegarde, "%s\n", itemsTouches[1].texte);
        fscanf(fichier_sauvegarde, "%s\n", itemsTouches[3].texte);
        fscanf(fichier_sauvegarde, "%s\n", itemsTouches[5].texte);
        fscanf(fichier_sauvegarde, "%s\n", itemsTouches[7].texte);
        fscanf(fichier_sauvegarde, "%s\n", itemsTouches[9].texte);
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

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    page_t page_active = MENU_PRINCIPAL;

    page_t page_precedente = MENU_PRINCIPAL;

    while(programme_lance) {

        SDL_Event event;

        if(page_active == MENU_PRINCIPAL) {
            page_precedente = MENU_PRINCIPAL;
            menu_principal(&event, &window, &renderer, &programme_lance, &texture_image_menu,
                           &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                           &titre_menu_principal, &texte_menu, &texture_texte_menu, &police,
                           couleurTitre, couleurNoire,
                           itemsMenuPrincipal, tailleMenuPrincipal, &largeur, &hauteur, &page_active);
        }

        if(page_active == OPTIONS)
            options(&event, &window, &renderer, &programme_lance,
                    &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                    &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                    &texture_image_hautParleurActif,
                    &texture_image_hautParleurDesactive, sonsActifs,
                    rectangles_boutons_sons, &ongletActif,
                    &titre_options, &texte_menu, &texture_texte_menu, &police,
                    &selection_touche, &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                    &touche_descendre, &touche_interagir, couleurNoire,
                    itemsMenuOptions, tailleMenuOptions, itemsTouches, tailleTouches,
                    barre_de_son, tailleBarres, itemsBarres,
                    &largeur, &hauteur, &page_active, &page_precedente);

        if(page_active == NOUVELLE_PARTIE) {
            page_precedente = NOUVELLE_PARTIE;
            nouvelle_partie(&event, &window, &renderer, &programme_lance,
                            &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran, 
                            &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                            &rectangle_options, &texture_image_options, &modeSaisie,
                            &modeActif, &texture_image_perso_1, &rectangle_perso_1,
                            &texture_image_perso_2, &rectangle_perso_2, &personnageActif,
                            &pseudo, &rectangle_pseudo, barre_de_son,
                            &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                            &touche_descendre, &touche_interagir, titres, tailleTitres, &texte_menu, &texture_texte_menu, 
                            &police, couleurNoire,
                            itemsMenuNouvellePartie, &valider, &largeur, &hauteur, &page_active);
        }

        if(page_active == INTRODUCTION) {
            introduction(&event, &renderer, &programme_lance,
                         &rectangle_texte_introduction, &texte_menu, &texture_texte_menu, 
                         &personnageActif, couleurBlanche,
                         &largeur, &hauteur, &page_active);
            
            page_active = NIVEAU_1;
        }

        if(page_active == NIVEAU_1) {
            page_active = MENU_PRINCIPAL;
            page_precedente = MENU_PRINCIPAL;
            menu_principal(&event, &window, &renderer, &programme_lance, &texture_image_menu,
                           &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                           &titre_menu_principal, &texte_menu, &texture_texte_menu, &police,
                           couleurTitre, couleurNoire,
                           itemsMenuPrincipal, tailleMenuPrincipal, &largeur, &hauteur, &page_active);
        }

    }

    /*-------------------------------------------------------------*/

    /* Libération de la mémoire allouée dynamiquement */
    free(itemsMenuPrincipal);

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}