#include "main.h"

/**
 * print_number_base - Prints an unsigned int in a given base
 * @n: The number to print
 * @base: The base to convert into.
 * @uppercase: 1 if hex should be uppercase, 0 otherwise
 * Return: Number of characters printed
 */
int print_number_base(unsigned int n, int base, int uppercase)
{
    char digits[] = "0123456789abcdef";
    char digits_upper[] = "0123456789ABCDEF";
    char buffer[32];
    int i = 0, j, count = 0;
    char *set = uppercase ? digits_upper : digits;

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        buffer[i++] = set[n % base];
        n /= base;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        count++;
    }

    return count;
}

int print_unsigned(va_list args)
{
    return (print_number_base(va_arg(args, unsigned int), 10, 0));
}

int print_octal(va_list args)
{
    return (print_number_base(va_arg(args, unsigned int), 8, 0));
}

int print_hex(va_list args)
{
    return (print_number_base(va_arg(args, unsigned int), 16, 0));
}

int print_HEX(va_list args)
{
    return (print_number_base(va_arg(args, unsigned int), 16, 1));
}
