
#include <stdbool.h>

#include "shearos.h"

int shearos_getkeyblock()
{
    int val = shearos_getkey();
    do
    {
        val = shearos_getkey();
    }while(val == 0);
    return val;
}

void shearos_terminal_readline(char* out, int max, bool output_while_typing)
{
    int i = 0;
    for(; i < max - 1; i++)
    {
        char key = shearos_getkeyblock();

        if(key == 13)
        {
            break;
        }
        if(output_while_typing)
        {
            shearos_putchar(key);
        }
        // backspace
        if(key == 0x08 && i >= 1)
        {
            out[i-1] = 0x00;
            i -= 2;
            continue;
        }

        out[i] = key;
    }
    out[i] = 0x00;
}