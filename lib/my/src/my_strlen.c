/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

size_t my_strlen(const char *str)
{
	for (size_t i = 0 ; ; i++)
		if (str[i] == '\0')
			return (i);
}

size_t my_strnlen(const char *str, size_t size)
{
	for (size_t i = 0 ; ; i++)
		if (str[i] == '\0' || i >= size)
			return (i);
}
