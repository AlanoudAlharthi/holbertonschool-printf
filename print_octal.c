#include "main.h"

/**
 * print_octal - print an unsigned long in octal
 * @n: number
 * Return: count of characters printed
 */
int print_octal(unsigned long n)
{
    int count = 0;

    if (n / 8)
        count += print_octal(n / 8);

    count += _putchar((n % 8) + '0');
    return (count);
}
