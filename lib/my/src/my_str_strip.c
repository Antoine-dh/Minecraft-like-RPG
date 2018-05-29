/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_str_rstrip(char *str, const char *to_strip)
{
	size_t len;

	if (str == NULL)
		return (NULL);
	len = my_strlen(str);
	for (size_t i = len ; i > 0 ; --i) {
		if (my_strindex(str[i - 1], to_strip) != -1)
			str[i - 1] = '\0';
		else
			break;
	}
	return (str);
}

char *my_str_lstrip(char *str, const char *to_strip)
{
	char *new = str;
	size_t len;

	if (str == NULL)
		return (NULL);
	len = my_strlen(str);
	for (size_t i = 0 ; i < len ; ++i) {
		if (my_strindex(str[i], to_strip) != -1)
			new++;
		else
			break;
	}
	new = my_strdup(new);
	free(str);
	return (new);
}

char *my_str_strip(char *str, const char *to_strip)
{
	return (my_str_lstrip(my_str_rstrip(str, to_strip), to_strip));
}
