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
void afficherParametresSon(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Texture* hautParleurActif, SDL_Texture* hautParleurDesactive, SDL_Rect rectBoutonSon, SDL_bool sonActif, SDL_Rect rectFenetre, int rectWidth, int largeurFenetre, int hauteurFenetre);
void afficherParametresTouches(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Rect rectFenetre, int rectWidth, int rectHeight, int largeurFenetre, int hauteurFenetre);
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
void afficherParametresSon(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Texture* hautParleurActif, SDL_Texture* hautParleurDesactive, SDL_Rect rectBoutonSon, SDL_bool sonActif, SDL_Rect rectFenetre, int rectWidth, int largeurFenetre, int hauteurFenetre) {
    
    SDL_Color textColor = {0, 0, 0, 255};

    // Calcul de la position x pour centrer le texte sur l'écran
    int positionX = rectFenetre.w * 0.2; // 20% de la largeur de la fenêtre depuis la gauche

    char volumeMusiqueText[50];
    sprintf(volumeMusiqueText, "Volume musique : %d", parametres.volumeMusique);
    afficherTexte(renderer, font, volumeMusiqueText, positionX, rectFenetre.h / 2 - hauteurFenetre / 16, textColor);

    char volumeEffetsText[50];
    sprintf(volumeEffetsText, "Volume effets sonores : %d", parametres.volumeEffets);
    afficherTexte(renderer, font, volumeEffetsText, positionX, rectFenetre.h / 2 + hauteurFenetre / 6, textColor);
        
    // Affichage du bouton de son
    if (sonActif) {
        SDL_RenderCopy(renderer, hautParleurActif, NULL, &rectBoutonSon);
    } else {
        SDL_RenderCopy(renderer, hautParleurDesactive, NULL, &rectBoutonSon);
    }
}

// Fonction pour afficher les paramètres "Touches"
void afficherParametresTouches(SDL_Renderer* renderer, TTF_Font* font, ParametresJeu parametres, SDL_Rect rectFenetre, int rectWidth, int rectHeight, int largeurFentre, int hauteurFenetre) {
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
    int hauteurAvancer = (rectFenetre.h / 2 - hauteurFenetre / 9.6) + rectHeight / 4;
    int hauteurReculer = (rectFenetre.h / 2) + rectHeight / 4;
    int hauteurSauter = (rectFenetre.h / 2 + hauteurFenetre / 9.6) + rectHeight / 4;
    int largeurAvancer = positionXValeur - (longAvancer / 2);
    int largeurReculer = positionXValeur - (longReculer / 2);
    int largeurSauter = positionXValeur - (longSauter / 2);

    // Afficher les paramètres "Touches"
    char toucheAvancerText[50];
    // Affichage du texte
    sprintf(toucheAvancerText, "Touche pour avancer : ");
    afficherTexte(renderer, font, toucheAvancerText, positionXTexte, rectFenetre.h / 2 - hauteurFenetre / 9.6, textColor);
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
    afficherTexte(renderer, font, toucheSauterText, positionXTexte, rectFenetre.h / 2 + hauteurFenetre / 9.6, textColor);
    sprintf(toucheAvancerText, "%s", SDL_GetKeyName(parametres.toucheSauter));
    afficherTexte(renderer, font, toucheAvancerText, largeurSauter, hauteurSauter, textColor);

}

// Fonction pour afficher du texte
void afficherTexte(SDL_Renderer* renderer, TTF_Font* font, const char* texte, int x, int y, SDL_Color color) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, texte, color);
    if (!surfaceMessage) {
        fprintf(stderr, "Erreur lors de la création de la surface de texte : %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    if (!messageTexture) {
        fprintf(stderr, "Erreur lors de la création de la texture de texte : %s\n", SDL_GetError());
        SDL_FreeSurface(surfaceMessage);
        return;
    }

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(messageTexture, NULL, NULL, &texW, &texH);

    SDL_Rect dstRect = {x, y, texW, texH};
    SDL_RenderCopy(renderer, messageTexture, NULL, &dstRect);

    SDL_DestroyTexture(messageTexture);
    SDL_FreeSurface(surfaceMessage);
}

