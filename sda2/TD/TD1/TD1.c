#include "TD1.h"


listeg vide(){
    return NULL;
}

char* affiche(void* e){
    if (e==NULL) {printf("Erreur pointeur NULL."); exit(1);}
    return (char*) e;
}

void destroy(void *e){
    if (e!=NULL){
        free(e);
        e = NULL;
    }
}

void* clone(void *x){
    char* res = malloc(strlen((char*) x)+1);
    strncpy(res,x,strlen((char*) x));
    res[strlen((char*) x)] ='\0';
    return (void*) res;
}


int compare(void *x1, void *x2){
    if (x1==NULL || x2==NULL)return -1;
    char* x = (char*) x1;
    char* y = (char*) x2;
    if (*x == *y || *y == *x +32 || *x == *y +32 ) return 1;
    return 0;
}


listeg adjtete(listeg lst, void *x, void* (*clone)(void *)){
    listeg new=(listeg)malloc(sizeof(struct s_node));
    if (new==NULL){printf("Nouv pointeur est NULL"); exit(1);}
    new -> prec = NULL;
    new -> suiv = lst;
    if (lst != NULL) lst ->prec = new;
    new ->val = clone(x);
    return new;
}

listeg adjqueue(listeg lst, void *x, void *(*clone)(void *)){
    if (lst==NULL)return adjtete(lst,x, clone);
    lst -> suiv = adjqueue(lst->suiv,x, clone);
    lst -> suiv -> prec =lst;
    return lst;
}

listeg suptete(listeg lst, void* (*det)(void *x)){
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

bool estvide(listeg lst){
    return lst==NULL;
} 

void detruire(listeg lst, void* (*det)(void *)){
    while (lst!=NULL) lst=suptete(lst,det);
}

void affichage(listeg lst, void* (*affiche)(void *)){
    if (lst==NULL){ printf("Liste vide."); exit(1);}
    while(lst!=NULL){
        
        printf("%s\n", (char*) affiche(lst->val));
        lst=lst->suiv;
    }    
}

listeg rech(listeg lst, void *x, int (*cmp)(void *, void *), void *(*clone)(void *)){
    listeg res = NULL;
    while (lst != NULL){
        if (cmp(lst->val,x)==1) res=adjqueue(res,lst->val,clone);
        lst=lst->suiv;
    }
    if (res==NULL) {printf("Liste vide.");exit(1);}
    return res;
} 

