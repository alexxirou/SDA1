#include "pile_char.h"

Pile pilenouv()
{
    Pile p;
    p.h=0;
    return p;
}

Pile empiler(Pile p, Car x) 
{
    if (p.h<50)
    {   
        p.tab[p.h]=x;
        p.h++;
    }
    else printf("Stack overflow.");
    return p;
}


Pile depiler(Pile p)
{
    if (!vide(p))
    {
        p.h--;
    }    
    return p;
}

Pile remplacer(Pile p, Car x)
{
    p.tab[p.h-1]=x;
    return p;
}

Car sommet(Pile p)
{   
    
    return p.tab[p.h-1];
}

Bool vide(Pile p)
{
    if (p.h<=0) return vrai;
    else return faux;
}

Nat hauteur(Pile p)
{
    return p.h;
}
