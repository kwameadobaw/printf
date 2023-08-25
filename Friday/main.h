#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct FormatHandler
{
	char specifier;
	int (*handler)(char *buffer, size_t size, va_list args);
} FormatHandler;

int _putchar(char c);
int _vsnprintf(char *buffer, size_t size, const char *format, va_list args);
int _printf(const char *format, ...);
int _print_number(int n, char *buffer, size_t size);
int _print_unsigned(unsigned int n, int base,
	       	int uppercase, char *buffer, size_t size);
int _print_binary(unsigned int n, char *buffer, size_t size);
int _print_hex(unsigned int n, int uppercase, char *buffer, size_t size);
int _print_string(char *buffer, size_t remaining_size, const char *str);
int apply_format_handler(char specifier, char *buffer, size_t size, va_list args);
int _process_format_specifier(const char **format, char *buffer,
		size_t remaining_size, va_list args, int *printed_chars);
int _print_num_rec(int n, char *buffer, size_t size, size_t index);
int _print_char(char *buffer, size_t size, va_list args);
int _print_decimal(char *buffer, size_t size, va_list args);
int _print_percent(char *buffer, size_t size, va_list args);
int _print_unsigned(char *buffer, size_t size, va_list args);

#endif /* MAIN_H */
