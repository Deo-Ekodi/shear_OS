#include "../stdlib/src/shearos.h"
#include "../stdlib/src/stdlib.h"
#include "../stdlib/src/stdio.h"

int main(int argc, char** argv)
{
    print("Hello, program active\n");

    print(itoa(928));
    printf("\nOhh damn! printf just worked!\n");
    putchar('z');
    void* ptr = malloc(512);
    free(ptr);

    char buf[1024];
    shearos_terminal_readline(buf, sizeof(buf), false);
    print(buf);
    while(1){
    }
    return 0;
}