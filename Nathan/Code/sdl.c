#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/*Initialisation simple d'une fenêtre SDL*/

int initialisationSDL(SDL_Window ** pWindow) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    /*Création de la fenêtre*/

    (*pWindow) = SDL_CreateWindow("MetaTravers (Le meilleur jeu de tous les temps !)",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  400,
												  500,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

    if(!(*pWindow)){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

    return 0;
}

/*Initialisation de la TTF*/

void initialisationTexte(TTF_Font ** police) {
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

    /*Chargement de la police*/

    if( ((*police) = TTF_OpenFont("ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
}

/*Donne le rendu de la fenêtre*/

void renduSDL(SDL_Renderer ** renderer, SDL_Window ** pWindow) {
    (*renderer) = SDL_CreateRenderer((*pWindow), -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}
}

/*Destruction de la fenetre SDL*/

void destructionTTF(TTF_Font * police) {

    /*Doit être avant TTF_Quit()*/

    TTF_CloseFont(police); 
	TTF_Quit();
}

/*Destruction de la fenetre SDL*/

void destructionFenetreSDL(SDL_Window ** pWindow) {
	SDL_DestroyWindow((*pWindow));
    SDL_Quit();
}


int main(int argc, char** argv) {
    /*Initialisation pointeur vers la fenetre*/

	SDL_Window * pWindow = NULL;

    /*Le pointeur vers la surface incluse dans la fenetre*/

    SDL_Surface * texte=NULL, * image=NULL;
	SDL_Renderer * renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect;

	/*Le pointeur vers notre police*/

	TTF_Font *police = NULL;

	/*Une variable de couleur noire*/

	SDL_Color couleurNoire = {0, 0, 0};


    initialisationSDL(&pWindow);

    initialisationTexte(&police);

    renduSDL(&renderer, &pWindow);



	texte = TTF_RenderUTF8_Blended(police, "Coucou Nathan :)", couleurNoire);
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
	if(!texte_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
    txtDestRect.x = txtDestRect.y = 10;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	// load sample.png into image
	SDL_RWops *rwop=SDL_RWFromFile("affiche2018.png", "rb");
	image=IMG_LoadPNG_RW(rwop);
	if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer, image); 
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	
	


	if( pWindow )
	{
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera blanc */
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
								SDL_RenderClear(renderer);
                                
                                /* Ajout du texte en noir */
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
								
                                /* Ajout de la seconde image à une certaine position */
                                imgDestRect.x = 10;
								imgDestRect.y = 50;
								SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* Ajout de la seconde image à une autre position */
								imgDestRect.x = 250;
								SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* On fait le rendu ! */
                                SDL_RenderPresent(renderer);

								
							break;
						}
					break;
				} 
			} 
		}
	} else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

    SDL_DestroyTexture(image_tex);
    SDL_DestroyTexture(texte_tex);
    SDL_DestroyRenderer(renderer);

	destructionTTF(police);

    destructionFenetreSDL(&pWindow);
    return 0;
}
