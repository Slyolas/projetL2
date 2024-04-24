#
# Macro
#



# Compilation avec SDL
CC = gcc
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags`
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Spécification des répertoires
SRC_DIR = fichiers_c
INC_DIR = fichiers_h
OBJ_DIR = obj
BIN_DIR = bin

# Fichiers sources que l'on veut compiler
SRCS_JEU = $(wildcard $(SRC_DIR)/metatravers.c)

SRCS_MENU_FONC = $(wildcard $(SRC_DIR)/fonctions_menu_principal.c)

SRCS_OPTIONS_FONC = $(wildcard $(SRC_DIR)/fonctions_options.c)

SRCS_DIFFICULTE_FONC = $(wildcard $(SRC_DIR)/fonctions_nouvelle_partie.c)

SRCS_COMMUN_FONC = $(wildcard $(SRC_DIR)/fonctions_generales.c)

SRCS_INTRODUCTION_FONC = $(wildcard $(SRC_DIR)/fonctions_introduction.c)

SRCS_CARTE_FONC = $(wildcard $(SRC_DIR)/fonctions_carte.c)

SRCS_NIVEAU_1_FONC = $(wildcard $(SRC_DIR)/fonctions_niveau_1.c)

SRCS_NIVEAU_2_FONC = $(wildcard $(SRC_DIR)/fonctions_niveau_2.c)

SRCS_NIVEAU_3_FONC = $(wildcard $(SRC_DIR)/fonctions_niveau_3.c)

SRCS_ARRIVEE_NIVEAUX_2_3_FONC = $(wildcard $(SRC_DIR)/fonctions_arrivee_niveaux_2_3.c)

SRCS_NIVEAU_4_FONC = $(wildcard $(SRC_DIR)/fonctions_niveau_4.c)

# Récupération des fichiers objets correspondants
OBJS_JEU = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_JEU))

OBJS_COMMUN_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_COMMUN_FONC))

OBJS_MENU_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_MENU_FONC))

OBJS_OPTIONS_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_OPTIONS_FONC))

OBJS_DIFFICULTE_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_DIFFICULTE_FONC))

OBJS_INTRODUCTION_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_INTRODUCTION_FONC))

OBJS_CARTE_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_CARTE_FONC))

OBJS_NIVEAU_1_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_NIVEAU_1_FONC))

OBJS_NIVEAU_2_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_NIVEAU_2_FONC))

OBJS_NIVEAU_3_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_NIVEAU_3_FONC))

OBJS_ARRIVEE_NIVEAUX_2_3_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_ARRIVEE_NIVEAUX_2_3_FONC))

OBJS_NIVEAU_4_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_NIVEAU_4_FONC))

# Nom de l'exécutable
EXECUTABLE = metatravers

#
# Compilations
#

# Compilation de l'exécutable
all: $(BIN_DIR)/$(EXECUTABLE); ./bin/metatravers

# Créer le répertoire bin s'il n'existe pas
$(shell mkdir -p $(BIN_DIR))
# Créer le répertoire obj s'il n'existe pas
$(shell mkdir -p $(OBJ_DIR))

$(BIN_DIR)/metatravers: $(OBJS_JEU) $(OBJS_COMMUN_FONC) $(OBJS_MENU_FONC) $(OBJS_OPTIONS_FONC) $(OBJS_DIFFICULTE_FONC) $(OBJS_INTRODUCTION_FONC) $(OBJS_CARTE_FONC) $(OBJS_NIVEAU_1_FONC) $(OBJS_NIVEAU_2_FONC) $(OBJS_NIVEAU_3_FONC) $(OBJS_ARRIVEE_NIVEAUX_2_3_FONC) $(OBJS_NIVEAU_4_FONC)
	$(CC) $^ $(LDFLAGS) -o $@


################################
# Compilation des fichiers .o  #
################################

# Règles pour les fichiers objets de metatravers.c
$(OBJ_DIR)/metatravers.o: $(SRC_DIR)/metatravers.c $(INC_DIR)/fonctions_generales.h $(INC_DIR)/fonctions_menu_principal.h $(INC_DIR)/fonctions_options.h $(INC_DIR)/fonctions_nouvelle_partie.h $(INC_DIR)/fonctions_introduction.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_generales.c
$(OBJ_DIR)/fonctions_generales.o: $(SRC_DIR)/fonctions_generales.c $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_menu_principal.c
$(OBJ_DIR)/fonctions_menu_principal.o: $(SRC_DIR)/fonctions_menu_principal.c $(INC_DIR)/fonctions_menu_principal.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_options.c
$(OBJ_DIR)/fonctions_options.o: $(SRC_DIR)/fonctions_options.c $(INC_DIR)/fonctions_options.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_nouvelle_partie.c
$(OBJ_DIR)/fonctions_nouvelle_partie.o: $(SRC_DIR)/fonctions_nouvelle_partie.c $(INC_DIR)/fonctions_nouvelle_partie.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_introduction.c
$(OBJ_DIR)/fonctions_introduction.o: $(SRC_DIR)/fonctions_introduction.c $(INC_DIR)/fonctions_introduction.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_carte.c
$(OBJ_DIR)/fonctions_carte.o: $(SRC_DIR)/fonctions_carte.c $(INC_DIR)/fonctions_carte.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_niveau_1.c
$(OBJ_DIR)/fonctions_niveau_1.o: $(SRC_DIR)/fonctions_niveau_1.c $(INC_DIR)/fonctions_niveau_1.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_niveau_2.c
$(OBJ_DIR)/fonctions_niveau_2.o: $(SRC_DIR)/fonctions_niveau_2.c $(INC_DIR)/fonctions_niveau_2.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_niveau_3.c
$(OBJ_DIR)/fonctions_niveau_3.o: $(SRC_DIR)/fonctions_niveau_3.c $(INC_DIR)/fonctions_niveau_3.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_arrivee_niveaux_2_3.c
$(OBJ_DIR)/fonctions_arrivee_niveaux_2_3.o: $(SRC_DIR)/fonctions_arrivee_niveaux_2_3.c $(INC_DIR)/fonctions_arrivee_niveaux_2_3.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctions_niveau_4.c
$(OBJ_DIR)/fonctions_niveau_4.o: $(SRC_DIR)/fonctions_niveau_4.c $(INC_DIR)/fonctions_niveau_4.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@





#
#Test unitaire
#

test:
	gcc test\ unitaire/test_pseudo.c -Wall -o test\ unitaire/test_pseudo;
	./test\ unitaire/test_pseudo


#
# Clean
#


# Nettoyage des fichiers temporaires
clean: clean_exe clean_obj

# Supprimer les fichiers objets
clean_obj:
	rm -rf $(OBJ_DIR)/*.o

# Supprimer l'exécutable
clean_exe:
	rm -rf $(BIN_DIR)/$(EXECUTABLES)

clean_test:
	rm test\ unitaire/test_pseudo

#Nom du projet
PROJECT_NAME = Metatravers
#Commande à exécuter
DOXYGEN = doxygen
DOC_DIR = docu
doc:
	@echo "Génération de la documentation Doxygen"
	@$(DOXYGEN) Doxyfile
	 
	@echo "Documentation générée dans $(DOC_DIR)/"

clean_doxy:
	@echo "Suppression de la documentation Doxygen"
	@rm -rf $(DOC_DIR)/latex
	@rm -rf $(DOC_DIR)/html
