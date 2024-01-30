#include "main.h"

/**
* print_char - print a character
* @args: argument
* Return: characters printed
*/

int print_char(va_list args)
{
char c = va_arg(args, int);
return (_putchar(c));
}

/**
* print_str - prints a string
* @args: argument
* Return: characters printed
*/

int print_str(va_list args)
{
char *str = va_arg(args, char *);
if (!str)
return (print_string("(null)"));
return (print_string(str));
}

/**
* print_percent - prints a percent symbol
* @args: argument
* Return: characters printed
*/

int print_percent(__attribute__((unused))va_list args)
{
return (_putchar('%'));
}

/**
* print_int - prints an integer
* @args: argument
* Return: number of digits
*/
int print_int(va_list args)
{
int num = va_arg(args, int);
int len = 0;
if (num < 0)
{
len += _putchar('-');
num *= -1;
}
return (len + print_number((unsigned int)num));
}

/**
* print_unsigned - prints an unsigned integer
* @args: argument pointer
* Return: number of digits printed
*/
int print_unsigned(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
return (print_number(num));
}
