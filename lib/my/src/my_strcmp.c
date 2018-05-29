/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_strncmp(const char *a, const char *b, size_t n)
{
	size_t i;

	for (i = 0 ; a[i] != '\0' && b[i] != '\0' && i < n ; i++)
		if (a[i] != b[i])
			return (a[i] - b[i]);
	if (i == n)
		return (0);
	return (a[i] - b[i]);
}

int my_strcmp(const char *a, const char *b)
{
	size_t i;

	for (i = 0 ; a[i] != '\0' && b[i] != '\0' ; i++)
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (a[i] - b[i]);
}
