#define EASY 1
#define NORMAL 2
#define HARD 3
#define MEN 1
#define WOMEN 2

//structure settings ? avec difficulte/perso/nom
typedef struct settings{
    int difficulte; //Valeur 1(facile), 2(normal), 3(difficile)
    int perso; //Valeur 1(gars) ou 2(fille)
    char * nom;
}settings_t;

void new_game();
int difficulte();
int perso();
int parametre();
int main();
void sauvegarde(settings_t * partie);
void nom_perso(char * nom);