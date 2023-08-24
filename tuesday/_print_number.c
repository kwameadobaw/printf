#include "main.h"
/**
 * _print_number - A function to print a number
 * @n: The integer number to be printed.
 * @buffer: The buffer to store the number representation.
 * @size: The size of the buffer.
 * @print_digit: A pointer to a function that prints a single digit.
 * Return: The number of characters printed.
 */
int _print_number(int n, char *buffer, size_t size,
		void (*print_digit)(char *buffer, int digit))
{
	(void)size;
	int printed_chars;
	int index;

	printed_chars = 0;
	index = 0;

	if (n < 0)
	{
		print_digit(buffer, '-');
		printed_chars++;
		n = -n;
	}

	index = printed_chars;
	while (n != 0)
	{
		print_digit(buffer + index++, (n % 10) + '0');
		n /= 10;
	}
	buffer[index] = '\0';
	return (printed_chars);
}
