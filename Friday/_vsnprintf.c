#include "main.h"

int _vsnprintf(char *buffer, size_t size, const char *format, va_list args)
{
	int printed_chars;
	size_t buffer_index = 0;

	while (*format && buffer_index < (size - 1))
	{
		if (*format == '%')
		{
			format++;
			printed_chars += _process_format_specifier
				(&format, &buffer[buffer_index], 
				 size - buffer_index, args);
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
