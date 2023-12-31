#include "main.h"

int _print_hex(unsigned int n, int uppercase, char *buffer, size_t size)
{
	int printed_chars;
	char temp;
	size_t index, start, end, i;
	char digits[16];
	const char *base_digits;

	base_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

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
		index = printed_chars;

		while (n != 0 && index < size - 1)
		{
			digits[index] = base_digits[n % 16];
			n /= 16;
			index++;
			printed_chars++;
		}

		start = printed_chars - printed_chars;
		end = index - printed_chars - 1;
		while (start < end)
		{
			temp = digits[start];
			digits[start] = digits[end];
			digits[end] = temp;
			start++;
			end--;
		}

		for (i = 0; i < index - printed_chars; i++)
		{
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
