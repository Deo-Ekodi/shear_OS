#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include <stddef.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

// headers
void terminal_putchar(int x, int y, char c, char color);
size_t strlen(const char*);
void terminal_initialize(void);
void kernel_main(void);
uint16_t terminal_uint16_t_make_char(char c, char col);

#endif
