#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/* Structure pour représenter une case de menu */
typedef struct {
    SDL_Rect rectangle;
    char texte[20];
} itemMenu;

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

/* Fonction qui permet d'initialiser les différents objets */
void initialisation_objets(SDL_Renderer **renderer, SDL_Surface **image_normal_mode, SDL_Texture **texture_image_normal_mode,
                           SDL_Surface **image_hard_mode, SDL_Texture **texture_image_hard_mode,
                           TTF_Font **police, itemMenu *titre, itemMenu *itemsMenu, int tailleMenu) {

    /* Initialisation de l'image de fond du menu */
    (*image_normal_mode) = IMG_Load("../Images/normal.png");
    if((*image_normal_mode) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_normal_mode) = SDL_CreateTextureFromSurface((*renderer), (*image_normal_mode));
    if((*texture_image_normal_mode) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_normal_mode));

    /* Initialisation de l'image de fond du menu */
    (*image_hard_mode) = IMG_Load("../Images/hard.png");
    if((*image_hard_mode) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_hard_mode) = SDL_CreateTextureFromSurface((*renderer), (*image_hard_mode));
    if((*texture_image_hard_mode) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_hard_mode));

    

    /* Initialisation de la police */
    if(((*police) = TTF_OpenFont("../Police/02587_ARIALMT.ttf", 20)) == NULL)
        erreur("Chargement de la police");

    /* Initialisation du titre du menu */
    sprintf(titre->texte, " Choisir le mode : ");

	/* Initialisation du texte dans les items du menu */
        for(int i = 0; i < tailleMenu; i++) {
            if(!i)
                sprintf(itemsMenu[i].texte, " Normal ");
            else
                sprintf(itemsMenu[i].texte, " Hard ");
        }
}

