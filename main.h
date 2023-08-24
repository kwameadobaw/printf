#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct FormatSpec - Structure to map format specifiers to print functions
 * @specifier: The format specifier character
 * @print_func: Pointer to the corresponding print function
*/
typedef struct FormatSpec {
	char specifier;
	int (*print_func)(char *, size,_t, va_list);
} FormatSpec;

int _vsnprintf(char *buffer, size_t size, const char *format, va_list args);
int print_int(va_list args);
int _printf(const char *format, ...);
int print_char(va_list args);
int _print_string(char *buffer, size_t size, const char *str);
int print_percent(void);
int _printf_int(const char *format, ...);
int _process_format_specifier(const char **format, char *buffer, size_t remaining_size, va_list args, int *printed_chars);
int _print_num_rec(int n, char *buffer, size_t size, size_t index);
int _print_number_base(unsigned int n, int base, int uppercase);
int _print_u(va_list args, char *buffer, int *buffer_index);
int _print_o(va_list args, char *buffer, int *buffer_index);
int _print_hex_lo(va_list args, char *buffer, int *buffer_index);
int _print_hex_up(va_list args, char *buffer, int *buffer_index);
int hex_printf(const char *format, ...);

#endif /* MAIN_H */
