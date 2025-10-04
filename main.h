#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

int print_number(long n);
int print_unsigned(unsigned long n);
int print_octal(unsigned long n);
int print_hex(unsigned long n, int uppercase);

#endif
