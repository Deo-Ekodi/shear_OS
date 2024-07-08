#ifndef KERNEL_H
#define KERNEL_H

/**
 * display param
 */
#define VGA_WIDTH 80
/**
 * display param
 */
#define VGA_HEIGHT 20

#define SHEAROS_MAX_PATH 108

void kernel_main();
void print(const char* str);
void terminal_writechar(char c, char colour);

void panic(const char* msg);
void kernel_page();
void kernel_registers();

/**
 * cast value to void* & return
 */
#define ERROR(value) (void*)(value)
/**
 * cast value to int & return
 */
#define ERROR_I(value) (int)(value)
/**
 * returns boolean
 */
#define ISERR(value) ((int)value < 0)
#endif