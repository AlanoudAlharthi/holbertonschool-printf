#include "main.h"

/**
 * _putchar - writes a single character directly to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error
 *
 * Note: Normally, _printf uses print_buffer() instead of _putchar()
 * to minimize write() calls. This function remains for compatibility.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
