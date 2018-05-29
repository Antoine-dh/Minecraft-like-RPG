/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_putstr_err(const char *str)
{
	return ((int)write(STDERR_FILENO, str, my_strlen(str)));
}

int my_putnstr_err(const char *str, size_t len)
{
	return ((int)write(STDERR_FILENO, str, len));
}
