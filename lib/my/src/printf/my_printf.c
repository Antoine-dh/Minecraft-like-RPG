/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"
#include "printf.h"

static void init_fptr(int (*fptr[])(va_list))
{
	fptr[0] = &printf_int;
	fptr[1] = &printf_int;
	fptr[2] = &printf_uint;
	fptr[3] = &printf_oct;
	fptr[4] = &printf_hex;
	fptr[5] = &printf_hexcap;
	fptr[6] = &printf_str;
	fptr[7] = &printf_char;
	fptr[8] = &printf_ptr;
	fptr[9] = &printf_unprintable;
	fptr[10] = &printf_bin;
	fptr[11] = &printf_percent;
}

static int print_flag(int index, va_list arglist)
{
	int (*fptr[12])(va_list);

	init_fptr(fptr);
	return ((*fptr[index])(arglist));
}

static int parse_flag(const char **ptr, va_list arglist, int *err)
{
	char flags[] = "diuoxXscpSb%";
	int index;
	int res = 0;

	while (**ptr == ' ')
		(*ptr)++;
	index = my_strindex(**ptr, flags);
	if (index >= 0)
		res += print_flag(index, arglist);
	else {
		*err = 1;
		return (0);
	}
	(*ptr)++;
	return (res);
}

int my_printf(const char *format, ...)
{
	va_list arglist;
	int res = 0;
	int err = 0;

	va_start(arglist, format);
	for (int i = 0 ; *format ;) {
		if (*format != '%') {
			res += my_putchar(*format);
			format++;
		} else {
			format++;
			res += parse_flag(&format, arglist, &err);
			i++;
		}
	}
	va_end(arglist);
	return (err ? -1 : res);
}
