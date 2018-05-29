/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "printf.h"

int printf_ptr(va_list args)
{
	return (my_put_address(va_arg(args, void *)));
}

int printf_unprintable(va_list args)
{
	return (my_put_unprintable(va_arg(args, char *)));
}

int printf_percent(va_list args)
{
	(void)args;
	return (my_putchar('%'));
}
