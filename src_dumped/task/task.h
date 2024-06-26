#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#include "config.h"
#include "memory/paging/paging.h"

struct interrupt_frame;
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

void restore_general_purpose_registers(struct registers* regs);
/**
 * returns us into userland
 */
void task_return(struct registers* regs);
/**
 * change all user data so segment registers
 */
void user_registers();
/**
 * switches task to current task in the linked list
 */
int task_switch(struct task* task);
/**
 * takes us from kernel page directory and loads task page directory
 */
int task_page();
/**
 * responsible for running first ever task
 */
void task_run_first_ever_task();
/**
 * saves state of current task
 * good for multithreading / concurrency
 */
void task_current_save_state(struct interrupt_frame* frame);
int copy_string_from_task(struct task* task, void* virtual, void* phys, int max);
void* task_get_stack_item(struct task* task, int index);
int task_page_task(struct task* task);


#endif