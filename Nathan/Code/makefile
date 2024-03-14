#
# Macro
#

# Compilation avec SDL
CC = gcc
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags`
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Spécification des répertoires
SRC_DIR = FichierC
INC_DIR = FichierH
OBJ_DIR = obj
BIN_DIR = bin

# Les fichiers source que l'on veut compiler
SRCS_MENU = $(wildcard $(SRC_DIR)/menu.c)
SRCS_MENU_FONC = $(wildcard $(SRC_DIR)/fonctionMenu.c)

SRCS_DIFFICULTE = $(wildcard $(SRC_DIR)/difficulte.c)
SRCS_DIFFICULTE_FONC = $(wildcard $(SRC_DIR)/fonctionDifficulte.c)

SRCS_PARAMETRES = $(wildcard $(SRC_DIR)/parametres.c)
SRCS_PARAMETRES_FONC = $(wildcard $(SRC_DIR)/fonctionParametres.c)

SRCS_INTRO = $(wildcard $(SRC_DIR)/fonctionIntro.c)
SRCS_INTRO_FONC = $(wildcard $(SRC_DIR)/fonctionIntro.c)

SRCS_COMMUN = $(wildcard $(SRC_DIR)/fonctionCommun.c)

# Récupération des fichiers objet correspondants
OBJS_MENU = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_MENU))
OBJS_MENU_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_MENU_FONC))

OBJS_DIFFICULTE = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_DIFFICULTE))
OBJS_DIFFICULTE_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_DIFFICULTE_FONC))

OBJS_PARAMETRES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_PARAMETRES))
OBJS_PARAMETRES_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_PARAMETRES_FONC))

OBJS_INTRO = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_INTRO))
OBJS_INTRO_FONC = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_INTRO_FONC))

OBJS_COMMUN = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS_COMMUN))

# Nom des exécutables
EXECUTABLES = menu difficulte parametres intro


#
# Compilations
#

# Compilation des exécutables
all: $(BIN_DIR)/$(EXECUTABLES)

# Créer le répertoire bin s'il n'existe pas
$(shell mkdir -p $(BIN_DIR))
# Créer le répertoire bin s'il n'existe pas
$(shell mkdir -p $(OBJ_DIR))

$(BIN_DIR)/menu: $(OBJS_MENU) $(OBJS_COMMUN) $(OBJS_MENU_FONC)
	$(CC) $^ $(LDFLAGS) -o $@

$(BIN_DIR)/difficulte: $(OBJS_DIFFICULTE) $(OBJS_COMMUN) $(OBJS_DIFFICULTE_FONC)
	$(CC) $^ $(LDFLAGS) -o $@

$(BIN_DIR)/parametres: $(OBJS_PARAMETRES) $(OBJS_COMMUN) $(OBJS_PARAMETRES_FONC)
	$(CC) $^ $(LDFLAGS) -o $@

$(BIN_DIR)/intro: $(OBJS_INTRO) $(OBJS_COMMUN) $(OBJS_INTRO_FONC)
	$(CC) $^ $(LDFLAGS) -o $@


################################
# Compilation des fichiers .o  #
################################

# Règles pour les fichiers objets de menu.c
$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.c $(INC_DIR)/fonctionMenu.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règles pour les fichiers objets de difficulte.c
$(OBJ_DIR)/difficulte.o: $(SRC_DIR)/difficulte.c $(INC_DIR)/fonctionDifficulte.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règles pour les fichiers objets de parametres.c
$(OBJ_DIR)/parametres.o: $(SRC_DIR)/parametres.c $(INC_DIR)/fonctionParametres.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règles pour les fichiers objets de intro.c
$(OBJ_DIR)/intro.o: $(SRC_DIR)/intro.c $(INC_DIR)/fonctionIntro.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@



# Règle pour le fichier objet fonctionCommun.c
$(OBJ_DIR)/fonctionCommun.o: $(SRC_DIR)/fonctionCommun.c $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionMenu.c
$(OBJ_DIR)/fonctionMenu.o: $(SRC_DIR)/fonctionMenu.c $(INC_DIR)/fonctionMenu.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionDifficulte.c
$(OBJ_DIR)/fonctionDifficulte.o: $(SRC_DIR)/fonctionDifficulte.c $(INC_DIR)/fonctionDifficulte.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionParametres.c
$(OBJ_DIR)/fonctionParametres.o: $(SRC_DIR)/fonctionParametres.c $(INC_DIR)/fonctionParametres.h $(INC_DIR)/fonctionCommun.h
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

# Règle pour le fichier objet fonctionIntro.c
$(OBJ_DIR)/fonctionIntro.o: $(SRC_DIR)/fonctionIntro.c $(INC_DIR)/fonctionIntro.h $(INC_DIR)/fonctionCommun.h
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