typedef struct timer{
    int startTicks; /*Le temps au moment ou le timer a commencé*/
    int pausedTicks;    /*Le temps enregistré au moment ou le Timer a été mis en pause*/
    bool_t paused;  /*Status du timer*/
    bool_t started;
    void (*lancer)(void);
    void (*stop)(void);
    void (*pause)(void);
    void (*relancer)(void);
    /*Récupère le nombre de millisecondes depuis le lancer du timer*/
    /*Récupère le nombre de millisecondes depuis que le timer a été mis en pause */
    int (*get_ticks)(void);
    /*Fonctions de vérification du status du timer*/
    bool_t (*is_started)(void);
    bool_t (*is_paused)(void);
}Timer_t