#include "main.h"
/**
 * handle_percent - Handles percentage
 * @args: the arguments
 */
void handle_percent(va_list args)
{
	char percent = '%';

	write(1, &percent, 1);
}

/**
 * percent_handler - handles percentage
 * @args: the arguments
 */
void percent_handler(va_list args)
{
	handle_percent(args);
}
