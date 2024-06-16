#ifndef KERNEL_H
#define KERNEL_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

#define SHEAROS_MAX_PATH 108

void kernel_main();

// display
void print(const char* str);

// for unrecoverable state in the kernel
void panic(const char* str);

#define ERROR(value) (void*)(value)
#define ERROR_I(value) (int)(value)
#define ISERR(value) ((int)value < 0)
#endif