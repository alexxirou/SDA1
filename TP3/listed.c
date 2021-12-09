#include "listed.h"

Liste liste_vide()
{
    return NULL;
}


Liste ajout_tete (Liste l, int v)
{
    Liste nouveau_liste=(Liste)malloc(sizeof(Strliste));
    nouveau_liste->v=v;
    nouveau_liste->s=l;
    nouveau_liste->p=NULL;
    if (l!=NULL){
        l->p=nouveau_liste;
    }
    return nouveau_liste;
}
:                   
bool est_vide (Liste l )
{
    return l==NULL;
}

S tete (Liste l)
{
    return l->v;
}

int longueur (Liste l)
{
   
    return l;
}


Liste suppression_tete(Liste l)
{   
 
    return nouveau_liste;
}