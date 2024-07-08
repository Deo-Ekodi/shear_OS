#include "../header/shell.h"
#include "../../stdlib/header/stdio.h"
#include "../../stdlib/header/stdlib.h"
#include "../../stdlib/header/shearos.h"

int main(int argc, char** argv)
{
    print("\nshearOS v1.0.0\n");

    while(1){
        print("> ");
        char buf[1024];
        shearos_terminal_readline(buf, sizeof(buf), true);
        shearos_process_load_start(buf);
        print("\n");
    }
    return 0;
}