/* Fonction qui permet de redimensionner la fenêtre et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Fonction qui met à jour le rendu après redimension de la fenêtre */
void mise_a_jour_rendu(SDL_Renderer **renderer, SDL_Texture **texture_image_normal_mode, SDL_Rect *rectangle_normal_mode,
                       SDL_Texture **texture_image_hard_mode, SDL_Rect *rectangle_hard_mode,
                       itemMenu *titre, SDL_Surface **texte_difficultee, SDL_Texture **texture_texte_difficultee, 
                       TTF_Font **police, SDL_Color couleurNoire,
                       itemMenu *itemsMenu, int tailleMenu, int largeur, int hauteur) {
    
    /* Efface le rendu */
    if(SDL_RenderClear((*renderer)) != 0)
        erreur("Effacement rendu échoué");

    /* Utilisation de la fusion pour un rendu avec transparence */
    SDL_SetRenderDrawBlendMode((*renderer), SDL_BLENDMODE_BLEND);

    /* Copie la texture de l'image de plein écran */
    rectangle_normal_mode->x = largeur / 6;
    rectangle_normal_mode->y = hauteur / 3;
    rectangle_normal_mode->w = largeur / 4;
    rectangle_normal_mode->h = hauteur / 5;

    if(SDL_RenderCopy((*renderer), (*texture_image_normal_mode), NULL, rectangle_normal_mode) != 0)
        erreur("Copie de la texture");

    /* Copie la texture de l'image de plein écran */
    rectangle_hard_mode->x = largeur - largeur / 6 - largeur / 4;
    rectangle_hard_mode->y = hauteur / 3;
    rectangle_hard_mode->w = largeur / 4;
    rectangle_hard_mode->h = hauteur / 5;

    if(SDL_RenderCopy((*renderer), (*texture_image_hard_mode), NULL, rectangle_hard_mode) != 0)
        erreur("Copie de la texture");

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 0);

    /* Dessine le titre du menu */
    titre->rectangle.x = largeur / 3;
    titre->rectangle.y = hauteur / 10;
    titre->rectangle.w = largeur / 3;
    titre->rectangle.h = hauteur / 10;

    SDL_RenderFillRect((*renderer), &(titre->rectangle));

    (*texte_difficultee) = TTF_RenderText_Solid((*police), titre->texte, couleurNoire);
    (*texture_texte_difficultee) = SDL_CreateTextureFromSurface((*renderer), (*texte_difficultee));

    SDL_RenderCopy((*renderer), (*texture_texte_difficultee), NULL, &(titre->rectangle));

    SDL_FreeSurface((*texte_difficultee));
    SDL_DestroyTexture((*texture_texte_difficultee));

    SDL_SetRenderDrawColor((*renderer), 255, 255, 255, 255);

    /* Dessine les éléments du menu */


        itemsMenu[0].rectangle.x = largeur / 6;
        itemsMenu[0].rectangle.y = hauteur / 3 - hauteur / 12;
        itemsMenu[0].rectangle.w = largeur / 4;
        itemsMenu[0].rectangle.h = hauteur / 13;

        SDL_RenderFillRect((*renderer), &(itemsMenu[0].rectangle));

        (*texte_difficultee) = TTF_RenderText_Solid((*police), itemsMenu[0].texte, couleurNoire);
        (*texture_texte_difficultee) = SDL_CreateTextureFromSurface((*renderer), (*texte_difficultee));

        SDL_RenderCopy((*renderer), (*texture_texte_difficultee), NULL, &(itemsMenu[0].rectangle));

        SDL_FreeSurface((*texte_difficultee));
        SDL_DestroyTexture((*texture_texte_difficultee));

        itemsMenu[1].rectangle.x = largeur - largeur / 6 - largeur / 4;
        itemsMenu[1].rectangle.y = hauteur / 3 - hauteur / 12;
        itemsMenu[1].rectangle.w = largeur / 4;
        itemsMenu[1].rectangle.h = hauteur / 13;

        SDL_RenderFillRect((*renderer), &(itemsMenu[1].rectangle));

        (*texte_difficultee) = TTF_RenderText_Solid((*police), itemsMenu[1].texte, couleurNoire);
        (*texture_texte_difficultee) = SDL_CreateTextureFromSurface((*renderer), (*texte_difficultee));

        SDL_RenderCopy((*renderer), (*texture_texte_difficultee), NULL, &(itemsMenu[1].rectangle));

        SDL_FreeSurface((*texte_difficultee));
        SDL_DestroyTexture((*texture_texte_difficultee));


    /* Affiche le rendu */
    SDL_RenderPresent((*renderer));
}

/* Fonction qui permet de ... quand on clique sur une case du menu */
void clic_case(SDL_Event event, itemMenu *itemsMenu, int numero_case, int tailleMenu, SDL_Rect *rectangle_mode, int mode) {

    if(tailleMenu == 2) {

        if((event.button.x >= itemsMenu[numero_case].rectangle.x) &&
           (event.button.x <= itemsMenu[numero_case].rectangle.x + itemsMenu[numero_case].rectangle.w) &&
           (event.button.y >= itemsMenu[numero_case].rectangle.y) &&
           (event.button.y <= itemsMenu[numero_case].rectangle.y + itemsMenu[numero_case].rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))

        if(!numero_case)
            printf("Vous avez fait clic gauche sur 'Normal' !\n");
        else
            printf("Vous avez fait clic gauche sur 'Hard' !\n");
    }
    if ((event.button.x >= rectangle_mode->x) &&
        (event.button.x <= rectangle_mode->x + rectangle_mode->w) &&
        (event.button.y >= rectangle_mode->y) &&
        (event.button.y <= rectangle_mode->y + rectangle_mode->h) &&
        (event.button.button == SDL_BUTTON_LEFT))

        if(!mode)
            printf("Vous avez fait clic gauche sur 'Normal' !\n");
        else
            printf("Vous avez fait clic gauche sur 'Hard' !\n");
}

