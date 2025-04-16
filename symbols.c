#include "main.h"
#include <stdarg.h>
int print_symbol(va_list args, char flag)
{
    if (flag == '+')
    {
        write(1, &flag, 1);
    }
    else if (flag == ' ')
    {
        write(1, &flag, 1);
    }
}