#include "file_int3.h"

File filenouv()
{
    return NULL;
}
File adjq(File f, Nat s)
{
    File new_file = (File)malloc(sizeof(Strfile));
    new_file->v = s;
    if (f == NULL)
    {
        new_file->s = new_file;
    }
    else
    {
        new_file->s = f;
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
    if (vide(f)) return 0;
    File new_file;
    new_file->s= f->s;
    Nat l = 1;
    while (new_file->s != f)
    {
        new_file = new_file->s;
        l++;
    }
    return l;
}