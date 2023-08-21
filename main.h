#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>


int _putchar(char c);
int _printf(const char *format, ...);
void handle_percent(va_list args);
void percent_handler(va_list args);
void handle_string(va_list args);
void s_handler(va_list args);
void handle_percent(va_list args);
void percent_handler(va_list args);
void handle_character(va_list args);
void c_handler(va_list args);

#endif
