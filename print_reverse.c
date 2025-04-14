#include "main.h"

/**
 * print_reverse - Prints the reverse of a string
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0, i;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	for (i = len - 1; i >= 0; i--)
		write(1, &str[i], 1);

	return (len);
}
