#include <stdint.h>
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

int strncmp(const char* str1, const char* str2, int num)
{
    uint8_t u1, u2;

    while(--num > 0)
    {
        u1 = (uint8_t)*str1++;
        u2 = (uint8_t)*str2++;

        if(u1 != u2)
        {
            return u1 - u2;
        }
        if(u1 == '\0')
        {
            return 0;
        }
    }
    return 0;
}

int strnlen_terminator(const char* str, int max, char terminator)
{
    int i = 0;
    for(; i < max; ++i)
    {
        if(str[i] == '\0' || str[i] == terminator)
        {
            break;
        }
    }
    return i;
}

int istrcmp(const char* s1, const char* s2, int n)
{
    uint8_t u1, u2;

    while (--n > 0)
    {
        u1 = (uint8_t)*s1++;
        u2 = (uint8_t)*s2++;
        if(u1 != u2 && tolower(u1) != tolower(u2))
        {
            return u1 - u2;
        }
        if(u1 == '\0')
        {
            return 0;
        }
    }
    return 0;
}

char tolower(char s1)
{
    if(s1 >= 65 && s1 <= 90)
    {
        s1 += 32;
    }
    return s1; 
}