#if CHAINE 
#include "pile_char2.h"
#else
#include "pile_char.h"
#endif

void test_pile(Pile p, char a, char b , char c)
{
    p=empiler(p,a);
    printf("Resultant empilation avec %c %c\n", a, sommet(p));
    p=empiler(p,b);
    printf("Resultant empilation avec %c %c\n", b, sommet(p));
    p=depiler(p);
    printf("Resultant depilation %c\n", sommet(p));
    p=remplacer(p,c);
    printf("Resultant remplacement avec %c %c\n", c, sommet(p));
    printf("Hauteur pile %d\n", hauteur(p));
    printf("Vide? %d\n", vide(p));
    return;

}