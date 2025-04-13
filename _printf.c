#include "main.h"

/**
 * flush_buffer - Writes buffer content to stdout
 * @buffer: The buffer to write
 * @length: Number of characters in the buffer
 * Return: Number of characters written
 */
int flush_buffer(char *buffer, int length)
{
	write(1, buffer, length);
	return length;
}

/**
 * _printf - Produces output according to a format
 * @format: A character string containing format specifiers
 * @buf: is the buffer index
 *
 * Return: Number of characters printed without null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
    	int i = 0, count = 0, buf = 0;
	char buffer[BUFFER_SIZE];

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
		buffer[buf++] = format[i];
		if (buf == BUFFER_SIZE)
		{
			count += flush_buffer(buffer, buf);
			buf = 0;
		}
   }
        else
        {
            i++;
            if (!format[i])
                return (-1);

	    /* buffer */
	    if (buf > 0)
	    {
		    count += flush_buffer(buffer, buf);
		    buf = 0;
	    }

            if (format[i] == 'c')
                count += print_char(args);
            else if (format[i] == 's')
                count += print_string(args);
            else if (format[i] == '%')
                count += print_percent();
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_integer(args);
	    else if (format[i] == 'b')
		    count += print_binary(args);
	    else if (format[i] == 'u')
		count += print_unsigned(args);
	    else if (format[i] == 'o')
		count += print_octal(args);
	    else if (format[i] == 'x')
		count += print_hex(args);
	    else if (format[i] == 'X')
		count += print_HEX(args);
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        i++;
    }

    if (buf > 0)
    {
	    count += flush_buffer(buffer, buf);
    }

    va_end(args);
    return (count);
}
