/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#ifndef LIBMY_PRINTF_H
#define LIBMY_PRINTF_H

#include <stdarg.h>

int my_printf(const char *format, ...);

int printf_int(va_list args);
int printf_uint(va_list args);
int printf_str(va_list args);
int printf_char(va_list args);
int printf_hex(va_list args);
int printf_hexcap(va_list args);
int printf_oct(va_list args);
int printf_ptr(va_list args);
int printf_unprintable(va_list args);
int printf_percent(va_list args);
int printf_bin(va_list args);

#endif //LIBMY_PRINTF_H
