#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number to print
 * @uppercase: 1 for uppercase A-F, 0 for lowercase a-f
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char *digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";

	if (n / 16)
		count += print_hex(n / 16, uppercase);

	count += _putchar(digits[n % 16]);

	return (count);
}
