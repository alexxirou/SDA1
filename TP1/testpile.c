#include "pile_char.h"
#include <stdio.h>

int main()
{   
    Pile test_pile=pilenouv();
    printf("Résultat création pile  pile de  taille %d\n", test_pile.h);
    test_pile=empiler(test_pile, 'a');
    test_pile=empiler(test_pile, 'b');
    printf("Résultat empilation: %c\n", test_pile.tab[test_pile.h-1]);
    
    test_pile=depiler(test_pile);
    printf("Résultat depilation %c\n", test_pile.tab[test_pile.h-1]);
    test_pile=remplacer(test_pile, 'c');
    printf("Résultat remplacement %c\n", test_pile.tab[test_pile.h-1]);
    printf("Résultat sommet %c\n", sommet(test_pile));
    printf("Resultat vacuité %s\n",vide(test_pile));
    printf("Hauteur de pile %d\n", hauteur(test_pile));
    return 0;
}