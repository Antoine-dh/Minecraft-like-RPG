/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "printf.h"

int printf_hex(va_list args)
{
	return (my_put_uint_base(va_arg(args, unsigned), "0123456789abcdef"));
}

int printf_hexcap(va_list args)
{
	return (my_put_uint_base(va_arg(args, unsigned), "0123456789ABCDEF"));
}

int printf_oct(va_list args)
{
	return (my_put_uint_base(va_arg(args, unsigned), "01234567"));
}

int printf_bin(va_list args)
{
	return (my_put_uint_base(va_arg(args, unsigned), "01"));
}
