#include "main.h"

/**
 * print_zeros: print and handles 0 flags
 * @args: va_list
 * @width: minimum width of output
 *
 *@pad: padding charachter ('0' for zero flag)
 *
 * return: number of printed charachters
 */

int print_zeros(va_list args, int width, char pad)
{
	int num = va_arg(args, int), count = 0, len = 0, neg = 0;
 	char buf[20];
	int i, n = num;
	
	if (num < 0 )
	{
		neg = 1;
		num = -num;
	}

	do {
		buf[len++] = (n % 10) + '0';
		n /= 10;
	}
	while (n > 0);

	if (neg)
	{
		count += write(1, "-", 1);
	}
	
	for (i = len + neg; i < width; i++)
	{
		count += write(1, &pad, 1);
	}

	while (len--)
	{
		count += write(1, &buf[len], 1);
	}
	return (count);
}

