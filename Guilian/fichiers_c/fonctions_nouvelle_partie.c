/* Fonction qui permet d'initialiser les différents objets de la nouvelle partie*/
void initialisation_objets_nouvelle_partie(SDL_Renderer **renderer,
                           SDL_Surface **image_perso_1, SDL_Texture **texture_image_perso_1,
                           SDL_Surface **image_perso_2, SDL_Texture **texture_image_perso_2,
                           itemMenu *titres, itemMenu *itemsMenu, itemMenu *valider) {

    /* Initialisation de l'image du premier personnage */
    (*image_perso_1) = IMG_Load("./images/normal.png");
    if((*image_perso_1) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_perso_1) = SDL_CreateTextureFromSurface((*renderer), (*image_perso_1));
    if((*texture_image_perso_1) == NULL)
        erreur("Création de la texture");

    SDL_FreeSurface((*image_perso_1));

    /* Initialisation de l'image du deuxième personnage */
    (*image_perso_2) = IMG_Load("./images/hard.png");
    if((*image_perso_2) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_perso_2) = SDL_CreateTextureFromSurface((*renderer), (*image_perso_2));
    if((*texture_image_perso_2) == NULL)
        erreur("Création de la texture");

    SDL_FreeSurface((*image_perso_2));

    /* Initialisation des titres du menu nouvelle partie */
    sprintf(titres[0].texte, " Entrez votre pseudo : ");
    sprintf(titres[1].texte, " Choisissez votre personnage : ");
    sprintf(titres[2].texte, " Choisir le mode : ");

	/* Initialisation du texte dans les items de la difficulté */
    sprintf(itemsMenu[0].texte, " Normal ");
    sprintf(itemsMenu[1].texte, " Difficile ");

    /* Initialisation du texte dans l'item pour commencer la partie */
    sprintf(valider->texte, " Commencer la partie ! ");
}

