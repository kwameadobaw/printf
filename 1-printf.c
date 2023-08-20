#include "main.h"
/**
 * _printf - Custom implementation of printf
 * @format: format string
 * @:...: Variable number of arguments
 * Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count, num;

	count = 0;
	va_start(args, format);

	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				/* Handle integer specifiers */
				case 'd':
				case 'i':
					{
					num = va_arg(args, int);
					print_integer(num);
					break;
					}
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
	}
	va_end(args);
	return (count);
}
