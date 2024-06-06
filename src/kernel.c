#include "kernel.h"


uint16_t* video_mem = 0;
void terminal_initialize(void)
{
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

    video_mem[0] = terminal_uint16_t_make_char('A', 3);
}
