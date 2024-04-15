#include <../fichiers_h/fonctions_generales.h>
#include <../fichiers_h/fonctions_introduction.h>

/* Fonction qui met à jour le rendu de l'introduction */
void mise_a_jour_rendu_introduction(SDL_Renderer **renderer, int indice, char *ligne,
                                    SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                                    SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, 
                                    TTF_Font **police, SDL_Color couleurBlanche,
                                    int largeur, int hauteur) {

    /* Création d'une sous-chaîne du texte jusqu'à la lettre actuelle */
    char buffer[indice + 2];
    strncpy(buffer, ligne, indice);

    /* Ajout de la lettre actuelle */
    buffer[indice] = ligne[indice];

    /* Ajout d'un caractère '\0' pour terminer la chaîne */
    buffer[indice + 1] = '\0';

    /* Rendu du texte actuel sur la surface texte */
    (*surface) = TTF_RenderUTF8_Blended((*police), buffer, couleurBlanche);
    
    /* Création de la texture texture_texte depuis la surface texte */
    (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*surface));

    /* Récupération des dimensions du texte */
    int largeur_texte, hauteur_texte;
    SDL_QueryTexture((*texture_texte), NULL, NULL, &largeur_texte, &hauteur_texte);

    /* Positionnement du texte au centre */
    rectangle_texte_introduction->x = largeur / 2 - largeur_texte / 2;
    rectangle_texte_introduction->y = hauteur / 2 - hauteur_texte ;
    rectangle_texte_introduction->w = largeur_texte;
    rectangle_texte_introduction->h = hauteur_texte;

    /* Affichage de la texture texture_texte */
    SDL_RenderCopy((*renderer), (*texture_texte), NULL, rectangle_texte_introduction);

    SDL_FreeSurface((*surface));
    SDL_DestroyTexture((*texture_texte));

    /* Copie la texture de l'image du passer */
    rectangle_passer->x = largeur - largeur / 21;
    rectangle_passer->y = 0;
    rectangle_passer->w = largeur / 21;
    rectangle_passer->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_passer), NULL, rectangle_passer) != 0)
        erreur("Copie de la texture");

    /* Fond noir */
    SDL_SetRenderDrawColor((*renderer), 0, 0, 0, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));

}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans l'introduction */
void introduction(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                  SDL_Rect *rectangle_passer, SDL_Texture **texture_image_passer,
                  SDL_Rect *rectangle_texte_introduction, SDL_Surface **surface, SDL_Texture **texture_texte, TTF_Font **police,
                  personnage_t *personnageActif, SDL_Color couleurBlanche,
                  int *largeur, int *hauteur, page_t *page_active) {

    /* Ouverture du fichier contenant l'introduction */
    FILE *fichier = NULL;

    if((*personnageActif) == PERSONNAGE_1) {
        fichier = fopen("./textes/introduction_masculin.txt", "r");
        if (!fichier)
            erreur("Ouverture du fichier introduction_masculin.txt");
    }
    
    else {
        fichier = fopen("./textes/introduction_feminin.txt", "r");
        if (!fichier)
            erreur("Ouverture du fichier introduction_feminin.txt");
    }
    
    /* Initialisation d'une chaîne de caractères */
    char * ligne = malloc(sizeof(char) * 125);
    int indice;

    /* Lecture de chaque ligne du fichier */
    while((fgets(ligne, sizeof(char) * 125, fichier) != NULL) && ((*page_active) == INTRODUCTION) && ((*programme_lance) == SDL_TRUE)) {

        /* Boucle pour afficher le texte lettre par lettre */
        for (indice = 0; (indice < ((int)strlen(ligne))) && ((*page_active) == INTRODUCTION) && ((*programme_lance) == SDL_TRUE); indice++) {

            /* Effacement du rendu précédent */
            SDL_RenderClear((*renderer));

            while(SDL_PollEvent(event)) {

                switch(event->type) {

                    case SDL_WINDOWEVENT:

                        /* Gestion de l'événement de redimensionnement de la fenêtre */
                        redimensionnement_fenetre((*event), largeur, hauteur);

                        /* Actualisation de la taille de la police */
                        (*police) = TTF_OpenFont("./polices/02587_ARIALMT.ttf", (*largeur) / 50);

                        break;
                        
                    case SDL_MOUSEBUTTONDOWN:

                        /* Appuiyer sur le clic gauche de la souris */
                        if(event->button.button == SDL_BUTTON_LEFT)
                            /* Fin de la ligne */
                            indice = strlen(ligne);

                        /* Bouton pour passer l'introduction */
                        if(clic_case((*event), *rectangle_passer))
                            (*page_active) = NIVEAU_1;

                        break;
                    
                    /* Quitter le programme*/
                    case SDL_QUIT:
                        (*programme_lance) = SDL_FALSE;
                        break;

                    default:
                        break;
                }
            }

            if(((*page_active) == INTRODUCTION) && ((*programme_lance) == SDL_TRUE)) {

                /* Mise à jour du rendu */
                mise_a_jour_rendu_introduction(renderer, indice, ligne,
                                               rectangle_passer, texture_image_passer, 
                                               rectangle_texte_introduction, surface, texture_texte, 
                                               police, couleurBlanche,
                                               (*largeur), (*hauteur));

                /* Délai entre chaque lettre */
                SDL_Delay(50);
            }
        }

        if(((*page_active) == INTRODUCTION) && ((*programme_lance) == SDL_TRUE)) {

            SDL_SetWindowResizable((*window), SDL_FALSE);

            /* Délai d'attente avant de passer à la ligne suivante */
            SDL_Delay(2000);

            SDL_SetWindowResizable((*window), SDL_TRUE);
        }
    }

    /* Libération de la mémoire allouée pour la ligne et fermeture du fichier */
    free(ligne);
    fclose(fichier);
}