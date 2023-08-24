#include "main.h"
/**
 * _printf - Prints formatted text to the standard output
 * @format: The format string containing placeholders
 * @...: The list of arguments to replace placeholders
 *
 * Return: The number of characters printed.
*/
int _printf(const cahr *format, ...)
{
	va_list args;
	int printed_chars;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
	printed_chars = _vsnprintf(buffer, BUFFER_SIZE, format, args);
	va_end(args);

	write(1, buffer, printed_chars);

	return (printed_chars);
}
