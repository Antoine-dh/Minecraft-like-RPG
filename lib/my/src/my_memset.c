/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
	char *ptr = (char *)s;

	for (size_t i = 0 ; i < n ; ++i)
		ptr[i] = c;
	return (s);
}
