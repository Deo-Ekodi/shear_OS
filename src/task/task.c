#include "task.h"
#include "kernel.h"
#include "status.h"
#include "memory/paging/paging.h"
#include "memory/heap/kheap.h"
#include "memory/memory.h"
#include "process.h"

/**
 * currennt task that is running
 */
struct task* current_task = 0;

/**
 * task linked list tail
 */
struct task* task_tail = 0;

/**
 * task linked list head
 */
struct task* task_head = 0;

struct task* task_current()
{
    return current_task;
}

int task_init(struct task* task, struct process* process);

struct task* task_new(struct process* process)
{
    int res = 0;
    struct task* task = kzalloc(sizeof(struct task));
    if(!task)
    {
        res = -ENOMEM;
        goto out;
    }

    res = task_init(task, process);
    if(res != SHEAROS_ALL_OK)
    {
        goto out;
    }

    /**
     * case empty linked list
     */
    if(task_head == 0)
    {
        task_head = task;
        task_tail = task;
        current_task = task;
        goto out;
    }
    task_tail->next = task;
    task->prev = task_tail;
    task_tail = task;

out:
    if(ISERR(res))
    {
        task_free(task);
        return ERROR(res);
    }
    return task;
}

struct task* task_get_next()
{
    if(!current_task->next)
    {
        return task_head;
    }
    return current_task->next;
}

static void task_list_remove(struct task* task)
{
    if(task->prev)
    {
        /**
         * detarch and link previous to next task
         */
        task->prev->next = task->next;
    }
    if(task == task_head)
    {
        /**
         * case task is first
         */
        task_head = task->next;
    }
    if(task == task_tail)
    {
        /**
         * case tail
         */
        task_tail = task->prev;
    }
    if(task == current_task)
    {
        current_task = task_get_next();
    }
}

int task_free(struct task* task)
{
    paging_free_4gb(task->page_directory);
    task_list_remove(task);

    // free task data
    kfree(task);
    return 0;
}

int task_switch(struct task* task)
{
    current_task = task;
    paging_switch(task->page_directory);
    return 0;
}

int task_page()
{
    user_registers();
    task_switch(current_task);
    return 0;
}

void task_run_first_ever_task()
{
    if(!current_task)
    {
        panic("task_run_first_ever_task() : No current task existing \n");
    }
    task_switch(task_head);
    task_return(&task_head->registers);
}

int task_init(struct task* task, struct process* process)
{
    memset(task, 0, sizeof(struct task));

    /**
     * map entire 4gb space to its self
     */
    task->page_directory = paging_new_4gb(PAGING_IS_PRESENT | PAGING_ACCESS_FROM_ALL);;
    if(!task->page_directory)
    {
        return -EIO;
    }

    task->registers.ip = SHEAROS_PROGRAM_VIRTUAL_ADDRESS;
    task->registers.ss = USER_DATA_SEGMENT;
    task->registers.cs = USER_CODE_SEGMENT;
    task->registers.esp = SHEAROS_PROGRAM_VIRTUAL_STACK_ADDRESS_START;
    task->process = process;

    return 0;
}