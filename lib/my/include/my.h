/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#ifndef LIBMY_MY_H
#define LIBMY_MY_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "printf.h"

#define ABS(x)			((x) < (0) ? (-(x)) : (x))
#define MIN(x, y)		((x) < (y) ? (x) : (y))
#define MAX(x, y)		((x) > (y) ? (x) : (y))
#define CLAMP(x, min, max)	(MIN((max), MAX((min), (x))))
#define CONTAINS(x, min, max)	((x) >= (min) && (x) <= (max))
#define LEN(array)		(sizeof(array) / sizeof(*(array)))
#define TO_RAD(x)		((x) * (float)M_PI / 180.0f)
#define TO_DEG(x)		((x) * 180.0f / (float)M_PI)

#define UNUSED			__attribute__ ((unused))
#define UNIQUE(fptr)		__attribute__ ((cleanup(fptr)))

typedef enum {
	FALSE = 0,
	TRUE = 1
} bool_t;

size_t my_strlen(const char *str);
size_t my_strnlen(const char *str, size_t n);

size_t my_array_len(void *const *array);
void my_free_array(void **array);

int my_putchar(char c);
int my_putstr(const char *str);
int my_putnstr(const char *str, size_t len);

int my_putstr_err(const char *str);
int my_putnstr_err(const char *str, size_t len);

void *my_calloc(size_t nmemb, size_t size);
void *my_realloc(void *ptr, size_t size);

void *my_memset(void *s, int c, size_t n);

char *my_revstr(char *str);

char *my_char_to_str(char c);

void *my_memcpy(void *dest, const void *src, size_t n);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);

char *my_strdup(const char *str);
char *my_strndup(const char *str, size_t n);
void *my_memdup(const void *ptr, size_t n);

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, size_t n);

char *my_strcat_dup(char *dest, const char *src);
char *my_strncat_dup(char *dest, const char *src, size_t n);

int my_strcmp(const char *a, const char *b);
int my_strncmp(const char *a, const char *b, size_t n);

int my_strindex(char c, const char *str);
int my_strnindex(char c, const char *str, size_t n);

char **my_str_split(char const *str, char *delim);
char **my_str_usplit(char const *str, char *delim);

int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);

char *my_itoa(int n, char const *base);
char *my_utoa(unsigned int n, char const *base);
char *my_ltoa(unsigned long n, char const *base);

size_t my_numlen(int n, size_t base);
size_t my_uintlen(unsigned int n, size_t base);
size_t my_ulonglen(unsigned long n, size_t base);

int my_putnbr_base(int nb, char const *base);
int my_put_uint_base(unsigned int nb, char const *base);
int my_put_ulong_base(unsigned long nb, char const *base);

int my_put_nbr(int nb);
int my_put_uint(unsigned int nb);
int my_put_ulong(unsigned long nb);

int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isalnum(char const *str);
int my_str_isref(char const *str, char const *ref);

char *my_str_strip(char *str, const char *to_strip);
char *my_str_lstrip(char *str, const char *to_strip);
char *my_str_rstrip(char *str, const char *to_strip);

float my_strtof(const char *str);

int my_put_address(void *ptr);

int my_put_unprintable(char const *str);

#endif //LIBMY_MY_H
