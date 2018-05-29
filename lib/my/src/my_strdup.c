/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_strndup(const char *str, size_t n)
{
	char *dup = malloc(sizeof(char) * n + 1);

	if (dup == NULL)
		return (NULL);
	dup[n] = '\0';
	return (my_strncpy(dup, str, n));
}

char *my_strdup(const char *str)
{
	if (str == NULL)
		return (NULL);
	return (my_strndup(str, my_strlen(str)));
}

void *my_memdup(const void *ptr, size_t n)
{
	void *dup = malloc(n);

	if (dup == NULL)
		return (NULL);
	return (my_memcpy(dup, ptr, n));
}
