#include "pile_char2.h"

Pile pilenouv()
{
    Pile nouveau_sommet=NULL;
    return nouveau_sommet;

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
    Pile nouveau_sommet;
    nouveau_sommet=p->s;
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
    return (p=NULL) ? vrai :faux;
}    

Nat hauteur(Pile p)
{
    Pile nouveau_sommet=(Pile)malloc(sizeof(Spile));
    nouveau_sommet=p;
    int hauteur = 0;
    while (nouveau_sommet->s!=NULL)
    {
        hauteur++;
        nouveau_sommet=nouveau_sommet->s;
    }
    return hauteur;
}

