#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 50
void pseudo_accepte(char * tab[BUFFER_SIZE]){
    
    for(int i = 0; tab[i];i++){
        int bool_accepte = 0;
        assert(strlen(tab[i]) <= 10);
        for(int j = 0; tab[i][j]; j++){
            if(tab[i][j] != ' ')
                bool_accepte = 1;
        }
        assert(bool_accepte == 1);
        printf("Pseudo \"%s\" a été accepté.\n",tab[i]);

    }
}

void pseudo_pas_accepte(char * tab[BUFFER_SIZE]){
    
    for(int i = 0; tab[i];i++){
        int bool_refuse = 0;

        if(strlen(tab[i]) > 10)
            bool_refuse = 1;

        else {
            for(int j = 0; tab[i][j];j++){
                if(tab[i][j] != ' ')
                    bool_refuse = 0;
                else
                    bool_refuse = 1;
            }
        }

        if(bool_refuse == 1)
            printf("Pseudo \"%s\" n'a pas été accepté.\n",tab[i]);

        else
            exit(1);
    }
}

int main(){
    char * pseudo_invalide[BUFFER_SIZE] = {" ","   ","TestPlusDixCara"};
    char * pseudo_valide[BUFFER_SIZE] = {"Te st","tes t&é","TES T&é","Tes t&é","test","TEST","&é","Test","test&é","TEST&é","TE ST","& é","Test&é"};
    printf("Tests des différents pseudos.\n");
    pseudo_accepte(pseudo_valide);
    pseudo_pas_accepte(pseudo_invalide);
    printf("Fin des tests des différents pseudos.\n");

    return 0;
}