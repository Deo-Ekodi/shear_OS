#include "../header/stdio.h"
#include "../header/shearos.h"
#include "../header/stdlib.h"
#include <stdarg.h>

int putchar(int charx)
{
    shearos_putchar((char)charx);
    return 0;
}

int printf(const char *fmt, ...)
{
    va_list ap;
    const char *p;
    char* sval;
    int ival;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
        /**
         * %i
         * format for integers
         */
        case 'i':
            ival = va_arg(ap, int);
            print(itoa(ival));
            break;
        
        /**
         * %s
         * format for strings
         */
        case 's':
            sval = va_arg(ap, char *);
            print(sval);
            break;

        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
    return 0;
}