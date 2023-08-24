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
		void (*print_char)(char *buffer, int character);
		int *printed_chars)
{
	int chars_written, basee, uppercase;

	chars_written = 0;
	base = (**format == 'o') ? 8 :10;
	uppercase = 0;

	chars_written += _print_unsigned(va_arg(args, unsigned int),
			base, uppercase, buffer + chars_written,
		       	remaining_size - chars_written, print_char,
			printedchars);
	(*printed_chars) += chars_written;
	(*format)++;
	return (chars_written);
}
