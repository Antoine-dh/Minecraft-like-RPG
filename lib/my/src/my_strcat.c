/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_strncat(char *dest, const char *src, size_t n)
{
	size_t len = my_strlen(dest);
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

char *my_strcat(char *dest, const char *src)
{
	return (my_strncat(dest, src, my_strlen(src)));
}
