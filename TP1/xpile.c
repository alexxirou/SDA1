#if CHAINE 
#include "pile_char2.h"
#else
#include "pile_char.h"
#endif
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{   

  Pile test=pilenouv();
  test_pile(test, 'a', 'b' ,'c');

    if (argc==2)
    {
      printf("Bien parenthésée ? %d\n", check_Parenthese(argv[1]));
    }
    else printf("Pas des mot à vérifier \n");
 
  return 0;
}