#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* _putchar writes a character to stdout */
int _putchar(char c);

/* _printf - custom printf function */
int _printf(const char *format, ...);

/* print_S - prints a string with non-printable characters as \xHH */
int print_S(const char *str);

#endif /* MAIN_H */
