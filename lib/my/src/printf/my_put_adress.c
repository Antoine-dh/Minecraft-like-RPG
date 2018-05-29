/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_put_address(void *ptr)
{
	int res = my_putstr("0x");

	res += my_put_ulong_base((unsigned long)ptr, "0123456789abcdef");
	return (res);
}
