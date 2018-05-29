/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_char_to_str(char const c)
{
	char *str = my_calloc(2, sizeof(char));

	if (str == NULL)
		return (NULL);
	str[0] = c;
	return (str);
}
