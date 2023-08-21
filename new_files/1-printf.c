#include "main.h"
/**
 * print_integer - Print an integer without using printf
 * @num: The integer to be printed
 */
void print_integer(int num)
{
	int i;
	char buffer [20];
	int idx;

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

	while (num > 0)
	{
		buffer[idx++] = '0' + (num % 10);
		num /= 10;
	}
	for (i = idx - 1; i >= 0; --i)
	{
		_putchar(buffer[i]);
	}
}

/**
 * custom_printf - Custom implementation of printf
 * @format: The format string
 * @...: Additional arguments
 */
void custom_printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; ++i)
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int num = va_arg(args, int);

			print_integer(num);
			++i;
		}
		else
		{
			_putchar(format[i]);
		}
	}
	va_end(args);
}
