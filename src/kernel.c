#include "kernel.h"


uint16_t* video_mem = 0;
uint16_t terminal_row = 0;
uint16_t terminal_col = 0;

void terminal_initialize(void)
{
    terminal_col = terminal_row = 0;

    video_mem = (uint16_t*)(0xB8000);

    for(int y = 0; y < VGA_HEIGHT; ++y)
    {
        for (int x = 0; x < VGA_WIDTH; ++x)
        {
            terminal_putchar(x, y, ' ', 0);
        }
    }
}

uint16_t terminal_uint16_t_make_char(char c, char col)
{
    return (col << 8) | c;
}

size_t strlen(const char* c)
{
    size_t len = 0;
    
    /**
     * hunt for null-terminator
     */
    while(c[len])
    {
        len++;
    }
    return len;
}

void print(const char* str)
{
    size_t len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        terminal_writechar(str[i], 15);
    }
}

void terminal_writechar(char c, char col)
{
    terminal_putchar(terminal_col, terminal_row, c, col);
    ++terminal_col;

    if(terminal_col += VGA_WIDTH)
    {
        terminal_col = 0;
        ++terminal_row;
    }
}

void terminal_putchar(int x, int y, char c, char color)
{
    video_mem[(y * VGA_WIDTH) + x] = terminal_uint16_t_make_char(c, color);
}
/**
 * 1st byte - character
 * 2nd byte - color
 * 
 * TEXT mode supports 16 different colors
*/
void kernel_main(void)
{
    terminal_initialize();
    // char* video_mem = (char*)(0xB8000);
    // video_mem[0] = 'A';
    // video_mem[1] = '3';

    // video_mem[0] = terminal_uint16_t_make_char('A', 3);
    // terminal_writechar('A', 15);
    // terminal_writechar('B', 10);

    print("Hello Kernel World!!");
}
