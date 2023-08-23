#include "main.h"
/**
 * _print_u - Print an unsigned decimal to buffer
 * @args: The arguments to be formatted
 * @buffer: The buffer to store the formatted output
 * @buffer_index: Pointer to the index in the buffer
 * Return: The number of characters printed
*/
int _print_u(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n;
	int printed_chars;

	n = va_arg(args, unsigned int);
	printed_chars = _print_unsigned(n, 10, 0, &buffer[*buffer_index],
		       	BUFFER_SIZE - *buffer_index);
	*buffer_index += printed_chars;
	return (printed_chars);
}
/**
 * _print_o - Print an unsigned integer as an octal number to buffer.
 * @args: The arguments to be formatted
 * @buffer: The buffer to store the formatted output
 * @buffer_index: Pointer to the index in the buffer
 * Return: The number of characters printed
*/
int _print_o(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n;
	int printed_chars;

	n = va_arg(args, unsigned int);
	printed_chars = _print_unsigned(n, 8, 0, &buffer[*buffer_index],
			BUFFER_SIZE - *buffer_index);
	*buffer_index += printed_chars;
	return (printed_chars);
}
/**
 * _print_hex_lo - Print an unsigned integer as a lowercase hexa to buffer
 * @args: The arguments to be formatted
 * @buffer: The buffer to store the formatted output
 * @buffer_index: Pointer to the index in the buffer
 * Return: The number of characters printed
*/
int _print_hex_lo(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n;
	int printed_chars;

	n = va_arg(args, unsigned int);
	printed_chars = _print_hex(n, 0, &buffer[*buffer_index],
			BUFFER_SIZE - *buffer_index);
	*buffer_index += printed_chars;
	return (printed_chars);
}
/**
 * _print_hex_up - Print an unsigned integer as an uppercase hexadecimal
 * @args: The arguments to be formatted
 * @buffer: The buffer to store the formatted output
 * @buffer_index: Pointer to the index in the buffer
 * Return: The number of characters printed
*/
int _print_hex_up(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n;
	int printed_chars;

	n = va_arg(args, unsigned int);
	printed_chars = _print_hex(n, 1, &buffer[*buffer_index],
			BUFFER_SIZE - *buffer_index);
	*buffer_index += printed_chars;
	return (printed_chars);
}
