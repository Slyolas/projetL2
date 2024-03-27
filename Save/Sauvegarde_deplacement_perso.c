#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "../fichiers_h/Deplacement_personnage.h"

void Mouvement(int Carte[][26], SDL_Rect *pos, int Direction, SDL_Renderer *render);


void HandleEvent(SDL_Event event,SDL_Renderer *render, SDL_Rect* positionJoueur,SDL_Texture* TPerso[],SDL_Texture* PersoActuelle, SDL_bool *run, int Carte[11][26]){
    switch(event.type)
            {  
                case SDL_QUIT:
                    *run = SDL_FALSE;
                    break;
 
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            *run = SDL_FALSE;
                                break;
                        case SDLK_DOWN:
                            Mouvement(Carte, positionJoueur, BAS, render);
                            PersoActuelle = TPerso[BAS];
                            break;
                        case SDLK_UP:
                            Mouvement(Carte, positionJoueur, HAUT, render);
                            PersoActuelle = TPerso[HAUT];
                            
                            break;
                        case SDLK_RIGHT:
                            Mouvement(Carte, positionJoueur, DROITE, render);
                            PersoActuelle = TPerso[DROITE];
                            
                            break;
                        case SDLK_LEFT:
                            Mouvement(Carte, positionJoueur, GAUCHE, render);
                            PersoActuelle = TPerso[GAUCHE];
                            
                            break;
 
                        default:
                            break;
                    }
 
                default:
                    break;
 
            }
}








 
int gestionPersonnage(SDL_Renderer *render)
{  
 
    SDL_Rect position, positionJoueur;
    SDL_Surface *SPerso[5] = {NULL};
    SDL_Texture *TPerso[5] = {NULL};
    SDL_Texture *PersoActuelle = NULL;
    
    // Compteur_Variable
    int i;
    int j;
 
    // Definit les images sur les Surfaces Perso[Orientation]

    SPerso[HAUT]=IMG_Load("images/personnage_masculin_haut_1.png");
    SPerso[DROITE]=IMG_Load("images/personnage_masculin_bas_gauche_1.png");
    SPerso[GAUCHE]=IMG_Load("images/personnage_masculin_bas_gauche_2.png");
    SPerso[BAS]=IMG_Load("images/personnage_masculin.png");
 
    // Définition de la Carte
    int Carte[11][26];
 
    for(j = 1; j < 5; j++)
    {  
        if(SPerso[j] == NULL)
        {
            printf("%d : Erreur SDL chargement de l'image Personnage \n",j );
            exit(EXIT_FAILURE);
        }
    }
 
    for(i = 1; i < 5; i++)
    {
        TPerso[i] = SDL_CreateTextureFromSurface(render, SPerso[i]);
        SDL_FreeSurface(SPerso[i]);
        SDL_Log("Free de la sufrace du perso %d", i);
    }
     
 
 
 
    // On Définit la position du Joueur
    PersoActuelle = TPerso[BAS];
    if(PersoActuelle == NULL)
        SDL_Log("Erreur lors du chargement du personnage actuelle");
    positionJoueur.x = 10;
    positionJoueur.y = 10;
    position.w = TAILLE_SPRITE*2;
    position.h = TAILLE_SPRITE*2;   
 
/*-------------------------------------*/
/*------------ Boucle infini ----------*/
/*-------------------------------------*/
    SDL_bool run = SDL_TRUE;
    while(run)
    {  
        // On remet le render vierge
        SDL_RenderClear(render);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            HandleEvent(event,render,&positionJoueur,TPerso,PersoActuelle,&run,Carte);
        }
 
        position.x = positionJoueur.x * TAILLE_SPRITE;
        position.y = positionJoueur.y * TAILLE_SPRITE;
 
        if(SDL_RenderCopy(render, PersoActuelle, NULL, &position) != 0)
            SDL_Log("Erreur lors de l'affichage à l'écran");
 
        SDL_RenderPresent(render);
 
    }
    SDL_DestroyRenderer(render);
    SDL_Quit();
    exit(EXIT_FAILURE);
}
    
void Mouvement(int Carte[][26], SDL_Rect *pos, int Direction, SDL_Renderer *render)
{
    SDL_Log("Entrée fonction Mouvement");
    switch(Direction)
    {  
        case BAS:
            pos->y++;
             
            break;
 
        case HAUT:
            pos->y--;
             
            break;
 
        case DROITE:
            pos->x++;
             
            break;
 
        case GAUCHE:
            pos->x--;
             
            break;
 
        default:
            break;
    }
 
 
}



int main(){
    SDL_Window* fenetre;
    SDL_Renderer* renderer;//Déclaration du renderer

if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
{
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    return EXIT_FAILURE;
}

// Création de la fenêtre :
fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 1920 , 1080 , SDL_WINDOW_RESIZABLE);
if(fenetre == NULL) // Gestion des erreurs
{
    printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
    return EXIT_FAILURE;
}

renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer

if(renderer == NULL)//gestion des erreurs
{
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
}
while(1)
    gestionPersonnage(renderer);


// Destruction du renderer et de la fenêtre :
SDL_DestroyRenderer(renderer); 
SDL_DestroyWindow(fenetre);
SDL_Quit(); // On quitte la SDL



}