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


