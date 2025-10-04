#include "main.h"

/**
 * print_S - prints a string, replacing non-printable chars with \xHH
 */
int print_S(const char *str)
{
    int count = 0;
    unsigned char c;
    char hex[] = "0123456789ABCDEF";

    if (!str)
        str = "(null)";

    while (*str)
    {
        c = (unsigned char)*str;

        if ((c > 0 && c < 32) || c >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar(hex[c / 16]);
            count += _putchar(hex[c % 16]);
        }
        else
        {
            count += _putchar(c);
        }

        str++;
    }
    return count;
}