void afficherTexteCentrerDansRectangle(SDL_Renderer* renderer, TTF_Font* font, const char* texte, SDL_Rect rect, SDL_Color color) {
    // Obtenir la largeur du texte rendu
    int largeurTexte = obtenirLargeurTexte(font, texte);
    
    // Calculer la position x pour centrer le texte dans le rectangle
    int x = rect.x + (rect.w - largeurTexte) / 2;
    
    // Calculer la position y pour centrer le texte verticalement dans le rectangle
    int y = rect.y + (rect.h - TTF_FontHeight(font)) / 2 + TTF_FontHeight(font) / 4; // Centrage vertical avec ajustement
    
    // Afficher le texte centré dans le rectangle
    afficherTexte(renderer, font, texte, x, y, color);
}

// Fonction pour charger une texture à partir d'un fichier
SDL_Texture* chargerTexture(SDL_Renderer* renderer, const char* fichier) {
    SDL_Surface* surface = IMG_Load(fichier);
    if (!surface) {
        fprintf(stderr, "Erreur lors du chargement de l'image : %s\n", IMG_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        fprintf(stderr, "Erreur lors de la création de la texture : %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }
    SDL_FreeSurface(surface);
    return texture;
}

int obtenirLargeurTexte(TTF_Font* font, const char* texte) {
    int largeur;
    TTF_SizeText(font, texte, &largeur, NULL);
    return largeur;
}


/***************************************************/
/*                      Main                       */
/***************************************************/

int main(int argc, char *argv[]) {
    // Initialisation de la SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Initialisation de SDL_ttf
    if (TTF_Init() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        return 1;
    }

    // Charger la police
    TTF_Font* font = TTF_OpenFont("../Police/02587_ARIALMT.ttf", 24);
    if (!font) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

     // Initialisation de SDL_image pour la gestion des images PNG
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_image : %s\n", IMG_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    int largeur = 640;
    int hauteur = 480;

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow("Paramètres du jeu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur, hauteur, SDL_WINDOW_RESIZABLE);
    
    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Paramètres du jeu
    ParametresJeu parametres = {50,50,SDLK_RIGHT, SDLK_LEFT, SDLK_UP};
    
    // Ajouter une variable pour suivre la touche sélectionnée
    SDL_Keycode *toucheSelectionnee = NULL;
    SDL_bool selectionTouche = SDL_FALSE;

    // Ajouter des rectangles pour représenter les boîtes de texte des touches
    SDL_Rect rectToucheAvancer = {0, 0, 0, 0};
    SDL_Rect rectToucheReculer = {0, 0, 0, 0};
    SDL_Rect rectToucheSauter = {0, 0, 0, 0};
    // Ajouter des rectangles pour représenter les boîtes de texte du son
    SDL_Rect rectVolumeMusique = {0, 0, 0, 0};
    SDL_Rect rectVolumeEffets = {0, 0, 0, 0};
    // Rectangle du bouton de son
    SDL_Rect rectBoutonSon = {0, 0, 0, 0}; 
    // Initialisation des onglets car on les utilisent avant de les afficher 
    SDL_Rect ongletSon;
    SDL_Rect ongletTouches;

    // Charger les textures des images de haut-parleur
    SDL_Texture* hautParleurActif = chargerTexture(renderer, "../Images/haut_parleur_actif.png");
    SDL_Texture* hautParleurDesactive = chargerTexture(renderer, "../Images/haut_parleur_desactive.png");
    
    // Variable pour suivre l'état du son (activé/désactivé)
    SDL_bool sonActif = SDL_TRUE;

    // Boucle principale
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    // Vérifier si le clic est dans la zone de l'onglet Son
                    if (mouseX >= ongletSon.x && mouseX <= ongletSon.x + ongletSon.w && mouseY >= ongletSon.y && mouseY <= ongletSon.y + ongletSon.h) {
                        ongletActif = ONGLET_SON;
                    }
                    // Vérifier si le clic est dans la zone de l'onglet Touches
                    else if (mouseX >= ongletTouches.x && mouseX <= ongletTouches.x + ongletTouches.w && mouseY >= ongletTouches.y && mouseY <= ongletTouches.y + ongletTouches.h) {
                        ongletActif = ONGLET_TOUCHES;
                    }
                    // Gestion des clics de souris pour les boîtes de modification des touches
                    if (ongletActif == ONGLET_TOUCHES) {
                        if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectToucheAvancer)) {
                            selectionTouche = SDL_TRUE;
                            toucheSelectionnee = &parametres.toucheAvancer;
                        } else if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectToucheReculer)) {
                            selectionTouche = SDL_TRUE;
                            toucheSelectionnee = &parametres.toucheReculer;
                        } else if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectToucheSauter)) {
                            selectionTouche = SDL_TRUE;
                            toucheSelectionnee = &parametres.toucheSauter;
                        } else {
                            selectionTouche = SDL_FALSE;
                            toucheSelectionnee = NULL;
                        }
                    }
                    // Gestion des clics de souris pour les boîtes de modification de son
                    if (ongletActif == ONGLET_SON) {
                        int tempMusique, tempEffets;
                        if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectVolumeMusique)) {
                            float percentage = (float)(mouseX - rectVolumeMusique.x) / rectVolumeMusique.w;
                            parametres.volumeMusique = (int)(percentage * 100);
                            tempMusique = parametres.volumeMusique;
                        } else if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectVolumeEffets)) {
                            float percentage = (float)(mouseX - rectVolumeEffets.x) / rectVolumeEffets.w;
                            parametres.volumeEffetssonActif = !sonActif; = (int)(percentage * 100);
                            tempEffets = parametres.volumeEffets;

                        } 
                        if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectBoutonSon)) {
                            // Inverser l'état du son lors du clic sur le bouton de son
                            sonActif = !sonActif;

                            if(sonActif == SDL_FALSE){
                                parametres.volumeEffets = 0;
                                parametres.volumeMusique = 0;
                                
                            }else if(sonActif == SDL_TRUE){
                                parametres.volumeEffets = tempEffets;
                                parametres.volumeMusique = tempMusique;
                            }
                        }
                        else if(sonActif == SDL_FALSE && parametres.volumeEffets != 0 || parametres.volumeMusique != 0){
                            if(parametres.volumeEffets)
                                parametres.volumeEffets = tempEffets;
                            else if(parametres.volumeMusique)
                                parametres.volumeMusique = tempMusique;
                            sonActif = !sonActif;
                        }
                    }
                }
                else if (event.type == SDL_MOUSEMOTION && (event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT))) {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    int deltaX = event.motion.x - mouseX;
                    int deltaY = event.motion.y - mouseY;
                    if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectVolumeMusique)) {
                        // Calculer le pourcentage de déplacement de la souris par rapport à la taille de la barre de volume
                        float percentage = (float)(mouseX + deltaX - rectVolumeMusique.x) / rectVolumeMusique.w;
                        // Modifier les paramètres de volume en fonction du pourcentage de déplacement de la souris
                        parametres.volumeMusique = (int)(percentage * 100); // Supposant que le volume est entre 0 et 100
                    } else if (SDL_PointInRect(&(SDL_Point){mouseX, mouseY}, &rectVolumeEffets)) {
                        // Même logique pour le volume des effets sonores si nécessaire
                    }
                    mouseX = event.motion.x;
                    mouseY = event.motion.y;
                }
                break;
                case SDL_KEYDOWN:
                    // Si une touche est sélectionnée, mettez à jour la touche correspondante
                    if (event.key.keysym.sym == SDLK_ESCAPE && selectionTouche) {
                        // Réinitialiser la touche sélectionnée à sa valeur par défaut
                        *toucheSelectionnee = (toucheSelectionnee == &parametres.toucheAvancer) ? SDLK_LEFT :
                                               (toucheSelectionnee == &parametres.toucheReculer) ? SDLK_RIGHT :
                                               (toucheSelectionnee == &parametres.toucheSauter) ? SDLK_UP : SDLK_UNKNOWN;
                        selectionTouche = SDL_FALSE;
                        toucheSelectionnee = NULL;
                    } else if (selectionTouche) {
                        // Vérifier si la touche sélectionnée est différente de la touche enfoncée
                        SDL_Keycode nouvelleTouche = event.key.keysym.sym;
                        if (nouvelleTouche != SDLK_ESCAPE && nouvelleTouche != SDLK_UNKNOWN &&
                            nouvelleTouche != parametres.toucheAvancer &&
                            nouvelleTouche != parametres.toucheReculer &&
                            nouvelleTouche != parametres.toucheSauter) {
                            *toucheSelectionnee = nouvelleTouche;
                            selectionTouche = SDL_FALSE;
                            toucheSelectionnee = NULL;
                        }
                    }
                break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        // Appeler la fonction de redimensionnement avec les nouvelles dimensions de la fenêtre
                        int largeur = event.window.data1;
                        int hauteur = event.window.data2;
                    }
                break;
            }
        }
        
        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        // Calculer la position des onglets en fonction de la largeur de la fenêtre
	    int tabWidth = largeur / 2; // Largeur d'un onglet
	    int screenWidth, screenHeight;
	    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
        SDL_Rect rectFenetre = {0, 0, screenWidth, screenHeight};

	
        // Dessiner les onglets

	    // Centrer les onglets horizontalement
	    ongletSon = (SDL_Rect){(screenWidth - tabWidth * 2) / 2, 0, tabWidth, hauteur / 9.6};
	    ongletTouches = (SDL_Rect){ongletSon.x + tabWidth, 0, tabWidth, hauteur / 9.6};
        SDL_Color colorOngletSon = ongletActif == ONGLET_SON ? (SDL_Color){255, 0, 0, 255} : (SDL_Color){200, 200, 200, 255};
        SDL_Color colorOngletTouches = ongletActif == ONGLET_TOUCHES ? (SDL_Color){255, 0, 0, 255} : (SDL_Color){200, 200, 200, 255};
        SDL_SetRenderDrawColor(renderer, colorOngletSon.r, colorOngletSon.g, colorOngletSon.b, colorOngletSon.a);
        SDL_RenderFillRect(renderer, &ongletSon);
        SDL_SetRenderDrawColor(renderer, colorOngletTouches.r, colorOngletTouches.g, colorOngletTouches.b, colorOngletTouches.a);
        SDL_RenderFillRect(renderer, &ongletTouches);


        // Calcul de la position x pour centrer les boîtes de clic à 20% de la droite de la fenêtre
        int positionX = rectFenetre.w * 0.8; // 80% de la largeur de la fenêtre depuis la gauche

        
        // Afficher le texte des onglets centré dans leurs rectangles respectifs
        afficherTexteCentrerDansRectangle(renderer, font, "Son", ongletSon, (SDL_Color){255, 255, 255, 255});
        afficherTexteCentrerDansRectangle(renderer, font, "Touches", ongletTouches, (SDL_Color){255, 255, 255, 255});

        // Dessiner les rectangles pour les boîtes de modification des touches uniquement dans l'onglet des touches
        if (ongletActif == ONGLET_TOUCHES) {
            int rectWidth = tabWidth / 2;
            int rectHeight = hauteur / 16;

            rectToucheAvancer = (SDL_Rect){positionX - rectWidth, rectFenetre.h / 2 - hauteur / 9.6, rectWidth, rectHeight};
            rectToucheReculer = (SDL_Rect){positionX - rectWidth, rectFenetre.h / 2, rectWidth, rectHeight};
            rectToucheSauter = (SDL_Rect){positionX - rectWidth, rectFenetre.h / 2 + hauteur / 9.6, rectWidth, rectHeight};
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Couleur grise
            SDL_RenderFillRect(renderer, &rectToucheAvancer);
            SDL_RenderFillRect(renderer, &rectToucheReculer);
            SDL_RenderFillRect(renderer, &rectToucheSauter);

            afficherParametresTouches(renderer, font, parametres, rectFenetre, rectWidth, rectHeight, largeur, hauteur);
        }
        // Dessiner les rectangles pour les boîtes de modification du son uniquement dans l'onglet du son
        else if (ongletActif == ONGLET_SON) {
            int rectWidth = tabWidth / 2;
            int rectHeight = hauteur / 24;

            rectVolumeMusique = (SDL_Rect){positionX - rectWidth, rectFenetre.h / 2 - hauteur / 16, rectWidth, rectHeight};
            rectVolumeEffets = (SDL_Rect){positionX - rectWidth, rectFenetre.h / 2 + hauteur / 6, rectWidth, rectHeight};
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Couleur grise
            SDL_RenderFillRect(renderer, &rectVolumeMusique);
            SDL_RenderFillRect(renderer, &rectVolumeEffets);

            // Dessiner le bouton de son
            rectBoutonSon = (SDL_Rect){50, 200, 32, 32};
            SDL_RenderCopy(renderer, sonActif ? hautParleurActif : hautParleurDesactive, NULL, &rectBoutonSon);
            afficherParametresSon(renderer, font, parametres, hautParleurActif, hautParleurDesactive, rectBoutonSon, sonActif, rectFenetre, rectWidth, largeur, hauteur);
        
        } 

        // Afficher le rendu
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    SDL_DestroyTexture(hautParleurActif);
    SDL_DestroyTexture(hautParleurDesactive);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}