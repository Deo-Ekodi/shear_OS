#include "../../stdlib/header/shearos.h"
#include "../../stdlib/header/stdlib.h"
#include "../../stdlib/header/stdio.h"
#include "../../stdlib/header/string.h"


int main(int argc, char** argv)
{
    char str[] = "hello world";
    struct command_argument* root_command = shearos_parse_command(str, sizeof(str));
    printf("%s\n", root_command->argument);
    printf("%s\n", root_command->next->argument);
    while(1){
    }
    return 0;
}
