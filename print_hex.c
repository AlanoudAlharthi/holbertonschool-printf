#include "main.h"

/**
 * print_hex - print an unsigned long in hexadecimal
 * @n: number
 * @uppercase: 1 = uppercase, 0 = lowercase
 * Return: count of characters printed
 */
int print_hex(unsigned long n, int uppercase)
{
    int count = 0;
    char *digits;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    count += _putchar(digits[n % 16]);
    return (count);
}
