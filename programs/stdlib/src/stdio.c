#include "stdio.h"
#include "shearos.h"

int putchar(int charx)
{
    shearos_putchar((char)charx);
    return 0;
}