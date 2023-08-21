#include <stdarg.h>
#include "main.h"

/**
 * print_char - Print a character
 * @args: Arguments list
 *
 * Return: Number of characters printed
*/
int print_char(va_list args)
{
	char c;

	va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
<<<<<<< HEAD
 * print_string - Prints a string
 * @args: Arguments list
 *
 * Return: Number of characters printed
*/
int print_string(va_list args)
{
	char *str;
	int count;

	str = va_arg(args, char *);
	count = 0;

	if (!str)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_int - Print an integer
 * @args: Arguments list
 *
 * Return: Number of characters printed
*/
int print_int(va_list args)
{
	int num, int count, num_digits, temp, num_digits, temp, divisor;

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
	for (int i = 1; i < num_digits; i++)
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

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments based on format
 *
=======
 * _printf - Custom implementation of printf
 * @format: format string
>>>>>>> origin/Alex
 * Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	int count;
	va_list args;
<<<<<<< HEAD
=======
	int count;
>>>>>>> origin/Alex

	va_start(args, format);
<<<<<<< HEAD
	if (!format)
		return (-1);
	while (*format)
=======

	while (*format != '\0')
>>>>>>> origin/Alex
	{
		if (*format == '%')
		{
			format++;
<<<<<<< HEAD
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
				count++;
=======
			if (*format == 'd' || *format == 'i')
			{
				count += print_int(args);
			}

		}
		else
		{
			_putchar(*format);
			count++;
>>>>>>> origin/Alex
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
