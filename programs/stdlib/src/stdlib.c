#include <stddef.h>
#include "stdlib.h"
#include "shearos.h"

void* malloc(size_t size)
{
    return shearos_malloc(size);
}

void free(void* ptr)
{
    shearos_free(ptr);
}