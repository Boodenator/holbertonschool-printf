#include "main.h"

/**
 * print_number - Writes an integer to stdout
 * @n: The integer to print
 * Return: Number of characters printed
 */

int print_integer(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    char buffer[12];
    int i = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num == 0)
        buffer[i++] = '0';

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}
