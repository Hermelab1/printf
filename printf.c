#include "main.h"

/**
 * _printf - prints anything we want
 *
 * @format: list of arguments
 * Return: integer(number of characters to be printed)
 */
int _printf(const char *format, ...)
{
	int count_of_char = 0;
	form_spec specifiers[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{"r", print_rev},
		{"R", print_rot13},
		{"S", print_STR},
		{"p", print_addr},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{NULL, NULL}
	};
	va_list args;

	if (!format)
	{
		return (-1);
	}
	va_start(args, format);
	count_of_char = printer(format, specifiers, args);
	va_end(args);
	return (count_of_char);
}

/**
 * printer - prints anything we want
 *
 * @format: list of arguments
 * @specifiers: specifiers list
 * @args: list of argument
 * Return: integer(number of characters to be printed)
 */
int printer(const char *format, form_spec specifiers[], va_list args)
{
	int x = 0, y, count_of_char = 0, examiner;

	while (format[x])
	{
		if (format[x] == '%')
		{
			x++;
			if (format[x] == '\0')
				return (-1);
			for (y = 0; specifiers[y].c != NULL; y++)
			{
				if (format[x] == specifiers[y].c[0])
				{
					examiner = specifiers[y].f(args);
					if (examiner == -1)
						return (-1);
					count_of_char += examiner;
					break;
				}
			}
			if (specifiers[y].c == NULL)
			{
				count_of_char += print_percent(args);
				count_of_char += _putchar(format[x]);
			}
		}
		else
		{
			count_of_char += _putchar(format[x]);
		}
		x++;
	}
	return (count_of_char);
}
