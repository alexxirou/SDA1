#ifndef LISTED_H
#define LISTED_H
#include "base.h"

#define foreach(V,L) Iter _I = init(L); for( V = value(_I) ; ! end(_I); next(_I), V = value(_I))

typedef struct sldc {
int v; // valeur
struct sldc *s; // suivant
struct sldc *p; // précédent
} Strliste, *Liste;

typedef struct {
Liste first; // premier élément de la liste
Liste cour; // élément courant
int fin; // vaut vrai si cur est sur le dernier élément
} *Iter;


Liste liste_nouv();
Liste ajout_tete (Liste l, int v);
bool est_vide (Liste l );
int tete (Liste l);
int longueur (Liste l);
Liste suppression_tete(Liste l);
Bool appartenance_liste(Liste l, int x);
int access_nth(Liste l, Nat x);
Liste ajout_nth(Liste l,int v, Nat x);
Liste suppr_nth(Liste l, Nat x);
void test_liste(Liste test_liste, Nat x, Nat y, Nat z);


Iter init(Liste l);
Bool end(Iter i);
Iter next(Iter i); // mise à jour du Bool fin en cas de fin
Iter prev(Iter i);
int value(Iter i);
int cherche_val(Iter i, int v);

#endif