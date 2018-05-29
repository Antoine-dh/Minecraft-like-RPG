/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

float my_strtof(const char *str)
{
	float res = 0.0f;
	int decimal = 0;
	float sign = 1.0f;
	float div = 1;

	if (str[0] == '-') {
		sign = -1.0f;
		str++;
	}
	for (; *str != '\0' ; str++) {
		if (*str == '.')
			decimal = 1;
		else if (!decimal) {
			res *= 10;
			res += *str - '0';
		} else {
			div *= 10;
			res += (float)(*str - '0') / div;
		}
	}
	return (res * sign);
}
