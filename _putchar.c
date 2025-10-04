#include "main.h"

/**
 * _putchar - write character to stdout
 * @c: char
 * Return: 1 on success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
