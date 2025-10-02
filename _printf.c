#include "main.h"

/**
 * handle_specifier - Chooses what to print based on format specifier
 * @c: The specifier character
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int handle_specifier(char c, va_list args)
{
	if (c == 'c')
		return (_putchar(va_arg(args, int)));

	if (c == 's')
	{
		char *str = va_arg(args, char *);
		int count = 0;

		if (str == NULL)
			str = "(null)";
		while (*str)
			count += _putchar(*str++);
		return (count);
	}

	if (c == '%')
		return (_putchar('%'));

	if (c == 'd' || c == 'i')
	{
		int n = va_arg(args, int);

		return (print_int(n));
	}

	/* Unknown specifier: print '%' and the character */
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf - Produces output according to a format
 * @format: Character string with directives
 *
 * Return: Number of characters printed (excluding null byte),
 * or -1 if error occurs
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
			if (!format[i])
				return (-1);
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
