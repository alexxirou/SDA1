#if CONT
#include "file_int.h"
#elif CIC
#include "file_int3.h"
#else
#include "file_int2.h"
#endif

int main(int argc, char* argv[])
{
    test_files(5, 10);
   
    return 0;    

    
}