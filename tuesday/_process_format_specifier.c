#include "main.h"
/**
 * _process_format_specifier_char - Process format specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * @printed_chars: Pointer to the number of printed characters
 * @print_char: Pointer to the function that prints a single character
 * Return: The number of characters written to the buffer
*/
int _process_format_specifier_char(const char **format,
		char *buffer,
		size_t remaining_size,
		va_list args,
		int *printed_chars,
		void (*print_char)(char *buffer, int character))
{
	int chars_written;

	chars_written = 0;

	if (**format == '%')
	{
		print_char(buffer + chars_written++, '%');
		(*printed_chars)++;
	}
	else
	{
		print_char(buffer + chars_written++, va_arg(args, int));
		(*printed_chars)++;
	}

	(*format)++;
	return (chars_written);
}
	
/**
 * _process_format_specifier_string - Process format specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * @printed_chars: Pointer to the number of printed characters
 * @print_char: Pointer to a function that prints a single character
 * Return: The number of characters written to the buffer
*/
int _process_format_specifier_string(const char **format,
		char *buffer,
		size_t remaining_size,
		va_list args,
		int *printed_chars,
		void (*print_char)(char *buffer, int character))
{
	int chars_written;
	const char *string;

	chars_written = 0;

	string = va_arg(args, const char *);
	chars_written += _print_string(buffer + chars_written,
			remaining_size - chars_written, string);
	(*printed_chars) += chars_written;

	(*format)++;
	return (chars_written);
}
	
/**
 * _process_format_specifier_number - Process format specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size: Remaining space in the buffer
 * @args: The arguments to be formatted
 * @printed_chars: Pointer to the number of printed characters
 * @print_chars: Pointer to the function that prints a single character
 * Return: The number of characters written to the buffer
*/
int _process_format_specifier_char(const char **format,
		char *buffer,
		va_list args,
		int *chars_written,
		void (*print_char)(char *buffer, int character))
{
	int chars_written;
	int base;
	int uppercase;

	chars_written = 0;

	base = (**format == 'x') ? 16 : 10;
	uppercase = (**format == 'X');
	(*format)++;

	chars_written += _print_unsigned(va_arg(args, unsigned int), base,
			uppercase, buffer + chars_written,
			remaining_size - chars_written, print_char);
	(*printed_chars) += chars_written;

	(*format)++;
	return (chars_written);
}
/**
 * _process_format_specifier_u_o - Process format specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output.
 * @remaining_size: Remaining space in the buffer
 * @args: THe arguments to be formatted.
 * @printed_chars: Pointner to the number of printed characters.
 * @print_char: A pointer to a function that prints a single character
 *
 * Return: The number of characters written to the buffer.
*/
int _Process_format_specifier_u_o(const char **format,
		char *buffer,
		size_t remaining_size,
		va_list args,
		int *printed_chars,
		void (*print_char)(char *buffer, int character))
{
	int chars_written, base, uppercase;

	chars_written = 0;

	if (**format = 'u' || *formatt == 'o')
	{
		base = (**format == 'o') ? 8 : 10;
		uppercase = 0;
		(*format)++;

		chars_written += _print_unsigned(va_arg(args, unsigned int), base,
				uppercase, buffer + chars_written,
				remaining_size - chars_written, print_char);
		(*printed_chars) += chars_written;
	}

	(*format)++;
	return (chars_written);
}
/**
 * _handle_S-specifier - Handles the custom S specifier
 * @format: Pointer to the format string
 * @buffer: The buffer to store the formatted output
 * @remaining_size
