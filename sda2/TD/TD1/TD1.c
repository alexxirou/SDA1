#include "TD1.h"


listeg vide(){
    return NULL;
}

char* afficheString(void* e){
    if (e==NULL) {printf("Erreur pointeur NULL."); exit(1);}
    printf("%s\n", e);
}

void destroy(void *e){
    if (e!=NULL){
        free(e);
        e = NULL;
    }
}

void* cloneString(void *x){
    char* res = malloc(strlen((char*) x)+1);
    strncpy(res,x,strlen((char*) x));
    res[strlen((char*) x)] ='\0';
    return (void*) res;
}


int compareString(void *x1, void *x2){
    if (x1==NULL || x2==NULL)return -1;
    return *(char*) x1 - (*(char*) x2);
}


listeg adjTete(listeg lst, void *x, void* (*clone)(void *)){
    listeg new=(listeg)malloc(sizeof(struct s_node));
    if (new==NULL){printf("Nouv pointeur est NULL"); exit(1);}
    new -> prec = NULL;
    new -> suiv = lst;
    if (lst != NULL) lst ->prec = new;
    new ->val = clone(x);
    return new;
}

listeg adjQueue(listeg lst, void *x, void *(*clone)(void *)){
    if (lst==NULL)return adjTete(lst,x, clone);
    lst -> suiv = adjQueue(lst->suiv,x, clone);
    lst -> suiv -> prec =lst;
    return lst;
}

listeg supTete(listeg lst, void* (*det)(void *x)){
    if(lst==NULL) return lst;
    listeg temp = lst -> suiv;
    if (temp!=NULL) temp->prec=NULL;
    det(lst->val);
    free(lst);
    return temp;
} 

void *tete(listeg lst){
    if (lst->val==NULL) {printf("NULL");exit(1);}
    return lst->val;
} 

int longueur(listeg lst){
    if (lst==NULL) return 0;
    return 1+longueur(lst->suiv);
}

bool estVide(listeg lst){
    return lst==NULL;
} 

void detruire(listeg lst, void* (*det)(void *)){
    while (lst!=NULL) lst=supTete(lst,det);
}

void affichage(listeg lst, void* (*affiche)(void *)){
    listeg l = lst;
    while(l!=NULL){
        affiche(tete(l));
        l=l->suiv;
    }    
}

listeg rech(listeg lst, void *x, int (*cmp)(void *, void *), void *(*clone)(void *)){
    listeg res = NULL;
    while (lst != NULL){
        if (cmp(lst->val,x)==0) res=adjQueue(res,lst->val,clone);
        lst=lst->suiv;
    }
    if (res==NULL) {printf("Liste vide.");exit(1);}
    return res;
} 

