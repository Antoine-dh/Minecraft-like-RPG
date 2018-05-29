/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_put_nbr(int nb)
{
	char *res = my_itoa(nb, "0123456789");
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}

int my_put_uint(unsigned int nb)
{
	char *res = my_utoa(nb, "0123456789");
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}

int my_put_ulong(unsigned long nb)
{
	char *res = my_ltoa(nb, "0123456789");
	size_t len;

	if (res == NULL)
		return (0);
	len = my_strlen(res);
	my_putstr(res);
	free(res);
	return ((int)len);
}
