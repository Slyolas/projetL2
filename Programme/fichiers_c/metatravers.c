#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../fichiers_h/fonctions_generales.h"
#include "../fichiers_h/fonctions_menu_principal.h"
#include "../fichiers_h/fonctions_options.h"
#include "../fichiers_h/fonctions_nouvelle_partie.h"
#include "../fichiers_h/fonctions_introduction.h"
#include "../fichiers_h/fonctions_carte.h"
#include "../fichiers_h/fonctions_niveau_1.h"
#include "../fichiers_h/fonctions_arrivee_niveaux_2_3.h"
#include "../fichiers_h/fonctions_niveau_2.h"
#include "../fichiers_h/fonctions_niveau_3.h"
#include "../fichiers_h/fonctions_niveau_4.h"

int main() {

    time_t timestamp = time( NULL );
    int mouvement_monstre;

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    int i, x, y;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Initialisation de la surface */
    SDL_Surface *surface = NULL;

    /* Initialisation de la texture */
    SDL_Texture *texture;

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

    SDL_Texture *texture_image_monstre_terrestre = NULL;
    SDL_Texture *texture_image_monstre_volant = NULL;

    /* Création des pointeurs sur la texture des différentes images du salon en arrivant dans le niveau 3 */
    SDL_Texture *texture_image_fond_niveau_1 = NULL;
    SDL_Texture *texture_image_sol_surface_niveau_1 = NULL;
    SDL_Texture *texture_image_sol_profondeur_niveau_1 = NULL;

    /* Création des pointeurs sur la texture des différentes images du salon en arrivant dans le niveau 2 */
    SDL_Texture *texture_image_fond_niveau_2 = NULL;
    SDL_Texture *texture_image_dossier_niveau_2 = NULL;
    SDL_Texture *texture_image_sol_niveau_2 = NULL;

    /* Création des pointeurs sur la texture des différentes images du salon en arrivant dans le niveau 3 */
    SDL_Texture *texture_image_fond_niveau_3 = NULL;
    SDL_Texture *texture_image_dossier_niveau_3 = NULL;
    SDL_Texture *texture_image_sol_niveau_3 = NULL;
    SDL_Texture *barre_windows_1 = NULL; 
    SDL_Texture *barre_windows_2 = NULL; 
    SDL_Texture *barre_windows_3 = NULL;
    SDL_Texture *barre_windows_4 = NULL;

    /* Création des pointeurs sur la texture des différentes images pour les étages */
    SDL_Texture *texture_image_mur = NULL;
    SDL_Texture *texture_image_fond_niveau_4 = NULL;
    SDL_Texture *texture_image_bordure_niveau_4 = NULL;
    SDL_Texture *texture_image_porte = NULL;
    SDL_Texture *texture_image_pique = NULL;

    /* Création des pointeurs sur la texture des différentes images pour la fin des niveaux */
    SDL_Texture *texture_image_fin_premiers_niveaux = NULL;
    SDL_Texture *texture_image_fin_dernier_niveau = NULL;

    /* Création du rectangle pour le texte de l'introduction */
    SDL_Rect rectangle_texte_introduction;

    /* Création du rectangle pour la demande de sauvegarde */
    SDL_Rect rectangle_demande;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 255};

    /* Variable de la couleur du titre principal */
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

    /*---------------------------------------------------------------- Initialisation des objets ----------------------------------------------------------------*/

    /* Objets globaux */

    int tailleDemande = 3;

    itemMenu itemsDemandeSauvegarde[tailleDemande];

    itemMenu itemsDemandeQuitter[tailleDemande];

    int tailleNiveaux = 4;

    niveaux avancee_niveaux[tailleNiveaux];

    int collectibles_intermediaires[3];

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    initialisation_objets(&renderer, &surface, &texture_image_plein_ecran,
                          &texture_image_retour_en_arriere, &texture_image_options,
                          &texture_image_passer, itemsDemandeSauvegarde, itemsDemandeQuitter,
                          &texture_image_fin_premiers_niveaux, &texture_image_monstre_terrestre,
                          &texture_image_monstre_volant,
                          avancee_niveaux, &police);

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

    char pseudo_temporaire[11];
    pseudo_temporaire[0] = '\0';

    personnage_t personnage_temporaire;

    modes_t mode_temporaire;

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

    int touche_pressee = 0;

    itemMenu itemsNiveaux[tailleNiveaux];

    position_t positionActive = NIVEAU1;

    direction_t direction = BAS;

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

    /* Objets des niveaux */

    /* Initialisation de la largeur de chaque case */
    int largeur_tile;
    /* Initialisation de la hauteur de chaque case */
    int hauteur_tile;
    /* Initialisation de la selection */
    int indice_menu_selectionne = 0;

    /* Initialisation de l'étage avec la méthode du tile mapping */

    int tile_map[18][32];

    SDL_Rect rectangle_tile;

    /* Positions et état du joueur */

    int position_x;
    int position_y;

    int position_x_initiale;
    int position_y_initiale;

    int avancer;
    int reculer;
    int sauter;
    int position_avant_saut;
    int saut;
    int tombe;

    /* Objets du niveau 1 */
    initialisation_objets_niveau_1(&renderer, &surface,
                                   &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1,
                                   &texture_image_fond_niveau_1);

    int tile_map_niveau_1[18][110];

    int decalage;
    int secret_1;
    int secret_2;

    /* Objets du niveau 2 */
    initialisation_objets_niveau_2(&renderer, &surface,
                                   &texture_image_fond_niveau_2, &texture_image_dossier_niveau_2,
                                   &texture_image_sol_niveau_2);

    /* Objets du niveau 3 */
    initialisation_objets_niveau_3(&renderer, &surface,
                                   &texture_image_fond_niveau_3, &texture_image_dossier_niveau_3,
                                   &texture_image_sol_niveau_3, &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                   &barre_windows_4);

    /* Objets du niveau 4 */
    initialisation_objets_niveau_4(&renderer, &surface,
                                   &texture_image_fond_niveau_4, &texture_image_bordure_niveau_4,
                                   &texture_image_porte, &texture_image_pique,
                                   &texture_image_fin_dernier_niveau);

    int numero_etage = 1;

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

        fscanf(fichier_sauvegarde, "%s\n", pseudo.texte);

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&personnageActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&modeActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&positionActive));

        for(i = 0; i < tailleNiveaux; i++) 
            fscanf(fichier_sauvegarde, "%d %d %d %d\n", &(avancee_niveaux[i].niveau_fini),
                                                        &(avancee_niveaux[i].numero_collectible[0]),
                                                        &(avancee_niveaux[i].numero_collectible[1]),
                                                        &(avancee_niveaux[i].numero_collectible[2]));

        /* Fermeture du fichier */
        if (fclose(fichier_sauvegarde) != 0)
            erreur("Fermeture du fichier");
    }

    else {
        barre_de_son[0].volume = 0.5;
        barre_de_son[1].volume = 0.5;

        for(i = 0; i < tailleNiveaux; i++) {
            avancee_niveaux[i].niveau_fini = 0;
            avancee_niveaux[i].numero_collectible[0] = 0;
            avancee_niveaux[i].numero_collectible[1] = 0;
            avancee_niveaux[i].numero_collectible[2] = 0;
        }
    }

    if(barre_de_son[0].volume)
        sonsActifs[0] = SDL_TRUE;

    else
        sonsActifs[0] = SDL_FALSE;
    
    if(barre_de_son[1].volume)
        sonsActifs[1] = SDL_TRUE;

    else
        sonsActifs[1] = SDL_FALSE; 
           
    /*---------------------------------------------------------------------- Début du jeu -----------------------------------------------------------------------*/

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
                           couleurTitre, couleurNoire, itemsMenuPrincipal, tailleMenuPrincipal,
                            &largeur, &hauteur, &page_active, &indice_menu_selectionne);

            /* Cas où on clique sur nouvelle partie */
            if(page_active == NOUVELLE_PARTIE) {

                /* Sauvegarde des variables de la nouvelle partie dans des variables temporaires */
                strcpy(pseudo_temporaire, pseudo.texte);
                personnage_temporaire = personnageActif;
                mode_temporaire = modeActif;

                /* Initialisation des variables de la nouvelle partie à NULL */
                pseudo.texte[0] = '\0';
                personnageActif = PERSONNAGE_1;
                modeActif = MODE_NORMAL;
        
                /* Initialisation de la police */
                if((police= TTF_OpenFont("./polices/04B_11__.TTF", largeur / 28)) == NULL)
                    erreur("Chargement de la police");
            }
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
                            &police, couleurNoire, &positionActive, avancee_niveaux, tailleNiveaux,
                            itemsMenuNouvellePartie, &valider, &largeur, &hauteur, &page_active);

            /* Cas où on retourne en arrière */
            if(page_active == MENU_PRINCIPAL) {

                /* Réinitialisation des variables de la nouvelle partie avec les anciennes valeurs sauvegardées */
                strcpy(pseudo.texte, pseudo_temporaire);
                personnageActif = personnage_temporaire;
                modeActif = mode_temporaire;
            }

            /* Cas où on on commence une nouvelle partie */
            else if(page_active == INTRODUCTION)

                /* Actualisation de la taille de la police pour l'introduction */
                if((police = TTF_OpenFont("./polices/02587_ARIALMT.ttf", largeur / 50)) == NULL)
                    erreur("Chargement de la police");
        }

        /* Page de l'introduction */

        else if(page_active == INTRODUCTION) {
            introduction(&event, &window, &renderer, &programme_lance,
                         &rectangle_passer, &texture_image_passer,
                         &rectangle_texte_introduction, &surface, &texture_texte, &police, 
                         &personnageActif, couleurBlanche,
                         &largeur, &hauteur, &page_active);
            
            page_active = NIVEAU_1;

            /* Initialisation de la police d'origine */
            if((police = TTF_OpenFont("./polices/04B_11__.TTF", 20)) == NULL)
                erreur("Chargement de la police");

            largeur_tile = largeur / 32;
            hauteur_tile = hauteur / 18;

            decalage = 0;
            secret_1 = 0;
            secret_2 = 0;

            for(i = 0; i < 3; i++)
                collectibles_intermediaires[i] = avancee_niveaux[0].numero_collectible[i];

            chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_niveaux.png");

            chargement_niveau_1(&position_x, &position_y, &position_x_initiale, &position_y_initiale, tile_map_niveau_1);

            for (y = 0; y < 18; y++)
                for (x = 0; x < 32; x++)
                    tile_map[y][x] = tile_map_niveau_1[y][13 + x];
        }

        /* Page de la carte */
        else if(page_active == CARTE) {

            page_precedente = CARTE;

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                carte(&event, &window, &renderer, &programme_lance, &texture_image_carte,
                      &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                      &rectangle_options, &texture_image_options,
                      &texture_image_perso_1_bas_1, &texture_image_perso_1_bas_2,
                      &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                      &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                      &texture_image_perso_1_haut, &texture_image_perso_1_droite,
                      &texture_image_perso_1_gauche, &texture_image_perso_1_pose,
                      &texture_image_perso_1, &rectangle_perso_1, avancee_niveaux,
                      &surface, &texture_texte, &police, &direction, &touche_pressee,
                      &rectangle_demande, itemsDemandeSauvegarde, tailleDemande,
                      &positionActive, barre_de_son, &pseudo, &modeActif, &personnageActif,
                      couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active);

            /* Cas où le personnage choisit est féminin */
            else
                carte(&event, &window, &renderer, &programme_lance, &texture_image_carte,
                      &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                      &rectangle_options, &texture_image_options,
                      &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2,
                      &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                      &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2,
                      &texture_image_perso_2_haut, &texture_image_perso_2_droite,
                      &texture_image_perso_2_gauche, &texture_image_perso_2_pose,
                      &texture_image_perso_2, &rectangle_perso_1, avancee_niveaux,
                      &surface, &texture_texte, &police, &direction, &touche_pressee,
                      &rectangle_demande, itemsDemandeSauvegarde, tailleDemande,
                      &positionActive, barre_de_son, &pseudo, &modeActif, &personnageActif,
                      couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active);

            /* Cas où on rentre dans le niveau 1 */
            if(page_active == NIVEAU_1) {

                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                decalage = 0;
                secret_1 = 0;
                secret_2 = 0;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;

                mouvement_monstre = 0;

                for(i = 0; i < 3; i++)
                    collectibles_intermediaires[i] = avancee_niveaux[0].numero_collectible[i];

                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_niveaux.png");

                chargement_niveau_1(&position_x, &position_y, &position_x_initiale, &position_y_initiale, tile_map_niveau_1);

                for (y = 0; y < 18; y++)
                    for (x = 0; x < 32; x++)
                        tile_map[y][x] = tile_map_niveau_1[y][13 + x];

            }

            /* Cas où on rentre dans le niveau 2 ou 3 */
            else if((page_active == NIVEAU_2) || (page_active == NIVEAU_3)) {

                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;
		 
		        /* On fait -4 car dans la fonction on vérifie pour 2 et 3 sauf que NIVEAU_2 vaut 6 dans l'énumération */
                salon_arrivee_niveaux_2_3(&position_x, &position_y, tile_map, page_active - 4);

                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_niveaux.png");
            }

            /* Cas où on rentre dans le niveau 4 */
            else if(page_active == NIVEAU_4) {

                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;

                for(i = 0; i < 3; i++)
                    collectibles_intermediaires[i] = avancee_niveaux[3].numero_collectible[i];

                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_niveaux.png");

                etage_1(&position_x, &position_y, &position_x_initiale, &position_y_initiale, tile_map,
                        &renderer, &surface, &texture_image_mur);
            }

            touche_pressee = 0;
        }

        /* Page du niveau 1 */
        else if(page_active == NIVEAU_1) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                niveau_1(&event, &window, &renderer,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_1, &rectangle_perso_1, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                         &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1, &texture_image_fond_niveau_1,
                         &texture_image_pique, avancee_niveaux, &mouvement_monstre,
                         &surface, collectibles_intermediaires, &timestamp,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &decalage, &secret_1, &secret_2,
                         tile_map, tile_map_niveau_1, &rectangle_tile,
                         itemsDemandeQuitter, tailleDemande, &texture_image_perso_1_pose,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_premiers_niveaux,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Cas où le personnage choisit est féminin */
            else
                niveau_1(&event, &window, &renderer,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_2, &rectangle_perso_2, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                         &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1, &texture_image_fond_niveau_1,
                         &texture_image_pique, avancee_niveaux, &mouvement_monstre,
                         &surface, collectibles_intermediaires, &timestamp,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &decalage, &secret_1, &secret_2,
                         tile_map, tile_map_niveau_1, &rectangle_tile,
                         itemsDemandeQuitter, tailleDemande, &texture_image_perso_2_pose,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_premiers_niveaux,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Retour sur la carte */
            if(page_active == CARTE) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                direction = BAS;
            }
        }

        /* Page du niveau 2 */
        else if(page_active == NIVEAU_2) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                arrivee_niveaux_2_3(&event, &window, &renderer,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_1, &rectangle_perso_1,
                                    &texture_image_fond_niveau_2, &texture_image_sol_niveau_2,
                                    &touche_aller_a_droite, &touche_aller_a_gauche,
                                    &touche_sauter_monter, &texture_image_dossier_niveau_2,
                                    NULL, NULL, NULL, NULL,
                                    tile_map, &rectangle_tile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire,
                                    &texture_texte, &police, &rectangle_demande,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Cas où le personnage choisit est féminin */
            else
                arrivee_niveaux_2_3(&event, &window, &renderer,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_2, &rectangle_perso_2,
                                    &texture_image_fond_niveau_2, &texture_image_sol_niveau_2,
                                    &touche_aller_a_droite, &touche_aller_a_gauche,
                                    &touche_sauter_monter, &texture_image_dossier_niveau_2,
                                    NULL, NULL, NULL, NULL,
                                    tile_map, &rectangle_tile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire,
                                    &texture_texte, &police, &rectangle_demande,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Retour sur la carte */
            if(page_active == CARTE) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                direction = BAS;
            }
        }

        /* Page du niveau 3 */
        else if(page_active == NIVEAU_3) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                arrivee_niveaux_2_3(&event, &window, &renderer,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_1, &rectangle_perso_1,
                                    &texture_image_fond_niveau_3, &texture_image_sol_niveau_3,
                                    &touche_aller_a_droite, &touche_aller_a_gauche,
                                    &touche_sauter_monter, &texture_image_dossier_niveau_3,
                                    &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                    &barre_windows_4, tile_map, &rectangle_tile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire,
                                    &texture_texte, &police, &rectangle_demande,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Cas où le personnage choisit est féminin */
            else
                arrivee_niveaux_2_3(&event, &window, &renderer,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_2, &rectangle_perso_2,
                                    &texture_image_fond_niveau_3, &texture_image_sol_niveau_3,
                                    &touche_aller_a_droite, &touche_aller_a_gauche,
                                    &touche_sauter_monter, &texture_image_dossier_niveau_3,
                                    &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                    &barre_windows_4, tile_map, &rectangle_tile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire,
                                    &texture_texte, &police, &rectangle_demande,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Retour sur la carte */
            if(page_active == CARTE) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                direction = BAS;
            }
        }

        /* Page du niveau 4 */
        else if(page_active == NIVEAU_4) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                niveau_4(&event, &window, &renderer,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_1, &rectangle_perso_1,
                         &texture_image_mur, &texture_image_fond_niveau_4,
                         &texture_image_bordure_niveau_4, &texture_image_porte,
                         &texture_image_pique, avancee_niveaux,
                         &surface, &modeActif, collectibles_intermediaires,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &touche_interagir,
                         tile_map, &rectangle_tile, &texture_image_perso_1_pose,
                         itemsDemandeQuitter, tailleDemande,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_dernier_niveau,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe, &numero_etage,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Cas où le personnage choisit est féminin */
            else
                niveau_4(&event, &window, &renderer,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_2, &rectangle_perso_2,
                         &texture_image_mur, &texture_image_fond_niveau_4,
                         &texture_image_bordure_niveau_4, &texture_image_porte,
                         &texture_image_pique, avancee_niveaux,
                         &surface, &modeActif, collectibles_intermediaires,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &touche_interagir,
                         tile_map, &rectangle_tile, &texture_image_perso_2_pose,
                         itemsDemandeQuitter, tailleDemande,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_dernier_niveau,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe, &numero_etage,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active);

            /* Retour sur la carte */
            if(page_active == CARTE) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                direction = BAS;
            }
        }

    }

    /*----------------------------------------------------------------------- Fin du jeu ------------------------------------------------------------------------*/

    /* Libération de la mémoire allouée dynamiquement */
    free(itemsMenuPrincipal);

    /* Destruction des différents objets */
    detruire_objets(&police, &texture_image_plein_ecran, &texture_image_retour_en_arriere,
                    &texture_image_options, &texture_image_passer, &texture_image_menu, &texture_image_carte,
                    &texture_image_hautParleurActif, &texture_image_hautParleurDesactive,
                    &texture_image_perso_1, &texture_image_perso_2, &texture_image_perso_1_bas_1,
                    &texture_image_perso_1_bas_2, &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                    &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                    &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2, 
                    &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                    &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2,
                    &texture_image_perso_1_haut, &texture_image_perso_1_droite,
                    &texture_image_perso_1_gauche, &texture_image_perso_1_pose,
                    &texture_image_perso_2_haut, &texture_image_perso_2_droite,
                    &texture_image_perso_2_gauche, &texture_image_perso_2_pose,
                    &texture_texte, &texture_image_fond_niveau_2,
                    &texture_image_dossier_niveau_2, &texture_image_sol_niveau_2,
                    &texture_image_fond_niveau_3, &texture_image_dossier_niveau_3,
                    &texture_image_sol_niveau_3, &texture_image_mur, &texture_image_fond_niveau_4,
                    &texture_image_bordure_niveau_4, &texture_image_porte, &texture_image_pique,
                    &texture_image_fin_premiers_niveaux, &texture_image_fin_dernier_niveau,
                    &texture_image_fond_niveau_1, &texture_image_sol_surface_niveau_1,
                    &texture_image_sol_profondeur_niveau_1, &texture_image_monstre_terrestre,
                    &texture_image_monstre_volant, &barre_windows_1, &barre_windows_2, 
                    &barre_windows_3, &barre_windows_4);

    /* Destruction du rendu et de la fenêtre*/
    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}
