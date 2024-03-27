#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/* Fonction qui affiche un message d'erreur quand une chose n'a pas pû être exécuté */
void erreur(const char *message) {

    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/* Fonction qui permet de créer une fenêtre et le rendu */
void creer_fenetre_rendu(SDL_Window **window,SDL_Renderer **renderer, int largeur, int hauteur) {

    /* Création de la fenêtre */
    (*window) = SDL_CreateWindow("MetaTravers", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, 
                                 largeur, hauteur,
                                 SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if((*window) == NULL)
        erreur("Création fenêtre échouée");

    /* Création du rendu */
    (*renderer) = SDL_CreateRenderer((*window), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if((*renderer) == NULL)
        erreur("Création rendu échoué");
}

/* Fonction qui permet de récupérer les nouvelles dimensions de la fenêtre pour redimensionner cette dernière et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Fonction qui met à jour le rendu du menu nouvelle partie après redimension de la fenêtre */
void mise_a_jour_rendu_nouvelle_partie(SDL_Renderer **renderer, SDL_Texture **texture_image_tablette_info, SDL_Rect *rectangle_tablette_info,
                                        int largeur, int hauteur) {

    int i;

    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de la tablette informative */
    rectangle_tablette_info->w = largeur / 4;
    rectangle_tablette_info->h = hauteur / 1.9;
    rectangle_tablette_info->x = largeur / 2 - (rectangle_tablette_info->w) / 2;
    rectangle_tablette_info->y = hauteur / 4 - (rectangle_tablette_info->h) / 4;

    if(SDL_RenderCopy((*renderer), (*texture_image_tablette_info), NULL, rectangle_tablette_info) != 0)
        erreur("Copie de la texture");

    SDL_SetRenderDrawColor((*renderer), 240, 240, 240, 0);

    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet d'initialiser les différents objets de la page d'information */
void initialisation_page_informatif(SDL_Renderer **renderer,
                           SDL_Surface **image_tablette_info, SDL_Texture **texture_image_tablette_info) {

    /* Initialisation de l'image de la tablette_info */
    (*image_tablette_info) = IMG_Load("../images/tablette_info.png");
    if((*image_tablette_info) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_tablette_info) = SDL_CreateTextureFromSurface((*renderer), (*image_tablette_info));
    if((*texture_image_tablette_info) == NULL)
        erreur("Création de la texture");

    SDL_FreeSurface((*image_tablette_info));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}

void prog(SDL_Event *event, int *largeur, int *hauteur, SDL_bool *programme_lance, SDL_Rect *rectangle_tablette_info,
        SDL_Renderer **renderer, SDL_Texture **texture_image_tablette_info){


    while(SDL_PollEvent(event)){
        switch(event->type) {
            /* Gestion de l'événement de redimensionnement de la fenêtre */
            case SDL_WINDOWEVENT:
                redimensionnement_fenetre((*event), largeur, hauteur);
                break;

            /* Quitter le programme */
            case SDL_QUIT:
                (*programme_lance) = SDL_FALSE;
                break;
        }
    }
    /* Mise à jour du rendu */
    mise_a_jour_rendu_nouvelle_partie(renderer, texture_image_tablette_info, rectangle_tablette_info,
                                    (*largeur), (*hauteur));
}

int main(){

    /* Initialisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_bool programme_lance = SDL_TRUE;

    SDL_Event event;


    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);


    /* Création des pointeurs sur la surface de l'image de la tablette et sur sa texture */
    SDL_Surface *image_tablette_info = NULL;
    SDL_Texture *texture_image_tablette_info = NULL;
    SDL_Rect rectangle_tablette_info;

    initialisation_page_informatif(&renderer, &image_tablette_info, &texture_image_tablette_info);
    
    while(programme_lance){
        prog(&event, &largeur, &hauteur, &programme_lance, &rectangle_tablette_info,
            &renderer, &texture_image_tablette_info);
    }

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}