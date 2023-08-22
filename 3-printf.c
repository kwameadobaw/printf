#include "main.h"
/**
 * _printf - Custom printf function
 * @format: THe format string.
 * @...: The variadic arguments to format and print.
 *
 * Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars;

	printed_chars = 0;
	va_start(args, format);
	buffer_index = 0;

	while (*format)
	{
		if (*format == '%')
			switch (*format)
			{
				case 'u':
					printed_chars += _print_unsigned_decimal(args, buffer,
							&buffer_index);
					break;
				case 'o':
					printed_chars += _print_octal(args, buffer, &buffer_index);
					break;
				case 'x':
					printed_chars += _print_hex_lower(args, buffer,
							&buffer_index);
					break;
				case 'X':
					printed_chars += _print_hex_upper(args, buffer,
							&buffer_index);
					break;
				default:
			}
		else
		{
			printed_chars += _putchar(*format, buffer, &buffer_index);
		}
		format++
	}
	write(1, buffer, buffer_index);
	va_end(args);
	return (printed_chars);
}
