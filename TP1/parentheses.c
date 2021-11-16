#if CHAINE 
#include "pile_char2.h"
#else
#include "pile_char.h"
#endif
#include <string.h>
#include <stdio.h>
  
bool check_Parenthese(char *mot)  
{
  Pile open = pilenouv();
  Pile close = pilenouv();
  for (int i=0; i<strlen(mot); i++)
  {
    if (mot[i]=='{' || mot[i]=='['|| mot[i]=='(')
    {
      open=empiler(open, mot[i]);
    }

  }
  for (int i=strlen(mot)-1; i>=0; i--)
  {
      if (mot[i]=='}' || mot[i]==']'|| mot[i]==')')
    {
      close=empiler(close, mot[i]);
    }
  }
  while(hauteur(open)>0 && hauteur(close)>0)
  {
     if ((sommet(open)=='{' && sommet(close)=='}' )|| (sommet(open)=='[' && sommet(close)==']')|| (sommet(open)=='(' && sommet(close)==')'))
     {
      open=depiler(open);
      close=depiler(close);
     }
     else return faux;
  }
  return vide(open)&&vide(close);
}
