#include "listed.h"

Liste liste_nouv()
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

bool est_vide (Liste l )
{
    return l==NULL;
}

int tete (Liste l)
{
    return l->v;
}

int longueur (Liste l)
{
    if (l==NULL) return 0;
    
    int lng=1;
    
    while (l->s!=NULL)
    {
        lng++;
        l=l->s;
    }
    return lng;
}


Liste suppression_tete(Liste l)
{   
    Liste adresse_pos=l->s;
    free(l);
    return adresse_pos;
}

Bool appartenance_liste(Liste l, int x)
{   
    if(l==NULL) return 0;
    while(l!=NULL)
    {   
        if (l->v==x) return 1;
        l=l->s;
    }
    return 0;
}
int access_nth(Liste l, Nat x)
{
    Liste temp=l;
    for(int i=0; i<x; i++){
        if(temp->s==NULL) return temp->v;
        temp=temp->s;
    }
    return temp->v;
        
}
Liste ajout_nth(Liste l,int v, Nat x){
    Liste temp=l;
    for(int i=0; i<x-1; i++){
        if(temp->s==NULL) {temp->s=ajout_tete(temp->s,v); temp->s->p=temp; return l;}
        temp=temp->s;
    }

    temp->s=ajout_tete(temp->s,v);
    temp->s->p=temp;
    return l;
}    
Liste suppr_nth(Liste l, Nat x){
    if (l==NULL) return NULL;
    if (l->s==NULL) return suppression_tete(l);
    Liste temp=l;
    for(int i=0; i<x-1; i++){
        temp=temp->s;
        if(temp->s->s==NULL) {temp->s=suppression_tete(temp->s); return l;}
    }
    temp->s->s->p=temp;
    temp->s=suppression_tete(temp->s);
    return l;
}



Iter init(Liste l){
    Iter i=(Iter)malloc(sizeof(Iter));
    if(l==NULL) i->fin=1;
    
    else i->fin=0;
    i->first=l;
    i->cour=l;
    return i;

}
Bool end(Iter i){
    return i->fin;
}
Iter next(Iter i)// mise à jour du Bool fin en cas de fin
{   
    if (i->cour==NULL) return i;
    if (i->cour->s==NULL) i->fin=1;
    else i->cour=i->cour->s;
    return i;
}
Iter prev(Iter i){
    if(i->cour->p!=NULL) i->cour=i->cour->p;
    return i;
}
int value(Iter i){ //precondition liste pas vide 
    return i->cour->v;
}

int cherche_val(Iter i, int v){
    int pos=0;
    i->cour=i->first;
    while(i->fin!=1){
        if(i->cour->v==v) return pos;
        i=next(i);
        pos++;
    }
    return -1;
}