/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_revstr(char *str)
{
	size_t len = my_strlen(str);
	char tmp;

	for (size_t i = 0 ; i < len / 2 ; i++) {
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
	return (str);
}
