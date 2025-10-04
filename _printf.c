#include "main.h"

/**
 * print_string - prints a string
 * @s: string to print
 *
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += _putchar(*s);
		s++;
	}

	return (count);
}

/**
 * handle_specifier - handles format specifiers
 * @c: specifier character
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int handle_specifier(char c, va_list args)
{
	int count = 0;

	if (c == 'c')
		count += _putchar(va_arg(args, int));
	else if (c == 's')
		count += print_string(va_arg(args, char *));
	else if (c == '%')
		count += _putchar('%');
	else if (c == 'b')
		count += print_binary(va_arg(args, unsigned long int));
	else if (c == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'o')
		count += print_octal(va_arg(args, unsigned int));
	else if (c == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else
	{
		count += _putchar('%');
		count += _putchar(c);
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
