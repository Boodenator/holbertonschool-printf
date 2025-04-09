#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: A character string containing format specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
   va_list args;
   int i = 0, count = 0;
   char *str;
   char c;
   const char *p;

   if (format == NULL)
        return (-1);

    va_start(args, format);
    p = format;

    while (*p)
    {
        if (*p == '%')
        {
            p++;
            if(*p == '0')
		    break;
	    if(*p == 'c') 
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*p == 's')
            {
                str = va_arg(args, char *);
                while (str[i])
                {
                    write(1, &str[i], 1);
                    count++;
		    i++;
                }
            }
            else if (*p == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                write(1, p, 1);
                count += 2;
            }
	}
	    else
	    {
		    write(1, p, 1);
		    count++;
	    }
	    p++;
	}

    va_end(args);
    return (count);
}
