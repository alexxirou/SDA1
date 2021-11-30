#include "file_int3.h"

File filenouv()
{
    return NULL;
}
File adjq(File f, Nat s)
{
    File new_file = MALLOC(Strfile);
    new_file->v = s;
    if (f == NULL)
    {
        new_file->s = new_file;
    }
    else
    {
        new_file->s = f->s;
        f->s = new_file;
    }
    return new_file;
}

File supt(File f) //precondition pas file vide
{
    if (f == f->s)
    {
        free(f);
        return NULL;
    }
    else
    {
        File res;
        Strfile *temp;
        temp = f->s;
        f->s = f->s->s;
        res = f;
        free(temp);
        return res;
    }
}

Nat tete(File f) // preconditionf pas vide
{  
    return f->s->v;
}
Nat vide(File f)
{
    return f == NULL;
}



Nat longuer(File f)
{
    Nat l =1;
    File count;
    count=f->s;
    while(count!=f)
    {
        count=count->s;
        l++;
    }
    return l;  
}