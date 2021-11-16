#include "base.h"
#define MAX_P 50


typedef struct spile {
char v;
struct spile *s;
} Spile, *Pile;



Pile pilenouv();

Pile empiler(Pile p, Car x);

Pile depiler(Pile p);

Pile remplacer(Pile p, Car x);

Car sommet(Pile p);

Bool vide(Pile p);

Nat hauteur(Pile p);


bool check_Parenthese(char * mot);

void test_pile(Pile p, char a, char b , char c);


#endif