/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_strncat_dup(char *dest, const char *src, size_t n)
{
	size_t len = n;
	char *new_str;

	if (src == NULL)
		return (dest);
	if (dest != NULL) {
		len += my_strlen(dest);
		new_str = my_strndup(dest, len);
		free(dest);
		if (new_str == NULL)
			return (NULL);
		my_strncat(new_str, src, n);
	} else
		new_str = my_strndup(src, len);
	return (new_str);
}

char *my_strcat_dup(char *dest, const char *src)
{
	if (src == NULL)
		return (dest);
	return (my_strncat_dup(dest, src, my_strlen(src)));
}
