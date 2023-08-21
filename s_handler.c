#include "main.h"
/**
 * handle_string - handle s specifier
 * @args: the arguments
 */
void handle_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/**
 * s_handler - handles s
 * @args: the arguments
 */
void s_handler(va_list args)
{
	handle_string(args);
}
