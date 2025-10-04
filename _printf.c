#include "main.h"

/**
 * _printf - prints formatted output
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'S')
                count += print_S(va_arg(args, char *));
            else if (format[i] == '%')
                count += _putchar('%');
            else
                count += _putchar(format[i]); /* unknown specifier */
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}
