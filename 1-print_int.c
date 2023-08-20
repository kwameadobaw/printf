#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom printf function 2
 * @format: Format string
 * @...: Additional arguemnts
 * Return: Number of characters printed
*/
void print_integer(int num)
{
	int reversed, original_num;
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return;
	}

	reversed = 0;
	original_num = num;

	while (reversed > 0)
	{
		_putchar((reversed % 10) + '0');
		reversed /= 10;
	}
}
