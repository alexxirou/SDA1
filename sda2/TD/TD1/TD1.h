#ifndef TD1_H
#define TD1_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
 void *val; // pointeur vers objet quelconque
 struct s_node *suiv, *prec;
} *listeg; 


int compareString(void *x1, void *x2) ;
listeg vide();
listeg adjTete(listeg lst, void *x, void * (*clone)(void *x)) ;
listeg adjQueue(listeg lst, void *x, void * (*clone)(void *x)) ;
listeg supTete(listeg lst, void* (*det)(void *x)) ;
listeg rech(listeg lst, void *x, int (*cmp)(void *, void *), void *(*clone)(void *)) ; 
void *tete(listeg lst) ;
int longueur(listeg lst) ;
bool estvide(listeg lst) ;
void detruire(listeg lst, void* (*det)(void *x)) ;
void affichage(listeg lst, void* (*affiche)(void *x)) ; 
void *cloneString(void *x);
void destroy(void *e);
char* afficheString(void* e);
#endif