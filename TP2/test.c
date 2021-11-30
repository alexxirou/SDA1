#if CONT
#include "file_int.h"
#elif CIC
#include "file_int3.h"
#else
#include "file_int2.h"
#endif

void test_files(Nat x , Nat y)
{
   File test_file=filenouv();
   printf("Test vaucuité de la file %d\n", vide(test_file));
   test_file=adjq(test_file, x);
   test_file=adjq(test_file, y);
   printf("Tête de la file, longuer de la file %d %d\n",tete(test_file), longuer(test_file));
   test_file=supt(test_file);
   printf("Tête de la file, longuer de la file %d %d\n",tete(test_file), longuer(test_file));
   printf("Longuer de la file %d\n", longuer(test_file));
   test_file=adjq(test_file, 2);
   test_file=adjq(test_file, 3);
   test_file=adjq(test_file, 4);
   test_file=adjq(test_file, 1);
   test_file=adjq(test_file, x);
   test_file=adjq(test_file, y);
   printf("Tête de la file, longuer de la file %d %d\n",tete(test_file), longuer(test_file));
   Nat safe=flavius(test_file,1);
   printf("%d\n",safe);

}