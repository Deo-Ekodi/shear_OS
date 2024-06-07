#include "memory/heap/kheap.h"
#include "paging.h"

struct paging_4gb_chunk* paging_new_4gb(uint8_t flags)
{
    kzalloc(sizeof(uint32_t) * PAGING_TOTAL_ENTRIES_PER_TABLE);
}