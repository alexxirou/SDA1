#include "pile_char.h"
#include <string.h>
#include <stdio.h>


  
bool check_Parenthese(char *mot)  
{
  Pile test = pilenouv();

  for (int i=0; i<strlen(mot); i++)
  { 
    if (mot[i]=='{' || mot[i]=='('|| mot[i]=='[' || mot[i]=='}'|| mot[i]==']'|| mot[i]==')') empiler(test, mot[i]);
  }
  while (hauteur(test)>1)
  {   
      printf("%c\n",test->tab[test->h-1]);
      if ((test->tab[test->h-1]==')' && test->tab[test->h-2]=='(') || (test->tab[test->h-1]==']'&& test->tab[test->h-2]=='[') || (test->tab[test->h-1]=='}' && test->tab[test->h-2]=='{'))
      {
        depiler(test);  
        //printf("%c\n",test->tab[test->h-1]);
        depiler(test);  
        //printf("%d\n",test->h);
      }
      //retour le dernière parenthése fausse
      else { 
        printf("Problem avec %c numéro %d\n", test->tab[test->h-1], test->h); 
        return faux;
      }  
  }
  return vide(test);
}
