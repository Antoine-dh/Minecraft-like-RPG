/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (!CONTAINS(str[i], 'a', 'z') && !CONTAINS(str[i], 'A', 'Z'))
			return (0);
	}
	return (1);
}

int my_str_isnum(char const *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (!CONTAINS(str[i], '0', '9'))
			return (0);
	}
	return (1);
}

int my_str_isalnum(char const *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (!CONTAINS(str[i], 'a', 'z') &&
			!CONTAINS(str[i], 'A', 'Z') &&
			!CONTAINS(str[i], '0', '9'))
			return (0);
	}
	return (1);
}

int my_str_isref(char const *str, char const *ref)
{
	for (int i = 0 ; str[i] != '\0' ; i++)
		if (my_strindex(str[i], ref) == -1)
			return (0);
	return (1);
}
