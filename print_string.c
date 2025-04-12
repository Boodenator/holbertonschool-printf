#include "main.h"

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;

   if (str == NULL)
	   str = "(null)";

   while (str[i])
        write(1, &str[i++], 1);

    return i;
}
