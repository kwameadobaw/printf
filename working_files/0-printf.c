#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Custom implementation of printf
 * @format: Format string
 * @:...: Variable number of arguments
 * Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	int count;
	char *str;
	va_list args;
	int c;

	va_start(args, format);
	count = 0;

	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
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
