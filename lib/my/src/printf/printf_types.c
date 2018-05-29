/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "printf.h"

int printf_int(va_list args)
{
	return (my_put_nbr(va_arg(args, int)));
}

int printf_uint(va_list args)
{
	return (my_put_uint(va_arg(args, unsigned)));
}

int printf_str(va_list args)
{
	return (my_putstr(va_arg(args, char *)));
}

int printf_char(va_list args)
{
	unsigned char c = (unsigned char)va_arg(args, unsigned);

	return ((int)write(1, &c, 1));
}
