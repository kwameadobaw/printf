#include "main.h"

int _print_unsigned(unsigned int n, int base, int uppercase, char *buffer, size_t size)
{
	int printed_chars;
	char digits[16];
	char temp;
	const char *base_digits;
	size_t index, start, end, i;

	printed_chars = 0;
	base_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

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
			digits[index - printed_chars] = base_digits[n % base];
			n /= base;
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
