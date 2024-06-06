#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20
void kernel_main(void);
uint16_t terminal_uint16_t_make_char(char c, char col);

#endif
