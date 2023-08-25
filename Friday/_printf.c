#include "main.h"
/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 * @...: Additional arguments for formatting
 * Return: The number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
	printed_chars = _vsnprintf(buffer, BUFFER_SIZE, format, args);

	write(1, buffer, printed_chars);

	va_end(args);
	return (printed_chars);
}
