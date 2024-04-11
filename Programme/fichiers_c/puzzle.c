#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 260
#define NUM_PIECES_X 9
#define NUM_PIECES_Y 5
#define PIECE_WIDTH SCREEN_WIDTH / NUM_PIECES_X
#define PIECE_HEIGHT SCREEN_HEIGHT / NUM_PIECES_Y
#define TOTAL_PIECES NUM_PIECES_X * NUM_PIECES_Y

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

void shufflePieces(int correctPieceOrder[TOTAL_PIECES]) {
    for (int i = 0; i < TOTAL_PIECES; ++i) {
        correctPieceOrder[i] = i;
    }

    for (int i = TOTAL_PIECES - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = correctPieceOrder[i];
        correctPieceOrder[i] = correctPieceOrder[j];
        correctPieceOrder[j] = temp;
    }
}

void render(SDL_Renderer** renderer, SDL_Texture** puzzleImage, SDL_Rect pieceRects[TOTAL_PIECES], int correctPieceOrder[TOTAL_PIECES]) {
    
    // Nettoyer le renderer
    SDL_RenderClear((*renderer));

    for (int i = 0; i < TOTAL_PIECES; ++i) {
        SDL_RenderCopy((*renderer), (*puzzleImage), &pieceRects[correctPieceOrder[i]], &pieceRects[i]);
    }

    SDL_RenderPresent((*renderer));
}

int main(int argc, char* args[]) {

    /* Initialisation */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* puzzleImage = NULL;
    SDL_Rect pieceRects[TOTAL_PIECES];
    int correctPieceOrder[TOTAL_PIECES];

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
        }
    }

    // Initialisation de srand
    srand(time(NULL));

    shufflePieces(correctPieceOrder);

    int quit = 1;
    int cpt_selection = 0;
    int mouseX, mouseY;
    int selection_1 = -1;
    int selection_2 = -1;
    SDL_Event event;

    while (quit) {
        while (SDL_PollEvent(&event) != 0) {
            switch(event.type){
                case SDL_QUIT :
                    quit = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&mouseX, &mouseY);

                    for (int i = 0; i < TOTAL_PIECES; ++i) {
                        if (mouseX >= pieceRects[i].x && mouseX < pieceRects[i].x + PIECE_WIDTH &&
                            mouseY >= pieceRects[i].y && mouseY < pieceRects[i].y + PIECE_HEIGHT) {
                            printf("Click sur la piece %d\n", i);
                            cpt_selection ++;
                            if(cpt_selection == 1){
                                selection_1 = i;
                            }
                            if(cpt_selection == 2){
                                /* Si la pièce cliqué est la même que la précédente */
                                if(selection_1 == i){
                                    cpt_selection --;
                                }
                                else{
                                    selection_2 = i;
                                    /* Echange */
                                    SDL_Rect temp = pieceRects[selection_1];
                                    pieceRects[selection_1] = pieceRects[selection_2];
                                    pieceRects[selection_2] = temp;
                                    cpt_selection = 0;
                                    /* Réinitialisation après l'échange */
                                    selection_1 = -1;
                                    selection_2 = -1;
                                }
                            }
                            break;
                        }
                    }
                    break;
                
                default:
                    break;
            }
        }

        // Nettoyer le renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        render(&renderer, &puzzleImage, pieceRects, correctPieceOrder);
    }

    closeSDL(&window, &renderer, &puzzleImage);

    return 0;
}
