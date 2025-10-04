#include "main.h"

/**
 * print_string - prints a string to buffer
 * @s: string to print
 * @buffer: buffer array
 * @index: pointer to current buffer index
 *
 * Return: number of characters printed
 */
int print_string(char *s, char *buffer, int *index)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		print_buffer(buffer, index, *s);
		count++;
		s++;
	}
	return (count);
}

/**
 * handle_specifier - handles format specifiers
 * @c: specifier character
 * @args: list of arguments
 * @buffer: buffer array
 * @index: pointer to buffer index
 *
 * Return: number of characters printed
 */
int handle_specifier(char c, va_list args, char *buffer, int *index)
{
	int count = 0;

	switch (c)
	{
	case 'c':
		print_buffer(buffer, index, va_arg(args, int));
		count++;
		break;
	case 's':
		count += print_string(va_arg(args, char *), buffer, index);
		break;
	case '%':
		print_buffer(buffer, index, '%');
		count++;
		break;
	case 'b':
	{
		long int val = va_arg(args, long int);
		if (val < 0)
			val = (unsigned long int)val;
		count += print_binary((unsigned long int)val);
		break;
	}
	case 'u':
		count += print_unsigned(va_arg(args, unsigned int));
		break;
	case 'o':
		count += print_octal(va_arg(args, unsigned int));
		break;
	case 'x':
		count += print_hex(va_arg(args, unsigned int), 0);
		break;
	case 'X':
		count += print_hex(va_arg(args, unsigned int), 1);
		break;
	default:
		print_buffer(buffer, index, '%');
		print_buffer(buffer, index, c);
		count += 2;
		break;
	}

	return (count);
}

/**
 * _printf - produces output according to a format using a 1024-char buffer
 * @format: character string with directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char buffer[1024];
	int index = 0;

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
				print_buffer(buffer, &index, -1); /* flush before returning */
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i], args, buffer, &index);
		}
		else
		{
			print_buffer(buffer, &index, format[i]);
			count++;
		}
		i++;
	}

	print_buffer(buffer, &index, -1); /* flush remaining buffer */
	va_end(args);
	return (count);
}
