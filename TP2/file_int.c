#include "file_int.h"

File filenouv()
{
   File nouveau_file;
   nouveau_file.l =0;
   return nouveau_file;
}
File adjq(File f, Nat s)
{
   if (f.l< MAX_P)
   {  
      f.l++;
      f.h=f.l%MAX_P;
      f.tab[f.h]=s;  
   }   
   else printf("Fille est pleine.");    
   return f;    
}
File supt(File f)
{
   if (f.l>0)
   {
      f.l--;
      f.h=f.l%MAX_P;
   }
   return f;
}
Nat tete(File f)
{
   return f.tab[f.h];
}
Nat vide(File f)
{
   return (f.l>0)? faux : vrai;
}
Nat longuer(File f)
{
   return f.l;
}

