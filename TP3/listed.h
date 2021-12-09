#ifndef LISTED_H
#define LISTED_H
#include "base.h"

typedef int S;
typedef struct strliste {
S v ;
struct strliste *s;
struct strliste *p;
}Strliste, *Liste;

Liste liste_vide();
Liste ajout_tete (Liste l, int v);
bool est_vide (Liste l );
S tete (Liste l);
int longueur (Liste l);
Liste suppression_tete(Liste l);

#endif