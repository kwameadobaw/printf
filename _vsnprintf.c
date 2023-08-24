#include "main.h"
/**
 * _vsnprintf - Print formattted output to a buffer
 * @buffer: The buffer to store the formatted output
 * @size: The size of the buffer
 * @format: The format string
 * @args: The arguments to be formatted
 * Return: Thr number of characters printed
*/
int _vsnprintf(char *buffer, size_t size, const char *format, va_list args)
{
	int printed_chars;
	size_t buffer_index;

	buffer_index = 0;
	printed_chars = 0;

	while (*format && buffer_index < (size - 1))
	{
		if (*format == '%')
		{
			format++;
			buffer_index += _process_format_specifier(&format,
					&buffer[buffer_index],
					size - buffer_index,
					args,
					&printed_chars);
		}
		else
		{
			buffer[buffer_index++] = *format;
			printed_chars++;
			format++;
		}
	}

	buffer[buffer_index] = '\0';
	return (printed_chars);
}
