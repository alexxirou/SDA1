#if CONT
#include "liste.h"
#else 
#include "listec.h"

#endif

int main(int argc, char* argv[])
{
    Liste nouveau_liste=liste_nouv();
    test_liste(nouveau_liste, 5, 10, 4);
   
    return 0;    
}