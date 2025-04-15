#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_integer(va_list args, char flag);
int print_binary(va_list args);

int print_unsigned(va_list args);
int print_octal(va_list args, char flag);
int print_hex(va_list args, char flag);
int print_HEX(va_list args, char flag);
int print_reverse(va_list args);
int print_symbol(va_list args, char flag);

int flush_buffer(char *buffer, int length);
int print_zeros(va_list args, int width, char pad);

#endif
