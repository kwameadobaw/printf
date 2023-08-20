#include "main.h"
/**
 * _abs - get the absolute value
 * @n: the value
 * Return: absolute value
 */
int _abs(int n)
{
	return (n < 0 ? -n : n);
}

/**
 * _strlen - get the length of a string
 * @s: the string
 * Return: Length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * _reverse - reverse a string
 * @s: the string
 */
void _reverse(char *s)
{
	int i = 0;
	int j = _strlen(s) - 1;
	char tmp;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

/**
 * _itoa - converts integer to string of digits
 * @n: the integer value
 * @s: the string of digits
 */
void _itoa(int n, char *s)
{
	int i = 0;
	int sign = n;

	if (n == 0)
		s[i++] = '0';
	while (n != 0)
	{
		s[i++] = _abs(n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	_reverse(s);
}

/**
 * _print_int - print integer
 * @n: the value to be printed
 */
void _print_int(int n)
{
	char s[20];

	_itoa(n, s);
	write(1, s, _strlen(s));
}
