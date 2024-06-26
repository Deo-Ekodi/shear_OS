#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef int(*KEYBOARD_INIT_FUNCTION)();

struct process;

/**
 * virtual keyboard layer
 * provides interface for infinite number of keyboards
 * this acts as a tempate for implementation of keyboard drivers
 */
struct keyboard
{
    KEYBOARD_INIT_FUNCTION init;
    char name[20];
    struct keyboard* next;
};

/**
 * initialize keyboard - virtual keyboard
 */
void keyboard_init();
/**
 * baskspace - just as is
 */
void keyboard_backspace(struct process* process);
/**
 * read scan code into keyboard buffer
 */
void keyboard_push(char c);
/**
 * delete scan code from keyboard buffer
 */
char keyboard_pop();



#endif