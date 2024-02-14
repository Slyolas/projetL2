#define EASY 1
#define NORMAL 2
#define HARD 3
#define MEN 1
#define WOMEN 2
#define LENGTH_NAME 10

//structure settings ? avec difficulte/perso/nom/chrono
typedef struct settings{
    int difficulte; //Valeur 1(normal), 2(difficile)
    int perso; //Valeur 1(gars) ou 2(fille)
    char * nom;
    struct timeval start_time;
    double chronometre;
}settings_t;

// Fonction pour désactiver l'écho des caractères saisis
void disable_echo() {
    struct termios oldt, newt;
    // Obtient les paramètres actuels du terminal
    tcgetattr(STDIN_FILENO, &oldt);
    // Copie les paramètres actuels dans une nouvelle structure
    newt = oldt;
    // Désactive les modes canoniques (ligne par ligne) et l'écho
    newt.c_lflag &= ~(ICANON | ECHO);
    // Applique les nouveaux paramètres au terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Fonction pour réactiver l'écho des caractères saisis
void enable_echo() {
    struct termios oldt;
    // Obtient les paramètres actuels du terminal
    tcgetattr(STDIN_FILENO, &oldt);
    // Réactive les modes canoniques (ligne par ligne) et l'écho
    oldt.c_lflag |= (ICANON | ECHO);
    // Applique les anciens paramètres au terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void new_game(settings_t * partie);
int difficulte();
int perso();
int parametre();
int main();
void sauvegarde(settings_t * partie);
int charger_sauvegarde(settings_t * partie);
void nom_perso(char ** nom);
void quitterJeu(settings_t *partie);
