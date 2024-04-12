#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define LARGEUR 800
#define HAUTEUR 260
#define NUM_PIECES_X 9
#define NUM_PIECES_Y 5
#define LARGEUR_PIECE (LARGEUR / NUM_PIECES_X)
#define HAUTEUR_PIECE (HAUTEUR / NUM_PIECES_Y)
#define TOTAL_PIECES (NUM_PIECES_X * NUM_PIECES_Y)
#define CORRECT_DISTANCE 10

/* Fonction pour obtenir un rectangle représentant une pièce de puzzle aléatoire */
SDL_Rect rectangle_piece_aleatoire() {
    SDL_Rect rectangle_aleatoire;
    rectangle_aleatoire.w = LARGEUR_PIECE;
    rectangle_aleatoire.h = HAUTEUR_PIECE;
    rectangle_aleatoire.x = rand() % (LARGEUR - LARGEUR_PIECE);
    rectangle_aleatoire.y = rand() % (HAUTEUR - HAUTEUR_PIECE);
    return rectangle_aleatoire;
}

/* Fonction d'initialisation de SDL */
int initialisation_SDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    (*window) = SDL_CreateWindow("Puzzle Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR, HAUTEUR, SDL_WINDOW_SHOWN);
    if ((*window) == NULL) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    (*renderer) = SDL_CreateRenderer((*window), -1, SDL_RENDERER_ACCELERATED);
    if ((*renderer) == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_SetRenderDrawColor((*renderer), 0xFF, 0xFF, 0xFF, 0xFF);
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

    return 1;
}

/* Fonction de chargement de l'image du puzzle */
int chargement_image(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle) {
    SDL_Surface* surface = IMG_Load("../images/puzzle/puzzle_ventilo.png");
    if (surface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

    (*texture_image_puzzle) = SDL_CreateTextureFromSurface((*renderer), surface);
    if ((*texture_image_puzzle) == NULL) {
        printf("Unable to create texture from image! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_FreeSurface(surface);

    return 1; 
}

/* Fonction de fermeture de SDL */
void fermeture_SDL(SDL_Window** window, SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle) {
    SDL_DestroyTexture((*texture_image_puzzle));
    (*texture_image_puzzle) = NULL;

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
    (*window) = NULL;
    (*renderer) = NULL;

    IMG_Quit();
    SDL_Quit();
}

/* Fonction pour mélanger les pièces du puzzle */
void melange_piece(SDL_Rect rectangle_piece[TOTAL_PIECES]) {
    for (int i = 0; i < TOTAL_PIECES; ++i) {
        rectangle_piece[i] = rectangle_piece_aleatoire();
    }
}

/* Fonction pour afficher le rendu du puzzle */
void afficher_rendu(SDL_Renderer** renderer, SDL_Texture** texture_image_puzzle, SDL_Rect rectangle_piece[TOTAL_PIECES]) {
    
    // Nettoyer le rendu
    SDL_RenderClear((*renderer));

    for (int i = 0; i < TOTAL_PIECES; ++i) {
        SDL_Rect sourceRect = {i % NUM_PIECES_X * LARGEUR_PIECE, i / NUM_PIECES_X * HAUTEUR_PIECE, LARGEUR_PIECE, HAUTEUR_PIECE};
        SDL_RenderCopy((*renderer), (*texture_image_puzzle), &sourceRect, &rectangle_piece[i]);
    }

    SDL_RenderPresent((*renderer));
}

/* Fonction pour vérifier si une pièce est proche de sa position correcte */
int estPieceProchePositionCorrecte(SDL_Rect pieceRect, SDL_Rect correctRect) {
    int distanceX = abs(pieceRect.x - correctRect.x);
    int distanceY = abs(pieceRect.y - correctRect.y);
    return (distanceX <= CORRECT_DISTANCE && distanceY <= CORRECT_DISTANCE);
}

/* Fonction pour vérifier si toutes les pièces du puzzle sont bloquées (à leur position correcte) */
int verification_puzzle_fini(const int piece_bloquer[]) {
    for (int i = 0; i < TOTAL_PIECES; ++i) {
        if (!piece_bloquer[i]) {
            return 0; // Au moins une pièce n'est pas verrouillée
        }
    }
    return 1; // Toutes les pièces sont verrouillées
}

int main() {

    /* Initialisation */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture_image_puzzle = NULL;
    SDL_Rect rectangle_piece[TOTAL_PIECES];
    SDL_Rect emplacement_rectangle_piece[TOTAL_PIECES];
    SDL_Event event;

    int quit = 1;
    int position_x, position_y;

    int piece_selectionnee = -1;
    /* Décalage en X/Y entre le coin supérieur gauche de la pièce et la position du curseur de la souris */
    int decalage_x = 0;
    int decalage_y = 0;

    /* Initialise toutes les pièces comme non verrouillées */
    int piece_bloquer[TOTAL_PIECES] = {0};

    /* Initialisation de SDL */
    if (!initialisation_SDL(&window, &renderer)) {
        printf("Erreur d'initialisation!\n");
        return -1;
    }

    /* Chargement de l'image du puzzle */
    if (!chargement_image(&renderer, &texture_image_puzzle)) {
        printf("Erreur chargement image!\n");
        return -1;
    }

    /* Calcul des rectangles pour chaque pièce du puzzle et des emplacements corrects */
    for (int y = 0; y < NUM_PIECES_Y; ++y) {
        for (int x = 0; x < NUM_PIECES_X; ++x) {
            int indice = y * NUM_PIECES_X + x;
            rectangle_piece[indice].w = LARGEUR_PIECE;
            rectangle_piece[indice].h = HAUTEUR_PIECE;
            rectangle_piece[indice].x = x * LARGEUR_PIECE;
            rectangle_piece[indice].y = y * HAUTEUR_PIECE;

            emplacement_rectangle_piece[indice].x = x * LARGEUR_PIECE;
            emplacement_rectangle_piece[indice].y = y * HAUTEUR_PIECE;
            emplacement_rectangle_piece[indice].w = LARGEUR_PIECE;
            emplacement_rectangle_piece[indice].h = HAUTEUR_PIECE;
        }
    }

    /* Initialisation de srand pour la génération de pièces aléatoires*/
    srand(time(NULL));

    /* Mélange des pièces du puzzle */
    melange_piece(rectangle_piece);

    /* Boucle principale */
    while (quit) {
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT :
                    quit = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&position_x, &position_y);

                    for (int i = 0; i < TOTAL_PIECES; ++i) {

                        /* Vérifier si l'utilisateur a cliqué sur une pièce non bloquée */
                        if (!piece_bloquer[i] && position_x >= rectangle_piece[i].x && position_x < rectangle_piece[i].x + LARGEUR_PIECE &&
                            position_y >= rectangle_piece[i].y && position_y < rectangle_piece[i].y + HAUTEUR_PIECE) {
                            /* Sélectionner la pièce et calculer le décalage de position */
                            piece_selectionnee = i;
                            decalage_x = position_x - rectangle_piece[i].x;
                            decalage_y = position_y - rectangle_piece[i].y;
                            break;
                        }
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if (piece_selectionnee != -1) {
                        position_x = event.motion.x;
                        position_y = event.motion.y;
                        /* Assurer que la pièce ne sort pas de l'écran */
                        rectangle_piece[piece_selectionnee].x = position_x - decalage_x;
                        rectangle_piece[piece_selectionnee].y = position_y - decalage_y;
                        /* Correction pour empêcher la pièce de sortir de l'écran */
                        if (rectangle_piece[piece_selectionnee].x < 0) {
                            rectangle_piece[piece_selectionnee].x = 0;
                        } else if (rectangle_piece[piece_selectionnee].x > LARGEUR - LARGEUR_PIECE) {
                            rectangle_piece[piece_selectionnee].x = LARGEUR - LARGEUR_PIECE;
                        }
                        if (rectangle_piece[piece_selectionnee].y < 0) {
                            rectangle_piece[piece_selectionnee].y = 0;
                        } else if (rectangle_piece[piece_selectionnee].y > HAUTEUR - HAUTEUR_PIECE) {
                            rectangle_piece[piece_selectionnee].y = HAUTEUR - HAUTEUR_PIECE;
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (piece_selectionnee != -1) {
                        /* Vérifier si la pièce est à proximité de sa position correcte */
                        if (estPieceProchePositionCorrecte(rectangle_piece[piece_selectionnee], emplacement_rectangle_piece[piece_selectionnee])) {
                            /* Déplacer la pièce à sa position correcte et bloquer son mouvement */
                            rectangle_piece[piece_selectionnee] = emplacement_rectangle_piece[piece_selectionnee];
                            piece_bloquer[piece_selectionnee] = 1; /* Verrouiller la pièce */
                        }
                        piece_selectionnee = -1; /* Réinitialiser la pièce sélectionnée */
                    }
                    break;
                default:
                    break;
            }
        }

        /* Vérifier si toutes les pièces sont bloquées à leur position correcte */
        if (verification_puzzle_fini(piece_bloquer)) {
            printf("Niveau terminé !\n");
            quit = 0;
        }

        /* Nettoyer le rendu */
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        afficher_rendu(&renderer, &texture_image_puzzle, rectangle_piece);
    }

    fermeture_SDL(&window, &renderer, &texture_image_puzzle);

    return 0;
}