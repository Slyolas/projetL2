#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

// Constantes pour les onglets
#define ONGLET_SON 0
#define ONGLET_TOUCHES 1

// Variable pour suivre l'onglet actif
int ongletActif = ONGLET_SON;

// Structure pour stocker les paramètres du jeu
typedef struct {
    int volumeMusique;
    int volumeEffets;
    SDL_Keycode toucheAvancer;
    SDL_Keycode toucheReculer;
    SDL_Keycode toucheSauter;
} ParametresJeu;

// Fonctions pour afficher les paramètres
void afficherParametresSon(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Texture* hautParleurActif, SDL_Texture* hautParleurDesactive, SDL_Rect rectBoutonSon, SDL_bool sonActif, SDL_Rect rectFenetre, int rectWidth);
void afficherParametresTouches(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Rect rectFenetre, int rectWidth, int rectHeight);
void afficherTexte(SDL_Renderer* renderer, TTF_Font* font, const char* texte, int x, int y, SDL_Color color);
void afficherTexteCentrerDansRectangle(SDL_Renderer* renderer, TTF_Font* font, const char* texte, SDL_Rect rect, SDL_Color color);
SDL_Texture* chargerTexture(SDL_Renderer* renderer, const char* fichier);
int obtenirLargeurTexte(TTF_Font* font, const char* texte);

// Fonction pour détecter les clics de souris sur les onglets
int detecterClicOnglet(int x, int y);

/***************************************************/
/*                    Fonctions                    */
/***************************************************/

// Fonction pour afficher les paramètres "Son"
void afficherParametresSon(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Texture* hautParleurActif, SDL_Texture* hautParleurDesactive, SDL_Rect rectBoutonSon, SDL_bool sonActif, SDL_Rect rectFenetre, int rectWidth) {
    
    SDL_Color textColor = {0, 0, 0, 255};

    // Calcul de la position x pour centrer le texte sur l'écran
    int positionX = rectFenetre.w * 0.2; // 20% de la largeur de la fenêtre depuis la gauche

    char volumeMusiqueText[50];
    sprintf(volumeMusiqueText, "Volume musique : %d", parametres.volumeMusique);
    afficherTexte(renderer, font, volumeMusiqueText, positionX, rectFenetre.h / 2 - 20, textColor);

    char volumeEffetsText[50];
    sprintf(volumeEffetsText, "Volume effets sonores : %d", parametres.volumeEffets);
    afficherTexte(renderer, font, volumeEffetsText, positionX, rectFenetre.h / 2 + 70, textColor);
        
    // Affichage du bouton de son
    if (sonActif) {
        SDL_RenderCopy(renderer, hautParleurActif, NULL, &rectBoutonSon);
    } else {
        SDL_RenderCopy(renderer, hautParleurDesactive, NULL, &rectBoutonSon);
    }
}

// Fonction pour afficher les paramètres "Touches"
void afficherParametresTouches(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Rect rectFenetre, int rectWidth, int rectHeight) {
    SDL_Color textColor = {0, 0, 0, 255};

    // Calcul de la position x pour centrer le texte sur l'écran
    int positionXTexte = rectFenetre.w * 0.2; // 20% de la largeur de la fenêtre depuis la gauche
    
    // 80% de la largeur de la fenêtre depuis la gauche
    // Et centrer sur le rectangle pour cliquer
    int positionXValeur = (rectFenetre.w * 0.8) - rectWidth / 2; 


    // Récupération de la longueur de la valeur
    int longAvancer = obtenirLargeurTexte(font, SDL_GetKeyName(parametres.toucheAvancer));
    int longReculer = obtenirLargeurTexte(font, SDL_GetKeyName(parametres.toucheReculer));
    int longSauter = obtenirLargeurTexte(font, SDL_GetKeyName(parametres.toucheSauter));

    // Calcule pour centrer le texte par rapport au rectangle grâce à ces mesures
    int hauteurAvancer = (rectFenetre.h / 2 - 50) + rectHeight / 4;
    int hauteurReculer = (rectFenetre.h / 2) + rectHeight / 4;
    int hauteurSauter = (rectFenetre.h / 2 + 50) + rectHeight / 4;
    int largeurAvancer = positionXValeur - (longAvancer / 2);
    int largeurReculer = positionXValeur - (longReculer / 2);
    int largeurSauter = positionXValeur - (longSauter / 2);

    // Afficher les paramètres "Touches"
    char toucheAvancerText[50];
    // Affichage du texte
    sprintf(toucheAvancerText, "Touche pour avancer : ");
    afficherTexte(renderer, font, toucheAvancerText, positionXTexte, rectFenetre.h / 2 - 50, textColor);
    // Affichage de la valeur de la touche
    sprintf(toucheAvancerText, "%s", SDL_GetKeyName(parametres.toucheAvancer));
    afficherTexte(renderer, font, toucheAvancerText, largeurAvancer, hauteurAvancer, textColor);

    char toucheReculerText[50];
    sprintf(toucheReculerText, "Touche pour reculer : ");
    afficherTexte(renderer, font, toucheReculerText, positionXTexte, rectFenetre.h / 2, textColor);
    sprintf(toucheAvancerText, "%s", SDL_GetKeyName(parametres.toucheReculer));
    afficherTexte(renderer, font, toucheAvancerText, largeurReculer, hauteurReculer, textColor);

    char toucheSauterText[50];
    sprintf(toucheSauterText, "Touche pour sauter : ");
    afficherTexte(renderer, font, toucheSauterText, positionXTexte, rectFenetre.h / 2 + 50, textColor);
    sprintf(toucheAvancerText, "%s", SDL_GetKeyName(parametres.toucheSauter));
    afficherTexte(renderer, font, toucheAvancerText, largeurSauter, hauteurSauter, textColor);
}

