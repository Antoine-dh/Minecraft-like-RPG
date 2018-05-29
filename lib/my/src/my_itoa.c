/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

char *my_itoa(int n, char const *base)
{
	int isneg = (n < 0) ? 1 : 0;
	int i = 0;
	int base_l = (int)my_strlen(base);
	char *str = my_calloc(my_numlen(n, (size_t)base_l) + 1, sizeof(char));

	if (str == NULL)
		return (NULL);
	if (n == 0) {
		free(str);
		return (my_char_to_str(base[0]));
	}
	for (i = 0 ; n != 0 ; i++) {
		str[i] = base[ABS(n % base_l)];
		n = n / base_l;
	}
	if (isneg)
		str[i] = '-';
	my_revstr(str);
	return (str);
}

char *my_utoa(unsigned int n, char const *base)
{
	size_t base_l = my_strlen(base);
	char *str = my_calloc(my_uintlen(n, base_l) + 1, sizeof(char));

	if (str == NULL)
		return (NULL);
	if (n == 0) {
		free(str);
		return (my_char_to_str(base[0]));
	}
	for (size_t i = 0 ; n != 0 ; i++) {
		str[i] = base[n % base_l];
		n = n / base_l;
	}
	my_revstr(str);
	return (str);
}

char *my_ltoa(unsigned long n, char const *base)
{
	size_t base_l = my_strlen(base);
	char *str = my_calloc(my_ulonglen(n, base_l) + 1, sizeof(char));

	if (str == NULL)
		return (NULL);
	if (n == 0) {
		free(str);
		return (my_char_to_str(base[0]));
	}
	for (size_t i = 0 ; n != 0 ; i++) {
		str[i] = base[n % base_l];
		n = n / base_l;
	}
	my_revstr(str);
	return (str);
}
