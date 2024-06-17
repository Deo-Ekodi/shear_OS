#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#include "config.h"
#include "memory/paging/paging.h"

struct registers
{
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t ip;
    uint32_t cs;
    uint32_t flags;
    uint32_t esp;
    uint32_t ss;
};

struct task
{
    /**
     * page_directory_of the task
     */
    struct paging_4gb_chunk* page_directory;
    /**
     * registers of the task when task idle
     */
    struct registers registers;
    /**
     * next task in linked lisk
     */
    struct task* next;
    /**
     * previous task in llist
     */
    struct task* prev;
    /**
     * process of the task
     */
    struct process* process;
};


int task_free(struct task* task);
struct task* task_new(struct process* process);
struct task* task_get_next();
struct task* task_current();

#endif