#include "main.h"

int _print_binary(unsigned int n, char *buffer, size_t size)
{
	int printed_chars;
	size_t index, start, end;
	char temp;

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
			buffer[index] = (n % 2) + '0';
			n /= 2;
			index++;
			printed_chars++;
		}

		start = printed_chars - printed_chars;
		end = index - printed_chars - 1;
		while (start < end)
		{
			temp = buffer[start];
			buffer[start] = buffer[end]
				buffer[end] = temp;
			start++;
			end--;
		}
	}

	buffer[printed_chars] = '\0';
	return (printed_chars);
}
