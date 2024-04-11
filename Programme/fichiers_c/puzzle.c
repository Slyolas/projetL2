#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 260
#define NUM_PIECES_X 9
#define NUM_PIECES_Y 5
#define PIECE_WIDTH (SCREEN_WIDTH / NUM_PIECES_X)
#define PIECE_HEIGHT (SCREEN_HEIGHT / NUM_PIECES_Y)
#define TOTAL_PIECES (NUM_PIECES_X * NUM_PIECES_Y)
#define CORRECT_DISTANCE 10

SDL_Rect getRandomPieceRect() {
    SDL_Rect randomRect;
    randomRect.w = PIECE_WIDTH;
    randomRect.h = PIECE_HEIGHT;
    randomRect.x = rand() % (SCREEN_WIDTH - PIECE_WIDTH);
    randomRect.y = rand() % (SCREEN_HEIGHT - PIECE_HEIGHT);
    return randomRect;
}

int initSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    (*window) = SDL_CreateWindow("Puzzle Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

int loadMedia(SDL_Renderer** renderer, SDL_Texture** puzzleImage) {
    SDL_Surface* surface = IMG_Load("../images/puzzle/puzzle_ventilo.png");
    if (surface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 0;
    }

    (*puzzleImage) = SDL_CreateTextureFromSurface((*renderer), surface);
    if ((*puzzleImage) == NULL) {
        printf("Unable to create texture from image! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_FreeSurface(surface);

    return 1; 
}

void closeSDL(SDL_Window** window, SDL_Renderer** renderer, SDL_Texture** puzzleImage) {
    SDL_DestroyTexture((*puzzleImage));
    (*puzzleImage) = NULL;

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
    (*window) = NULL;
    (*renderer) = NULL;

    IMG_Quit();
    SDL_Quit();
}

void shufflePieces(SDL_Rect pieceRects[TOTAL_PIECES]) {
    for (int i = 0; i < TOTAL_PIECES; ++i) {
        pieceRects[i] = getRandomPieceRect();
    }
}

void render(SDL_Renderer** renderer, SDL_Texture** puzzleImage, SDL_Rect pieceRects[TOTAL_PIECES]) {
    
    // Nettoyer le renderer
    SDL_RenderClear((*renderer));

    for (int i = 0; i < TOTAL_PIECES; ++i) {
        SDL_Rect sourceRect = {i % NUM_PIECES_X * PIECE_WIDTH, i / NUM_PIECES_X * PIECE_HEIGHT, PIECE_WIDTH, PIECE_HEIGHT};
        SDL_RenderCopy((*renderer), (*puzzleImage), &sourceRect, &pieceRects[i]);
    }

    SDL_RenderPresent((*renderer));
}

int isPieceNearCorrectPosition(SDL_Rect pieceRect, SDL_Rect correctRect) {
    int distanceX = abs(pieceRect.x - correctRect.x);
    int distanceY = abs(pieceRect.y - correctRect.y);
    return (distanceX <= CORRECT_DISTANCE && distanceY <= CORRECT_DISTANCE);
}

int allPiecesLocked(const int pieceLocked[]) {
    for (int i = 0; i < TOTAL_PIECES; ++i) {
        if (!pieceLocked[i]) {
            return 0; // Au moins une pièce n'est pas verrouillée
        }
    }
    return 1; // Toutes les pièces sont verrouillées
}

int main() {

    /* Initialisation */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* puzzleImage = NULL;
    SDL_Rect pieceRects[TOTAL_PIECES];
    SDL_Rect correctPieceRects[TOTAL_PIECES];
    SDL_Event event;

    int correctPieceOrder[TOTAL_PIECES];
    int quit = 1;
    int mouseX, mouseY;
    int selectedPieceIndex = -1;
    int offsetX = 0;
    int offsetY = 0;
    int pieceLocked[TOTAL_PIECES] = {0}; // Initialise toutes les pièces comme non verrouillées

    if (!initSDL(&window, &renderer)) {
        printf("Failed to initialize!\n");
        return -1;
    }

    if (!loadMedia(&renderer, &puzzleImage)) {
        printf("Failed to load media!\n");
        return -1;
    }

    for (int y = 0; y < NUM_PIECES_Y; ++y) {
        for (int x = 0; x < NUM_PIECES_X; ++x) {
            int index = y * NUM_PIECES_X + x;
            pieceRects[index].w = PIECE_WIDTH;
            pieceRects[index].h = PIECE_HEIGHT;
            pieceRects[index].x = x * PIECE_WIDTH;
            pieceRects[index].y = y * PIECE_HEIGHT;

            correctPieceRects[index].x = x * PIECE_WIDTH;
            correctPieceRects[index].y = y * PIECE_HEIGHT;
            correctPieceRects[index].w = PIECE_WIDTH;
            correctPieceRects[index].h = PIECE_HEIGHT;
        }
    }

    // Initialisation de srand
    srand(time(NULL));

    shufflePieces(pieceRects);

    while (quit) {
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT :
                    quit = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&mouseX, &mouseY);

                    for (int i = 0; i < TOTAL_PIECES; ++i) {
                        if (!pieceLocked[i] && mouseX >= pieceRects[i].x && mouseX < pieceRects[i].x + PIECE_WIDTH &&
                            mouseY >= pieceRects[i].y && mouseY < pieceRects[i].y + PIECE_HEIGHT) {
                            // Sélectionner la pièce et calculer le décalage de position
                            selectedPieceIndex = i;
                            offsetX = mouseX - pieceRects[i].x;
                            offsetY = mouseY - pieceRects[i].y;
                            break;
                        }
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if (selectedPieceIndex != -1) {
                        mouseX = event.motion.x;
                        mouseY = event.motion.y;
                        // Assurer que la pièce ne sort pas de l'écran
                        pieceRects[selectedPieceIndex].x = mouseX - offsetX;
                        pieceRects[selectedPieceIndex].y = mouseY - offsetY;
                        // Correction pour empêcher la pièce de sortir de l'écran
                        if (pieceRects[selectedPieceIndex].x < 0) {
                            pieceRects[selectedPieceIndex].x = 0;
                        } else if (pieceRects[selectedPieceIndex].x > SCREEN_WIDTH - PIECE_WIDTH) {
                            pieceRects[selectedPieceIndex].x = SCREEN_WIDTH - PIECE_WIDTH;
                        }
                        if (pieceRects[selectedPieceIndex].y < 0) {
                            pieceRects[selectedPieceIndex].y = 0;
                        } else if (pieceRects[selectedPieceIndex].y > SCREEN_HEIGHT - PIECE_HEIGHT) {
                            pieceRects[selectedPieceIndex].y = SCREEN_HEIGHT - PIECE_HEIGHT;
                        }
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (selectedPieceIndex != -1) {
                        // Vérifier si la pièce est à proximité de sa position correcte
                        if (isPieceNearCorrectPosition(pieceRects[selectedPieceIndex], correctPieceRects[selectedPieceIndex])) {
                            // Déplacer la pièce à sa position correcte et bloquer son mouvement
                            pieceRects[selectedPieceIndex] = correctPieceRects[selectedPieceIndex];
                            pieceLocked[selectedPieceIndex] = 1; // Verrouiller la pièce
                        }
                        selectedPieceIndex = -1; // Réinitialiser la pièce sélectionnée
                    }
                    break;
                default:
                    break;
            }
        }

        if (allPiecesLocked(pieceLocked)) {
            printf("Niveau terminé !\n");
            quit = 0;
        }

        // Nettoyer le renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        render(&renderer, &puzzleImage, pieceRects);
    }

    closeSDL(&window, &renderer, &puzzleImage);

    return 0;
}