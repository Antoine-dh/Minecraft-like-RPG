/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** Created by antoine_dh,
*/

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	void *ptr = malloc(total);
	char *char_ptr = (char *)ptr;

	if (ptr == NULL)
		return (NULL);
	for (size_t i = 0 ; i < total ; i++)
		char_ptr[i] = 0;
	return (ptr);
}

void *my_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);
	if (ptr != NULL)
		free(ptr);
	return (new_ptr);
}
