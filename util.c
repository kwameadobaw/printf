#include "main.h"
/**
 * _print_number_base - Prints an unsigned number in a specified base.
 * @n: The number to print.
 * @base: The base of the number (e.g., 2, 8, 16).
 * @uppercase: Flag for uppercase hex (1) or lowercase (0).
 *
 * Return: Number of digits printed.
*/
extern char buffer[];
extern int buffer_index;
int _print_number_base(unsigned int n, int base, int uppercase)
{
	int num_digits, i;
	unsigned int temp;
	char tmp;

	char digits[] = "0123456789abcdef";
	if (uppercase)
	{
		digits[10] = 'A';
		digits[11] = 'B';
		digits[12] = 'C';
		digits[13] = 'D';
		digits[14] = 'E';
		digits[15] = 'F';
	}

	num_digits = 0;
	temp = n;

	for (i = 0; i < BUFFER_SIZE; i++)
	{
		buffer[buffer_index++] = digits[temp % base];
		num_digits++;
		temp /= base;
		if (temp == 0)
			break;
	}
	/* Reverse the digits in the buffer */
	for (i = 0; i < num_digits / 2; i++)
	{
		tmp = buffer[buffer_index - 1 -i];
		buffer[buffer_index - 1 - i] = buffer[buffer_index - num_digits + i];
		buffer[buffer_index - num_digits + i] = tmp;
	}

	return (num_digits);
}
