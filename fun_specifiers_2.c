#include "main.h"

/**
* print_bin - prints an unsigned integer in binary
* @args: argument
* Return: number to print
*/

int print_bin(va_list args)
{
unsigned int value = va_arg(args, unsigned int);
if (value == 0)
{
return (_putchar('0'));
}
if (value == 1)
{
return (_putchar('1'));
}
else
{
return (print_binary(value));
}
}

/**
* print_rev - prints a string in reverse
* @args: argument
* Return: characters to print
*/

int print_rev(va_list args)
{
char *str = va_arg(args, char *);
int len = 0, count = 0;
if (!str)
return (-1);
while (*str)
{
str++;
len++;
}
while (len > 0)
{
str--;
count += _putchar(*str);
len--;
}
return (count);
}

/**
* print_rot13 - prints a string in rot13
* @args: argument
* Return: characters to print
*/

int print_rot13(va_list args)
{
char *str = va_arg(args, char *);
int x, count = 0;
if (!str)
return (-1);
for (x = 0; str[x]; x++)
{
if ((str[x] >= 'a' && str[x] <= 'm') ||
(str[x] >= 'A' && str[x] <= 'M'))
{
count += _putchar(str[x] + 13);
}
else if ((str[x] >= 'n' && str[x] <= 'z') ||
(str[x] >= 'N' && str[x] <= 'Z'))
{
count += _putchar(str[x] - 13);
}
else
{
count += _putchar(str[x]);
}
}
return (count);
}

/**
* print_STR - prints a string
* @args: argument
* Return: characters to print
*/

int print_STR(va_list args)
{
char *str = va_arg(args, char *);
int x, count = 0;
if (!str)
return (-1);
for (x = 0; str[x]; x++)
{
if (str[x] < 32 || str[x] >= 127)
{
count += _putchar('\\');
count += _putchar('x');
count += print_hexadecimal(str[x], 0, 1);
}
else
{
count += _putchar(str[x]);
}
}
return (count);
}


/**
* print_addr - prints address
* @args: argument
* Return: address printed
*/
int print_addr(va_list args)
{
unsigned long int value = va_arg(args, unsigned long int);
int count = 0;
if (!value)
{
return (print_string("(nil)"));
}
count += print_string("0x");
count += print_hexadecimal(value, 1, 0);
return (count);
}