/* Fonction qui met à jour le rendu du menu nouvelle partie après redimension de la fenêtre */
void mise_a_jour_rendu_nouvelle_partie(SDL_Renderer **renderer, SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                                       SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                                       SDL_Rect *rectangle_options, SDL_Texture **texture_image_options,
                                       int modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                                       SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, int personnageActif,
                                       itemMenu *pseudo,
                                       itemMenu *titres, int tailleTitres, SDL_Surface **texte, SDL_Texture **texture_texte, 
                                       TTF_Font **police, SDL_Color couleurNoire,
                                       itemMenu *itemsMenu, itemMenu *valider, int largeur, int hauteur) {

    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de plein écran */
    rectangle_plein_ecran->x = largeur - largeur / 21;
    rectangle_plein_ecran->y = 0;
    rectangle_plein_ecran->w = largeur / 21;
    rectangle_plein_ecran->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_plein_ecran), NULL, rectangle_plein_ecran) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image du retour en arrière */
    rectangle_retour_en_arriere->x = 0;
    rectangle_retour_en_arriere->y = 0;
    rectangle_retour_en_arriere->w = largeur / 21;
    rectangle_retour_en_arriere->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_retour_en_arriere), NULL, rectangle_retour_en_arriere) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image des options */
    rectangle_options->x = largeur - largeur / 21;
    rectangle_options->y = hauteur - hauteur / 12;
    rectangle_options->w = largeur / 21;
    rectangle_options->h = hauteur / 12;

    if(SDL_RenderCopy((*renderer), (*texture_image_options), NULL, rectangle_options) != 0)
        erreur("Copie de la texture");

    /* Dessine les items du menu nouvelle partie */
    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    for(i = 0; i < tailleTitres; i++) {

        titres[i].rectangle.x = largeur / 3;
        titres[i].rectangle.y = hauteur / 20 + i * hauteur / 4;
        titres[i].rectangle.w = largeur / 3;
        titres[i].rectangle.h = hauteur / 14;

        SDL_RenderFillRect((*renderer), &(titres[i].rectangle));

        (*texte) = TTF_RenderText_Solid((*police), titres[i].texte, couleurNoire);
        (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*texte));

        SDL_RenderCopy((*renderer), (*texture_texte), NULL, &(titres[i].rectangle));

        SDL_FreeSurface((*texte));
        SDL_DestroyTexture((*texture_texte));
    }

    /* Dessine l'item pour la saisie du pseudo */
    pseudo->rectangle.x = largeur / 3;
    pseudo->rectangle.y = hauteur / 8;
    pseudo->rectangle.w = largeur / 3;
    pseudo->rectangle.h = hauteur / 8;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    SDL_RenderFillRect((*renderer), &(pseudo->rectangle));

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
    SDL_RenderDrawRect((*renderer), &(pseudo->rectangle));

    (*texte) = TTF_RenderText_Solid((*police), pseudo->texte, couleurNoire);
    (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*texte));

    SDL_RenderCopy((*renderer), (*texture_texte), NULL, &(pseudo->rectangle));

    SDL_FreeSurface((*texte));
    SDL_DestroyTexture((*texture_texte));

    /* Copie la texture de l'image du premier personnage */
    rectangle_perso_1->x = largeur / 6;
    rectangle_perso_1->y = hauteur / 3 + hauteur / 20;
    rectangle_perso_1->w = largeur / 4;
    rectangle_perso_1->h = hauteur / 7;

    if(SDL_RenderCopy((*renderer), (*texture_image_perso_1), NULL, rectangle_perso_1) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image du deuxième personnage */
    rectangle_perso_2->x = largeur - largeur / 6 - largeur / 4;
    rectangle_perso_2->y = hauteur / 3 + hauteur / 20;
    rectangle_perso_2->w = largeur / 4;
    rectangle_perso_2->h = hauteur / 7;

    if(SDL_RenderCopy((*renderer), (*texture_image_perso_2), NULL, rectangle_perso_2) != 0)
        erreur("Copie de la texture");

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

    if(personnageActif == PERSONNAGE_1)
        SDL_RenderDrawRect((*renderer), rectangle_perso_1);
    else 
        SDL_RenderDrawRect((*renderer), rectangle_perso_2);

    /* Dessine les éléments du menu pour la difficulté */

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);

    if(modeActif == MODE_NORMAL) {
        SDL_RenderFillRect((*renderer), &(itemsMenu[0].rectangle));
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
        SDL_RenderFillRect((*renderer), &(itemsMenu[1].rectangle));
    }
    else {
        SDL_RenderFillRect((*renderer), &(itemsMenu[1].rectangle));
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
        SDL_RenderFillRect((*renderer), &(itemsMenu[0].rectangle));
    }

    /* Décide de la couleur en fonction de l'onglet actif */
    if(modeActif == MODE_NORMAL)
        SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
    else
        SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    itemsMenu[0].rectangle.x = largeur / 6;
    itemsMenu[1].rectangle.x = largeur - largeur / 6 - largeur / 4;

    for(i = 0; i < 2; i++) {

        if((i) && (modeActif == MODE_HARD))
            SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
        else if(i)
            SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

        itemsMenu[i].rectangle.y = hauteur / 2 + hauteur / 6;
        itemsMenu[i].rectangle.w = largeur / 4;
        itemsMenu[i].rectangle.h = hauteur / 12;

        SDL_RenderFillRect((*renderer), &(itemsMenu[i].rectangle));

        (*texte) = TTF_RenderText_Solid((*police), itemsMenu[i].texte, couleurNoire);
        (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*texte));

        SDL_RenderCopy((*renderer), (*texture_texte), NULL, &(itemsMenu[i].rectangle));

        SDL_FreeSurface((*texte));
        SDL_DestroyTexture((*texture_texte));
    }

    /* Dessine les éléments du menu pour le bouton "Commencer la partie !" */
    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    valider->rectangle.x = largeur / 3;
    valider->rectangle.y = hauteur / 2 + hauteur / 3;
    valider->rectangle.w = largeur / 3;
    valider->rectangle.h = hauteur / 8;

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);
    SDL_RenderFillRect((*renderer), &(valider->rectangle));

    SDL_SetRenderDrawColor((*renderer), 175, 95, 185, 255);
    SDL_RenderDrawRect((*renderer), &(valider->rectangle));

    (*texte) = TTF_RenderText_Solid((*police), valider->texte, couleurNoire);
    (*texture_texte) = SDL_CreateTextureFromSurface((*renderer), (*texte));

    SDL_RenderCopy((*renderer), (*texture_texte), NULL, &(valider->rectangle));

    SDL_FreeSurface((*texte));
    SDL_DestroyTexture((*texture_texte));

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de gérer toutes les possibilités qui sont possiblent dans le menu nouvelle partie */
void nouvelle_partie(SDL_Event *event, SDL_Window **window, SDL_Renderer **renderer, SDL_bool *programme_lance,
                     SDL_Rect *rectangle_plein_ecran, SDL_Texture **texture_image_plein_ecran, SDL_bool *plein_ecran, 
                     SDL_Rect *rectangle_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere, 
                     SDL_Rect *rectangle_options, SDL_Texture **texture_image_options, int *modeSaisie,
                     int *modeActif, SDL_Texture **texture_image_perso_1, SDL_Rect *rectangle_perso_1,
                     SDL_Texture **texture_image_perso_2, SDL_Rect *rectangle_perso_2, int *personnageActif,
                     itemMenu *pseudo, barreDeSon *barre_de_son,
                     SDL_Keycode *touche_aller_a_droite, SDL_Keycode *touche_aller_a_gauche, SDL_Keycode *touche_sauter,
                     itemMenu *titres, int tailleTitres, SDL_Surface **texte, SDL_Texture **texture_texte, 
                     TTF_Font **police, SDL_Color couleurNoire,
                     itemMenu *itemsMenu, itemMenu *valider, int *largeur, int *hauteur, int *page) {

    while(SDL_PollEvent(event)) {

            switch(event->type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre((*event), largeur, hauteur);
            
                    break;

                /* Si l'utilisateur tape quelque chose */
                case SDL_TEXTINPUT:
                    if((*modeSaisie))
                        /* Concatène le texte saisi au pseudo */
                        if(strlen(pseudo->texte) + strlen(event->text.text) <= 10)
                            strcat(pseudo->texte, event->text.text);

                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(clic_case((*event), pseudo->rectangle))
                        (*modeSaisie) = 1;
                    else
                        (*modeSaisie) = 0;

                    if(clic_case((*event), itemsMenu[0].rectangle)) 
                        (*modeActif) = MODE_NORMAL;
                    else if(clic_case((*event), itemsMenu[1].rectangle))
                        (*modeActif) = MODE_HARD;

                    if(clic_case((*event), (*rectangle_perso_1))) 
                        (*personnageActif) = PERSONNAGE_1;
                    else if(clic_case((*event), (*rectangle_perso_2)))
                        (*personnageActif) = PERSONNAGE_2;

                    if(clic_plein_ecran((*event), rectangle_plein_ecran, plein_ecran, window))
                        redimensionnement_fenetre((*event), largeur, hauteur);

                    if(clic_case((*event), (*rectangle_retour_en_arriere)))
                        (*page) = MENU_PRINCIPAL;

                    if(clic_case((*event), (*rectangle_options)))
                        (*page) = OPTIONS;

                    if(clic_case((*event), valider->rectangle)) {
                        FILE *fichier_sauvegarde;

                        /* Ouverture du fichier en mode écriture */
                        fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "w");

                        fprintf(fichier_sauvegarde, "%f\n", barre_de_son[0].volume);
                        fprintf(fichier_sauvegarde, "%f\n", barre_de_son[1].volume);
                        fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_aller_a_droite)));
                        fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_aller_a_gauche)));
                        fprintf(fichier_sauvegarde, "%s\n", SDL_GetKeyName((*touche_sauter)));
                        fprintf(fichier_sauvegarde, "%s\n", pseudo->texte);

                        if((*personnageActif) == PERSONNAGE_1)
                            fprintf(fichier_sauvegarde, "%d\n", PERSONNAGE_1);
                        else
                            fprintf(fichier_sauvegarde, "%d\n", PERSONNAGE_2);

                        if((*modeActif) == MODE_NORMAL)
                            fprintf(fichier_sauvegarde, "%d\n", MODE_NORMAL);
                        else
                            fprintf(fichier_sauvegarde, "%d\n", MODE_HARD);

                        /* Fermeture du fichier */
                        if (fclose(fichier_sauvegarde) != 0)
                            erreur("Fermeture du fichier");

                        printf("Vous avez fait clic gauche sur 'Commencer la partie !' !\n");
                    }

                    break;

                case SDL_KEYDOWN:
                    if((*modeSaisie))
                        if(event->key.keysym.sym == SDLK_BACKSPACE && strlen(pseudo->texte) > 0)
                            pseudo->texte[strlen(pseudo->texte) - 1] = '\0'; /* Supprime le dernier caractère du pseudo */

                    break; 

                case SDL_QUIT:
                    (*programme_lance) = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
        mise_a_jour_rendu_nouvelle_partie(renderer, rectangle_plein_ecran, texture_image_plein_ecran,
                                          rectangle_retour_en_arriere, texture_image_retour_en_arriere,
                                          rectangle_options, texture_image_options,
                                          (*modeActif), texture_image_perso_1, rectangle_perso_1,
                                          texture_image_perso_2, rectangle_perso_2, (*personnageActif),
                                          pseudo,
                                          titres, tailleTitres, texte, texture_texte, 
                                          police, couleurNoire,
                                          itemsMenu, valider, (*largeur), (*hauteur));
}
