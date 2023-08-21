#include "main.h"
/**
 * _printf - custom printf
 * @format: format specifier
 * Return: the length
 */

typedef void (*conversion_handler)(va_list args);
{
	char specifier;
	conversion_handler handler;
} conversion_specifier;

conversion_specifier specifiers[] = {
	{'c', c_handler},
	{'s', s_handler},
	{'%', percent_handler},
	{'\0', NULL}
};
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

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
			conversion_specifier *specifier = specifiers;

			while (specifier->specifier != '\0')
			{
				if (specifier->specifier == *format)
				{
					format++;
					specifier->handler(args);
					break;
				}
				specifier++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
