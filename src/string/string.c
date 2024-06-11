#include "string.h"

int strlen(const char* str)
{
    int i = 0;
    while(*str != 0)
    {
        ++i;
        ++str;
    }
    return i;
}

int strnlen(const char* ptr, int max)
{
    int i = 0;
    for(; i < max; ++i)
    {
        if(ptr[i] == 0)
            break;
    }
    return i;
}

bool isdigit(char c)
{
    return (c >= 48 && c <= 57);
}
int tonumericdigit(char c)
{
    return c - 48;
}

char* strcpy(char* dest, const char* src)
{
    char* tmp = dest;
    while(*src != 0)
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }
    return tmp;
}