#include "main.h"
/**
 * _print_unsigned - prints unsigned int with custom base.
 * @n: The unsigned int to be printed
 * @base: The base for printing
 * @uppercase: Flag indicating whether to use uppercase
 * @buffer: The buffer to store the printed characters
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
*/

int _print_unsigned(unsigned int n, int base, char *buffer)
{
	void(uppercase);
	static const char base_digits[] = "0123456789ABCDEF";
	int printed_chars, i, size;
	char digits[16];

	printed_chars = 0;

	if (n == 0)
	{
		if (size > 0)
		{
			buffer[0] = '0';
		}
		printed_chars++;
	}
	else
	{
		for (i = printed_chars; i >= 0; i--)
		{
			digits[i] = base_digits[n % base];
			n /= base;
		}
	}

	for (i = 0; i < printed_chars; i++)
	{
		buffer[i] = digits[printed_chars - i - 1];
	}

	buffer[printed_chars] = '\0';
	return (printed_chars);
}
