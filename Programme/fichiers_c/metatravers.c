/**
 * \file metatravers.c
 * \brief Fichier qui réunit les différents modules pour le bon fonctionnement du programme
 */
#include "../fichiers_h/commun.h"
#include "../fichiers_h/fonctions_options.h"
#include "../fichiers_h/fonctions_nouvelle_partie.h"
#include "../fichiers_h/fonctions_introduction.h"
#include "../fichiers_h/fonctions_carte.h"
#include "../fichiers_h/fonctions_niveau_1.h"
#include "../fichiers_h/fonctions_niveau_2.h"
#include "../fichiers_h/fonctions_niveau_3.h"
#include "../fichiers_h/fonctions_arrivee_niveaux_2_3.h"
#include "../fichiers_h/fonctions_niveau_4.h"
/**
 * \fn int main(void)
 * \brief Fonction principal du programme
 * \return déroulement du programme (0 si bien passé sinon code erreur)
 * \see creer_fenetre_rendu
 * \see initialisation_objets
 * \see verification_sauvegarde
 * \see erreur
 * \see initialisation_objets_menu_principal
 * \see initialisation_objets_options
 * \see initialisation_objets_nouvelle_partie
 * \see initialisation_objets_carte
 * \see initialisation_objets_niveau_1
 * \see initialisation_objets_niveau_2
 * \see initialisation_objets_niveau_3
 * \see initialisation_objets_niveau_4
 * \see chargement_image
 * \see menu_principal
 * \see options
 * \see nouvelle_partie
 * \see introduction
 * \see carte
 * \see chargement_niveau_1
 * \see salon_arrivee_niveaux_2_3
 * \see etage_1 
 * \see arrivee_niveaux_2_3
 * \see niveau_1
 * \see niveau_4
 * \see detruire_objets
 * \see detruire_fenetre_rendu
*/ 
int main() {

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
    SDL_Texture *texture = NULL;

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

    /* Création du pointeur sur la texture de l'image du retour au menu principal et du où se trouvera l'image */
    SDL_Texture *texture_image_retour_menu = NULL;
    SDL_Rect rectangle_retour_menu;

    /* Création du pointeur sur la texture de l'image du plein écran et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_passer = NULL;
    SDL_Rect rectangle_passer;

    /* Création du pointeur sur la texture de l'image de la croix et du rectangle où se trouvera l'image */
    SDL_Texture *texture_image_croix = NULL;
    SDL_Rect rectangle_croix;

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
    SDL_Keycode touche_aller_a_droite = SDLK_RIGHT;
    SDL_Keycode touche_aller_a_gauche = SDLK_LEFT;
    SDL_Keycode touche_sauter_monter = SDLK_UP;
    SDL_Keycode touche_descendre = SDLK_DOWN;
    SDL_Keycode touche_interagir = SDLK_SPACE;

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
    SDL_Texture *texture_image_perso_1_gagnant = NULL;

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
    SDL_Texture *texture_image_perso_2_gagnant = NULL;

    /* Création des pointeur sur la texture des différentes images pour les monstres */
    SDL_Texture *texture_image_monstre_terrestre = NULL;
    SDL_Texture *texture_image_monstre_volant = NULL;

    /* Création des pointeurs sur la texture des différentes images du niveau 1 */
    SDL_Texture *texture_image_fond_niveau_1 = NULL;
    SDL_Texture *texture_image_sol_surface_niveau_1 = NULL;
    SDL_Texture *texture_image_sol_profondeur_niveau_1 = NULL;
    SDL_Texture *texture_image_nuage_1 = NULL;
    SDL_Texture *texture_image_nuage_2 = NULL;

    /* Création des pointeurs sur la texture des différentes images du salon en arrivant dans le niveau 2 */
    SDL_Texture *texture_image_fond_niveau_2 = NULL;
    SDL_Texture *texture_image_dossier_niveau_2 = NULL;
    SDL_Texture *texture_image_sol_niveau_2 = NULL;

    /* Création des pointeurs sur la texture des différentes images des pipes pour le niveau 2 */
    SDL_Texture *texture_image_mur_mini_jeu = NULL;
    SDL_Texture *texture_image_pipe_vertical = NULL;
    SDL_Texture *texture_image_pipe_horizontal = NULL;
    SDL_Texture *texture_image_pipe_haut_droit = NULL;
    SDL_Texture *texture_image_pipe_bas_droit = NULL;
    SDL_Texture *texture_image_pipe_bas_gauche = NULL;
    SDL_Texture *texture_image_pipe_haut_gauche = NULL;
    SDL_Texture *texture_image_pipe_courant = NULL;
    SDL_Texture *texture_image_mur_termine = NULL;

    /* Création des pointeurs sur la texture des différentes images du salon en arrivant dans le niveau 3 */
    SDL_Texture *texture_image_fond_niveau_3 = NULL;
    SDL_Texture *texture_image_dossier_niveau_3 = NULL;
    SDL_Texture *texture_image_sol_niveau_3 = NULL;
    SDL_Texture *barre_windows_1 = NULL; 
    SDL_Texture *barre_windows_2 = NULL; 
    SDL_Texture *barre_windows_3 = NULL;
    SDL_Texture *barre_windows_4 = NULL;

    /* Création des pointeurs sur la texture de l'image du puzzle */
    SDL_Texture* texture_image_puzzle = NULL;

    /* Création des pointeurs sur la texture des différentes images du labyrinthe */
    SDL_Texture *texture_image_sol_labyrinthe = NULL;
    SDL_Texture *texture_image_bordure_labyrinthe = NULL;
    SDL_Texture *texture_image_fin_labyrinthe = NULL;

    /* Création des pointeurs sur la texture des différentes images pour les étages */
    SDL_Texture *texture_image_mur = NULL;
    SDL_Texture *texture_image_fond_niveau_4 = NULL;
    SDL_Texture *texture_image_bordure_niveau_4 = NULL;
    SDL_Texture *texture_image_porte = NULL;
    SDL_Texture *texture_image_pique = NULL;

    /* Création des pointeurs sur la texture des différentes images pour la fin des niveaux */
    SDL_Texture *texture_image_fin_premiers_niveaux = NULL;
    SDL_Texture *texture_image_fin_dernier_niveau = NULL;

    /* Création des pointeurs sur la texture des différentes images pour les succès et pour leur rectangle */
    SDL_Texture *textures_images_succes[11] = {NULL};
    SDL_Rect rectangle_succes;

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

    /* Lancement de VIDEO SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation VIDEO SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    /* Lancement de AUDIO SDL */
	if(SDL_Init(SDL_INIT_AUDIO) == -1)
        erreur("Initialisation AUDIO SDL");

    /* Lancement du mixer */
    if(Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
        erreur("Initialisation AUDIO SDL");

    /* Initialisation de la musique */
    Mix_Music *musique = NULL;

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    /*---------------------------------------------------------------- Initialisation des objets ----------------------------------------------------------------*/

    /* Objets globaux */

    int tailleDemande = 3;

    itemMenu itemsDemandeSauvegarde[tailleDemande];

    itemMenu itemsDemandeQuitter[tailleDemande];

    int tailleNiveaux = 4;

    niveaux avancee_niveaux[tailleNiveaux];

    time_t temps_debut_partie;

    int compteur_mort;

    int avancee_succes[10];

    int avancee_succes_intermediaires[10];

    int collectibles_intermediaires[3];

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    initialisation_objets(&renderer, &surface, &texture_image_plein_ecran,
                          &texture_image_retour_en_arriere, &texture_image_options,
                          &texture_image_passer, itemsDemandeSauvegarde, itemsDemandeQuitter,
                          &texture_image_fin_premiers_niveaux, &texture_image_monstre_terrestre,
                          &texture_image_monstre_volant, &texture_image_perso_1_gagnant,
                          &texture_image_perso_2_gagnant,
                          avancee_niveaux, &police, &texture_image_croix);

    /* Objets du menu principal */

    int selection_menu = 0;

    /* Initialisation des objets intermédiaires pour la sauvegarde */
    int niveau_fini[4] = {0};
    int collectibles[12] = {0};
    position_t position_intermediaire;

    int code_de_triche[3] = {0};

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

    int maintient_clic = 0;

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

    int pseudo_valide;

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

    itemMenu itemsSucces[12];

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
                                itemsNiveaux, &texture_image_retour_menu,
                                itemsSucces, textures_images_succes); 

    /* Objets des niveaux */

    /* Initialisation de la largeur de chaque case */
    int largeur_tile;
    /* Initialisation de la hauteur de chaque case */
    int hauteur_tile;

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

    int mini_jeu;

    time_t timestamp = time(NULL);
    int mouvement_monstre;

    int mode_difficile;

    int mini_jeu_1_termine;
    int mini_jeu_2_termine;

    itemMenu itemsExplications[2];

    /* Objets du niveau 1 */

    initialisation_objets_niveau_1(&renderer, &surface,
                                   &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1,
                                   &texture_image_fond_niveau_1, &texture_image_nuage_1, &texture_image_nuage_2);

    int tile_map_niveau_1[18][110];

    int decalage;
    int secret_1;
    int secret_2;

    /* Objets du niveau 2 */

    initialisation_objets_niveau_2(&renderer, &surface,
                                   &texture_image_fond_niveau_2, &texture_image_dossier_niveau_2,
                                   &texture_image_sol_niveau_2, &texture_image_mur_mini_jeu,
                                   &texture_image_pipe_vertical, &texture_image_pipe_horizontal,
                                   &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                                   &texture_image_pipe_bas_gauche, &texture_image_pipe_haut_gauche,
                                   &texture_image_pipe_courant,
                                   &texture_image_mur_termine);

    int tile_map_mini_jeu_niveau_2[19][27];

    int mini_jeu_termine;

    /* Objets du niveau 3 */

    SDL_Rect rectangle_piece[45];

    /* Initialise toutes les pièces comme non verrouillées */
    int piece_bloquee[45];

    SDL_Rect rectangle_emplacement_piece[45];

    int piece_selectionnee;

    /* Décalage en X/Y entre le coin supérieur gauche de la pièce et la position du curseur de la souris */
    int decalage_x;
    int decalage_y;

    int valide;

    initialisation_objets_niveau_3(&renderer, &surface,
                                   &texture_image_fond_niveau_3, &texture_image_dossier_niveau_3,
                                   &texture_image_sol_niveau_3, &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                   &barre_windows_4,
                                   &texture_image_puzzle, &texture_image_sol_labyrinthe,
                                   &texture_image_bordure_labyrinthe, &texture_image_fin_labyrinthe);

    int tile_map_mini_jeu_niveau_3[24][32];

    int descendre;
    int interagir;

    int bloc_x;
    int bloc_y;

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

        /* Assignation des touches sauvegardées au touches de contrôle */
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

        /* Récupération des informations */
        fscanf(fichier_sauvegarde, "%[^\n]\n", pseudo.texte);

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&personnageActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&modeActif));

        fscanf(fichier_sauvegarde, "%d\n", (int*)(&positionActive));

        for(i = 0; i < tailleNiveaux; i++) 
            fscanf(fichier_sauvegarde, "%d %d %d %d\n", &(avancee_niveaux[i].niveau_fini),
                                                        &(avancee_niveaux[i].numero_collectible[0]),
                                                        &(avancee_niveaux[i].numero_collectible[1]),
                                                        &(avancee_niveaux[i].numero_collectible[2]));

        fscanf(fichier_sauvegarde, "%ld\n", &temps_debut_partie);

        fscanf(fichier_sauvegarde, "%d\n", &compteur_mort);

        for(i = 0; i < 10; i++)
            fscanf(fichier_sauvegarde, "%d ", &(avancee_succes[i]));                               

        /* Fermeture du fichier */
        if (fclose(fichier_sauvegarde) != 0)
            erreur("Fermeture du fichier");
    }

    /* Initialisation par défaut du son et de l'avancer dans le jeu */
    else {
        barre_de_son[0].volume = 0.5;
        barre_de_son[1].volume = 0.5;

        for(i = 0; i < tailleNiveaux; i++) {

            avancee_niveaux[i].niveau_fini = 0;
            avancee_niveaux[i].numero_collectible[0] = 0;
            avancee_niveaux[i].numero_collectible[1] = 0;
            avancee_niveaux[i].numero_collectible[2] = 0;
        }

        for(i = 0; i < 10; i++)
            avancee_succes[i] = 0;

        compteur_mort = 0;
    }

    if(barre_de_son[0].volume)
        sonsActifs[0] = SDL_TRUE;

    else
        sonsActifs[0] = SDL_FALSE;
    
    if(barre_de_son[1].volume)
        sonsActifs[1] = SDL_TRUE;

    else
        sonsActifs[1] = SDL_FALSE;

    /*-------------------------------------------------------------------- Chargement du jeu --------------------------------------------------------------------*/

    SDL_SetWindowResizable(window, SDL_FALSE);

    /* Chargement des sprites */
    SDL_Texture *sprites[3];

    chargement_image(&renderer, &surface, &sprites[0], "./images/personnages/personnage_masculin_droite_NB.png");
    chargement_image(&renderer, &surface, &sprites[1], "./images/personnages/personnage_masculin_bas_droit_1_NB.png");
    chargement_image(&renderer, &surface, &sprites[2], "./images/personnages/personnage_masculin_bas_droit_2_NB.png");

    int chargement = 1;
    int indice_sprite = 0;
    int pourcentage = 0;

    while (chargement) {

        srand(time(NULL));

        /* Simulation du chargement du jeu */
        pourcentage += (rand() % 6) + 1;

        if (pourcentage >= 100)
            chargement = 0;

        if(pourcentage > 100)
            pourcentage = 100;
    
        /* Rendu du chargement du jeu */

        /* Nettoyage du rendu */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        /* Afficher le sprite actuel */

        rectangle_perso_1.x = ((largeur - largeur / 2) / 2 - 50) + (largeur / 2 * pourcentage / 100); 
        rectangle_perso_1.y = (hauteur - 100) / 3;
        rectangle_perso_1.w = 100;
        rectangle_perso_1.h = 100;

        SDL_RenderCopy(renderer, sprites[indice_sprite], NULL, &rectangle_perso_1);

        /* Barre de chargement */

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        rectangle_pseudo.x = (largeur - largeur / 2) / 2;
        rectangle_pseudo.y = hauteur / 2 - hauteur / 40;
        rectangle_pseudo.w = largeur / 2;
        rectangle_pseudo.h = hauteur / 20;

        SDL_RenderFillRect(renderer, &rectangle_pseudo);

        rectangle_pseudo.w = largeur / 2 * pourcentage / 100;

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        SDL_RenderFillRect(renderer, &rectangle_pseudo);

        /* Texte du pourcentage */

        char texte_chargement[20];

        sprintf(texte_chargement, "Chargement... %d%%", pourcentage);

        surface = TTF_RenderText_Solid(police, texte_chargement, couleurBlanche);

        texture_texte = SDL_CreateTextureFromSurface(renderer, surface);

        rectangle_texte_introduction.x = (largeur - surface->w) / 2;
        rectangle_texte_introduction.y = hauteur / 2 + surface->h + 20;
        rectangle_texte_introduction.w = surface->w;
        rectangle_texte_introduction.h = surface->h;

        SDL_RenderCopy(renderer, texture_texte, NULL, &rectangle_texte_introduction);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture_texte);

        /* Mise à jour de l'écran */
        SDL_RenderPresent(renderer);

        /* Ajout d'un délai pour simuler le chargement */
        SDL_Delay(200);

        /* Passer au sprite suivant */
        indice_sprite++;

        /* Revenir au premier sprite si tous les sprites ont été affichés */
        if (indice_sprite >= 3)
            indice_sprite = 0;
    }

    SDL_SetWindowResizable(window, SDL_TRUE);
           
    /*---------------------------------------------------------------------- Début du jeu -----------------------------------------------------------------------*/

    page_t page_active = MENU_PRINCIPAL;

    page_t page_precedente = MENU_PRINCIPAL;

    SDL_Event event;

    Mix_VolumeMusic(barre_de_son[0].volume * 100);

    Mix_Volume(1, barre_de_son[1].volume * 100); 

    /* Musique du menu principal */
    if((musique = Mix_LoadMUS("./sons/musiques/menu_principal.mp3")) == NULL)
        erreur("Chargement de la musique");

    Mix_PlayMusic(musique, -1);

    while(programme_lance) {

        /* Page du menu principal */
        if(page_active == MENU_PRINCIPAL) {

            page_precedente = MENU_PRINCIPAL;

            menu_principal(&event, &window, &renderer, &programme_lance, &texture_image_menu,
                           &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                           &titre_menu_principal, &surface, &texture_texte, &police,
                           couleurTitre, couleurNoire, code_de_triche, &selection_menu,
                           itemsMenuPrincipal, tailleMenuPrincipal, &largeur, &hauteur, &page_active);

            if((code_de_triche[0]) && (code_de_triche[1]) && (code_de_triche[2])) {

                for(i = 0; i < 4; i++) {

                    avancee_niveaux[i].niveau_fini = 1;

                    for(x = 0; x < 3; x++)
                        avancee_niveaux[i].numero_collectible[x] = 0;
                }

                for(i = 0; i < 10; i++) {

                    if((!i) || (i == 2) || (i == 5) || (i == 7))
                        avancee_succes[i] = 1;
                    else
                        avancee_succes[i] = 0;
                }

                temps_debut_partie = time(NULL);

                compteur_mort = 0;

                strcpy(pseudo.texte, "mode Dev");    

                personnageActif = PERSONNAGE_1;

                modeActif = MODE_NORMAL;

                positionActive = NIVEAU1;

                /* Libération de la mémoire allouée dynamiquement */
                free(itemsMenuPrincipal);

                tailleMenuPrincipal = 3;

                /* Allocation dynamique de mémoire pour le tableau itemsMenuPrincipal en fonction de tailleMenuPrincipal */
                itemsMenuPrincipal = malloc(tailleMenuPrincipal * sizeof(itemMenu));

                initialisation_objets_menu_principal(&renderer, &surface, &texture_image_menu,
                                                     &titre_menu_principal, itemsMenuPrincipal, tailleMenuPrincipal); 

                code_de_triche[0] = 0;
                code_de_triche[1] = 0;
                code_de_triche[2] = 0;
            }

            /* Cas où on clique sur nouvelle partie */
            if(page_active == NOUVELLE_PARTIE) {

                selection_menu = 0;

                pseudo_valide = 0;

                /* Sauvegarde des variables de la nouvelle partie dans des variables temporaires */
                strcpy(pseudo_temporaire, pseudo.texte);
                personnage_temporaire = personnageActif;
                mode_temporaire = modeActif;

                /* Initialisation des variables de la nouvelle partie à NULL */
                pseudo.texte[0] = '\0';
                personnageActif = PERSONNAGE_1;
                modeActif = MODE_NORMAL;
        
                /* Initialisation de la police */
                if((police= TTF_OpenFont("./polices/04B_11__.TTF", largeur / 35)) == NULL)
                    erreur("Chargement de la police");
            }

            /* Cas où on clique sur options ou nouvelle partie */
            if((page_active == OPTIONS) || (page_active == NOUVELLE_PARTIE)) {

                selection_menu = 0;

                for(i = 0; i < 4; i++) {

                    niveau_fini[i] = 0;

                    for(x = 0; x < 3; x++)
                        collectibles[i + x] = 0;

                    position_intermediaire = NIVEAU1;
                }

                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                chargement_image(&renderer, &surface, &texture_image_options, "./images/options.png");
            }

            /* Cas où on clique sur continuer */
            if(page_active == CARTE) {

                selection_menu = 0;

                for(i = 0; i < 4; i++) {

                    niveau_fini[i] = avancee_niveaux[i].niveau_fini;

                    for(x = 0; x < 3; x++)
                        collectibles[i + x] = avancee_niveaux[i].numero_collectible[x];

                    position_intermediaire = positionActive;
                }

                for(i = 0; i < 10; i++)
                    avancee_succes_intermediaires[i] = avancee_succes[i];

                if(!avancee_niveaux[0].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                else if(!avancee_niveaux[1].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_3_bloque.jpg");

                else if(!avancee_niveaux[2].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_4_bloque.jpg");

                else
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte.jpg");

                direction = BAS;

                /* Musique de la carte */
                if((musique = Mix_LoadMUS("./sons/musiques/carte.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);
            }
        }

        /* Page des options */
        else if(page_active == OPTIONS) {

            /* Mise à jour du volume d ela musique et des effets sonores*/
            Mix_VolumeMusic(barre_de_son[0].volume * 100); 
            Mix_Volume(1, barre_de_son[1].volume * 100); 

            options(&event, &window, &renderer, &programme_lance,
                    &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                    &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                    &texture_image_hautParleurActif, &rectangle_demande, itemsDemandeSauvegarde, tailleDemande,
                    &texture_image_hautParleurDesactive, sonsActifs,
                    rectangles_boutons_sons, &ongletActif, &pseudo,
                    &modeActif, &personnageActif, &positionActive,
                    avancee_niveaux, tailleNiveaux,
                    &titre_options, &surface, &texture_texte, &police,
                    &selection_touche, &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                    &touche_descendre, &touche_interagir, couleurNoire,
                    itemsMenuOptions, tailleMenuOptions, itemsTouches, tailleTouches,
                    barre_de_son, tailleBarres, itemsBarres,
                    &largeur, &hauteur, &page_active, &page_precedente, &maintient_clic,
                    temps_debut_partie, &compteur_mort, avancee_succes);

            if((page_active != OPTIONS) && (page_active != NOUVELLE_PARTIE)) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_blanc.png");
                chargement_image(&renderer, &surface, &texture_image_options, "./images/options_blanc.png");
            }
        }

        /* Page de la nouvelle partie */
        else if(page_active == NOUVELLE_PARTIE) {

            page_precedente = NOUVELLE_PARTIE;

            nouvelle_partie(&event, &window, &renderer, &programme_lance,
                            &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran, 
                            &rectangle_retour_en_arriere, &texture_image_retour_en_arriere,
                            &rectangle_options, &texture_image_options, &modeSaisie,
                            &modeActif, &texture_image_perso_1, &rectangle_perso_1,
                            &texture_image_perso_2, &rectangle_perso_2, &personnageActif,
                            &pseudo, &rectangle_pseudo, barre_de_son, &pseudo_valide,
                            &touche_aller_a_droite, &touche_aller_a_gauche, &touche_sauter_monter,
                            &touche_descendre, &touche_interagir, titres, tailleTitres, &surface, &texture_texte, 
                            &police, couleurNoire, &positionActive, avancee_niveaux, tailleNiveaux,
                            itemsMenuNouvellePartie, &valider, &largeur, &hauteur, &page_active,
                            &temps_debut_partie, &compteur_mort, avancee_succes);

            /* Cas où on retourne en arrière */
            if(page_active == MENU_PRINCIPAL) {

                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_blanc.png");
                chargement_image(&renderer, &surface, &texture_image_options, "./images/options_blanc.png");

                /* Réinitialisation des variables de la nouvelle partie avec les anciennes valeurs sauvegardées */
                strcpy(pseudo.texte, pseudo_temporaire);
                personnageActif = personnage_temporaire;
                modeActif = mode_temporaire;
            }

            /* Cas où on on commence une nouvelle partie */
            else if(page_active == INTRODUCTION) {

                /* Musique de l'introduction */
                if((musique = Mix_LoadMUS("./sons/musiques/introduction.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);

                chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                /* Actualisation de la taille de la police pour l'introduction */
                if((police = TTF_OpenFont("./polices/02587_ARIALMT.ttf", largeur / 50)) == NULL)
                    erreur("Chargement de la police");
            }
        }

        /* Page de l'introduction */

        else if(page_active == INTRODUCTION) {

            introduction(&event, &window, &renderer, &programme_lance,
                         &rectangle_passer, &texture_image_passer,
                         &rectangle_texte_introduction, &surface, &texture_texte, &police, 
                         &personnageActif, couleurBlanche,
                         &largeur, &hauteur, &page_active);
            
            /* On entre directement dans le niveau 1 après l'introduction */
            page_active = NIVEAU_1;

            /* Initialisation de la police d'origine */
            if((police = TTF_OpenFont("./polices/04B_11__.TTF", 20)) == NULL)
                erreur("Chargement de la police");

            /* Musique du niveau 1 */
            if((musique = Mix_LoadMUS("./sons/musiques/niveau_1.mp3")) == NULL)
                erreur("Chargement de la musique");

            Mix_PlayMusic(musique, -1);

            /* Initialisation par défaut du niveau */
            largeur_tile = largeur / 32;
            hauteur_tile = hauteur / 18;

            decalage = 0;
            secret_1 = 0;
            secret_2 = 0;

            sauter = 0;
            avancer = 0;
            reculer = 0;
            tombe = 0;
            saut = 0;

            mouvement_monstre = 0;

            /* Initialisation collectible récolté */
            for(i = 0; i < 3; i++)
                collectibles_intermediaires[i] = 0;

            /* Initialisation des succès déjà obtenus */
            for(i = 0; i < 10; i++)
                avancee_succes_intermediaires[i] = 0;

            chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran_blanc.png");
            chargement_image(&renderer, &surface, &texture_image_options, "./images/options_blanc.png");

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
                      &rectangle_options, &texture_image_options, &rectangle_retour_menu, &texture_image_retour_menu,
                      &texture_image_perso_1_bas_1, &texture_image_perso_1_bas_2,
                      &texture_image_perso_1_haut_1, &texture_image_perso_1_haut_2,
                      &texture_image_perso_1_bas_gauche_1, &texture_image_perso_1_bas_gauche_2,
                      &texture_image_perso_1_haut, &texture_image_perso_1_droite,
                      &texture_image_perso_1_gauche, &texture_image_perso_1_pose,
                      &texture_image_perso_1, &rectangle_perso_1, avancee_niveaux,
                      niveau_fini, collectibles, &position_intermediaire, &texture_image_fin_dernier_niveau, &rectangle_succes,
                      &surface, &texture_texte, &police, &direction, &touche_pressee,
                      &rectangle_demande, itemsDemandeSauvegarde, tailleDemande,
                      &positionActive, barre_de_son, &pseudo, &modeActif, &personnageActif,
                      couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active,
                      itemsSucces, textures_images_succes,
                      temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où le personnage choisit est féminin */
            else
                carte(&event, &window, &renderer, &programme_lance, &texture_image_carte,
                      &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                      &rectangle_options, &texture_image_options, &rectangle_retour_menu, &texture_image_retour_menu,
                      &texture_image_perso_2_bas_1, &texture_image_perso_2_bas_2,
                      &texture_image_perso_2_haut_1, &texture_image_perso_2_haut_2,
                      &texture_image_perso_2_bas_gauche_1, &texture_image_perso_2_bas_gauche_2,
                      &texture_image_perso_2_haut, &texture_image_perso_2_droite,
                      &texture_image_perso_2_gauche, &texture_image_perso_2_pose,
                      &texture_image_perso_2, &rectangle_perso_1, avancee_niveaux,
                      niveau_fini, collectibles, &position_intermediaire, &texture_image_fin_dernier_niveau, &rectangle_succes,
                      &surface, &texture_texte, &police, &direction, &touche_pressee,
                      &rectangle_demande, itemsDemandeSauvegarde, tailleDemande,
                      &positionActive, barre_de_son, &pseudo, &modeActif, &personnageActif,
                      couleurNoire, &touche_aller_a_droite, &touche_aller_a_gauche, 
                      &touche_sauter_monter, &touche_descendre, &touche_interagir,
                      itemsNiveaux, tailleNiveaux, &largeur, &hauteur, &page_active,
                      itemsSucces, textures_images_succes,
                      temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où on va dans les options */
            if(page_active == OPTIONS) {
                chargement_image(&renderer, &surface, &texture_image_plein_ecran, "./images/plein_ecran.png");
                chargement_image(&renderer, &surface, &texture_image_options, "./images/options.png");
            }

            /* Ca soù on retourne dans le menu principal */
            if(page_active == MENU_PRINCIPAL) {

                /* Musique du menu principal */
                if((musique = Mix_LoadMUS("./sons/musiques/menu_principal.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
                Mix_PlayMusic(musique, -1);
            }

            /* Cas où on rentre dans le niveau 1 */
            if(page_active == NIVEAU_1) {

                /* Musique du niveau 1 */
                if((musique = Mix_LoadMUS("./sons/musiques/niveau_1.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);

                /* Initialisation par défaut du niveau */
                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                decalage = 0;
                secret_1 = 0;
                secret_2 = 0;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;
                saut = 0;

                mouvement_monstre = 0;

                /* Initialisation collectible récolté */
                for(i = 0; i < 3; i++)
                    collectibles_intermediaires[i] = avancee_niveaux[0].numero_collectible[i];

                /* Initialisation des succès déjà obtenus */
                for(i = 0; i < 10; i++)
                    avancee_succes_intermediaires[i] = avancee_succes[i];

                chargement_niveau_1(&position_x, &position_y, &position_x_initiale, &position_y_initiale, tile_map_niveau_1);

                for (y = 0; y < 18; y++)
                    for (x = 0; x < 32; x++)
                        tile_map[y][x] = tile_map_niveau_1[y][13 + x];

            }

            /* Cas où on rentre dans le niveau 2 ou 3 */
            else if((page_active == NIVEAU_2) || (page_active == NIVEAU_3)) {

                /* Musique du salon */
                if((musique = Mix_LoadMUS("./sons/musiques/salon.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);

                /* Initialisation par défaut du niveau */
                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;
                saut = 0;

                mouvement_monstre = 0;

                mini_jeu = 0;

                mode_difficile = 0;

                mini_jeu_1_termine = 0;
                mini_jeu_2_termine = 0;

                mini_jeu_termine = 0;

                /* Initialisation collectible récolté */
                if(page_active == NIVEAU_2)
                    for(i = 0; i < 3; i++)
                        collectibles_intermediaires[i] = avancee_niveaux[1].numero_collectible[i];
                
                /* Initialisation collectible récolté */
                else
                    for(i = 0; i < 3; i++)
                        collectibles_intermediaires[i] = avancee_niveaux[2].numero_collectible[i];

                /* Initialisation des succès déjà obtenus */
                for(i = 0; i < 10; i++)
                    avancee_succes_intermediaires[i] = avancee_succes[i];
		 
                salon_arrivee_niveaux_2_3(&position_x, &position_y, tile_map, page_active);
            }

            /* Cas où on rentre dans le niveau 4 */
            else if(page_active == NIVEAU_4) {

                /* Musique du niveau 4 */
                if((musique = Mix_LoadMUS("./sons/musiques/niveau_4.mp3")) == NULL)
                    erreur("Chargement de la musique");
                
                Mix_PlayMusic(musique, -1);

                /* Initialisation par défaut du niveau */
                largeur_tile = largeur / 32;
                hauteur_tile = hauteur / 18;

                sauter = 0;
                avancer = 0;
                reculer = 0;
                tombe = 0;
                saut = 0;

                /* Initialisation collectible récolté */
                for(i = 0; i < 3; i++)
                    collectibles_intermediaires[i] = avancee_niveaux[3].numero_collectible[i];

                /* Initialisation des succès déjà obtenus */
                for(i = 0; i < 10; i++)
                    avancee_succes_intermediaires[i] = avancee_succes[i];

                /* On entre dans l'étage 1 de la tour (total 5 étages) */
                etage_1(&position_x, &position_y, &position_x_initiale, &position_y_initiale, tile_map,
                        &renderer, &surface, &texture_image_mur);
            }

            else if(page_active == MENU_PRINCIPAL) {

                /* Libération de la mémoire allouée dynamiquement */
                free(itemsMenuPrincipal);

                tailleMenuPrincipal = 3;

                /* Allocation dynamique de mémoire pour le tableau itemsMenuPrincipal en fonction de tailleMenuPrincipal */
                itemsMenuPrincipal = malloc(tailleMenuPrincipal * sizeof(itemMenu));

                initialisation_objets_menu_principal(&renderer, &surface, &texture_image_menu,
                                                     &titre_menu_principal, itemsMenuPrincipal, tailleMenuPrincipal);  
            }

            touche_pressee = 0;
        }

        /* Page du niveau 1 */
        else if(page_active == NIVEAU_1) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                niveau_1(&event, &window, &renderer, &programme_lance, &texture_image_croix, &rectangle_croix,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_1, &rectangle_perso_1, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                         &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1, &texture_image_fond_niveau_1,
                         &texture_image_pique, avancee_niveaux, &mouvement_monstre,
                         &surface, collectibles_intermediaires, &timestamp,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &decalage, &secret_1, &secret_2,
                         tile_map, tile_map_niveau_1, &rectangle_tile,
                         itemsDemandeQuitter, tailleDemande, &texture_image_perso_1_gagnant,
                         &texture_texte, &police, &rectangle_demande, &texture_image_nuage_1, &texture_image_nuage_2,
                         couleurNoire, &texture_image_fin_premiers_niveaux,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                         itemsDemandeSauvegarde, &touche_descendre, &touche_interagir, barre_de_son, &pseudo, 
                         &modeActif, &personnageActif, &positionActive, tailleNiveaux,
                         temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où le personnage choisit est féminin */
            else
                niveau_1(&event, &window, &renderer, &programme_lance, &texture_image_croix, &rectangle_croix,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_2, &rectangle_perso_2, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                         &texture_image_sol_surface_niveau_1, &texture_image_sol_profondeur_niveau_1, &texture_image_fond_niveau_1,
                         &texture_image_pique, avancee_niveaux, &mouvement_monstre,
                         &surface, collectibles_intermediaires, &timestamp,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &decalage, &secret_1, &secret_2,
                         tile_map, tile_map_niveau_1, &rectangle_tile,
                         itemsDemandeQuitter, tailleDemande, &texture_image_perso_2_gagnant,
                         &texture_texte, &police, &rectangle_demande, &texture_image_nuage_1, &texture_image_nuage_2,
                         couleurNoire, &texture_image_fin_premiers_niveaux,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                         itemsDemandeSauvegarde, &touche_descendre, &touche_interagir, barre_de_son, &pseudo, 
                         &modeActif, &personnageActif, &positionActive, tailleNiveaux,
                         temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Retour sur la carte */
            if(page_active == CARTE) {

                if(!avancee_niveaux[0].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                else if(!avancee_niveaux[1].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_3_bloque.jpg");

                else if(!avancee_niveaux[2].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_4_bloque.jpg");

                else
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte.jpg");

                direction = BAS;

                /* Musique de la carte */
                if((musique = Mix_LoadMUS("./sons/musiques/carte.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);
            }
        }

        /* Page du niveau 2 */
        else if(page_active == NIVEAU_2) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                arrivee_niveaux_2_3(&event, &window, &renderer, &programme_lance, &mini_jeu, &texture_image_fin_premiers_niveaux,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_1, &rectangle_perso_1, &mini_jeu_termine, &mini_jeu_1_termine, &mini_jeu_2_termine,
                                    &texture_image_fond_niveau_2, &texture_image_sol_niveau_2, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                                    &touche_aller_a_droite, &touche_aller_a_gauche, &touche_interagir, &texture_image_porte, avancee_niveaux,
                                    &touche_sauter_monter, &touche_descendre, &texture_image_dossier_niveau_2,
                                    NULL, NULL, NULL, NULL,
                                    tile_map, &rectangle_tile, &mouvement_monstre, &modeActif, &mode_difficile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire, tile_map_mini_jeu_niveau_2,
                                    &texture_texte, &police, &rectangle_demande, &timestamp, &texture_image_perso_1_gagnant,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                                    &texture_image_mur_mini_jeu, collectibles_intermediaires, itemsExplications,
                                    &texture_image_pipe_vertical,&texture_image_pipe_horizontal,
                                    &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                                    &texture_image_pipe_bas_gauche,&texture_image_pipe_haut_gauche,
                                    &texture_image_pipe_courant, &texture_image_mur_termine, &valide,
                                    rectangle_piece, piece_bloquee, rectangle_emplacement_piece, &piece_selectionnee,
                                    &decalage_x, &decalage_y, &texture_image_puzzle, &musique, &texture_image_croix, &rectangle_croix,
                                    tile_map_mini_jeu_niveau_3, &descendre, &interagir, &bloc_x, &bloc_y,
                                    &texture_image_sol_labyrinthe, &texture_image_bordure_labyrinthe, &texture_image_fin_labyrinthe, couleurTitre,
                                    itemsDemandeSauvegarde, barre_de_son, &pseudo, 
                                    &personnageActif, &positionActive, tailleNiveaux,
                                    temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où le personnage choisit est féminin */
            else
                arrivee_niveaux_2_3(&event, &window, &renderer, &programme_lance, &mini_jeu, &texture_image_fin_premiers_niveaux,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_2, &rectangle_perso_2, &mini_jeu_termine, &mini_jeu_1_termine, &mini_jeu_2_termine,
                                    &texture_image_fond_niveau_2, &texture_image_sol_niveau_2, &texture_image_monstre_terrestre, &texture_image_monstre_volant,
                                    &touche_aller_a_droite, &touche_aller_a_gauche, &touche_interagir, &texture_image_porte, avancee_niveaux,
                                    &touche_sauter_monter, &touche_descendre, &texture_image_dossier_niveau_2,
                                    NULL, NULL, NULL, NULL,
                                    tile_map, &rectangle_tile, &mouvement_monstre, &modeActif, &mode_difficile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire, tile_map_mini_jeu_niveau_2,
                                    &texture_texte, &police, &rectangle_demande, &timestamp, &texture_image_perso_2_gagnant,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                                    &texture_image_mur_mini_jeu, collectibles_intermediaires, itemsExplications,
                                    &texture_image_pipe_vertical,&texture_image_pipe_horizontal,
                                    &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                                    &texture_image_pipe_bas_gauche,&texture_image_pipe_haut_gauche,
                                    &texture_image_pipe_courant, &texture_image_mur_termine, &valide,
                                    rectangle_piece, piece_bloquee, rectangle_emplacement_piece, &piece_selectionnee,
                                    &decalage_x, &decalage_y, &texture_image_puzzle, &musique, &texture_image_croix, &rectangle_croix,
                                    tile_map_mini_jeu_niveau_3, &descendre, &interagir, &bloc_x, &bloc_y,
                                    &texture_image_sol_labyrinthe, &texture_image_bordure_labyrinthe, &texture_image_fin_labyrinthe, couleurTitre,
                                    itemsDemandeSauvegarde, barre_de_son, &pseudo, 
                                    &personnageActif, &positionActive, tailleNiveaux,
                                    temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Retour sur la carte */
            if(page_active == CARTE) {

                if(!avancee_niveaux[0].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                else if(!avancee_niveaux[1].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_3_bloque.jpg");

                else if(!avancee_niveaux[2].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_4_bloque.jpg");

                else
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte.jpg");

                direction = BAS;

                /* Musique de la carte */
                if((musique = Mix_LoadMUS("./sons/musiques/carte.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);
            }    
        }

        /* Page du niveau 3 */
        else if(page_active == NIVEAU_3) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                arrivee_niveaux_2_3(&event, &window, &renderer, &programme_lance, &mini_jeu, &texture_image_fin_premiers_niveaux,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_1, &rectangle_perso_1, &mini_jeu_termine, &mini_jeu_1_termine, &mini_jeu_2_termine,
                                    &texture_image_fond_niveau_3, &texture_image_sol_niveau_3, NULL, NULL,
                                    &touche_aller_a_droite, &touche_aller_a_gauche, &touche_interagir, &texture_image_porte, avancee_niveaux,
                                    &touche_sauter_monter, &touche_descendre, &texture_image_dossier_niveau_3,
                                    &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                    &barre_windows_4, tile_map, &rectangle_tile, &mouvement_monstre, &modeActif, &mode_difficile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire, tile_map_mini_jeu_niveau_2,
                                    &texture_texte, &police, &rectangle_demande, &timestamp, &texture_image_perso_1_gagnant,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                                    &texture_image_mur_mini_jeu, collectibles_intermediaires, itemsExplications,
                                    &texture_image_pipe_vertical,&texture_image_pipe_horizontal,
                                    &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                                    &texture_image_pipe_bas_gauche,&texture_image_pipe_haut_gauche,
                                    &texture_image_pipe_courant, &texture_image_mur_termine, &valide,
                                    rectangle_piece, piece_bloquee, rectangle_emplacement_piece, &piece_selectionnee,
                                    &decalage_x, &decalage_y, &texture_image_puzzle, &musique, &texture_image_croix, &rectangle_croix,
                                    tile_map_mini_jeu_niveau_3, &descendre, &interagir, &bloc_x, &bloc_y,
                                    &texture_image_sol_labyrinthe, &texture_image_bordure_labyrinthe, &texture_image_fin_labyrinthe, couleurTitre,
                                    itemsDemandeSauvegarde, barre_de_son, &pseudo, 
                                    &personnageActif, &positionActive, tailleNiveaux,
                                    temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où le personnage choisit est féminin */
            else
                arrivee_niveaux_2_3(&event, &window, &renderer, &programme_lance, &mini_jeu, &texture_image_fin_premiers_niveaux,
                                    &texture, &surface, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                                    &texture_image_perso_2, &rectangle_perso_2, &mini_jeu_termine, &mini_jeu_1_termine, &mini_jeu_2_termine,
                                    &texture_image_fond_niveau_3, &texture_image_sol_niveau_3, NULL, NULL,
                                    &touche_aller_a_droite, &touche_aller_a_gauche, &touche_interagir, &texture_image_porte, avancee_niveaux,
                                    &touche_sauter_monter, &touche_descendre, &texture_image_dossier_niveau_3,
                                    &barre_windows_1, &barre_windows_2, &barre_windows_3,
                                    &barre_windows_4, tile_map, &rectangle_tile, &mouvement_monstre, &modeActif, &mode_difficile,
                                    itemsDemandeQuitter, tailleDemande, couleurNoire, tile_map_mini_jeu_niveau_2,
                                    &texture_texte, &police, &rectangle_demande, &timestamp, &texture_image_perso_2_gagnant,
                                    &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe,
                                    &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                                    &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                                    &texture_image_mur_mini_jeu, collectibles_intermediaires, itemsExplications,
                                    &texture_image_pipe_vertical,&texture_image_pipe_horizontal,
                                    &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                                    &texture_image_pipe_bas_gauche,&texture_image_pipe_haut_gauche,
                                    &texture_image_pipe_courant, &texture_image_mur_termine, &valide,
                                    rectangle_piece, piece_bloquee, rectangle_emplacement_piece,
                                    &piece_selectionnee, &decalage_x, &decalage_y, &texture_image_puzzle, &musique, &texture_image_croix, &rectangle_croix,
                                    tile_map_mini_jeu_niveau_3, &descendre, &interagir, &bloc_x, &bloc_y,
                                    &texture_image_sol_labyrinthe, &texture_image_bordure_labyrinthe, &texture_image_fin_labyrinthe, couleurTitre,
                                    itemsDemandeSauvegarde, barre_de_son, &pseudo, 
                                    &personnageActif, &positionActive, tailleNiveaux,
                                    temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Retour sur la carte */
            if(page_active == CARTE) {

                if(!avancee_niveaux[0].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                else if(!avancee_niveaux[1].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_3_bloque.jpg");

                else if(!avancee_niveaux[2].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_4_bloque.jpg");

                else
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte.jpg");

                direction = BAS;

                /* Musique de la carte */
                if((musique = Mix_LoadMUS("./sons/musiques/carte.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);
            }   
        }

        /* Page du niveau 4 */
        else if(page_active == NIVEAU_4) {

            /* Cas où le personnage choisit est masculin */
            if(personnageActif == PERSONNAGE_1)
                niveau_4(&event, &window, &renderer, &programme_lance,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_1, &rectangle_perso_1,
                         &texture_image_mur, &texture_image_fond_niveau_4,
                         &texture_image_bordure_niveau_4, &texture_image_porte,
                         &texture_image_pique, avancee_niveaux,
                         &surface, &modeActif, collectibles_intermediaires,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &touche_interagir,
                         tile_map, &rectangle_tile, &texture_image_perso_1_gagnant,
                         itemsDemandeQuitter, tailleDemande,&texture_image_croix, &rectangle_croix,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_dernier_niveau,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe, &numero_etage,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                         itemsDemandeSauvegarde, &touche_descendre, barre_de_son, &pseudo, 
                         &personnageActif, &positionActive, tailleNiveaux,
                         temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Cas où le personnage choisit est féminin */
            else
                niveau_4(&event, &window, &renderer, &programme_lance,
                         &texture, &rectangle_plein_ecran, &texture_image_plein_ecran, &plein_ecran,
                         &texture_image_perso_2, &rectangle_perso_2,
                         &texture_image_mur, &texture_image_fond_niveau_4,
                         &texture_image_bordure_niveau_4, &texture_image_porte,
                         &texture_image_pique, avancee_niveaux,
                         &surface, &modeActif, collectibles_intermediaires,
                         &touche_aller_a_droite, &touche_aller_a_gauche,
                         &touche_sauter_monter, &touche_interagir,
                         tile_map, &rectangle_tile, &texture_image_perso_2_gagnant,
                         itemsDemandeQuitter, tailleDemande, &texture_image_croix, &rectangle_croix,
                         &texture_texte, &police, &rectangle_demande,
                         couleurNoire, &texture_image_fin_dernier_niveau,
                         &avancer, &reculer, &sauter, &position_avant_saut, &saut, &tombe, &numero_etage,
                         &position_x_initiale, &position_y_initiale, &position_x, &position_y,
                         &largeur, &hauteur, &largeur_tile, &hauteur_tile, &page_active,
                         itemsDemandeSauvegarde, &touche_descendre, barre_de_son, &pseudo, 
                         &personnageActif, &positionActive, tailleNiveaux,
                         temps_debut_partie, &compteur_mort, avancee_succes, avancee_succes_intermediaires);

            /* Retour sur la carte */
            if(page_active == CARTE) {
                
                if(!avancee_niveaux[0].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_2_bloque.jpg");

                else if(!avancee_niveaux[1].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_3_bloque.jpg");

                else if(!avancee_niveaux[2].niveau_fini)
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte_niveau_4_bloque.jpg");

                else
                    chargement_image(&renderer, &surface, &texture_image_carte, "./images/carte.jpg");

                direction = BAS;

                /* Musique de la carte */
                if((musique = Mix_LoadMUS("./sons/musiques/carte.mp3")) == NULL)
                    erreur("Chargement de la musique");

                Mix_PlayMusic(musique, -1);
            }
        }
    }

    /*----------------------------------------------------------------------- Fin du jeu ------------------------------------------------------------------------*/

    /* Libération de la mémoire allouée dynamiquement */
    free(itemsMenuPrincipal);

    /* Destruction des différents objets */
    detruire_objets(&police, &musique, &texture_image_plein_ecran, &texture_image_retour_en_arriere,
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
                    &barre_windows_3, &barre_windows_4, &texture_image_mur_mini_jeu,
                    &texture_image_pipe_vertical, &texture_image_pipe_horizontal,
                    &texture_image_pipe_haut_droit, &texture_image_pipe_bas_droit,
                    &texture_image_pipe_bas_gauche, &texture_image_pipe_haut_gauche,
                    &texture_image_pipe_courant, &texture_image_mur_termine,
                    &texture_image_perso_1_gagnant, &texture_image_perso_2_gagnant,
                    &texture_image_puzzle, &texture_image_retour_menu,
                    &texture_image_sol_labyrinthe, &texture_image_bordure_labyrinthe,
                    &texture_image_fin_labyrinthe, &texture_image_nuage_1, 
                    &texture_image_nuage_2, &texture_image_croix,
                    textures_images_succes);

    /* Destruction du rendu et de la fenêtre*/
    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF, VIDEO SDL et AUDIO SDL */
	TTF_Quit(); 
    SDL_Quit();
    Mix_CloseAudio();

    return EXIT_SUCCESS; /* return 0; */
}
