#ifndef LISTE_H
#define LISTE_H
#include "base.h"

typedef int S;
typedef struct strliste {
S v ;
struct strliste *s;
}Strliste, *Liste;

Liste liste_nouv();
Liste ajout_tete (Liste l, int v);
bool est_vide (Liste l );
S tete (Liste l);
int longueur (Liste l);
Liste suppression_tete(Liste l);
Bool appartenance_liste(Liste l, int v);
void test_liste(Liste test_liste, Nat x , Nat y, Nat z);
Strliste* premier_occurrence(Liste l , int v);
Liste suppr_premiere_occurrence(Liste l, int v);
Liste change_premier_occurrence(Liste l, int t, int v);
Liste inser_dernier(Liste l,int v);
Liste suppr_dernier(Liste l);
int acces_dernier(Liste l);
int access_nth(Liste l, Nat i);
Liste insertion_nth(Liste l, int v, Nat i);
Liste suppression_nth(Liste l, Nat i);

#endif
