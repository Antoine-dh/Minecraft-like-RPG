/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

size_t my_numlen(int n, size_t base)
{
	size_t len = n < 0 ? 1 : 0;

	while (n) {
		len++;
		n /= (int)base;
	}
	return (len);
}

size_t my_uintlen(unsigned int n, size_t base)
{
	size_t len = 0;

	while (n) {
		len++;
		n /= (int)base;
	}
	return (len);
}

size_t my_ulonglen(unsigned long n, size_t base)
{
	size_t len = 0;

	while (n) {
		len++;
		n /= (int)base;
	}
	return (len);
}
