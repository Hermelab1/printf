#include "main.h"

/**
* print_oct - prints in octal
* @args: argument
* Return: number of printed char
*/

int print_oct(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (print_octal(num));
}

/**
* print_hex - prints a number in hexadecimal
* @args: argument
* Return: characters printed
*/

int print_hex(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
if (!num)
return (_putchar('0'));
return (print_hexadecimal(num, 0, 0));
}

/**
* print_HEX - prints a number in hexadecimal in upper case
* @args: argument
* Return: characters printed
*/

int print_HEX(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
if (!num)
return (_putchar('0'));
return (print_hexadecimal(num, 0, 1));
}
