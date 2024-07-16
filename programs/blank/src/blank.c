#include "../../stdlib/header/shearos.h"
#include "../../stdlib/header/stdlib.h"
#include "../../stdlib/header/stdio.h"
#include "../../stdlib/header/string.h"


int main(int argc, char** argv)
{
    char* ptr = malloc(20);
    strcpy(ptr, "hello kernel!");

    print(ptr);
    free(ptr);

    ptr[0] = 'B';
    print("abc\n");
    while(1){
    }
    return 0;
}
