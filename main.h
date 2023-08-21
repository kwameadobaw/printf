#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _abs(int n);
int _strlen(char *s);
void _reverse(char *s);
void _itoa(int n, char *s);
int print_int(va_list args);
int _print(const char *format, ...);

#endif
