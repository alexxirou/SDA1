#include "file_int2.h"

File filenouv()
{
   File nouveau_file;
   nouveau_file.h=NULL;
   nouveau_file.q=NULL;
   return nouveau_file;

}

File adjq(File f, Nat s)
{
    Strfile* nouveau_file=(Strfile*)malloc(sizeof(Strfile));    
    nouveau_file->v=s;
    nouveau_file->s=NULL;
    if(f.h==NULL){
        f.h=nouveau_file; 
        f.q=nouveau_file;
        }
    else {f.q->s=nouveau_file; f.q=nouveau_file;}
    return f;    
}
File supt(File f)
{
    Strfile* temp_file = f.h;
    if (f.q==f.h)
    {
       f.h=NULL; 
       f.q=NULL;
    }
    else f.h=f.h->s;
    free(temp_file);
    return f;
}

Nat tete(File f)
{
   return f.h->v;
}
Nat vide(File f)
{
   return (f.h==NULL)? vrai : faux;
}
Nat longuer(File f)
{
   File nouv_file;
   nouv_file.h=f.h;

   Nat l= 0;
   while(nouv_file.h!=f.q->s)
   {
       nouv_file.h=nouv_file.h->s;
       l++;
   }
   return l;
}

