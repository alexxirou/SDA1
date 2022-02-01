#include "TD1.h"

//« claire » ,« jean », « amélie », « pierre », « amien », « paul », « michel », « valentine », « arnaud »



int main(){   
    listeg test =vide();
    listeg test_rech_a=vide();
    char* m[9] = {"claire"  ,"jean", "amélie", "pierre", "amien", "paul", "michel", "valentine" ,  "arnaud "};
    for(int i=0; i<9; i++){
        test=adjQueue(test,m[i],cloneString);
    }
    test_rech_a=rech(test, (void*) "a", compareString, cloneString);
    //printf("%s\n", affiche(test->val));
    affichage(test_rech_a, (void*) afficheString);

}