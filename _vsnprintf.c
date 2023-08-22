#include "main.h"

int _vsnprintf(char *buffer, size_t size, const char *format, va_list args)
{
	int printed_chars;
	int buffer_index;

	printed_chars = 0;
	buffer_index = 0;

	while (*format && buffer_index < size - 1)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					buffer[buffer_index++] = va_arg(args, int);
					printed_chars++;
					break;

				case 's':
					printed_chars += _print_string(&buffer[buffer_index], size - buffer_index, va_arg(args, const char *));
					break;

				case '%':
					buffer[buffer_index++] = '%';
					printed_chars++;
					break;

				case 'd':
				case 'i':
					printed_chars += _print_number(va_arg(args, int), & buffer[buffer_index], size - buffer_index);
					buffer_index += printed_chars;
					break;

				case 'b':
					printed_chars += _print_binary(va_arg(args, unsigned int), &buffer[buffer_index], size - buffer_index);
					buffer_index += printed_chars;
					break;

				case 'u':
					printed_chars += _print_unsigned(va_arg(args, unsigned int), 10, 0, &buffer[buffer_index], size - buffer_index);
					break;

				case 'o':
					printed_chars += _print_unsigned(va_arg(args, unsigned int), 8, 0, &buffer[buffer_index], size - buffer_index);
					buffer_index += printed_chars;
					break;

				case 'X':
					printed_chars += _print_hex(va_arg(args, unsigned int), 1, &buffer[buffer_index], size - buffer_index);
				
				case 'x':
					printed_chars += _print_hex(va_arg(args, unsigned int), 0, &buffer[buffer_index], size - buffer_index);
					buffer_index += printed_chars;
					break;

				default:
					buffer[buffer_index++] = '%';
					buffer[buffer_index++] = *format;
					printed_chars += 2;
					break;
			}
		}
		else
		{
			buffer[buffer_index++] = *format;
			printed_chars++;
		}

		format++;
	}

	buffer[buffer_index] = '\0';
	return (printed_chars);
}
