#include "listec.h"

//ciruclar liste parcourir la lsite et retourner au debut
Liste liste_nouv()
{
    return NULL;
}


Liste ajout_tete (Liste l, int v)
{
    Liste nouv_liste=(Liste)malloc(sizeof(Strliste));
    nouv_liste->v=v;
    if (l==NULL) nouv_liste->s=nouv_liste;
    else {
        nouv_liste->s=l;
        Liste temp =l->s;
        while (temp->s!=l) temp=temp->s;
        temp->s=nouv_liste;
    }
   
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
    if(l==NULL) return 0;
    int lon=1;
    Liste addresse_pos=l->s;
    while(addresse_pos!=l)
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
    Liste temp =l->s;
    while (temp->s!=l) temp=temp->s;
    temp->s = addresse_pos;
    free(l);
    return addresse_pos;
}

Bool appartenance_liste(Liste l, int v){
    if(est_vide(l)) return 0;
    Liste addresse_pos=l->s;
    while(addresse_pos!=l)
    {
        if(addresse_pos->v==v) return 1;
        addresse_pos=addresse_pos->s;
    }
    return 0;
}    

Strliste* premier_occurrence(Liste l , int v)
{
    if(est_vide(l)) return NULL;
    Strliste* addresse_pos=l->s;
    while(addresse_pos!=l){
        if(addresse_pos->v==v) return addresse_pos;
            addresse_pos=addresse_pos->s;
    }
    return NULL;
}

Liste suppr_premiere_occurrence(Liste l, int v)
{
    if (est_vide(l)) return NULL;
    else if (tete(l)==v) return suppression_tete(l);
    Liste addresse_pos=premier_occurrence(l,v);
    addresse_pos=suppression_tete(addresse_pos);
    return l; 
}

Liste change_premier_occurrence(Liste l, int t, int v){
    if (l->v==t) {l->v=v; return l;}
    Liste addresse_pos=premier_occurrence(l,t);
    addresse_pos->v=v;   
    return l;
}

Liste suppr_dernier(Liste l){
    if (est_vide(l)) return l;
    if (l->s==l) return suppression_tete(l);
    Liste addresse_pos=l;
    while(addresse_pos->s!=l)
    {   
        addresse_pos=addresse_pos->s;
    }
    addresse_pos=suppression_tete(addresse_pos);
    return l;
}

Liste inser_dernier(Liste l,int v){
    if (l->s==l||l==NULL) return ajout_tete(l,v);
    Liste addresse_pos=l->s;
    while(addresse_pos!=l)
    {   
        addresse_pos=addresse_pos->s;
    }
    addresse_pos=ajout_tete(addresse_pos,v);
    
    return l;
}

int acces_dernier(Liste l){ // precondition pas vide 
    Liste addresse_pos=l->s;
    while (addresse_pos->s!=l)
    {
        addresse_pos=addresse_pos->s;
    }
    return addresse_pos->v;
}

int access_nth(Liste l, Nat i){ //precondtion i<=longeur;  
    Liste addresse_pos=l;
    for(int j=0; j<i; j++)
    {   
        if(addresse_pos->s==l) break;
        addresse_pos=addresse_pos->s;
    }
    return addresse_pos->v;
}

Liste insertion_nth(Liste l, int v, Nat i){
    Liste addresse_pos=l;
    for(int j=0; j<i-1; j++)
    {   
        if(l->s==l) break;
        l=l->s;
    }
    Liste temp =l->s;
    temp=ajout_tete(temp,v);
    l->s =temp;
    return addresse_pos;
}

Liste suppression_nth(Liste l, Nat i){
    Liste addresse_pos=l->s;
    for(int j=0; j<i-1; j++)
    {   
        if(addresse_pos->s==l) break;
        addresse_pos=addresse_pos->s;
    }
    addresse_pos=suppression_tete(addresse_pos);
    return l;
}