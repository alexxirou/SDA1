#include "TD1.h"

//« claire » ,« jean », « amélie », « pierre », « amien », « paul », « michel », « valentine », « arnaud »



int main(){   
    listeg test =vide();
    listeg test_rech_a=vide();
    test=adjqueue(test,"claire",clone);
    test=adjqueue(test,"jean",clone);
    test=adjqueue(test,"amélie",clone);
    test=adjqueue(test,"pierre",clone);
    test=adjqueue(test,"amien",clone);
    test=adjqueue(test,"paul",clone);
    test=adjqueue(test,"michel",clone);
    test=adjqueue(test,"valentine",clone);
    test=adjqueue(test,"arnaud",clone);
    test_rech_a=rech(test, (void*) "a", compare, clone);
    //printf("%s\n", affiche(test->val));
    affichage(test_rech_a, (void*) affiche);

}