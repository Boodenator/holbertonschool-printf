#include "main.h"

/**
 * print_symbol - will print an integer with + or space flag
 * @args: argument list
 * @flag: '+' or ' '
 * Return: characters printed
 */
int print_symbol(va_list args, char flag)
{
	int n = va_arg(args, int);
	int count = 0;
	char num[12];
	int i = 0, is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	else if (flag == '+')
		write(1, "+", 1), count++;
	else if (flag == ' ')
		write(1, " ", 1), count++;

	if (is_negative)
		write(1, "-", 1), count++;

	do {
		num[i++] = (n % 10) + '0';
		n /= 10;
	} while (n);

	while (i--)
		write(1, &num[i], 1), count++;

	return count;
}