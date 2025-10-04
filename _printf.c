#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char modifier = '\0';

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            /* تحقق من الـ length modifier */
            if (format[i] == 'l' || format[i] == 'h')
            {
                modifier = format[i];
                i++;
            }

            switch (format[i])
            {
                case 'd':
                case 'i':
                    if (modifier == 'l')
                        count += print_number(va_arg(args, long));
                    else if (modifier == 'h')
                        count += print_number((short)va_arg(args, int));
                    else
                        count += print_number(va_arg(args, int));
                    break;

                case 'u':
                    if (modifier == 'l')
                        count += print_unsigned(va_arg(args, unsigned long));
                    else if (modifier == 'h')
                        count += print_unsigned((unsigned short)va_arg(args, unsigned int));
                    else
                        count += print_unsigned(va_arg(args, unsigned int));
                    break;

                case 'o':
                    if (modifier == 'l')
                        count += print_octal(va_arg(args, unsigned long));
                    else if (modifier == 'h')
                        count += print_octal((unsigned short)va_arg(args, unsigned int));
                    else
                        count += print_octal(va_arg(args, unsigned int));
                    break;

                case 'x':
                    if (modifier == 'l')
                        count += print_hex(va_arg(args, unsigned long), 0);
                    else if (modifier == 'h')
                        count += print_hex((unsigned short)va_arg(args, unsigned int), 0);
                    else
                        count += print_hex(va_arg(args, unsigned int), 0);
                    break;

                case 'X':
                    if (modifier == 'l')
                        count += print_hex(va_arg(args, unsigned long), 1);
                    else if (modifier == 'h')
                        count += print_hex((unsigned short)va_arg(args, unsigned int), 1);
                    else
                        count += print_hex(va_arg(args, unsigned int), 1);
                    break;

                case '%':
                    _putchar('%');
                    count++;
                    break;

                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
            }
            modifier = '\0'; /* رجعها للوضع العادي */
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
