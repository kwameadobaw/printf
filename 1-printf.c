#include "main.h"
/**
 * print_int - Print an integer
 * @args: Arguments list
 *
 * Return: Number oof characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;

	while (*format != '\0')
	{
		va_list args;
		int count;

		va_start(args, format);
		count = 0;

		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				if (*format == '\0')
					break;
				if (*format == '%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num;

				num = va_arg(args, int);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
		va_end(args);
		return (count);
