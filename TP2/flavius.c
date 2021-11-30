#include "file_int3.h"

Nat flavius(File f , Nat elim)
{   Nat safe=0;
    Nat long_initial=longuer(f);
    while(f->s!=f)
    {   
        for(Nat i = 0; i<elim; i++)
        {   
            f=f->s;
        }
        f=supt(f);
        safe+=elim;
    }   
    safe=safe%long_initial;
    return safe;
}    
