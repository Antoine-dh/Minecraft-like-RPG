/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

int my_getnbr_base(char const *str, char const *base)
{
	int result = 0;
	int base_len = (int)my_strlen(base);
	int sign;
	int prev;
	int n;

	for (sign = 1 ; *str == '-' || *str == '+' ; str++)
		if (*str == '-')
			sign = -sign;
	for (size_t i = 0 ; str[i] ; i++) {
		for (n = 0 ; str[i] != base[n] && base[n] != '\0' ; n++);
		if (base[n] == '\0')
			return (result * sign);
		prev = result;
		result = result * base_len + n;
		if ((result - n) / base_len != prev || result < 0)
			return (0);
	}
	return (result * sign);
}

int my_getnbr(char const *str)
{
	if (str == NULL)
		return (0);
	return (my_getnbr_base(str, "0123456789"));
}
