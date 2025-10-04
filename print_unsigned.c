#include "main.h"

/**
 * print_unsigned - print an unsigned long integer
 * @n: number
 * Return: count of characters printed
 */
int print_unsigned(unsigned long n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}
