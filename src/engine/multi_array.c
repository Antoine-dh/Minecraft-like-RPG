/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <string.h>
#include "my.h"

void *multi_array_alloc(const size_t *nmemb, size_t size, int depth)
{
	void **data;

	if (depth <= 1) {
		data = malloc(nmemb[0] * size);
		(void)(data && memset(data, 0, nmemb[0] * size));
		return (data);
	} else
		data = malloc(nmemb[depth - 1] * sizeof(void *));
	if (data == NULL)
		return (NULL);
	for (size_t i = 0 ; i < nmemb[depth - 1] ; ++i) {
		data[i] = multi_array_alloc(nmemb, size, depth - 1);
		if (data[i] == NULL)
			return (NULL);
	}
	return (data);
}
