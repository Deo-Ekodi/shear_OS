#include "shell.h"
#include "../../stdlib/src/stdio.h"
#include "../../stdlib/src/stdlib.h"
#include "../../stdlib/src/shearos.h"

int main(int argc, char** argv)
{
    print("shearOS v1.0.0\n");

    while(1){
        ptint("> ");
        char buf[1024];
        shearos_terminal_readline(buf, sizeof(buf), true);
        print("\n");
    }
    return 0;
}