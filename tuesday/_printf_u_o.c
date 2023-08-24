#include "main.h"
/**
 * _handle_u_oo_specifier - Handle 'u' and 'o' conversion specifiers
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * @print_char: Pointr to a function that prints a single character
 * @printed_chars: Pointer to  the number of printed characters
 *
 * Return: The number of characters written to the buffer
*/
int _handle_u_o_specifier(const char **format, char *buffer,
		size_t remaining_size,
		va_list args,
		int *printed_chars)
{
	int chars_written, base;

	chars_written = 0;
	if (**format == 'u' || **format == 'o')
	{
		base = (**format == 'o') ? 8 :10;
		uppercase = 0;
		(*format)++;

	chars_written += _print_unsigned(va_arg(args, unsigned int),
			base, buffer);
	(*printed_chars) += chars_written;
	}

	(*format)++;
	return (chars_written);
}
