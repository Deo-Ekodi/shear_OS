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
}

bool isdigit(char c)
{
    return (c >= 48 && c <= 57);
}
int tonumericdigit(char c)
{
    return c - 48;
}