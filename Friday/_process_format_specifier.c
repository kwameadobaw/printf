#include "main.h"
/**
 * _process_format_specifier - Process format specifier and call handler
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * Return: The number of characters written to the buffer
*/
int _process_format_specifier(const char **format, char *buffer,
		size_t remaining_size, va_list args)
{
	int chars_written = 0;

	switch (**format)
	{
		case 'c':
			chars_written += _print_char(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case '%':
			chars_written += _print_percent(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case 'd':
		case 'i':
			chars_written += _print_decimal(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case 'u':
			chars_written += _print_unsigned(&buffer[chars_written],
					remaining_size - chars_written, args);
		case 'b':
			chars_written += _print_binary(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case 'o':
			chars_written += _print_octal(&buffer[chars_written],
					remaining_size - chars_written, args);
		case 'x':
			chars_written += _print_hex_lower(&buffer[chars_written],
				       	remaining_size - chars_written, args);
		case 'X':
			chars_written += _print_hex_upper(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case 'p':
			chars_written += _print_pointer(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		case 'S':
			chars_written += _print_custom_string(&buffer[chars_written],
					remaining_size - chars_written, args);
			break;
		default:
			buffer[chars_written++] = '%';
			buffer[chars_written++] **format;
			(*format)++;
			break;
	}

	(*format)++;
	return (chars_written);
}
