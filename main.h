#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Core functions */
int _printf(const char *format, ...);
int _putchar(char c);

/* Print helpers */
int print_int(int n);
int print_string(char *s);
int print_binary(unsigned long int n);

#endif /* MAIN_H */
