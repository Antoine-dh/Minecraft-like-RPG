/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_putnbr_base(int nb, char const *base)
{
	char *res = my_itoa(nb, base);
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}

int my_put_uint_base(unsigned int nb, char const *base)
{
	char *res = my_utoa(nb, base);
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}

int my_put_ulong_base(unsigned long nb, char const *base)
{
	char *res = my_ltoa(nb, base);
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}
