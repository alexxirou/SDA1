#ifndef __PILE_CHAR_H
#define __PILE_CHAR_H
#include "base.h"

#define MAX_P 50

typedef struct {
    char tab[MAX_P];
    Nat h; } Pile;

Pile pilenouv();

Pile empiler(Pile p, Car x);

Pile depiler(Pile p);

Pile remplacer(Pile p, Car x);

Car sommet(Pile p);

Bool vide(Pile p);

Nat hauteur(Pile p);

#endif