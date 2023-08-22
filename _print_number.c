#include "main.h"

int _print_number(int n, char *buffer, size_t size)
{
	int printed_chars;
	size_t start;
	size_t end;
	char temp;
	size_t index;

	printed_chars = 0;

	if (n < 0)
	{
		if (size > 0)
		{
			buffer[0] = '-';
		}
		printed_chars++;
		n = -n;
	}
	index = printed_chars;
	while (n != 0 && index < size - 1)
	{
		buffer[index] = (n % 10) + '0';
		n /= 10;
		index++;
		printed_chars++;
	}
	start = printed_chars > 0 ? printed_chars - 1 : 0;
	end = index - 1;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}

	buffer[index] = '\0';
	return (printed_chars);
}

