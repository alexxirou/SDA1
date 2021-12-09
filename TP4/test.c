#if CIC
#include "listedc.h"
#else
#include "listed.h"

#endif

void test_liste(Liste test_liste, Nat x, Nat y, Nat z)
{  
   printf("Vide liste? %d\n", est_vide(test_liste));
   test_liste=ajout_tete(test_liste, x);
   test_liste=ajout_tete(test_liste, y);
   test_liste=ajout_tete(test_liste, z);
   Liste temp = test_liste;

   while(temp!=NULL)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   //printf("%d ",tete(temp));
   printf("\n");
   printf("Vide liste? %d\n", est_vide(test_liste));
   printf("Longueur liste? %d\n", longueur(test_liste));
   test_liste=suppression_tete(test_liste);
   temp = test_liste;
   while(temp!=NULL)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   //printf("%d ",tete(temp));
   printf("\n");
   printf("%d\n",longueur(test_liste));
   printf("Longueur liste? %d\n", longueur(test_liste));
   printf("Appartenance %d %d\n", 5, appartenance_liste(test_liste, 5));
   printf("Appartenance %d %d\n", 1, appartenance_liste(test_liste, 1));

   test_liste=ajout_nth(test_liste, 15, 2);
   test_liste=ajout_nth(test_liste, 1, 1);
   temp = test_liste;
   while(temp!=NULL)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   //printf("%d ",tete(temp));
   printf("\n");
   printf("2me tete: %d\n",access_nth(test_liste,1));
   test_liste=suppr_nth(test_liste, 1);
   temp = test_liste;
   while(temp!=NULL)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   //printf("%d ",tete(temp));
   printf("\n");
   test_liste=suppr_nth(test_liste, 5);
   temp = test_liste;
   while(temp!=NULL)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   //printf("%d ",tete(temp));
   printf("\n");

   Iter i=init(test_liste);
   printf("Position du  %d : %d\n", 5, cherche_val(i,5) );
   int V;
   foreach(V, test_liste) printf("%d ",V);
   printf("\n");
   free(test_liste);
}