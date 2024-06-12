#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include <stddef.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

// takes value and casts to void*
#define ERROR(value) (void*)(value)

// takes value and casts to int
#define ERROR_I(value) (int)(value)

// takes value and compares to zero (boolean)
#define ISERR(value) ((int) value < 0)

// headers
void print(const char* str);
void terminal_writechar(char c, char col);
void terminal_putchar(int x, int y, char c, char color);
// size_t strlen(const char*);
void terminal_initialize(void);
void kernel_main(void);
uint16_t terminal_uint16_t_make_char(char c, char col);
uint16_t terminal_make_char(char c, char col);

#endif
