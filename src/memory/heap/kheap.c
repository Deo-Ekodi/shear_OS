#include "kheap.h"
#include "heap.h"
#include "config.h"
#include "kernel.h"

struct heap kernel_heap;
struct heap_table kernel_heap_table;


void kheap_init()
{
    int total_table_entries = SHEAROS_HEAP_SIZE_BYTES / SHEAROS_HEAP_BLOCK_SIZE;
    kernel_heap_table.entries = (HEAP_BLOCK_TABLE_ENTRY*)(SHEAROS_HEAP_TABLE_ADDRESS);
    kernel_heap_table.total = total_table_entries;

    void* end = (void*)(SHEAROS_HEAP_ADDRESS + SHEAROS_HEAP_SIZE_BYTES);
    int res = heap_create(&kernel_heap, (void*)(SHEAROS_HEAP_ADDRESS), end, &kernel_heap_table);
    if(res < 0)
    {
    print("failed to create heap! \n");
    }
}