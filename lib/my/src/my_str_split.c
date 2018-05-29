/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

static size_t get_word_len(char const *str, char *delim)
{
	for (size_t i = 0 ; ; i++)
		if (str[i] == '\0' || my_strindex(str[i], delim) != -1)
			return (i);
}

static size_t count_words(char const *str, char *delim)
{
	size_t words = 0;
	int i = 0;

	while (str[i]) {
		while (my_strindex(str[i], delim) != -1)
			i++;
		if (str[i])
			words++;
		while (my_strindex(str[i], delim) == -1 && str[i])
			i++;
	}
	return (words);
}

char **my_str_split(char const *str, char *delim)
{
	size_t size = count_words(str, delim);
	int i = 0;
	int j = 0;
	char **arr = malloc(sizeof(char *) * (size + 1));

	if (arr == NULL)
		return (NULL);
	while (str[i]) {
		while (my_strindex(str[i], delim) != -1)
			i++;
		if (str[i]) {
			arr[j] = my_strndup(&str[i],
				get_word_len(&str[i], delim));
			j++;
		}
		while (my_strindex(str[i], delim) == -1 && str[i])
			i++;
	}
	arr[size] = NULL;
	return (arr);
}
