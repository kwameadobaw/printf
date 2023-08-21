#include "main.h"
/**
 * printBinary - print a binary
 * @num: the number to convert
 */
void printBinary(unsigned int num)
{
	int i;
	int b[32];
	int index;

	if (num == 0)
	{
		_putchar('0');
		return;
	}
	index = 0;

	while (num > 0)
	{
		b[index++] = num % 2;
		num /= 2;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(b[i] + '0');
	}
}
