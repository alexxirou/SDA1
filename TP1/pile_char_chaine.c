#include "pile_char.h"

Pile pilenouv()
{
    Pile p;
    p=NULL;
    return p;
}

Pile empiler(Pile p, Car x) 
{   
  Pile nouveau_sommet=(Pile)malloc(sizeof(Spile));
  nouveau_sommet->v=x;
  nouveau_sommet->s=p;
  return nouveau_sommet;
}


Pile depiler(Pile p)
{
  Pile nouveau_sommet = p->s;
  free(p);  
  return nouveau_sommet;
}

Pile remplacer(Pile p, Car x)
{
    p->v=x;
    return p;
}

Car sommet(Pile p)
{   
    
    return p->v;
}

Bool vide(Pile p)
{
    return (p->s==NULL) ? vrai : faux;
}

Nat hauteur(Pile p)
{
  Nat h=0;
  Pile nouveau_sommet=(Pile)malloc(sizeof(Spile));
  nouveau_sommet=p;
  while (nouveau_sommet!=NULL)
  {
    nouveau_sommet=nouveau_sommet->s;
    h++;
  }
  free(nouveau_sommet);
  return h;
}

