#ifndef SHEAROS_H
#define SHEAROS_H

#include <stddef.h>

void print(const char* filename);
int getkey();
void* shearos_malloc(size_t size);
void shearos_free(void* ptr);
void shearos_putchar(char c);

#endif