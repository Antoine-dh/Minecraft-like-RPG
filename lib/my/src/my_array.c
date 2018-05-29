/*
** EPITECH PROJECT, 2018
** minishell2
** File description:
** Created by antoine_dh,
*/

#include "my.h"

size_t my_array_len(void *const *array)
{
	for (size_t i = 0 ; ; ++i)
		if (array[i] == NULL)
			return (i);
}

void my_free_array(void **array)
{
	if (array == NULL)
		return;
	for (size_t i = 0 ; array[i] != NULL ; ++i)
		free(array[i]);
	free(array);
}
