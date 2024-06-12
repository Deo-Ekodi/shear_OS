#ifndef STRING_H
#define STAING_H

#include <stdbool.h>

// get string length
int strlen(const char* ptr);

// get string length
int strnlen(const char* ptr, int max);

// convert char to int
int tonumericdigit(char c);

// check if string has numeric attribute
bool isdigit(char);

// copy string to specified destination
char* strcpy(char*, const char*);

// compare (int)n bytes of two strings
int strncmp(const char* str, const char* str2, int num);

// check null terminator
int strnlen_terminator(const char* str, int max, char terminator);

// non case-sentisite version of strcmp
int istrcmp(const char* s1, const char* s2, int n);

// converts caps to lowersase, no change otherwise
char tolower(char s1);


#endif