#include "../../stdlib/src/shearos.h"
#include "../../stdlib/src/stdlib.h"
#include "../../stdlib/src/stdio.h"
#include "../../stdlib/src/string.h"


int main(int argc, char** argv)
{
    char words[] = "hello guy!!";
    const char* token = strtok(words, " ");

    while(token)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    ;
    printf("\nOhh damn! printf just worked!\n");

    while(1){
    }
    return 0;
}
