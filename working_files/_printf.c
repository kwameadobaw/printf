#include <stdarg.h>
#include <unistd.h>
#include "main.h"
char buffer[BUFFER_SIZE];
int buffer_index = 0;
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
	printed_chars = _vsnprintf(buffer, BUFFER_SIZE, format, args);

	write(1, buffer, printed_chars);

	va_end(args);
	return (printed_chars);
}
