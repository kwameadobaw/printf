#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
int _print_number(int n, char *buffer, size_t size);
int _print_unsigned(unsigned int n, int base, int uppercase, char *buffer, size_t size);
int _print_binary(unsigned int n, char *buffer, size_t size);
int _print_hex(unsigned int n, int uppercase, char *buffer, size_t size);

int _vsnprintf(char *buffer, size_t size, const char *format, va_list args);
int print_int(va_list args);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int _printf_int(const char *format, ...);

#endif /* MAIN_H */
