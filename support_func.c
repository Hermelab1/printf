#iinclude "main.h"

/**
 * print_number - prints integer
 * @num: integer to be displayed
 * Return: digits to be printed
 */
int print_number(unsigned int num)
{
	int power = 1, len = 0;

	while ((num / power) > 9)
		power *= 10;
	while (power > 0)
	{
		len += _putchar('0' + num / power);
		num %= power;
		power /= 10;
	}
	return (len);
}

/**
 * print_string - prints string
 * @str: string to be displayed
 * Return: characters to display
 */
int print_string(char *str)
{
	int len = 0;

	while (*str)
	{
		len += _putchar(*str);
		str++;
	}
	return (len);
}

/**
 * print_binary - prints a value in binary
 * @num: value to be printed
 * Return: number of digit
 */
int print_binary(unsigned int num)
{
	int counts = 0;

	if (num == 0)
	{
		return (0);
	}
	else
	{
		counts += print_binary(num / 2);
		counts += _putchar((num % 2) + '0');
	}
	return (counts);
}

/**
 * print_hexadecimal - prints value in hexadecimal
 * @value: value to be printed
 * @affix: flag
 * @cap: flag
 * Return: number of digits printed
 */
int print_hexadecimal(unsigned long int value, int affix, int cap)
{
	int count = 0;

	if (value < 16)
	{
		if (!affix)
			count += _putchar('0');
		if (value < 10)
			count += _putchar(value + '0');
		else
			count += cap ?
				_putchar((value - 10) + 'A') : _putchar((value - 10) + 'a');
	}
	else
	{
		affix = 1;
		count += print_hexadecimal((value / 16), affix, cap);
		count += print_hexadecimal((value % 16), affix, cap);
	}
	return (count);
}

/**
 * print_octal - prints a value in octal
 * @num: value to be printed
 * Return: digits to print
 */
int print_octal(unsigned int num)
{
	int counts = 0;

	if (num < 8)
	{
		counts += _putchar(num + '0');
	}
	else
	{
		counts += print_octal((num / 8));
		counts += _putchar((num % 8) + '0');
	}
	return (counts);
}
