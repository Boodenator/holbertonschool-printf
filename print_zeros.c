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
	if (num < 0 )
	{
		neg = 1;
		num = -num;
	}
	else
	{
		num = num;
	}








