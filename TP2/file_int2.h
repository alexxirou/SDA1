#ifndef FILE_INT2
#define FILE_INT2
#include "base.h"

#define MAX_P 50

typedef struct strfile {
Nat v;
struct strfile *s;
} Strfile;


typedef struct sfile {
Strfile *h;
Strfile *q; } File;
#endif

File filenouv();
File adjq(File f, Nat S);
File supt(File f);
Nat tete(File f); 
Nat vide(File f);
Nat longuer(File f);


