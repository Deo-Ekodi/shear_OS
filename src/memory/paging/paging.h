#ifndef PAGING_H
#define PAING_H

#include <stdint.h>
#include <stddef.h>

#define PAGING_CACHE_DISABLED   0b00010000
#define PAGING_WRITE_THROUGH    0b00001000
#define PAGING_ACCESS_FROM_ALL  0b00000100
#define PAGIN_IS_WRITEABLE      0b00000010
#define PAGING_IS_PRESENt       0b00000001

#define PAGING_TOTAL_ENTRIES_PER_TABLE  1024

struct paging_4gb_chunk
{
    uint32_t* directory_entry;
};

#endif