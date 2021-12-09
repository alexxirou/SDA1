#if CONT
#include "liste.h"
#else
#include "listec.h"

#endif

void test_liste(Liste test_liste, Nat x, Nat y, Nat z)
{
   test_liste=ajout_tete(test_liste, x);
   test_liste=ajout_tete(test_liste, y);
   test_liste=ajout_tete(test_liste, z);
   Liste temp = test_liste;

   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");

   test_liste=suppression_tete(test_liste);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   printf("%d\n",longueur(test_liste));

   printf("Appartenance %d %d\n", 5, appartenance_liste(test_liste, 5));
   
   test_liste=suppr_premiere_occurrence(test_liste,5);
   
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   test_liste=ajout_tete(test_liste, x);
   test_liste=ajout_tete(test_liste, y);
   test_liste=ajout_tete(test_liste, z);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");

   test_liste=change_premier_occurrence(test_liste,10,6);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");

   test_liste=suppr_dernier(test_liste);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   test_liste=inser_dernier(test_liste, 10);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   printf("Dernière valeur %d\n", acces_dernier(test_liste));
   test_liste=insertion_nth(test_liste,15,2);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   printf("%d eme valeur %d\n",2, access_nth(test_liste,1));
   test_liste=suppression_nth(test_liste,1);
   temp = test_liste;
   while(temp->s!=test_liste)
   {
      printf("%d ",tete(temp));
      temp=temp->s;
   }
   printf("%d ",tete(temp));
   printf("\n");
   printf("%d eme valeur %d\n",2, access_nth(test_liste,1));
   
   free(test_liste);
}