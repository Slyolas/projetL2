include Makefile.compilation

#
# Objets
#

fich_obj_test_individu=test_individu.o individu.o commun.o
fich_obj_test_fraction=test_fraction.o fraction.o commun.o
fich_obj_test_mystring=test_mystring.o mystring.o commun.o
fich_obj_test_personne=test_personne.o personne.o individu.o mystring.o commun.o
fich_obj_test_liste=test_liste.o liste.o individu.o fraction.o mystring.o commun.o
fich_obj_test_liste_objet=test_liste_objet.o liste_objet.o individu.o fraction.o mystring.o personne.o commun.o

#
# Tests (executables+objets)
#

SRC= test_individu.c test_personne.c test_fraction.c test_mystring.c test_liste.c test_liste_objet.c
BIN=$(SRC:.c=)
OBJ=$(SRC:.c=.o)

test_individu : $(fich_obj_test_individu) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_individu) -o test_individu 

test_individu.o : test_individu.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_individu.c -o test_individu.o -I./

test_personne : $(fich_obj_test_personne) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_personne) -o test_personne 

test_personne.o : test_personne.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_personne.c -o test_personne.o -I./ 

test_fraction : $(fich_obj_test_fraction) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_fraction) -o test_fraction 

test_fraction.o : test_fraction.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_fraction.c -o test_fraction.o -I./ 

test_mystring : $(fich_obj_test_mystring) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_mystring) -o test_mystring 

test_mystring.o : test_mystring.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_mystring.c -o test_mystring.o -I./ 

test_liste : $(fich_obj_test_liste) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_liste) -o test_liste 

test_liste.o : test_liste.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_liste.c -o test_liste.o -I./ 

test_liste_objet : $(fich_obj_test_liste_objet) 
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_obj_test_liste_objet) -o test_liste_objet

test_liste_objet.o : test_liste_objet.c 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) test_liste_objet.c -o test_liste_objet.o -I./ -Wno-unused-variable

#
# Modules
#

MOD= commun.o individu.o personne.o fraction.o mystring.o liste.o liste_objet.o 

commun.o : commun.c commun.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) commun.c -o commun.o -I./

individu.o : individu.c individu.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) individu.c -o individu.o -I./ -Wno-unused-function

personne.o : personne.c personne.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) personne.c -o personne.o -I./ 

fraction.o : fraction.c fraction.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) fraction.c -o fraction.o -I./ -Wno-unused-function

mystring.o : mystring.c mystring.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) mystring.c -o mystring.o -I./ -Wno-unused-function

liste.o : liste.c liste.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) liste.c -o liste.o -I./

liste_objet.o : liste_objet.c liste_objet.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) liste_objet.c -o liste_objet.o -I./ 


#
# Headers 
#

personne.h : individu.h mystring.h
	touch personne.h

individu.h : objet.h
	touch individu.h 

fraction.h : objet.h
	touch fraction.o

mystring.h : objet.h
	touch mystring.h

liste.h : liste_sdd.h
	touch liste.h

#
#
#

all : $(BIN) $(OBJ)

clean :
	- rm *~
	- rm $(MOD)
	- rm $(OBJ)
	- rm $(BIN)

tests : 
	./test_individu
	./test_fraction
	./test_mystring
	./test_personne
	./test_liste
	./test_liste_objet
