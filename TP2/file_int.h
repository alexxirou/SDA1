#ifndef FILE_INT
#define FILE_INT
#include "base.h"


#define MAX_P 50
typedef struct {
Nat tab[MAX_P];
Nat h; /* tête de la File */
Nat l; /* longueur de la File */ } File;


#endif

File filenouv();
File adjq(File f, Nat S);
File supt(File f);
Nat tete(File f); 
Nat vide(File f);
Nat longuer(File f);

void test_files(Nat x , Nat y);
