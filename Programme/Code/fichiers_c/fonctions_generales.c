/* Définir le nombre d'FPS (100 / nombre_FPS) */
#define FPS_LIMIT 16

/* Constantes pour l'onglet actif des options */
#define ONGLET_SON 0
#define ONGLET_TOUCHES 1

/* Constantes pour le mode séléctionné */
#define MODE_NORMAL 0
#define MODE_HARD 1

/* Constantes pour le personnage séléctionné */
#define PERSONNAGE_1 0
#define PERSONNAGE_2 1

/* Constantes pour la page */
#define MENU_PRINCIPAL 0
#define OPTIONS 1
#define NOUVELLE_PARTIE 2

/* Structure pour représenter une case avec un rectangle et du texte */
typedef struct {
    SDL_Rect rectangle;
    char texte[40];
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

void initialisation_objets(SDL_Renderer **renderer,
                          SDL_Surface **image_plein_ecran, SDL_Texture **texture_image_plein_ecran,
                          SDL_Surface **image_retour_en_arriere, SDL_Texture **texture_image_retour_en_arriere,
                          SDL_Surface **image_options, SDL_Texture **texture_image_options,
                          TTF_Font **police) {

    /* Initialisation de l'image du plein écran du menu */
    (*image_plein_ecran) = IMG_Load("./images/plein_ecran.png");
    if((*image_plein_ecran) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_plein_ecran) = SDL_CreateTextureFromSurface((*renderer), (*image_plein_ecran));
    if((*texture_image_plein_ecran) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_plein_ecran));

    /* Initialisation de l'image du retour en arrière */
    (*image_retour_en_arriere) = IMG_Load("./images/retour_en_arriere.png");
    if((*image_retour_en_arriere) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_retour_en_arriere) = SDL_CreateTextureFromSurface((*renderer), (*image_retour_en_arriere));
    if((*texture_image_retour_en_arriere) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_retour_en_arriere));

    /* Initialisation de l'image des options du menu */
    (*image_options) = IMG_Load("./images/options.png");
    if((*image_options) == NULL)
        erreur("Chargement de l'image");
    
    (*texture_image_options) = SDL_CreateTextureFromSurface((*renderer), (*image_options));
    if((*texture_image_options) == NULL)
        erreur("Création de la texture");
    SDL_FreeSurface((*image_options));

    /* Initialisation de la police */
    if(((*police) = TTF_OpenFont("./polices/04B_11__.TTF", 20)) == NULL)
        erreur("Chargement de la police");
}

/* Fonction qui permet de récupérer les nouvelles dimensions de la fenêtre pour redimensionner cette dernière et les différents objets */
void redimensionnement_fenetre(SDL_Event event, int *largeur, int *hauteur) {

    if(event.window.event == SDL_WINDOWEVENT_RESIZED) {

        (*largeur) = event.window.data1;
        (*hauteur) = event.window.data2;
    }
}

/* Vérifie si une sauvegarde existe */
int verification_sauvegarde() {
    
    FILE *fichier_sauvegarde;

    /* Ouverture du fichier en mode lecture */
    fichier_sauvegarde = fopen("./sauvegardes/sauvegarde.txt", "r");

    /* Vérifie si le fichier existe */
    if (fichier_sauvegarde == NULL)
        return 0;

    /* Fermeture du fichier */
    if (fclose(fichier_sauvegarde) != 0)
        erreur("Fermeture du fichier");

    return 1;
}

/* Fonction qui permet de renvoyer vrai quand on clique sur un rectangle, faux sinon */
int clic_case(SDL_Event event, SDL_Rect rectangle) {

        if((event.button.x >= rectangle.x) &&
           (event.button.x <= rectangle.x + rectangle.w) &&
           (event.button.y >= rectangle.y) &&
           (event.button.y <= rectangle.y + rectangle.h) &&
           (event.button.button == SDL_BUTTON_LEFT))
            return 1;
        
        return 0;
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

/* Fonction qui permet de gérer le nombre d'FPS à différents moments du jeu */
void SDL_LimitFPS(unsigned int limit) {

    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
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