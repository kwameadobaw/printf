#include "main.h"
/**
 * _process_format_specifier - Process format specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * printed_Pointer to the number of printed characters
 * Return: THe number of characters written to the buffer
*/
int _process_format_specifier(const char **format,
		char *buffer,
		size_t remaining_size,
		va_list args,
		int *printed_chars)
{
	int chars_written;

	chars_written = 0;

	switch (**format)
	{
		case 'c':
			buffer[chars_written++] = va_arg(args, int);
			(*printed_chars)++;
			break;
		case 's':
			chars_written += _print_string(&buffer[chars_written],
					remaining_size - chars_written,
					va_arg(args, const char *));
			(*printed_chars) += chars_written;
			break;
		case '%':
			buffer[chars_written++] = '%';
			(*printed_chars)++;
			break;
		case 'd':
		case 'i':
			chars_written += _print_number(va_arg(args, int),
					&buffer[chars_written],
					remaining_size - chars_written);
			(*printed_chars) += chars_written;
			break;
		case 'b':
			chars_written += _print_binary(va_arg(args, unsigned int),
					&buffer[chars_written],
					remaining_size - chars_written);
			(*printed_chars) += chars_written;
			break;

		default: buffer[chars_written++] = '%';
			 buffer[chars_written++] = **format;
			 (*printed_chars) += chars_written;
			 break;
	}
	(*format)++;
	return (chars_written);
}
