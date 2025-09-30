#include "main.h"

/**
 * handle_specifier - chooses what to print based on format
 * @c: the specifier character
 * @args: list of arguments
 *
 * Return: number of characters printed
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

	/* Unknown specifier: print '%' and the character */
	_putchar('%');
	_putchar(c);
	return (2);
}

/**
 * _printf - produces output according to a format
 * @format: character string with directives
 *
 * Return: number of characters printed (excluding null byte),
 * or -1 if error
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
