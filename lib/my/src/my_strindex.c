/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_strnindex(char c, const char *str, size_t n)
{
	for (size_t i = 0 ; str[i] != '\0' && i < n ; i++)
		if (str[i] == c)
			return ((int)i);
	return (-1);
}

int my_strindex(char c, const char *str)
{
	return (my_strnindex(c, str, my_strlen(str)));
}
