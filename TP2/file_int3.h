#ifndef FILE_INT3
#define FILE_INT3
#include "base.h"


typedef struct strfile {
Nat v;
struct strfile *s;
} Strfile, *File;



#endif

File filenouv();
File adjq(File f, Nat S);
File supt(File f);
Nat tete(File f); 
Nat vide(File f);
Nat longuer(File f);
Nat lgb1(File f1, File f2);
Nat flavius(File f , Nat skip);
void test_files(Nat x , Nat y);
Nat flavius(File f , Nat skip);