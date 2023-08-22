#include "main.h"
/**
 * _print_num_rec - Recursively print an int to buffer
 * @n: The interger to be printed
 * @buffer: The buffer to store the printed string.
 * @size: The size of the buffer
 * @index: The number of characters printed.
*/
int _print_num_rec(int n, char *buffer, size_t size, size_t index)
{
	int digits;

	if (n == 0)
	{
		buffer[index] = '0';
		return (0);
	}
	else if (n < 0)
	{
		buffer[index] = '-';
		return (1) + (_print_num_rec(-n, buffer, size, index + 1));
	}
	else if (index >= size - 1)
		return (0);
	else
	{
		digits = _print_num_rec(n / 10, buffer, size, index);
		buffer[index + digits] = (n % 10) + '0';
		return (digits + 1);
	}
}

/**
 * print_number - Print an integer to buffer
 * @n: The integer to be printed
 * @buffer: The buffer to store the printed string
 * @size: The size of the buffer
 * Return: The number of characters printed
*/
int _print_number(int n, char *buffer, size_t size)
{
	size_t index = 0;
	int printed_chars = _print_num_rec(n, buffer, size, index);

	buffer[printed_chars] = '\0';
	return (printed_chars);
}
