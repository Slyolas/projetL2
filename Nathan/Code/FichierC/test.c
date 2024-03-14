#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// Ajoutez ces constantes pour définir la couleur du texte et les intervalles de clignotement
#define TEXT_BLINK_INTERVAL 500 // Intervalle de clignotement en millisecondes
#define TEXT_BLINK_TIMES 5      // Nombre de clignotements

// Ajoutez ces variables globales pour le clignotement du texte
int textVisible = 1; // Indique si le texte est visible ou non
int blinkCount = 0;  // Compteur pour le nombre de clignotements

// Fonction pour afficher le texte "Skip ->" en haut à droite de l'écran
void afficherSkip(SDL_Renderer *renderer, TTF_Font *font, int largeur, int hauteur) {
    SDL_Color couleurBlanche = {255, 255, 255, 255};
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dstRect;

    // Texte à afficher
    const char *texte = "Skip ->";

    // Rendu du texte sur une surface
    surface = TTF_RenderUTF8_Blended(font, texte, couleurBlanche);
    if (!surface) {
        fprintf(stderr, "Erreur lors du rendu du texte \"%s\"\n", texte);
        return;
    }

    // Création d'une texture depuis la surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_FreeSurface(surface);
        fprintf(stderr, "Erreur lors de la création de la texture pour le texte \"%s\"\n", texte);
        return;
    }

    // Obtention des dimensions de la texture
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

    // Positionnement du texte en haut à droite de l'écran
    dstRect.x = largeur - textureWidth - 10; // 10 pixels de marge
    dstRect.y = 10;                           // 10 pixels de marge
    dstRect.w = textureWidth;
    dstRect.h = textureHeight;

    // Affichage de la texture
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    // Libération de la texture et de la surface
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

// Fonction pour clignoter le texte "Skip ->"
void clignoterTexte() {
    Uint32 ticks = SDL_GetTicks();
    Uint32 seconds = ticks / TEXT_BLINK_INTERVAL;

    if (seconds % 2 == 0) {
        textVisible = 1; // Rendre le texte visible pendant les secondes paires
    } else {
        textVisible = 0; // Rendre le texte invisible pendant les secondes impaires
    }
}

// Fonction pour gérer l'événement de clic sur le texte "Skip ->"
void gererClicSkip(SDL_Event event, int largeur, int hauteur, state_Intro_t *etat) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            // Vérifiez si le clic a eu lieu sur le texte "Skip ->"
            if (event.button.x >= largeur - 10 - 100 && event.button.x <= largeur - 10 &&
                event.button.y >= 10 && event.button.y <= 10 + 50) {
                // Si oui, passez l'intro
                etat->ligne = nombreDeLignes(fichier);
                printf("Intro Passé\n");
            }
        }
    }
}

// Modifiez votre fonction afficherIntro pour appeler ces nouvelles fonctions
void afficherIntro(SDL_Window *window, SDL_Renderer *renderer, TTF_Font *font, int largeur, int hauteur, state_Intro_t *etat) {
    // Ouverture du fichier contenant l'introduction
    FILE *fichier = fopen("../../Texte/intro.txt", "r");
    if (!fichier) {
        erreur("Erreur lors de l'ouverture du fichier intro.txt");
    }

    int nbLignes = nombreDeLignes(fichier);
    // Revenir au début du fichier
    rewind(fichier);

    int indice;
    char *ligne = NULL;
    size_t longueur = 0;
    ssize_t lecture;

    // Lecture de chaque ligne du fichier
    for (indice = etat->ligne; ((lecture = getline(&ligne, &longueur, fichier)) != -1) && indice < nbLignes; indice++) {
        // Effacement du rendu précédent
        SDL_RenderClear(renderer);

        // Affichage du texte centré
        afficherTexte(renderer, font, ligne, largeur, hauteur, etat, nbLignes);

        // Affichage du texte "Skip ->"
        if (textVisible) {
            afficherSkip(renderer, font, largeur, hauteur);
        }

        // Rafraîchissement de l'affichage
        SDL_RenderPresent(renderer);

        // Délai d'attente avant de passer à la ligne suivante
        SDL_Delay(2000);

        // Mise à jour de la ligne dans la structure après en avoir utilisé 1
        etat->ligne++;

        // Gestion de l'événement de clic sur le texte "Skip ->"
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            gererClicSkip(event, largeur, hauteur, etat);
        }

        // Clignotement du texte "Skip ->"
        clignoterTexte();
    }

    // Libération de la mémoire allouée pour la ligne et fermeture du fichier
    free(ligne);
    fclose(fichier);
}

int main() {

    // Variables globales dans main()
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    TTF_Font *font = NULL;

    /* Initialisation de l'état de l'introduction à 0 */
    state_Intro_t *etat;
    etat->ligne = 0;

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    
    // Affichage de l'introduction
    afficherIntro(window, renderer, font, largeur, hauteur, etat);
    

    return EXIT_SUCCESS;
}