/* Fonction qui permet de mettre la fenêtre en plein écran quand on clique sur le bouton plein écran */
int clic_plein_ecran(SDL_Event event, SDL_Rect *rectangle_plein_ecran, SDL_bool *plein_ecran, SDL_Window **window) {

    if ((event.button.x >= rectangle_plein_ecran->x) &&
        (event.button.x <= rectangle_plein_ecran->x + rectangle_plein_ecran->w) &&
        (event.button.y >= rectangle_plein_ecran->y) &&
        (event.button.y <= rectangle_plein_ecran->y + rectangle_plein_ecran->h) &&
        (event.button.button == SDL_BUTTON_LEFT)) {
            
        if ((*plein_ecran)) {   
            SDL_SetWindowFullscreen((*window), 0);
            (*plein_ecran) = SDL_FALSE;
        } else {
            SDL_SetWindowFullscreen((*window), SDL_WINDOW_FULLSCREEN_DESKTOP);
            (*plein_ecran) = SDL_TRUE;
        }
        return 1;
    }
    return 0;
}

/* Fonction qui permet de détruire les objets initialisés */
void detruire_objets(TTF_Font **police) {

    TTF_CloseFont((*police));
}

/* Fonction qui permet de détruire le rendu et la fenêtre */
void detruire_fenetre_rendu(SDL_Renderer **renderer, SDL_Window **window) {

    SDL_DestroyRenderer((*renderer));
    SDL_DestroyWindow((*window));
}

int main(int argc, char **argv) {

    /* Initailisation de la largeur de la fenêtre */
    int largeur = 960;
    /* Initialisation de la hauteur de la fenêtre */
    int hauteur = 540;

    /* Création des pointeurs sur la fenêtre et sur le rendu */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Création des pointeurs sur la surface de l'image du menu et sur sa texture */
    SDL_Surface *image_normal_mode = NULL;
    SDL_Texture *texture_image_normal_mode = NULL;
    SDL_Rect rectangle_normal_mode;

    /* Création des pointeurs sur la surface de l'image du plein écran, sur sa texture et du rectangle où se trouvera l'image */
    SDL_Surface *image_hard_mode = NULL;
    SDL_Texture *texture_image_hard_mode = NULL;
    SDL_Rect rectangle_hard_mode;

    /* Création des pointeurs sur la surface du texte du menu et sur sa texture */
    SDL_Surface *texte_difficultee = NULL;
    SDL_Texture *texture_texte_difficultee = NULL;

    /* Pointeur sur la police */
    TTF_Font *police = NULL;

    /* Variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0};

    /* Lancement de SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        erreur("Initialisation SDL");

    /* Lancement de TTF */
	if(TTF_Init() == -1)
        erreur("Initialisation TTF");

    creer_fenetre_rendu(&window, &renderer, largeur, hauteur);

    /*-------------------------------------------------------------*/
    itemMenu titre;

    int tailleMenu = 2;
    itemMenu itemsMenu[tailleMenu];

    initialisation_objets(&renderer, &image_normal_mode, &texture_image_normal_mode,
                          &image_hard_mode, &texture_image_hard_mode,
                          &police, &titre, itemsMenu, tailleMenu);

    SDL_bool programme_lance = SDL_TRUE;

    SDL_bool plein_ecran = SDL_FALSE;

    while(programme_lance) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {

            switch(event.type) {
                case SDL_WINDOWEVENT:
                    redimensionnement_fenetre(event, &largeur, &hauteur);
                    mise_a_jour_rendu(&renderer, &texture_image_normal_mode,
                                      &rectangle_normal_mode, &texture_image_hard_mode, &rectangle_hard_mode,
                                      &titre, &texte_difficultee, &texture_texte_difficultee, 
                                      &police, couleurNoire,
                                      itemsMenu, tailleMenu, largeur, hauteur);
                    break;

                case SDL_MOUSEBUTTONUP:
                    clic_case(event, itemsMenu, 0, tailleMenu, &rectangle_normal_mode, 0);
                    clic_case(event, itemsMenu, 1, tailleMenu, &rectangle_hard_mode, 1);
                    break;     

                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }

    /*-------------------------------------------------------------*/

    detruire_objets(&police);

    detruire_fenetre_rendu(&renderer, &window);

    /* Quitter TTF et SDL */
	TTF_Quit(); 
    SDL_Quit();

    return EXIT_SUCCESS; /* return 0; */
}