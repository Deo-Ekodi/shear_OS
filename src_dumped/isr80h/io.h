#ifndef ISR80H_IO_H
#define ISR80H_IO_H

#include "idt/idt.h"

struct interrupt_frame;
void* isr80h_command1_print(struct interrupt_frame* frame);


#endif