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
	int (*print_func)(char *, size_t, va_list);
} FormatSpec;

int _putchar(char c);
int _printf(const char *format, ...);
int _vsnprintf(char *buffer, size_t size, const char *format, va_list args);
int _print_unsigned(unsigned int n, int base, char *buffer);
int _print_binary(unsigned int n, char *buffer, size_t size);
int _print_hex(unsigned int n, int uppercase, char *buffer, size_t size);
int _print_number(int n, char *buffer,
		void (*print_digit)(char *buffer, int digit));
int _process_format_specifier_char(const char **format,
                char *buffer,
                va_list args,
                int *chars_written,
                void (*print_char)(char *buffer, int character));
int _process_format_specifier_string(const char **format, char *buffer,
		size_t remaining_size, va_list args,
		void (*print_char)(char *buffer, int character));
int _process_format_specifier_number(const char **format, char *buffer,
		size_t remaining_size, va_list args, int *printed_chars,
		void (*print_char)(char *buffer, int character));
int _Process_format_specifier_u_o(const char **format, char *buffer,
		size_t remaining_size, va_list args, int *printed_chars);
int _handle_S_specifier(const char **format, char *buffer, 
		size_t remaining_size, va_list args, int *printed_chars);

#endif /* MAIN_H */
