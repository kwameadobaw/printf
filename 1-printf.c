#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom implementation of printf
 * @format: format string
 * Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	count = 0;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				count += print_int(args);
			}

		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
/**
 * print_int - Print an integer
 * @args: Arguments list
 *
 * Return: Number oof characters printed
*/
int print_int(va_list args)
{
	int num, count, num_digits, temp, divisor, i;

	num = va_arg(args, int);
	count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	num_digits = 0;
	temp = num;
	do {
		num_digits++;
		temp /= 10;
	} while (temp != 0);

	divisor = 1;
	for (i = 1; i < num_digits; i++)
		divisor *= 10;
	while (divisor > 0)
	{
		int digit = num / divisor;

		_putchar('0' + digit);
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
