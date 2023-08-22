#include "main.h"

/**
 * _printf_int - Print an integer
 * @args: Arguments list
 *
 * Return: Number oof characters printed
*/
int _printf_int(const char *format, ...)
{
	va_list args;
	int count;
	int n;

	va_start(args, format);
	count = 0;
	n = va_arg(args, int);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{

				_putchar(n + '0');
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
	}
	
	va_end(args);
	return (count);
}
