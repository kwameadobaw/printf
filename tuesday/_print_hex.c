#include "main.h"
/**
 * _print_hex - This function prints an unsigned int as hexa number
 * @n: The unsigned int to be printed.
 * @uppercase: Flag indicating whether to use uppercase letters.
 * @size: The size of the buffer.
 * @buffer: The buffer to sotre the number representation.
 *
 * Return: The number of characters printed.
*/
int _print_hex(unsigned int n, int uppercase, char *buffer, size_t size)
{
	int printed_chars = 0, i;
	size_t index = 0, start = 0, end = index - printed_chars - 1;
	char digits[16], temp;

	if (n == 0)
	{
		if (size > 0)
			buffer[0] = '0';
		{
			printed_chars++;
		}
		else
		{
			while (n != 0 && index < size - 1)
			{
				buffer[index++] = base_digits[n % 16];
				n /= 16;
			}

			while (start < end)
			{
				temp = buffer[start];
				buffer[start] = buffer[end];
				buffer[end] = temp;
				start++;
				end--;
			}

			for (i = 0; i < index - printed_chars; i++)
				if (size > 0)
				{
					buffer[i] = digits[i];
				}
		}
		printed_chars += i;
	}

	buffer[printed_chars] = '\0';
	return (printed_chars);
}
