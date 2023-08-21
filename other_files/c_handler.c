#include "main.h"
/**
 * handle_character - handles c character
 * @args: the arguments
 */
void handle_character(va_list args)
{
	char c = (char)va_arg(args, int);
	write(1, &c, 1);
}

/**
 * c_handler - hancles c
 * @args: the arguments
 */
void c_handler(va_list args)
{
	handle_character(args);
}
