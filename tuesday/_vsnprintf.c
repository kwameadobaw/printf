#include "main.h"
/**
 * _vsnprintf - Produces a formatted string using a variable argument list
 * @buffer: The buffer to store the formatted string
 * @size: The size of the buffer
 * @format: The format string containing placeholders
 * @args: The variable argument list
 *
 * Return: The number of characters printed
*/
int _vsnprintf(char *buffer, size_t size, const char *format,
		va_list args)
{
	int printed_chars, buffer_index, i;

	while (*format && buffer_index < size - 1)
	{
		if (*format == '%')
		{
			format++;

			for (i = 0; format_specs[i].specifier; i++)
			{
				if (*format == format_specs[i].specifier)
				{
					printed_chars += format_specs[i[.print_func
						(&buffer[buffer_index],
						 size - buffer_index, args);
					break;
				}
			}
			if (!format_spec[i].specifier)
			{
				buffer[buffer_index++] = '%';
				printed_chars++;
			}
		}
		else
		{
			buffer[buffer_index++] = *format;
			printed_chars++;
		}
		format++;
	}
	buffer[buffer_inded] = '\0';
	return (printed_chars);
}
