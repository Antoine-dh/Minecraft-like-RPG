/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[i] = src[i];
	while (i < n) {
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char *my_strcpy(char *dest, const char *src)
{
	return (my_strncpy(dest, src, my_strlen(src) + 1));
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *ptr_dest = (char *)dest;
	char *ptr_src = (char *)src;

	for (size_t i = 0 ; i < n ; i++)
		ptr_dest[i] = ptr_src[i];
	return (dest);
}
