#include "main.h"

/**
 * print_buffer - handles buffered output to minimize write calls
 * @buffer: the char buffer
 * @index: pointer to current buffer index
 * @c: char to add, or -1 to flush
 */
void print_buffer(char *buffer, int *index, char c)
{
    if (c == -1 || *index >= 1024)
    {
        write(1, buffer, *index);
        *index = 0;
    }

    if (c != -1)
    {
        buffer[*index] = c;
        (*index)++;
    }
}
