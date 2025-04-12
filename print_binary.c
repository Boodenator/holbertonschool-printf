#include "main.h"

int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[33];
	int i = 0, count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = (n % 2) + '0';
		n = n / 2;
	}

	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
