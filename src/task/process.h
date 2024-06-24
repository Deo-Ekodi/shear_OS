#ifndef PROCESS_H
#define PROCESS_H


#include <stdint.h>
#include "config.h"


struct process
{
    // process id
    uint16_t id;
    char filename[SHEAROS_MAX_PATH];

    // main process task
    struct task* task;

    // the memory (malloc) allocations of the process
    void* allocation[SHEAROS_MAX_PROGRAM_ALLOCATIONS];

    // physical pointer to process memory
    void* ptr;

    // physical pointer to stack memory
    void* stack;

    // size of data pointed by "ptr"
    uint32_t size;

    // keyboard_buffer
    struct keyboard_buffer
    {
        char buffer[SHEAROS_KEYBOARD_BUFFR_SIZE];
        int tail;
        int head;
    }keyboard;
};

struct process* process_get(int process_id);
struct process* process_current();
int process_load_for_slot(const char* filename, struct process** process, int process_slot);
int process_load(const char* filename, struct process** process);

#endif