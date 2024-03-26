#
# Macro
#

# Compilation avec SDL
CC = gcc
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags`
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Spécification des répertoires
SRC_DIR = fichiers_c
INC_DIR = fichiers_h
OBJ_DIR = obj
BIN_DIR = bin

# Les fichiers source que l'on veut compiler
SRCS_JEU = $(wildcard $(SRC_DIR)/metatravers.c)

SRCS_MENU_FONC = $(wildcard $(SRC_DIR)/fonctions_menu_principal.c)

SRCS_OPTIONS_FONC = $(wildcard $(SRC_DIR)/fonctions_options.c)

SRCS_DIFFICULTE_FONC = $(wildcard $(SRC_DIR)/fonctions_nouvelle_partie.c)

SRCS_COMMUN_FONC = $(wildcard $(SRC_DIR)/fonctions_generales.c)

SRCS_INTRODUCTION_FONC = $(wildcard $(SRC_DIR)/fonctions_introduction.c)

SRCS_CARTE_FONC = $(wildcard $(SRC_DIR)/fonctions_carte.c)

# Récupération des fichiers objet correspondants
OBJS_JEU = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_JEU))

OBJS_COMMUN_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_COMMUN_FONC))

OBJS_MENU_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_MENU_FONC))

OBJS_OPTIONS_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_OPTIONS_FONC))

OBJS_DIFFICULTE_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_DIFFICULTE_FONC))

OBJS_INTRODUCTION_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_INTRODUCTION_FONC))

OBJS_CARTE_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_CARTE_FONC))

# Nom des exécutables
EXECUTABLES = metatravers


#
# Compilations
#

# Compilation des exécutables
all: $(BIN_DIR)/$(EXECUTABLES)

# Créer le répertoire bin s'il n'existe pas
$(shell mkdir -p $(BIN_DIR))
# Créer le répertoire bin s'il n'existe pas
$(shell mkdir -p $(OBJ_DIR))

$(BIN_DIR)/metatravers: $(OBJS_JEU) $(OBJS_COMMUN_FONC) $(OBJS_MENU_FONC) $(OBJS_OPTIONS_FONC) $(OBJS_DIFFICULTE_FONC) $(OBJS_INTRODUCTION_FONC) $(OBJS_CARTE_FONC)
	$(CC) $^ $(LDFLAGS) -o $@


################################
# Compilation des fichiers .o  #
################################

# Règles pour les fichiers objets de menu.c
$(OBJ_DIR)/metatravers.o: $(SRC_DIR)/metatravers.c $(INC_DIR)/fonctions_generales.h $(INC_DIR)/fonctions_menu_principal.h $(INC_DIR)/fonctions_options.h $(INC_DIR)/fonctions_nouvelle_partie.h $(INC_DIR)/fonctions_introduction.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionCommun.c
$(OBJ_DIR)/fonctions_generales.o: $(SRC_DIR)/fonctions_generales.c $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctions_menu_principal.o: $(SRC_DIR)/fonctions_menu_principal.c $(INC_DIR)/fonctions_menu_principal.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctions_options.o: $(SRC_DIR)/fonctions_options.c $(INC_DIR)/fonctions_options.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctions_nouvelle_partie.o: $(SRC_DIR)/fonctions_nouvelle_partie.c $(INC_DIR)/fonctions_nouvelle_partie.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctions_introduction.o: $(SRC_DIR)/fonctions_introduction.c $(INC_DIR)/fonctions_introduction.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctions_carte.o: $(SRC_DIR)/fonctions_carte.c $(INC_DIR)/fonctions_carte.h $(INC_DIR)/fonctions_generales.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@


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