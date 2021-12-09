#include "liste.h"

//ciruclar liste parcourir la lsite et retourner au debut
Liste liste_nouv()
{
    return NULL;
}


Liste ajout_tete (Liste l, int v)
{
    Liste nouv_liste=(Liste)malloc(sizeof(Strliste));
    nouv_liste->v=v;
    nouv_liste->s=l;
    return nouv_liste;
}

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
    int lon=0;
    Liste addresse_pos=l;
    while(addresse_pos!=NULL)
    {
        lon++;
        addresse_pos=addresse_pos->s;

    }
    return lon;
}


Liste suppression_tete(Liste l){   
    if (l==NULL)
    {
        return l;
    }
    Liste addresse_pos=l->s;
    free(l);
    return addresse_pos;
}

Bool appartenance_liste(Liste l, int v){
    if(est_vide(l)) return 0;
    Liste addresse_pos=l;
    while(addresse_pos->s!=NULL)
    {
        if(addresse_pos->s->v==v) return 1;
        addresse_pos=addresse_pos->s;
    }
    return 0;
}    

Strliste* premier_occurrence(Liste l , int v)
{
    if(est_vide(l)) return NULL;
    Strliste* addresse_pos=l;
    while(addresse_pos->s!=NULL){
        if(addresse_pos->s->v==v) return addresse_pos;
            addresse_pos=addresse_pos->s;
    }
    return NULL;
}

Liste suppr_premiere_occurrence(Liste l, int v)
{
    if (est_vide(l)) return NULL;
    else if (tete(l)==v) return suppression_tete(l);
    Liste addresse_pos=premier_occurrence(l,v);
    addresse_pos->s=suppression_tete(addresse_pos->s);
    return l; 
}

Liste change_premier_occurrence(Liste l, int t, int v){
    if (l->v==t) {l->v=v; return l;}
    Liste addresse_pos=premier_occurrence(l,t);
    addresse_pos->s->v=v;   
    return l;
}

Liste suppr_dernier(Liste l){
    if (est_vide(l)) return l;
    if (l->s==NULL) return suppression_tete(l);
    Liste addresse_pos=l;
    while(addresse_pos->s->s!=NULL)
    {   
        addresse_pos=addresse_pos->s;
    }
    addresse_pos->s=suppression_tete(addresse_pos->s);
    return l;
}

Liste inser_dernier(Liste l,int v){
    if (est_vide(l)) return l;
    Liste addresse_pos=l;
    if (l->s==NULL) return ajout_tete(l,v);
    while(addresse_pos->s!=NULL)
    {   
        addresse_pos=addresse_pos->s;
    }
    addresse_pos->s=ajout_tete(addresse_pos->s,v);
    
    return l;
}

int acces_dernier(Liste l){ // precondition pas vide 
    Liste addresse_pos=l;
    while (addresse_pos->s!=NULL)
    {
        addresse_pos=addresse_pos->s;
    }
    return addresse_pos->v;
}

int access_nth(Liste l, Nat i){ //precondtion i<=longeur;  
    Liste addresse_pos=l;
    for(int j=0; j<i-1; j++)
    {   
        addresse_pos=addresse_pos->s;
    }
    return addresse_pos->v;
}

Liste insertion_nth(Liste l, int v, Nat i){
    Liste addresse_pos=l;
    for(int j=0; j<i-2; j++)
    {   
        if(l->s==NULL) break;
        l=l->s;
    }
    Liste temp =l->s;
    temp=ajout_tete(temp,v);
    l->s =temp;
    return addresse_pos;
}

Liste suppression_nth(Liste l, Nat i){
    Liste addresse_pos=l;
    for(int j=0; j<i-2; j++)
    {
        l=l->s;
    }
    l->s=suppression_tete(l->s);
    return addresse_pos;
}