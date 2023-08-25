#include "main.h"

static int handle_char_format(char *buffer, size_t size, va_list args);
static int handle_string_format(char *buffer, size_t size, va_list args);
static int handle_decimal_format(char *buffer, size_t size, va_list args);
static int handle_percent_format(char *buffer, size_t size, va_list args);
static int handle_unsigned_format(char *buffer, size_t size, va_list args);

static const format_handler_t format_handlers[] = {
	{'c', handle_char_format},
	{'s', handle_string_format},
	{'d', handle_decimal_format},
	{'i', handle_decimal_format},
	{'%', handle_percent_format},
	{'u', handle_unsigned_format},

	{0, NULL}
};

int apply_format_handler(char specifier, char *buffer, size_t size, va_list args)
{
	int i =0;

	while (format_handlers[i].specifier != 0)
	{
		if (format_handlers[i].specifier == specifier)
			return format_handlers[i].handler(buffer, size, args);
		i++;
	}
	return (0);
}
static int handle_char_format(char *buffer, size_t size, va_list args)
{
	char c = va_arg(args, int);

	if (size > 0)
	{
		buffer[0] = c;
		buffer[1] = '\0';
		return (1);
	}
	return (0);
}
static int handle_string_format(char *buffer, size_t size, va_list args)
{
	char *str = va_arg(args, char *);
	int chars_written = 0;
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0' && size > 1; i++)
	{
		buffer[i] = str[i];
		size--;
		chars_written++;
	}

	buffer[i] = '\0';
	return chars_written = 0;
}

static int handle_decimal_format(char *buffer, size_t size, va_list args)
{
	int n = va_arg(args, int);
	int chars_written = 0;
	int is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	chars_written += _print_number(n, buffer, size);

	if (is_negative && (size_t)chars_written < size)
	{
		buffer[chars_written] = '-';
		chars_written++;
	}
	return (chars_written);
}

static int handle_percent_format(char *buffer, size_t size, va_list args)
{
	(void)args;

	if (size > 0)
	{
		buffer[0] = '%';
		buffer[1] = '\0';
		return (1);
	}

	return (0);
}
static int handle_unsigned_format(char *buffer, size_t size, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (_print_unsigned(n, 10, 0, buffer, size));
}