// Fonction pour afficher un texte
void afficherTexte(SDL_Renderer* renderer, TTF_Font* font, const char* texte, int x, int y, SDL_Color color) {
    SDL_Surface* surfaceTexte = TTF_RenderText_Blended(font, texte, color);
    SDL_Texture* textureTexte = SDL_CreateTextureFromSurface(renderer, surfaceTexte);

    SDL_Rect dstRect = { x, y, surfaceTexte->w, surfaceTexte->h };

    SDL_RenderCopy(renderer, textureTexte, NULL, &dstRect);

    SDL_FreeSurface(surfaceTexte);
    SDL_DestroyTexture(textureTexte);
}

// Fonction pour afficher un texte centré dans un rectangle
void afficherTexteCentrerDansRectangle(SDL_Renderer* renderer, TTF_Font* font, const char* texte, SDL_Rect rect, SDL_Color color) {
    int texteWidth, texteHeight;
    TTF_SizeText(font, texte, &texteWidth, &texteHeight);

    int x = rect.x + (rect.w - texteWidth) / 2;
    int y = rect.y + (rect.h - texteHeight) / 2;

    afficherTexte(renderer, font, texte, x, y, color);
}

// Fonction pour charger une texture à partir d'un fichier
SDL_Texture* chargerTexture(SDL_Renderer* renderer, const char* fichier) {
    SDL_Surface* surface = IMG_Load(fichier);
    if (!surface) {
        printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Fonction pour obtenir la largeur d'un texte en pixels
int obtenirLargeurTexte(TTF_Font* font, const char* texte) {
    int width, height;
    TTF_SizeText(font, texte, &width, &height);
    return width;
}

/***************************************************/
/*                  Main Function                  */
/***************************************************/

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Paramètres", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialisation de SDL_ttf
    if (TTF_Init() != 0) {
        printf("Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Chargement de la police
    TTF_Font* font = TTF_OpenFont("../Police/02587_ARIALMT.ttf", 28);
    if (!font) {
        printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Chargement des images
    SDL_Texture* hautParleurActif = chargerTexture(renderer, "../Images/haut_parleur_actif.png");
    SDL_Texture* hautParleurDesactive = chargerTexture(renderer, "../Images/haut_parleur_desactive.png");
    if (!hautParleurActif || !hautParleurDesactive) {
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Paramètres du jeu
    ParametresJeu parametres = {50, 50, SDLK_w, SDLK_s, SDLK_SPACE};

    // Boucle principale
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                // Redimensionnement de la fenêtre
            } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                // Clic de souris
                int x = event.button.x;
                int y = event.button.y;
                ongletActif = detecterClicOnglet(x, y);
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Obtenir la taille de la fenêtre
        int screenWidth, screenHeight;
        SDL_GetWindowSize(window, &screenWidth, &screenHeight);

        // Calculer la taille de police en fonction de la taille de la fenêtre
        int taillePolice = screenHeight / 20; // Par exemple, vous pouvez ajuster ce ratio selon vos besoins

        // Définir la police avec la nouvelle taille
        TTF_Font* font = TTF_OpenFont("../Police/02587_ARIALMT.ttf", taillePolice);
        if (!font) {
            printf("Erreur lors du chargement de la police : %s\n", TTF_GetError());
            TTF_Quit();
            SDL_Quit();
            return 1;
        }

        // Affichage des onglets et des paramètres correspondants
        SDL_Rect rectFenetre = {0, 0, screenWidth, screenHeight};
        int rectWidth = screenWidth * 0.6; // Largeur de la zone des paramètres
        int rectHeight = screenHeight * 0.8; // Hauteur de la zone des paramètres
        SDL_Rect rectParametres = {screenWidth / 2 - rectWidth / 2, screenHeight / 2 - rectHeight / 2, rectWidth, rectHeight};

        // Dessiner le rectangle des paramètres
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderFillRect(renderer, &rectParametres);

        // Dessiner les onglets
        SDL_Rect rectOngletSon = {rectParametres.x, rectParametres.y, rectWidth / 2, 50};
        SDL_Rect rectOngletTouches = {rectParametres.x + rectWidth / 2, rectParametres.y, rectWidth / 2, 50};

        if (ongletActif == ONGLET_SON) {
            SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        }
        SDL_RenderFillRect(renderer, &rectOngletSon);

        if (ongletActif == ONGLET_TOUCHES) {
            SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        }
        SDL_RenderFillRect(renderer, &rectOngletTouches);

        // Afficher le texte des onglets
        SDL_Color textColor = {255, 255, 255, 255};
        afficherTexteCentrerDansRectangle(renderer, font, "Son", rectOngletSon, textColor);
        afficherTexteCentrerDansRectangle(renderer, font, "Touches", rectOngletTouches, textColor);

        // Afficher les paramètres correspondant à l'onglet actif
        if (ongletActif == ONGLET_SON) {
            afficherParametresSon(renderer, font, parametres, hautParleurActif, hautParleurDesactive, rectParametres, SDL_TRUE, rectFenetre, rectWidth);
        } else if (ongletActif == ONGLET_TOUCHES) {
            afficherParametresTouches(renderer, font, parametres, rectFenetre, rectWidth, rectHeight);
        }

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);

        // Libérer la police
        TTF_CloseFont(font);
    }

    // Libération des ressources
    SDL_DestroyTexture(hautParleurActif);
    SDL_DestroyTexture(hautParleurDesactive);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}

// Fonction pour détecter le clic de souris sur un onglet
int detecterClicOnglet(int x, int y) {
    if (x < 400 && y < 50) {
        return ONGLET_SON;
    } else if (x >= 400 && y < 50) {
        return ONGLET_TOUCHES;
    }
    return -1;
}