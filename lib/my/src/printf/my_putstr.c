/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_putchar(char c)
{
	return ((int)write(STDOUT_FILENO, &c, 1));
}

int my_putstr(const char *str)
{
	return ((int)write(STDOUT_FILENO, str, my_strlen(str)));
}

int my_putnstr(const char *str, size_t len)
{
	return ((int)write(STDOUT_FILENO, str, len));
}
