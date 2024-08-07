#ifndef SHEAROS_H
#define SHEAROS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument
{
    char argument[512];
    struct command_argument* next;
};

struct command_argument* shearos_parse_command(const char* command, int max);

void print(const char* filename);
int shearos_getkey();
void* shearos_malloc(size_t size);
void shearos_free(void* ptr);
void shearos_putchar(char c);
int shearos_getkeyblock();
void shearos_terminal_readline(char* out, int max, bool output_while_typing);
void shearos_process_load_start(const char* filename);

#endif