#include "../../stdlib/header/shearos.h"
#include "../../stdlib/header/stdlib.h"
#include "../../stdlib/header/stdio.h"
#include "../../stdlib/header/string.h"


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
