/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

static int print_octal_value(char c)
{
	int res = 0;

	res += my_putchar('\\');
	for (int len = (int)my_numlen((int)c, 8) ; len < 3 ; len++)
		res += my_putchar('0');
	res += (int)my_putnbr_base((int)c, "01234567");
	return (res);
}

int my_put_unprintable(char const *str)
{
	int res = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (str[i] < 32 || str[i] >= 127)
			res += print_octal_value(str[i]);
		else
			res += my_putchar(str[i]);
	}
	return (res);
}
